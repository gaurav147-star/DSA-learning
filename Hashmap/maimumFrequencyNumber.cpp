#include <bits/stdc++.h>
using namespace std;

int maximumFrequencyNumber(int *a, int size)
{
    unordered_map<int, int> s;
    for (int i = 0; i < size; i++)
    {
        s[a[i]]++;
    }
    // int max = 0;

    // cout << "size: " << s.size() << endl;
    // for (auto x : s)
    //     cout << x.first << " " << x.second << endl;
    int key = 0;
    int value = 0;

    for (int i = 0; i < size; i++)
    {
        if (s[a[i]] > value)
        {
            key = a[i];
            value = s[a[i]];
        }
    }
    return key;
}

int main()
{
    // int a[] = {2, 12, 2, 11, 12, 2, 1, 2, 2, 11, 12, 2, 6};
    int a[] = {1, 4, 5};
    int output = maximumFrequencyNumber(a, 13);
    cout << output << endl;
    return 0;
}
