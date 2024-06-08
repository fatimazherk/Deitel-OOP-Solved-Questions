// 4.27 (Printing the Decimmal Equivalent of a Binary Number) Input an integer containing only
// 0s and 1s (i.e., a “binary” integer) and print its decimal equivalent. Use the modulus and division
// operators to pick off the “binary” number’s digits one at a time from right to left. Much as in the
// decimal number system, where the rightmost digit has a positional value of 1, the next digit left has
// a positional value of 10, then 100, then 1000, and so on, in the binary number system the rightmost
// digit has a positional value of 1, the next digit left has a positional value of 2, then 4, then 8, and so
// on. Thus the decimal number 234 can be interpreted as 2 * 100 + 3 * 10 + 4 * 1. The decimal equiv-
// alent of binary 1101 is 1 * 1 + 0 * 2 + 1 * 4 + 1 * 8 or 1 + 0 + 4 + 8, or 13. [Note: To learn more
// about binary numbers, refer to Appendix D.]

#include <iostream>
#include <cmath>

using namespace std;

class BinaryToDecimalConverter {
private:
    int binaryNumber;

public:
    // Constructor
    BinaryToDecimalConverter(int num) : binaryNumber(num) {}

    // Function to convert binary to decimal
    int convertToDecimal() {
        int decimalNumber = 0;
        int position = 0;

        // Extract digits from right to left and calculate decimal equivalent
        while (binaryNumber != 0) {
            int digit = binaryNumber % 10;
            decimalNumber += digit * pow(2, position);
            position++;
            binaryNumber /= 10;
        }

        return decimalNumber;
    }
};

int main() {
    int binary;
    cout << "Enter a binary number: ";
    cin >> binary;

    BinaryToDecimalConverter converter(binary);
    int decimal = converter.convertToDecimal();

    cout << "Decimal equivalent: " << decimal << endl;

    return 0;
}
