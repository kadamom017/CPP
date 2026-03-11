#include<iostream>
#include<cstring>
using namespace std;

class Vehicle {
    private:
        char model[50];
        int speed;
    public:
        void setData(char m, int s)
        {
            strcpy(model, m0;
            speed = s;
        }

        int getSpeed()
        {
            return speed;
        }

        void showModel()
        {
            cout<<"Model: "<<model<<endl;
        }

};

class Car: public Vehicle {
    public:
        void time(int distance)
        {
            cout<<"Car Time: "<<distance/getSpeed()<<"hours"<<endl; 
        }
};

class Bike : public Vehicle {
    public:
        void time(int distance)
        {
            cout<<"Bike Time: "<<distance/getSpeed()<<"hours"<<endl; 
        }
};

int main() {
    Car c;
    Bike b;

    c.setData("BMW", 150);
    b.setData("Kawasaki",100);

    c.showModel();
    c.time(200);

    b.showModel();
    b.time(200);

    return 0;

}







