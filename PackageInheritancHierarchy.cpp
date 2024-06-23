// (Package Inheritance Hierarchy) Package-delivery services, such as FedEx®, DHL® and
// UPS®, offer a number of different shipping options, each with specific costs associated. Create an
// inheritance hierarchy to represent various types of packages. Use Package as the base class of the hi-
// erarchy, then include classes TwoDayPackage and OvernightPackage that derive from Package. Base
// class Package should include data members representing the name, address, city, state and ZIP code
// for both the sender and the recipient of the package, in addition to data members that store the
// weight (in ounces) and cost per ounce to ship the package. Package’s constructor should initialize
// these data members. Ensure that the weight and cost per ounce contain positive values. Package
// should provide a public member function calculateCost that returns a double indicating the cost
// associated with shipping the package. Package’s calculateCost function should determine the cost
// by multiplying the weight by the cost per ounce. Derived class TwoDayPackage should inherit the
// functionality of base class Package, but also include a data member that represents a flat fee that the
// shipping company charges for two-day-delivery service. TwoDayPackage’s constructor should receive
// a value to initialize this data member. TwoDayPackage should redefine member function calculate-
// Cost so that it computes the shipping cost by adding the flat fee to the weight-based cost calculated
// by base class Package’s calculateCost function. Class OvernightPackage should inherit directly
// from class Package and contain an additional data member representing an additional fee per ounce
// charged for overnight-delivery service. OvernightPackage should redefine member function calcu-
// lateCost so that it adds the additional fee per ounce to the standard cost per ounce before calculat-
// ing the shipping cost. Write a test program that creates objects of each type of Package and tests
// member function calculateCost.

#include <iostream>
#include <cmath>
#include<string>

using namespace std;

class Package{
    protected:
string senderName;
string recipentName;
string senderAddress;
string receipentAddress;
string senderCity;
string receipentCity;
string senderState;
string receipentState;
int weight;
int cost;
public:
Package(string sn,string rn,string sa,string ra,string sc,string rc,
string ss,string rs,int w,int c):senderName(sn),recipentName(rn),senderAddress(sa),
receipentAddress(ra),senderCity(sc),receipentCity(rc),senderState(ss),receipentState(rs)
{
    if(w>0){
    weight=w;
}else{cout<<"only positive values"<<endl;
}
if(c>0){
    cost=c;
}else{cout<<"Only positive values"<<endl;
}
}

double calculateCost(){
    return weight*cost;
}

void display(){
    cout<<"the sender is: "<<senderName<<endl;
    cout<<"the receiver is: "<<recipentName<<endl;
    cout<<"senders address is: "<<senderAddress<<endl;
    cout<<"receievers address is: "<<receipentAddress<<endl;
    cout<<"senders city is: "<<senderCity<<endl;
    cout<<"receivers city is: "<<receipentCity<<endl;
    cout<<"senders state is: "<<senderState<<endl;
    cout<<"receivers state is: "<<receipentState<<endl;

}

};

class TwoDayPackage:public Package{
int flatfee;
public:
TwoDayPackage(string sn,string rn,string sa,string ra,string sc,string rc,string ss,string rs,int w,int c,
int ff):Package(sn,rn,sa,ra,sc,rc,ss,rs,w,c),flatfee(ff){}
double calculateCost(){
    return flatfee+(weight*cost);
}
void display(){
    Package::display();
    cout<<"flat fee applied is: "<<flatfee<<endl;
}
};

class OvernightPackage:public Package{
int additionalFee;
public:
OvernightPackage(string sn,string rn,string sa,string ra,string sc,string rc,
string ss,string rs,int w,int c,int af):Package(sn,rn,sa,ra,sc,rc,ss,rs,w,c),
additionalFee(af){}
double calculateCost(){
    return additionalFee+(weight*cost);
}
void display(){
    Package::display();
    cout<<"additional fee applied is: "<<additionalFee<<endl;
}
};

int main(){
TwoDayPackage t1("fatima","haseeb","karachi","hyderabad","khi","Hyd","sindh","sindh",3,400,250);
t1.display();
cout<<"the total cost is: "<<t1.calculateCost()<<endl;

OvernightPackage o1("shahrukh","Gauri","mumbai","delhi","mxb","dilli","mahrashtra","uttar pradeesh",10,400,700);
o1.calculateCost();
o1.display();
cout<<"the total cost is: "<<o1.calculateCost()<<endl;

    return 0;
}
