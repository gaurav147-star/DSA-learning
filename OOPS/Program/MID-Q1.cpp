#include <iostream>
using namespace std;

class ABC;
class XYZ
{
    int value1;
    int value2;

public:
    XYZ(int a = 0, int b = 0)
    {
        value1 = a;
        value2 = b;
    }

    void setData(int a, int b)
    {
        value1 = a;
        value2 = b;
    }
    void getData()
    {
        cout << value1 << endl;
        cout << value2 << endl;
    }
    friend int add(XYZ, ABC);
};
class ABC
{
    int value1;
    int value2;

public:
    ABC(int a = 0, int b = 0)
    {
        value1 = a;
        value2 = b;
    }
    void setData(int a, int b)
    {
        value1 = a;
        value2 = b;
    }
    void getData()
    {
        cout << value1 << endl;
        cout << value2 << endl;
    }
    friend int add(XYZ, ABC);
};

int add(XYZ obj1, ABC obj2)
{
    int x = obj1.value1 + obj1.value2;
    int y = obj2.value1 + obj2.value2;
    if (x == y)
    {
        return 0;
    }
    else
    {
        return x - y;
    }
}
int main()
{
    XYZ X(10, 5);
    ABC A(12, 3);
    cout << add(X, A);
}
