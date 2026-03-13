#include <iostream>
using namespace std;

const int MAX_ITEMS = 10;

class LibraryItem {
private:
    string title;
    string author;
    string dueDate;

public :
    string getTitle()
    {
        return title;
    }

    string getAuthor()
    {
        return author;
    }

    string getDueDate()
    {
        return dueDate;
    }

    void setTitle( string newTitle )
    {
        title = newTitle;
    }

    void setAuthor( string newAuthor )
    {
        author = newAuthor;
    }

    void setDueData(string newDueDate)
    {
        dueDate = newDueDate;
    }
    
        virtual void checkOut() = 0;
        virtual void returnItem() = 0;
        virtual void displayDetails() = 0;

        virtual  ~LibraryItem() {}

};

class Book : public LibraryItem {
private:
    int pages;

public:
    void setPages(int p)
    {
        pages = p;
    }    

     void checkOut()
    {
       cout<< "Book has been checked out Successfully\n ";
    }    

     void returnItem()
    {
       cout<< "Book has been returned Successfully\n ";
    }    
    
    void displayDetails()
    {
        cout <<"\nDetails Of Books\n";
        cout <<"Title : " <<getTitle()<<endl;
        cout <<"Author : " <<getAuthor()<<endl;
        cout <<"DueDate : " <<getDueDate()<<endl;
        cout <<"Pages: " << pages <<endl;
    }
    
};   

class DVD : public LibraryItem
{
    private:
        int duration; 

   public:
    void setDuration(int d)
    {
        duration = d;
    }    

     void checkOut()
    {
       cout<< "DVD has been checked out Successfully\n ";
    }    

     void returnItem()
    {
       cout<< "DVD has been returned Successfully\n ";
    }    
    
    void displayDetails()
    {
        cout <<"\nDetails Of DVD\n";
        cout <<"Title : " <<getTitle()<<endl;
        cout <<"Author : " <<getAuthor()<<endl;
        cout <<"Due Date : " <<getDueDate()<<endl;
        cout <<"Duration: " << duration <<"minutes\n";
    }
};
    

class Magazine : public LibraryItem
{
    private:
        int issueNumber; 

   public:
     void setIssueNumber(int i)
    {
        issueNumber = i;
    }    

     void checkOut()
    {
       cout<< "Magazine has been checked out Successfully\n ";
    }    

     void returnItem()
    {
       cout<< "Magazine has been returned Successfully\n ";
    }    
    
    void displayDetails()
    {
        cout <<"\nDetails Of Magazine\n";
        cout <<"Title : " <<getTitle()<<endl;
        cout <<"Author : " <<getAuthor()<<endl;
        cout <<"DueDate : " <<getDueDate()<<endl;
        cout <<"Issue Number: " <<issueNumber<<endl;
    }
};

int main() {

    LibraryItem* libraryItems[MAX_ITEMS];
    int count = 0;
    int choice; 

    while (true)
    {
        cout << "--- Library Management System Info ---" << endl;
        cout << "1. Add Book\n";
        cout << "2. Add DVD\n";
        cout << "3. Add Magazine\n";
        cout << "4. Display Items\n";
        cout << "5. Check Out Item\n";
        cout << "6. Return Item\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try
        {
             if(choice == 1)
            {
               if(count >= MAX_ITEMS)
               throw "Library is full"; 

               Book* b = new Book();
                string title,author,dueDate;
                int pages;

                cout << "Enter title: "; 
                cin >> title;
                cout << "Enter author : "; 
                cin >> author;
                cout << "Enter dueDate: "; 
                cin >> dueDate;
                cout << "Enter pages : " ;
                cin >> pages;

                if (pages < 0)
                throw "Invalid page number";

                b->setTitle(title);
                b->setAuthor(author);
                b->setDueDate(dueDate);
                b->setPages(pages);

                libraryItems[count++] = b;
            }

            else if(choice == 2)
            {
               if(count >= MAX_ITEMS)
               throw "Library is full";

                DVD* d = new DVD();
                string title,author,dueDate;
                int duration;

                cout << "Enter title: "; 
                cin >> title;
                cout << "Enter author : "; 
                cin >> author;
                cout << "Enter dueDate: "; 
                cin >> dueDate;
                cout << "Enter duration : " ;
                cin >> duration;

                if (duration < 0)
                throw "Invalid duration";

                d->setTitle(title);
                d->setAuthor(author);
                d->setDueDate(dueDate);
                d->setDuration(duration);

                libraryItems[count++] = d;
            }
        
            else if(choice == 3)
            {
               if(count >= MAX_ITEMS)
               throw "Library is full";

                Magazine* m = new Magazine();
                string title,author,dueDate;
                int issue;

                cout << "Enter title: "; 
                cin >> title;
                cout << "Enter author : "; 
                cin >> author;
                cout << "Enter dueDate: "; 
                cin >> dueDate;
                cout << "Enter issue number : " ;
                cin >> issue;

                if (issue < 0)
                throw "Invalid issue number";

                m->setTitle(title);
                m->setAuthor(author);
                m->setDueDate(dueDate);
                m->setIssueNumber(issue);

                libraryItems[count++] = m;
            }

            else if(choice == 4)
            {
                for (int i = 0; i < count; i++)
                {
                    libraryItems[i]-> displayDetails();
                }
            }

             else if(choice == 5)
            {
                int id;
                cout<<"Enter item index:";
                cin>>id;

                if(id < 0 || id>= count)
                 throw "Invalid item index";
                
                libraryItems[id]-> checkOut();
            }

            
             else if(choice == 6)
            {
                int id;
                cout<<"Enter item index:";
                cin>>id;

                if(id < 0 || id>= count)
                 throw "Invalid item index";
                
                libraryItems[id]-> returnItem();
            }

            
             else if(choice == 0)
            {
                break;
            }

        }
    }
        catch(const char* msg)
        {
            cout<<"Error:"<<msg<<endl;
        }

        for (int i = 0; i < count; i++)
        {
            delete libraryItems[i];
        }

        return 0;
}
    