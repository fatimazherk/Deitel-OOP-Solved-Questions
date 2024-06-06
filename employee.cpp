// 3.14 (Employee Class) Create a class called Employee that includes three pieces of information as
// data members—a first name (type string), a last name (type string) and a monthly salary (type
// int). [Note: In subsequent chapters, we’ll use numbers that contain decimal points.
// Your class should have a constructor that
// initializes the three data members. Provide a set and a get function for each data member. If the
// monthly salary is not positive, set it to 0. Write a test program that demonstrates class Employee’s
// capabilities. Create two Employee objects and display each object’s yearly salary. Then give each Em-
// ployee a 10 percent raise and display each Employee’s yearly salary again.

#include<iostream>
#include<string>
using namespace std;

class Employee{
    string firstName;
    string lastName;
    int monthlySalary;
    public:
    Employee(){}
    Employee(string fn,string ln,int ms):firstName(fn),lastName(ln),monthlySalary(ms){
        if (monthlySalary<0){
            monthlySalary=0;
        }else{
            monthlySalary=monthlySalary;
        }
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
    void setMonthlySalary(int ms){
     if (ms > 0) {
    monthlySalary = ms;
    } else {
    monthlySalary = 0;
    }
    }
    int getMonthlySalary(){
        return monthlySalary;
    }
    void raise(){
        monthlySalary=monthlySalary+(monthlySalary*0.10);
        }
    void displayEmp(){
        cout<<"Employee's name is: "<<firstName<<" "<<lastName<<endl;
    }
    void displaySalary(){
        cout<<"Employee's salary is: "<<monthlySalary<<endl;
    }

};

int main(){
//first employee made through constructor
Employee e1("Fatimaa","Khan",25000);
e1.displayEmp();
e1.displaySalary();
//after raise
e1.raise();
e1.displaySalary();

//second employee through setters and getters
Employee e2;
e2.setFirstName("Shahrukh");
e2.getFirstName();
e2.setLastName("Khan");
e2.getLastName();
e2.setMonthlySalary(2000);
e2.getMonthlySalary();
e2.displayEmp();
e2.displaySalary();
e2.raise();
e2.displaySalary();

}