#include <iostream>
#include <cstring>
using namespace std;

class Vehicle{
private :
    int vehicleID;
    char manufacturer[50];
    char model[50];
    int year;
    
    static int totalVehicles;

public :
    Vehicle() 
    {
        vehicleID = 0;
        strcpy(manufacturer, "");
        strcpy(model, "");
        year = 0;
        totalVehicles++;
    }

    Vehicle(int id, const char manu[], const char mod[], int y)
    {
        vehicleID = id;
        strcpy(manufacturer, manu);
        strcpy(model, mod);
        year = y;
        totalVehicles++;
    }

    void setVehicle(int id, const char manu[], const char mod[], int y)
    {
        vehicleID = id;
        strcpy(manufacturer, manu);
        strcpy(model, mod);
        year = y;
    }

    int getVehicleID()
    {
        return vehicleID;
    }

    void displayVehicle()
    {
        cout <<"Vehicle ID : " <<vehicleID<<endl;
        cout <<"Manufacturer : " <<manufacturer<<endl;
        cout <<"Model : " <<model<<endl;
        cout <<"Year : " <<year<<endl;
    }

    ~Vehicle(){
    }
};

    int Vehicle ::totalVehicles = 0;


class Car : public Vehicle
{
    public:

    Car(){
    }

    Car(int id, const char manu[], const char mod[], int y)
        : Vehicle(id,manu,mod,y){
        }

    void setCar(int id, const char manu[], const char mod[], int y)
    {
        setVehicle(id,manu,mod,y);
    }    
    
    void displayCar()
    {
        displayVehicle();
    }

    ~Car(){
    }    
}; 

class ElectricCar : public Car
{
    public:

    ElectricCar(){
    }

    ElectricCar(int id, const char manu[], const char mod[], int y)
        : Car(id,manu,mod,y){
        }

    void setElectricCar(int id, const char manu[], const char mod[], int y)
    {
        setCar(id,manu,mod,y);
    }    
    
    void displayElectricCar()
    {
        displayCar();
    }

    ~ElectricCar(){
    }
};    

class SportsCar : public ElectricCar
{
    public:

    SportsCar(){
    }

    SportsCar(int id, const char manu[], const char mod[], int y)
        : ElectricCar(id,manu,mod,y){
        }

    void setSportsCar(int id, const char manu[], const char mod[], int y)
    {
        setElectricCar(id,manu,mod,y);
    }    
    
    void displaySportsCar()
    {
        displayElectricCar();
    }

    ~SportsCar(){
    }
};    

class AirCraft 
{
    public:

    AirCraft(){
    }
};

class FlyingCar : public Car, public AirCraft
{
    public:

    FlyingCar(){
    }

    void setFlyingCar(int id, const char manu[], const char mod[], int y)
    {
        setCar(id,manu,mod,y);
    }    
    
    void displayFlyingCar()
    {
        displayCar();
    }

    ~FlyingCar(){
    }
};   

class Sedan : public Car
{
    public:

    Sedan(){
    }

    void displaySedan(){
        displayCar();
    }

    ~Sedan(){
    }
};

class SUV : public Car
{
    public:

    SUV(){
    }

    void displaySUV(){
        displayCar();
    }

    ~SUV(){
    }
};

class VehicleRegistry{
    
    private:
        Vehicle vehicles[50];
        int count;

    public:
        VehicleRegistry()
        {
            count = 0;
        }    

        void addVehicle()
        {
            int id,y;
            char manu[50];
            char mod[50];

        cout << "Vehicle ID : "; 
        cin >> id;
        cout << "Manufacturer : "; 
        cin >> manu;
        cout << "Model : "; 
        cin >> mod;
        cout << "Year : " ;
        cin >> y;

        vehicles[count].setVehicle(id,manu,mod,y);
        count++;

        cout << "Vehicle Added Succesfully!\n";

        }

        void displayVehicle()
        {
            if(count == 0)
            {
                cout<<"No Vehciles were found\n";
                return;
            }
        
            for(int i=0; i < count; i++)
            {
                cout<<"\nVehicle "<<i+1<<endl;
                vehicles[i].displayVehicle();
            }
        }    

        void searchVehicle()
        {
            int id;
            {
                cout<<"Enter the Vehicle Id : ";
                cin>>id;
            }
        
            for(int i=0; i < count; i++)
            {
                if (vehicles[i].getVehicleID()==id)
                {        
                    cout<<"\nVehicle Found\n";
                    vehicles[i].displayVehicle();
                    return;
                }
            }    

            cout<<"No Vehicle Found\n";
        }    
};

int main()
{
    VehicleRegistry registry;
    int choice;

    do{
        cout << "--- Vehicle Registry System Info ---" << endl;
        cout << "1. Add Vehicle" << endl;
        cout << "2. View All Vehicle" << endl;
        cout << "3. Search Vehicle by ID" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        
        switch (choice) 
        {
        case 1:
            registry.addVehicle();
            break;

        case 2:
            registry.displayVehicle();
            break;

        case 3:
            registry.searchVehicle();
            break;

        case 0:
            cout << "Exit" << endl;
            break;

        default:
            cout << "Incorrect Choice" << endl;
        }

    } 
    while (choice != 0);

    return 0;

}



    






