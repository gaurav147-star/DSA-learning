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

    Time operator<=(const Time &a)
    {
        if (hour == a.hour && minute == a.minute && second == a.second)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    friend Time operator-=(const Time &a, const Time &b);

    // postfix
    Time operator--()
    {

        --second;
        if (second >= 60)
        {
            --minute;
            second %= 60;
        }
        return *this; // return value before increment
    }
};

Time operator-=(const Time &a, const Time &b)
{
    Time tf; //object created with default value
    int totals = (a.hour - b.hour) * 3600 + (a.minute - b.minute) * 60 + a.second - b.second;
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

    Time t3;
    t3 = t1 <= t2;
    cout << t3 << endl;

    cout << (t1 -= t2) << endl;
    Time t4;
    t4 = --t2;
    cout << t2 << endl;
    cout << t4 << endl;
}
