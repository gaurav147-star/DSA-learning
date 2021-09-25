#include <iostream>
#include <iomanip>
using namespace std;

class Time
{
    // Operator Overloaders
    friend ostream &operator<<(ostream &os, const Time &t);
    friend istream &operator>>(istream &is, Time &t);

private:
    int hour;
    int minute;
    int second;

public:
    Time(int h = 0, int m = 0, int s = 0)
    {
        hour = h;
        minute = m;
        second = s;
    }

    void setTime(int h, int m, int s)
    {
        hour = h;
        minute = m;
        second = s;
    }

    void showTime()
    {
        cout << setw(2) << setfill('0') << hour << ":"
             << setw(2) << setfill('0') << minute << ":"
             << setw(2) << setfill('0') << second << "\n";
    }

    Time addTime(Time a)
    {
        Time tf; //object created with default value
        int totals = (a.hour + hour) * 3600 + (a.minute + minute) * 60 + a.second + second;
        int hf = totals / 3600;
        totals %= 3600;
        int mf = totals / 60;
        totals %= 60;
        int sf = totals;
        tf.hour = hf;
        tf.minute = mf;
        tf.second = sf;
        return tf;
    }

    Time subtractTime(Time a)
    {
        Time tf; //object created with default value
        int totals = (hour - a.hour) * 3600 + (minute - a.minute) * 60 + second - a.second;
        int hf = totals / 3600;
        totals %= 3600;
        int mf = totals / 60;
        totals %= 60;
        int sf = totals;
        tf.hour = hf;
        tf.minute = mf;
        tf.second = sf;
        return tf;
    }

    Time operator+(Time a)
    {
        return addTime(a);
    }

    Time operator-(Time a)
    {
        return subtractTime(a);
    }
    // prefix
    Time operator++()
    {
        second++;
        if (second >= 60)
        {
            minute++;
            second %= 60;
        }
        // implement increment logic on this instance, return reference to it.
        return *this;
    }
    // postfix
    Time operator++(int)
    {
        Time old(*this);
        operator++(); // prefix-increment this instance
        return old;   // return value before increment
    }
};

istream &operator>>(istream &is, Time &t)
{
    int h, m, s;
    is >> h >> m >> s;
    t.hour = h;
    t.minute = m;
    t.second = s;

    return is;
}

ostream &operator<<(ostream &os, const Time &t)
{
    os << setw(2) << setfill('0') << t.hour << ":" << setw(2) << setfill('0') << t.minute << ":" << setw(2) << setfill('0') << t.second;
    return os;
}

int main()
{
    Time t1, t2;
    cout << "time 1 in space seperated form {for eg: 12 10 39}\n";
    cin >> t1;

    cout << t1 << "\n";
    cout << "time 2 in space seperated form {for eg: 12 10 39}\n";
    cin >> t2;
    cout << t2 << "\n";

    cout << "sum   :";
    Time t3 = t1 + t2;
    cout << t3 << "\n";

    cout << "post increment on t2   ";
    /* t2++; */
    cout << t2++ << " //t++ \n";
    cout << "pre increment on t2   ";
    /* ++t2; */
    cout << ++t2 << " //++t \n";

    cout << "diff   :";
    t3 = t2 - t1;
    cout << t3 << "\n";

    cout << "Program code by Gaurav Gupta & Scholar No.: 20U03030" << endl;
    return 0;
}
