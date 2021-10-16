#include <iostream>
using namespace std;
template <typename T>

class Pair
{
    T x;
    T y;

public:
    void setX(T x)
    {
        this->x = x;
    }

    T getX()
    {
        return x;
    }
    void setY(T y)
    {
        this->y = y;
    }
    T getY()
    {
        return y;
    }
};

int main()
{
    Pair<int> p1;
    p1.setX(10);
    p1.setY(20);

    cout << p1.getX() << " " << p1.getY() << endl;

    Pair<double> p2;
    p2.setX(0.52);
    p2.setY(1.52);

    cout << p2.getX() << " " << p2.getY() << endl;
}
