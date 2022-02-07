#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        int oprs = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int max = v[0];
        for (int i = 1; i < n; i++)
        {
            if (v[i] > max)
            {
                max = v[i];
            }
        }
        // if (n == 2)
        // {
        //     if (v[1] == v[2])
        //     {
        //         oprs = 0;
        //     }
        //     else
        //     {
        //         oprs = 1;
        //     }
        // }
        int j = 0;
        if (n >= 2)
        {
            while (j < n - 1)
            {
                if (v[j] + v[j + 1] == max)
                {
                    v[j + 1] = max;
                    oprs++;
                    j++;
                }
                else if (v[j] == v[j + 1])
                {
                    j++;
                }
                else if (v[j] == max)
                {
                    j++;
                }
                else if (v[j] + v[j + 1] < max)
                {
                    v[j + 1] = v[j] + v[j + 1];
                    oprs++;
                    j++;
                }
                else if (v[j] + v[j + 1] > max)
                {
                    v[j + 1] = v[j] + v[j + 1];
                    oprs++;
                    j++;
                }
            }
        }
        cout << oprs << endl;
    }
    return 0;
}
