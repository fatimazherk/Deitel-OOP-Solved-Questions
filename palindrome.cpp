// 4.26 (Palindromes) A palindrome is a number or a text phrase that reads the same backward as for-
// ward. For example, each of the following five-digit integers is a palindrome: 12321, 55555, 45554 and
// 11611. Write a program that reads in a five-digit integer and determines whether it’s a palindrome.
// [Hint: Use the division and modulus operators to separate the number into its individual digits.]

#include <iostream>

using namespace std;

class PalindromeChecker {
private:
    int number;

public:
    // Constructor
    PalindromeChecker(int num) : number(num) {}

    // Function to check if the number is a palindrome
    bool isPalindrome() {
        int temp = number;
        int reverse = 0;

        // Reverse the number
        while (temp > 0) {
            int digit = temp % 10;
            reverse = reverse * 10 + digit;
            temp /= 10;
        }

        // Check if the original number is equal to its reverse
        return (number == reverse);
    }
};

int main() {
    int num;
    cout << "Enter a five-digit integer: ";
    cin >> num;

    if (num >= 10000 && num <= 99999) {
        PalindromeChecker checker(num);
        if (checker.isPalindrome()) {
            cout << num << " is a palindrome." << endl;
        } else {
            cout << num << " is not a palindrome." << endl;
        }
    } else {
        cout << "Invalid input. Please enter a five-digit integer." << endl;
    }

    return 0;
}
