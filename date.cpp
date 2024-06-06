// 3.15 (Date Class) Create a class called Date that includes three pieces of information as data
// members—a month (type int), a day (type int) and a year (type int). Your class should have a con-
// structor with three parameters that uses the parameters to initialize the three data members. For the
// purpose of this exercise, assume that the values provided for the year and day are correct, but ensure
// that the month value is in the range 1–12; if it isn’t, set the month to 1. Provide a set and a get func-
// tion for each data member. Provide a member function displayDate that displays the month, day
// and year separated by forward slashes (/). Write a test program that demonstrates class Date’s capa-
// bilities.
#include<iostream>
#include<string>
using namespace std;

class Date{
int month;
int day;
int year;
public:
Date(){}
Date(int m,int d,int y):month(m),day(d),year(y){
    if(m>12){
        month=1;
    }else{
        month=m;
    }
}
void setMonth(int m){
if(m<12){
    month=1;
}else{
    month=m;
}
}
int getMonth(){
    return month;
}
void setDay(int d){
    day=d;
}
int getDay(){
    return day;
}
void setYear(int y){
    year=y;
}
int getYear(){
    return year;
}
void display(){
    cout<<"The Date Today Is: "<<day<<"/"<<month<<"/"<<year<<endl;
}
};

int main(){
    //first date using constructor
    Date d1(5,21,2004);
    d1.display();

    //second date using getters and setters
    Date d2;
    d2.setMonth(3);
    d2.getMonth();
    d2.setDay(23);
    d2.getDay();
    d2.setYear(2002);
    d2.getYear();
    d2.display();
}