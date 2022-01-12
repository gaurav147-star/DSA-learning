#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
class Shape
{
public:
    double height, base;

    Shape()
    {
        height = 0;
        base = 0;
    }

    void get_data()
    {
        cin >> height >> base;
    }

    void get_data_circle()
    {
        cin >> height;
        base = height;
    }

    virtual void display_area()
    {
    }
};

class Triangle : public Shape
{
public:
    void display_area()
    {
        cout << "\nArea of Triangle = " << (height * base) / 2 << endl;
    }
};

class Rectangle : public Shape
{
public:
    void display_area()
    {
        cout << "\nArea of Rectangle = " << height * base << endl;
    }
};
class Circle : public Shape
{
public:
    void display_area()
    {
        cout << "\nArea of Circle = " << 3.14 * height * height << endl;
    }
};
int main()
{
    Shape *s;
    Triangle t;
    cout << "Enter height and base for triangle" << endl;
    t.get_data();
    s = &t;
    s->display_area();
    Rectangle r;
    cout << "Enter height and base for rectangle" << endl;
    r.get_data();
    s = &r;
    s->display_area();
    Circle c;
    cout << "Enter radius for circle" << endl;
    c.get_data_circle();
    s = &c;
    s->display_area();

    cout << "\n( Gaurav Gupta )\n( Scholar No: 20U03030 )" << endl;
}
