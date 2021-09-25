#include <iostream>
#include <iomanip>
using namespace std;

class RationalNumber
{

    friend ostream &operator<<(ostream &os, const RationalNumber &r);
    friend istream &operator>>(istream &is, RationalNumber &r);

public:
    int numerator;
    int denominator;

    RationalNumber(int n = 0, int d = 1)
    {
        numerator = n;
        denominator = d;
    }

    void setRationalNumber(int n, int d)
    {
        numerator = n;
        denominator = d;
    }

    RationalNumber addRationalNumber(RationalNumber a)
    {
        RationalNumber t;

        t.numerator = a.numerator * denominator + a.denominator * numerator;
        t.denominator = a.denominator * denominator;
        t.reduction();
        return t;
    }
    RationalNumber subtractRationalNumber(RationalNumber s)
    {
        RationalNumber t;

        t.numerator = s.denominator * numerator - denominator * s.numerator;
        t.denominator = s.denominator * denominator;
        t.reduction();

        return t;
    }

    RationalNumber multiplication(RationalNumber &m)
    {
        RationalNumber t;

        t.numerator = m.numerator * numerator;
        t.denominator = m.denominator * denominator;
        t.reduction();

        return t;
    }

    RationalNumber division(RationalNumber &v)
    {
        RationalNumber t;

        t.numerator = v.denominator * numerator;
        t.denominator = denominator * v.numerator;
        t.reduction();

        return t;
    }
    void reduction(void)
    {
        int largest = numerator > denominator ? numerator : denominator;
        int gcd = 0; // greatest common divisor

        for (int loop = 2; loop <= largest; ++loop)
            if (numerator % loop == 0 && denominator % loop == 0)
                gcd = loop;

        if (gcd != 0)
        {
            numerator /= gcd;
            denominator /= gcd;
        }
    };

    void print()
    {
        cout << numerator << "/" << denominator << "\n";
    }
    RationalNumber &operator+=(const RationalNumber &a)
    {

        numerator = a.numerator * denominator + a.denominator * numerator;
        denominator = a.denominator * denominator;
        this->reduction();
        return *this;
    }

    RationalNumber &operator/=(const RationalNumber &v)
    {

        numerator = v.denominator * numerator;
        denominator = denominator * v.numerator;
        this->reduction();
        return *this;
    }
};

istream &operator>>(istream &is, RationalNumber &r)
{
    int n, d;
    is >> n >> d;
    r.numerator = n;
    r.denominator = d;
    return is;
}

ostream &operator<<(ostream &os, const RationalNumber &r)
{
    os << r.numerator << "/" << r.denominator;
    return os;
}

int main()
{
    cout << "Enter numerator and denominator in space separated form {for eg 7 8}\t";
    RationalNumber r1;
    cin >> r1;
    cout << r1 << "\n";
    cout << "Enter numerator and denominator in space separated form {for eg 7 8}\t";
    RationalNumber r2;
    cin >> r2;
    cout << r2 << "\n";
    cout << "\n"
         << "sum of rational number is ";
    /* r2.addRationalNumber(r1).print(); */
    RationalNumber r3;
    r3 += r1;
    r3 += r2;
    cout << r3 << "\n";
    cout << "\n"
         << "division of rational number is ";
    r2 /= r1;
    cout << r2 << "\n";

    cout << "Program code by Gaurav Gupta & Scholar No.: 20U03030" << endl;

    return 0;
}
