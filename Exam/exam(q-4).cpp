#include <iostream>
using namespace std;

class Vehicle {
public:
    virtual void displayDetails() {
        cout<<"Vehicle Details\n";
    }
};

class Car : public Vehicle {
public:
    void displayDetails() {
        cout<<"This is a Car\n";
    }
};

class Bike : public Vehicle {
public:
    void displayDetails() {
        cout<<"This is a Bike\n";
    }
};

int main() {
    Vehicle* v[2];

    Car c;
    Bike b;

    v[0]=&c;
    v[1]=&b;

    for(int i=0;i<2;i++) {
        v[i]->displayDetails();
    }

    return 0;
}