#include <iostream>
using namespace std;

void increment(int &i)
{
    i++;
}

int main()
{
    int i = 10;
    int &j = i;

    increment(i);
    cout << i << endl;

    i++;
    cout << j << endl;
    j++;
    cout << i << endl;

    int k = 100;
    j = k;
    cout << i << endl;
    cout << j << endl;
}
