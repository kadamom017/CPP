#include<iostream>
#include<cstring>
using namespace std;

class bankAccount {
    private:
        int accountNumber;
        float balance;
        char ownerName[50];

    public:    
        void setData() 
        { 
            cout<<"Enter Account Number: ";
            cin>>accountNumber;
            cout<<"Enter balance ";
            cin>>balance;
            cout<<"Enter Owner Name: ";
            cin>>ownerName;
        }

        void credit(float amount)
        {
            balance += amount;
        }

        void debit(float amount)
        {
            balance -= amount;
        }

        void display() 
        {
            cout<<"Enter Account Number: "<<accountNumber<<endl;
            cout<<"Enter balance "<<balance<<endl;;
            cout<<"Enter Owner Name: "<<ownerName<<endl;;
        }
};

    int main() {
        bankAccount b;

        b.setData();
        b.credit(500);
        b.debit(200);

        b.display();

        return 0;
    }



    



    