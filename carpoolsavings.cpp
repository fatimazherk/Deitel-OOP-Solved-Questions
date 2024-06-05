// (Car-Pool Savings Calculator) Research several car-pooling websites. Create an application
// that calculates your daily driving cost, so that you can estimate how much money could be saved by
// car pooling, which also has other advantages such as reducing carbon emissions and reducing traffic
// congestion. The application should input the following information and display the user’s cost per
// day of driving to work:

// a) Total miles driven per day. b) Cost per gallon of gasoline.
// c) Average miles per gallon. d) Parking fees per day.
// e) Tolls per day.

#include <iostream>
#include <string>
using namespace std;

class CarPoolSavingsCalculator {
    int milesDriven;
    int costPerGallon;
    int averageMilesPerGallon;
    int parkingFeesPerDay;
    int tollsPerDay;
    int dailyDrivingCost;

public:
    CarPoolSavingsCalculator() {}
    CarPoolSavingsCalculator(int m, int c, int mpg, int p, int t) : milesDriven(m), costPerGallon(c), averageMilesPerGallon(mpg), parkingFeesPerDay(p), tollsPerDay(t) {}

    void calculateDailyDrivingCost() {
        float gasolineCost = (milesDriven / averageMilesPerGallon) * costPerGallon;
        dailyDrivingCost = gasolineCost + parkingFeesPerDay + tollsPerDay;
    }

    void displayDailyDrivingCost() {
        cout << "Your daily driving cost is: $" << dailyDrivingCost << endl;
    }
};

int main() {
    CarPoolSavingsCalculator c1(500, 50, 20, 200, 3); // Removed the extra argument
    c1.calculateDailyDrivingCost();
    c1.displayDailyDrivingCost(); // Corrected the function call
    return 0;
}
