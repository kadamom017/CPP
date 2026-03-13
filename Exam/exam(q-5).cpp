 #include<iostream>
using namespace std;

class Shape {
public:
    virtual void calculateArea()=0;
    virtual void draw()=0;
};

class Circle : public Shape {
    float r;
public:
    Circle(float radius) {
        r=radius;
    }

    void calculateArea() {
        cout<<"Circle Area: "<<3.14*r*r<<endl;
    }

    void draw() {
        cout<<"Drawing Circle\n";
    }
};

class Rectangle : public Shape {
    float l,b;
public:
    Rectangle(float x,float y) {
        l=x;
        b=y;
    }

    void calculateArea() {
        cout<<"Rectangle Area: "<<l*b<<endl;
    }

    void draw() {
        cout<<"Drawing Rectangle\n";
    }
};

int main() {
    Shape* s[2];

    Circle c(5);
    Rectangle r(4,6);

    s[0]=&c;
    s[1]=&r;

    for(int i=0;i<2;i++) {
        s[i]->calculateArea();
        s[i]->draw();
    }

    return 0;
}