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

    friend RationalNumber &operator*=(RationalNumber &a,RationalNumber &b);
    friend RationalNumber &operator++(RationalNumber &a);
};
RationalNumber &operator*=(RationalNumber &a,RationalNumber &b){
    a.numerator=a.numerator*b.numerator;
    a.denominator=a.denominator*b.denominator;
    return a;
}

RationalNumber &operator++(RationalNumber &a)
{
    a.numerator = a.numerator + a.denominator;
    a.denominator = a.denominator;
    return a;
}

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
    r1+=r2;
    cout << r1 << "\n";
    cout << "\n"
         << "multiply of rational number is ";
    r1 *= r2;
    cout << r1 << "\n";
    ++r1;
    cout << r1 << "\n";

    cout << "Program code by Gaurav Gupta & Scholar No.: 20U03030" << endl;

    return 0;
}
