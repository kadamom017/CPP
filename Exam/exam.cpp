#include<iostream>
#include<cstring>
using namespace std;

class Movie {
    public:
    char title[50];
    char genre[50];
    int releasedYear;

    void getdata()
    {
        cout<<"Enter Title: ";
        cin>>title;
        cout<<"Enter Genre: ";
        cin>>genre;
        cout<<"Enter year: ";
        cin>>releasedYear;

    }

    void display()
        {
            cout<<"Title : "<<title<<endl;
            cout<<"Genre : "<<genre<<endl;
            cout<<"Year : "<<releasedYear<<endl;
        }    
};

int main () {

Movie m[2];
    
        for (int i = 0; i < 2; i++)
        {
            cout<<"Enter Movie "<<i+1<<"details\n";
                m[i].getdata();
        }
        
        cout<<"\nMovie Details\n";
        for(int i = 0; i < 2; i++)
        {
              m[i].getdata();
        }
             
        return 0;
};

