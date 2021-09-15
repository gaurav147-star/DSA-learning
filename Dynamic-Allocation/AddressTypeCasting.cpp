#include <iostream>
using namespace std;
int main()
{
    int i = 65;
    char c = i;
    cout << c << endl;

    int *p = &i;
    char *pi = (char *)p;

    cout << p << endl;
    cout << pi << endl;

    cout << *p << endl;
    cout << *pi << endl;
    cout << *(pi + 1) << endl;
    cout << *(pi + 2) << endl;
    cout << *(pi + 3) << endl;
}
