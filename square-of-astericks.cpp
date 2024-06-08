#include <iostream>
using namespace std;

// (Square of Asterisks) Write a program that reads in the size of the side of a square then prints
// a hollow square of that size out of asterisks and blanks. Your program should work for squares of all
// side sizes between 1 and 20.

class SquareOfAsterisks {
public:
    void printHollowSquare(int size) {
        if(size <= 20 && size >= 1) {
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    // Print '*' on the borders
                    if (i == 0 || i == size - 1 || j == 0 || j == size - 1) {
                        cout << "*";
                    } else {
                        // Print spaces inside the square
                        cout << " ";
                    }
                }
                cout << endl;
            }
        } else {
            cout << "Size should be between 1 and 20." << endl;
        }
    }
};

int main() {
    SquareOfAsterisks s1;
    int size;
    cout << "Enter the size of the square (between 1 and 20): ";
    cin >> size;
    s1.printHollowSquare(size);

    return 0;
}
