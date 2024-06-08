#include <iostream>
#include <string>
#include <cmath> 
using namespace std;

// 3.17 (Computerization of Health Records) A health care issue that has been in the news lately is
// the computerization of health records. This possibility is being approached cautiously because of
// sensitive privacy and security concerns, among others. [We address such concerns in later exercises.]
// Computerizing health records could make it easier for patients to share their health profiles and his-
// tories among their various health care professionals. This could improve the quality of health care,
// help avoid drug conflicts and erroneous drug prescriptions, reduce costs and in emergencies, could
// save lives. In this exercise, you’ll design a “starter” HealthProfile class for a person. The class attri-
// butes should include the person’s first name, last name, gender, date of birth (consisting of separate
// attributes for the month, day and year of birth), height (in inches) and weight (in pounds). Your class
// should have a constructor that receives this data. For each attribute, provide set and get functions.
// The class also should include functions that calculate and return the user’s age in years, maximum
// heart rate and target-heart-rate range (see Exercise 3.16), and body mass index (BMI; see
// Exercise 2.30). Write an application that prompts for the person’s information, instantiates an ob-
// ject of class HealthProfile for that person and prints the information from that object—including
// the person’s first name, last name, gender, date of birth, height and weight—then calculates and
// prints the person’s age in years, BMI, maximum heart rate and target-heart-rate range. It should also
// display the “BMI values” chart from Exercise 2.30. Use the same technique as Exercise 3.16 to cal-
// culate the person’s age.

class HealthProfile {
public:
    HealthProfile(string first_name,string last_name,string gender,int birth_month, int birth_day, int birth_year, double height, double weight):
    firstName(first_name), lastName(last_name), gender(gender),
    birthMonth(birth_month), birthDay(birth_day), birthYear(birth_year),
    height(height), weight(weight) {}

    // Setter and Getter for firstName
    void setFirstName(string first_name) {
    firstName = first_name; 
    }
    string getFirstName(){ 
    return firstName;
    }

    // Setter and Getter for lastName
    void setLastName(string last_name) {
    lastName = last_name; 
    }
    string getLastName(){
    return lastName;
    }

    // Setter and Getter for gender
    void setGender(string gender){
    this->gender = gender;
    }
    string getGender(){ 
    return gender; 
    }

    // Setter and Getter for birthMonth
    void setBirthMonth(int birth_month){
    birthMonth = birth_month; 
    }
    int getBirthMonth(){
    return birthMonth; 
    }

    // Setter and Getter for birthDay
    void setBirthDay(int birth_day) { birthDay = birth_day; }
    int getBirthDay(){ return birthDay; }

    // Setter and Getter for birthYear
    void setBirthYear(int birth_year) { birthYear = birth_year; }
    int getBirthYear(){ return birthYear; }

    // Setter and Getter for height
    void setHeight(double height) { this->height = height; }
    double getHeight(){ return height; }

    // Setter and Getter for weight
    void setWeight(double weight) { this->weight = weight; }
    double getWeight(){ return weight; }

    // Calculate age
    int getAge(int current_day, int current_month, int current_year){
        int age = current_year - birthYear;
        if (current_month < birthMonth || (current_month == birthMonth && current_day < birthDay)) {
            age -= 1;
        }
        return age;
    }

    // Calculate maximum heart rate
    int getMaximumHeartRate(int current_day, int current_month, int current_year){
        int age = getAge(current_day, current_month, current_year);
        return 220 - age;
    }

    // Calculate target heart rate range
    void getTargetHeartRate(int current_day, int current_month, int current_year, int lower_bound, int upper_bound){
        int maxHR = getMaximumHeartRate(current_day, current_month, current_year);
        lower_bound = (int)(0.5 * maxHR);
        upper_bound = (int)(0.85 * maxHR);
    }

    // Calculate BMI
    double getBMI() const {
        return (weight * 703) / (height * height);
    }

private:
    std::string firstName;
    std::string lastName;
    std::string gender;
    int birthMonth;
    int birthDay;
    int birthYear;
    double height;
    double weight;
};

// Function to display BMI values chart
void displayBMIValuesChart() {
    std::cout << "\nBMI VALUES\n";
    std::cout << "Underweight: less than 18.5\n";
    std::cout << "Normal:      between 18.5 and 24.9\n";
    std::cout << "Overweight:  between 25 and 29.9\n";
    std::cout << "Obese:       30 or greater\n";
}

// Main function
int main() {
    // Prompt user for personal information
    std::string firstName, lastName, gender;
    int birthDay, birthMonth, birthYear;
    double height, weight;
    int currentDay, currentMonth, currentYear;

    std::cout << "Enter first name: ";
    std::cin >> firstName;
    std::cout << "Enter last name: ";
    std::cin >> lastName;
    std::cout << "Enter gender: ";
    std::cin >> gender;
    std::cout << "Enter birth day (DD): ";
    std::cin >> birthDay;
    std::cout << "Enter birth month (MM): ";
    std::cin >> birthMonth;
    std::cout << "Enter birth year (YYYY): ";
    std::cin >> birthYear;
    std::cout << "Enter height (in inches): ";
    std::cin >> height;
    std::cout << "Enter weight (in pounds): ";
    std::cin >> weight;

    // Create HealthProfile object
    HealthProfile person(firstName, lastName, gender, birthMonth, birthDay, birthYear, height, weight);

    // Prompt user for current date
    std::cout << "Enter current day (DD): ";
    std::cin >> currentDay;
    std::cout << "Enter current month (MM): ";
    std::cin >> currentMonth;
    std::cout << "Enter current year (YYYY): ";
    std::cin >> currentYear;

    // Calculate age, maximum heart rate, and target heart rate
    int age = person.getAge(currentDay, currentMonth, currentYear);
    int maxHR = person.getMaximumHeartRate(currentDay, currentMonth, currentYear);
    int lowerBound, upperBound;
    person.getTargetHeartRate(currentDay, currentMonth, currentYear, lowerBound, upperBound);
    double bmi = person.getBMI();

    // Print the information
    std::cout << "\nPerson's Information:\n";
    std::cout << "First Name: " << person.getFirstName() << "\n";
    std::cout << "Last Name: " << person.getLastName() << "\n";
    std::cout << "Gender: " << person.getGender() << "\n";
    std::cout << "Date of Birth: " << person.getBirthMonth() << "/" << person.getBirthDay() << "/" << person.getBirthYear() << "\n";
    std::cout << "Height: " << person.getHeight() << " inches\n";
    std::cout << "Weight: " << person.getWeight() << " pounds\n";
    std::cout << "Age: " << age << " years\n";
    std::cout << "BMI: " << bmi << "\n";
    std::cout << "Maximum Heart Rate: " << maxHR << " bpm\n";
    std::cout << "Target Heart Rate Range: " << lowerBound << " - " << upperBound << " bpm\n";

    // Display BMI values chart
    displayBMIValuesChart();

    return 0;
}
