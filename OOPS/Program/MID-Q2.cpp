#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction(int nu = 0, int de = 0)
    {
        numerator = nu;
        denominator = de;
    }
    void print()
    {
        cout << numerator << " / " << denominator << endl;
    }

    void simplify()
    {
        int gcd = 1;
        int j = min(numerator, denominator);
        for (int i = 1; i <= j; i++)
        {
            if (numerator % i == 0 && denominator % i == 0)
            {
                gcd = i;
            }
        }
        numerator = numerator / gcd;
        denominator = denominator / gcd;
    }
    friend Fraction operator+(Fraction const &f1, Fraction const &f2);
    Fraction operator*(Fraction const &f2)
    {
        int n = numerator * f2.numerator;
        int d = denominator * f2.denominator;
        Fraction fNew(n, d);

        fNew.simplify();
        return fNew;
    }
};

Fraction operator+(Fraction const &f1, Fraction const &f2)
{
    int lcm = f1.denominator * f2.denominator;
    int x = lcm / f1.denominator;
    int y = lcm / f2.denominator;
    int num = x * f1.numerator + (y * f2.numerator);

    Fraction fNew(num, lcm);
    fNew.simplify();
    return fNew;
}

int main()
{

    Fraction f1(10, 4);
    Fraction f2(15, 4);
    Fraction f3, f4;
    f3 = f1 + f2;
    f1.print();
    f2.print();
    f3.print();
    f4 = f1 * f2;
    f1.print();
    f2.print();
    f4.print();
}