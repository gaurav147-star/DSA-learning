#include <iostream>
using namespace std;
int main()
{
    int *p = new int;
    *p = 10;
    cout << *p << endl;

    int n;
    cout << "Enter num of elements" << endl;
    cin >> n;

    int *pa = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> pa[i];
    }
    int max = -1;
    for (int i = 0; i < n; i++)
    {
        if (max < pa[i])
        {
            max = pa[i];
        }
    }
    cout << max << endl;
    delete[] p;
}
