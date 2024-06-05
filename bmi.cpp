// 2.30 (Body Mass Index Calculator) We introduced the body mass index (BMI) calculator in
// Exercise 1.12. The formulas for calculating BMI are

// weightinkg/heightinmetre*heightinmetre

// Create a BMI calculator application that reads the user’s weight in pounds and height in inches
// (or, if you prefer, the user’s weight in kilograms and height in meters), then calculates and displays
// the user’s body mass index. Also, the application should display the following information from

// the Department of Health and Human Services/National Institutes of Health so the user can eval-
// uate his/her BMI:
// BMI VALUES
// Underweight: less than 18.5
// Normal: between 18.5 and 24.9
// Overweight: between 25 and 29.9
// Obese: 30 or greater

#include<iostream>
#include<cmath>
using namespace std;
class BodyMassCalculator{
    int weight;
    float height;
    float bmi;
    public:
    BodyMassCalculator(){}
    BodyMassCalculator(int w, float h):weight(w),height(h){}
    void calculateBMI(){
        bmi=weight/pow(height,2);
    }
   void checkBMI() {
    if (bmi < 18.5) {
    cout << "underweight";
    } else if (bmi >= 18.5 && bmi <= 24.9) {
    cout << "normal weight";
    } else if (bmi >= 25 && bmi <= 29.9) {
    cout << "overweight";
    } else {
    cout << "obese";
    }
    }
};

int main(){
BodyMassCalculator b1(56,1.56);
b1.calculateBMI();
b1.checkBMI();
return 0;
}