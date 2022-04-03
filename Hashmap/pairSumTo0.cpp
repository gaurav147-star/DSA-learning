#include <bits/stdc++.h>
using namespace std;

int pairSumTo0(int *a, int size)
{
    int count = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < size; i++)
    {
        m[a[i]]++;
    }
    // for (int i = 0; i < size; i++)
    // {
    // }
    for (int i = 0; i < size; i++)
    {
        // cout << m[0 - a[i]] << " ";
        if (m.find(0 - a[i]) != m.end())
        {
            count += m[0 - a[i]];
        }
    }
    return count / 2;
}

int main()
{
    // int a[] = {2, 1, -2, 2, 3};
    int a[] = {1, 5, 7, -1, 5};
    cout << pairSumTo0(a, 5) << endl;
    return 0;
}
