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

    Time operator-(Time a)
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

    // prefix
    friend Time &operator--(Time &a);
    // postfix
    friend Time operator--(Time &a, int);
};
// friend Point& operator--( Point& );
Time &operator--(Time &a)
{
    a.second--;
    if (a.second < 0)
    {
        a.minute--;
        a.second = 59;

        if (a.minute < 0)
        {
            a.hour--;
            a.minute = 59;
        }
    }
    return a;
}
Time operator--(Time &a, int)
{
    (a.second)--;
    if ((a.second) < 0)
    {
        (a.minute)--;
        (a.second) = 59;

        if ((a.minute) < 0)
        {
            (a.hour)--;
            (a.minute) = 59;
        }
    }
    return a;
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
    cout << "time 1 in space seperated form {for eg: 00 01 02}\n";
    cin >> t1;

    cout << t1 << "\n";
    cout << "time 2 in space seperated form {for eg: 00 01 02}\n";
    cin >> t2;
    cout << t2 << "\n";

    Time t3;
    cout << "diff   :";
    t3 = t2 - t1;
    cout << t3 << "\n";

    cout << "post decrement t2   ";
    /* t2++; */
    cout << t2-- << " //t-- \n";

    cout << "pre decrement on t2   ";
    /* ++t2; */
    cout << --t2 << " //--t \n";

    cout << "\n( Gaurav Gupta )\n( Scholar No: 20U03030 )" << endl;
    return 0;
}
