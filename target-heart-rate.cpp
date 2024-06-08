#include<iostream>
#include<string>
using namespace std;

// 3.16 (Target-Heart-Rate Calculator) While exercising, you can use a heart-rate monitor to see
// that your heart rate stays within a safe range suggested by your trainers and doctors. According to the
// American Heart Association (AHA) (www.americanheart.org/presenter.jhtml?identifier=4736),
// the formula for calculating your maximum heart rate in beats per minute is 220 minus your age in
// years. Your target heart rate is a range that is 50–85% of your maximum heart rate. [Note: These for-
// mulas are estimates provided by the AHA. Maximum and target heart rates may vary based on the health,
// fitness and gender of the individual. Always consult a physician or qualified health care professional before
// beginning or modifying an exercise program.] Create a class called HeartRates. The class attributes
// should include the person’s first name, last name and date of birth (consisting of separate attributes
// for the month, day and year of birth). Your class should have a constructor that receives this data as
// parameters. For each attribute provide set and get functions. The class also should include a function
// getAge that calculates and returns the person’s age (in years), a function getMaxiumumHeartRate that
// calculates and returns the person’s maximum heart rate and a function getTargetHeartRate that cal-
// culates and returns the person’s target heart rate. Since you do not yet know how to obtain the current
// date from the computer, function getAge should prompt the user to enter the current month, day
// and year before calculating the person’s age. Write an application that prompts for the person’s in-
// formation, instantiates an object of class HeartRates and prints the information from that object—
// including the person’s first name, last name and date of birth—then calculates and prints the person’s
// age in (years), maximum heart rate and target-heart-rate range.

class HeartRates{
    int heartRate;
    int targetHeartRate;
    string firstName;
    string lastName;
    int day;
    int month;
    int year;
    int age;
    public:
    HeartRates(){}
    HeartRates(string fn, string ln, int d, int m,int y):firstName(fn),lastName(ln),day(d),month(m),year(y){
    }
    void setFirstName(string fn){
        firstName=fn;
    }
    string getFirstName(){
        return firstName;
    }
    void setLastName(string ln){
        lastName=ln;
    }
    string getLastName(){
        return lastName;
    }
    void setDay(int d){
        day=d;
    }
    int getDay(){
        return day;
    }
    void setMonth(int m){
        month=m;
    }
    int getMonth(){
        return month;
    }
    void setYear(int y){
        year=y;
    }
    int getYear(){
        return year;
    }
  int getAge(int current_day, int current_month, int current_year) const {
        int age = current_year - year;
        if (current_month < month || (current_month == month && current_day < day)) {
            age = age-1;
        }
        return age;
       
    }

    void getMaximumHeartRate(){
        heartRate=year-220;
         cout<<"your maximum heart rate is: "<<heartRate<<endl;
    }
    void getTargetHeartRate(){
        targetHeartRate=0.5*heartRate;
        targetHeartRate=0.8*heartRate;
         cout<<"your target heart rate is: " <<targetHeartRate<<endl;
    }


};

int main(){
    HeartRates h1("fatima","khan",21,5,2004);
    h1.getAge(8,6,2024);
     cout<<"Your age is: "<<h1.getAge(8,6,2024);
    h1.getMaximumHeartRate();
    h1.getTargetHeartRate();
    return 0;
}