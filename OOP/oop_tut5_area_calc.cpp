#include <iostream>
using namespace std;

class Shape{
public:
virtual void display_area() = 0;
};

class Triangle : public Shape{
public:
float x, y;
Triangle(float a, float b) : x(a), y(b){}

void display_area(){
cout << "Area of the Triangle is: " << 0.5*x*y << endl;
}
};

class Rectangle : public Shape{
public:
float x, y;
Rectangle(float a, float b) : x(a), y(b) {}

void display_area(){
cout << "Area of the Rectangle is: " << x*y << endl;
}
};

int main(){
float x, y;
cout << "Enter Triangle's Height: "; cin >> x;
cout<< "Enter Triangle's Base: "; cin >> y;

Triangle T(x, y);
T.display_area();

cout << "\n------------------\n" << endl;

cout << "Enter Rectangle's Height: "; cin >> x;
cout<< "Enter Rectangle's Breadth: "; cin >> y;

Rectangle R(x, y);
R.display_area();

return 0;
}
