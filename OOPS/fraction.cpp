#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }
    void print()
    {
        cout << this->numerator << " / " << denominator << endl;
    }

    void simplify()
    {
        int gcd = 1;
        int j = min(this->numerator, this->denominator);
        for (int i = 0; i <= j; i++)
        {
            if (this->numerator == 0 && this->denominator == 0)
            {
                gcd = i;
            }
        }
        this->numerator = this->numerator / gcd;
        this->denominator = this->denominator / gcd;
    }
    void add(Fraction const &f2)
    {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;
        int num = x * f2.numerator + (y * numerator);
        numerator = num;
        denominator = lcm;
        simplify();
    }
    void multiply(Fraction const &f2)
    {
        numerator = numerator * f2.numerator;
        denominator = denominator * f2.denominator;
        simplify();
    }
};

int main()
{
    int x, y, a, b;
    cout << "Enter fraction number in (x,y)" << endl;
    cin >> x >> y;
    Fraction f1(x, y);

    cout << "Enter fraction number in (x,y)" << endl;
    cin >> a >> b;
    Fraction f2(a, b);

    f1.add(f2);

    f1.print();
    f2.print();

    f1.multiply(f2);
    f1.print();
    f2.print();
}
