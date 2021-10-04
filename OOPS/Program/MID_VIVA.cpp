#include <iostream>
#include <iomanip>
using namespace std;

class Date
{
    // Operator Overloaders
    friend ostream &operator<<(ostream &os, const Date &t);
    friend istream &operator>>(istream &is, Date &t);

private:
    int day;
    int month;
    int year;

public:
    Date(int yy = 0, int mm = 0, int dd = 0)
    {
        day = dd;
        month = mm;
        year = yy;
    }

    void setDate(int yy, int mm, int dd)
    {
        year = yy;
        month = mm;
        day = dd;
    }
    void showDate()
    {
        cout << setw(2) << setfill('0') << day << "/"
             << setw(2) << setfill('0') << month << "/"
             << setw(2) << setfill('0') << year << "\n";
    }

    Date operator+(Date a)
    {
        Date tf; //object created with default value
        int totaldd = (a.month + month) * 30 + a.day + day;
        int yf = a.year + year;
        int mf = totaldd / 30;
        yf += mf / 12;
        mf %= 12;
        if (mf == 0)
            mf = 12;
        totaldd %= 30;
        int df = totaldd;
        tf.year = yf;
        tf.month = mf;
        tf.day = df;
        return tf;
    }
    friend Date operator-(Date &a, Date &b);
    // prefix
    friend Date operator++(Date &S);
    // postfix
    friend Date operator++(Date &S, int);
};

Date operator-(Date &a, Date &b)
{
    Date tf; //object created with default value
    int totaldd = (a.month - b.month) * 30 + a.day - b.day + (a.year - b.year) * 360;
    int yf = totaldd / 360;
    int mf = totaldd / 30;
    yf += mf / 12;
    mf %= 12;
    if (mf == 0)
        mf = 12;
    totaldd %= 30;
    int df = totaldd;
    tf.year = yf;
    tf.month = mf;
    tf.day = df;
    return tf;
}

Date operator++(Date &S)
{
    ++S.day;
    if (S.day >= 30)
    {
        ++S.month;
        S.day %= 30;
    }
    // implement increment logic on this instance, return reference to it.
    return S;
}

Date operator++(Date &S, int)
{

    Date old(S);
    ++S.day;
    if (S.day >= 30)
    {
        ++S.month;
        S.day %= 30;
    }           // prefix-increment this instance
    return old; // return value before increment
}

istream &operator>>(istream &is, Date &t)
{
    int yy, mm, dd;
    is >> dd >> mm >> yy;
    t.year = yy;
    t.month = mm;
    t.day = dd;

    return is;
}

ostream &operator<<(ostream &os, const Date &t)
{
    os << setw(2) << setfill('0') << t.day << "/"
       << setw(2) << setfill('0') << t.month << "/"
       << setw(2) << setfill('0') << t.year;
    return os;
}

int main()
{
    Date t1, t2;
    cout << "Date 1 in space seperated form {for eg: 12 10 39}\n";
    cin >> t1;

    cout << t1 << "\n";
    cout << "Date 2 in space seperated form {for eg: 12 10 39}\n";
    cin >> t2;
    cout << t2 << "\n";

    cout << "sum   :";
    Date t3 = t1 + t2;
    cout << t3 << "\n";

    cout << "diff   :";
    t3 = t2 - t1;
    cout << t3 << "\n";

    cout << "pre increment on t2   ";
    /* ++t2; */
    cout << ++t2 << " //++t \n";
    cout << "post increment on t2   ";
    /* t2++; */
    cout << t2++ << " //t++ \n";
    cout << endl;
    cout << "Name:Gaurav Gupta & Scholar No.:20U03030" << endl;
    return 0;
}
