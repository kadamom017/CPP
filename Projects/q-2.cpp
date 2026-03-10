#include <iostream>
#include <cstring>
using namespace std;

class Train {
    private:
        int trainNumber;
        char trainName[70];
        char source[70];
        char departure[70];
        char destination[70];
        char trainTime[50];

        static int trainCount;

    public:
        Train() 
        {
            trainNumber = 0;
            strcpy(trainName, "");
            strcpy(source, "");
            strcpy(departure, "");
            strcpy(destination, "");
            strcpy(trainTime, "");
            trainCount++;

    }

    Train(int num, const char name[], const char src[], const char depart[], const char dest[], const char time[]) 
    {
        trainNumber = num;
        strcpy(trainName, name);
        strcpy(source, src);
        strcpy(departure, depart);
        strcpy(destination, dest);
        strcpy(trainTime, time);
        trainCount++;

    }

    ~Train() 
    {
        trainCount--;
    }

    int getTrainNumber() 
    {
        return trainNumber;
    }

    void inputTrainDetails() 
    {
        cout << "Enter Train Number: ";
        cin >> trainNumber;
        cin.ignore();

        cout << "Enter Train Name: ";
        cin.getline(trainName, 70);

        cout << "Enter Source: ";
        cin.getline(source, 70);

        cout << "Enter Departure: ";
        cin.getline(departure, 70);

        cout << "Enter Destination: ";
        cin.getline(destination, 70);

        cout << "Enter Train Time: ";
        cin.getline(trainTime, 50);

    }

    void displayTrainDetails() 
    {
        cout << "Train Number: " << trainNumber << endl;
        cout << "Train Name: " << trainName << endl;
        cout << "Source: " << source << endl;
        cout << "Departure: " << departure << endl;
        cout << "Destination: " << destination << endl;
        cout << "Train Time: " << trainTime << endl;
        cout << "-------------------------" << endl;

    }

    static int getTrainCount() 
    {
        return trainCount;
    }
};

int Train::trainCount = 0;

class RailwaySystem {
private:
    Train trains[100];
    int totalTrains;

public:
    RailwaySystem() 
    {
        totalTrains = 0;
        trains[totalTrains++] = Train(101, "Vande Bharat Express", "Surat","Rajasthan", "Punjab", "9 PM");
        trains[totalTrains++] = Train(102, "Rajdhani Express", "Chennai","Banglore", "Mumbai", "4 PM");
        trains[totalTrains++] = Train(103, "Vivek Express", "Ahmedabad","madhya Pradesh", "Karnataka", "5 AM");
        trains[totalTrains++] = Train(104, "Tejas Express", "Ranchi","Delhi", "Dharmshala", "10 AM");
    }

    void addTrain() 
    {
        trains[totalTrains].inputTrainDetails();
        totalTrains++;
        cout << "Info Added Successfully!\n";
    }

    void displayAllTrains() 
    {
        for (int i = 0; i < totalTrains; i++) 
        {
            cout << "\nTrain " << i + 1 << " Details:\n";
            trains[i].displayTrainDetails();
        }
    }

    void searchTrainByNumber(int num) 
    {
        for (int i = 0; i < totalTrains; i++) 
        {
            if (trains[i].getTrainNumber() == num) 
            {
                trains[i].displayTrainDetails();
                return;
            }
        }
        cout << "Invalid Info!\n";
    }
};

int main() 
{
    RailwaySystem system;
    int choice, number;

    do 
    {
        cout << "--- Railway Reservation System Info ---" << endl;
        cout << "1. Add Records of New Train" << endl;
        cout << "2. Display All Train Records" << endl;
        cout << "3. Search Train by Number" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            system.addTrain();
            break;

        case 2:
            system.displayAllTrains();
            break;

        case 3:
            cout << "Enter Train Number: ";
            cin >> number;
            system.searchTrainByNumber(number);
            break;

        case 0:
            cout << "Thank You For Visiting..." << endl;
            break;

        default:
            cout << "Incorrect Choice" << endl;
        }

    } 
    while (choice != 0);

    return 0;
}


