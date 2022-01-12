#include <iostream>
#include <iomanip>
using namespace std;

class Time
{
    // Operator Overloaders
    friend ostream &operator<<(ostream &os, const Time &t);
    friend istream &operator>>(istream &is, Time &t);
    friend Time operator--(Time t, int);
    friend Time &operator--(Time &t);

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

Time &operator--(Time &t)
{
    cout << "pre -- called" << endl;
    t.second--;
    if (t.second < 0)
    {
        t.minute--;
        t.second = 59;

        if (t.minute < 0)
        {
            t.hour--;
            t.minute = 59;
        }
    }
    return t;
}
Time operator--(Time t, int)
{
    cout << "post -- called" << endl;
    (t.second)--;
    if ((t.second) < 0)
    {
        (t.minute)--;
        (t.second) = 59;

        if ((t.minute) < 0)
        {
            (t.hour)--;
            (t.minute) = 59;
        }
    }
    return t;
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

    Time t5;
    t5 = --t2;
    cout << t5 << endl;

    Time t4;
    t4 = t2--;
    cout << t4 << endl;
}