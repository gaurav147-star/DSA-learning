#include <bits/stdc++.h>
using namespace std;
void arrayIntersection(int *a, int as, int *b, int bs)
{
    unordered_map<int, int> x, y;
    for (int i = 0; i < as; i++)
    {
        x[a[i]]++;
    }
    for (int i = 0; i < bs; i++)
    {
        if (x.find(b[i]) != x.end())
        {
            cout << b[i] << " ";
        }
    }
}

int main()
{
    int a[] = {2, 6, 8, 5, 4, 3};
    int b[] = {2, 3, 4, 7};
    arrayIntersection(a, 6, b, 4);
}
