// (Reading Phone Numbers with and Overloaded Stream Extraction Operator) In Fig.11.5,
//  the stream extraction and stream insertion operators were overloaded for input and output of objects
//  of the PhoneNumber class. Rewrite the stream extraction operator to perform the following error
//  checking on input. The operator>> function will need to be reimplemented. 
// a) Input the entire phone number into an array. Test that the proper number of characters
//  has been entered. There should be a total of 14 characters read for a phone number of
//  the form (800) 555-1212. Use ios_base-member-function clear to set failbit for im
// proper input. 
// b) The area code and exchange do not begin with 0 or 1. Test the first digit of the area
// code and exchange portions of the phone number to be sure that neither begins with 0
//  or1. Use ios_base-member-functionclear to set failbit for improper input. 
// c) The middle digit of an area code used to be limited to 0 or 1 (although this has changed
//  recently). Test the middle digit for a value of 0 or 1. Use the ios_base-member-function
//  clear to set failbit for improper input. If none of the above operations results in fail
// bit being set for improper input, copy the three parts of the telephone number into th areaCode,exchange and line members of the PhoneNumber object. If failbit has been
//  set on the input, have the program print an error message and end, rather than print the
//  phone number.

#include <iostream>
#include <iomanip>
#include <string>

class PhoneNumber {
    friend std::ostream& operator<<(std::ostream& output, const PhoneNumber& number);
    friend std::istream& operator>>(std::istream& input, PhoneNumber& number);

private:
    std::string areaCode;   // 3-digit area code
    std::string exchange;   // 3-digit exchange
    std::string line;       // 4-digit line number
    bool valid;             // Flag to indicate valid phone number

public:
    PhoneNumber() : areaCode(""), exchange(""), line(""), valid(false) {}

    // Overloaded constructor to initialize PhoneNumber object with values
    PhoneNumber(std::string ac, std::string ex, std::string ln) : areaCode(ac), exchange(ex), line(ln), valid(true) {}

    // Getter for valid flag
    bool isValid() const {
        return valid;
    }
};

// Overloaded stream insertion operator
std::ostream& operator<<(std::ostream& output, const PhoneNumber& number) {
    if (number.isValid()) {
        output << "(" << number.areaCode << ") " << number.exchange << "-" << number.line;
    } else {
        output << "Invalid phone number";
    }
    return output;
}

// Overloaded stream extraction operator
std::istream& operator>>(std::istream& input, PhoneNumber& number) {
    std::string phoneNumber;
    input >> std::setw(14) >> phoneNumber; // Read exactly 14 characters

    // Check if exactly 14 characters were read
    if (phoneNumber.size() != 14) {
        input.clear(std::ios_base::failbit); // Set failbit for improper input
        return input;
    }

    // Validate area code and exchange
    if (phoneNumber[1] == '0' || phoneNumber[1] == '1' ||
        phoneNumber[6] == '0' || phoneNumber[6] == '1') {
        input.clear(std::ios_base::failbit); // Set failbit for improper input
        return input;
    }

    // Validate middle digit of area code (optional check)
    if (phoneNumber[2] == '0' || phoneNumber[2] == '1') {
        input.clear(std::ios_base::failbit); // Set failbit for improper input
        return input;
    }

    // Extract parts of the phone number
    number.areaCode = phoneNumber.substr(1, 3);     // Extract area code
    number.exchange = phoneNumber.substr(6, 3);     // Extract exchange
    number.line = phoneNumber.substr(10, 4);        // Extract line number
    number.valid = true;                            // Set valid flag

    return input;
}

int main() {
    PhoneNumber phone;

    std::cout << "Enter a phone number in the format (800) 555-1212: ";
    std::cin >> phone;

    if (!std::cin.fail()) {
        std::cout << "Valid phone number entered: " << phone << std::endl;
    } else {
        std::cout << "Error: Invalid phone number format." << std::endl;
    }

    return 0;
}
