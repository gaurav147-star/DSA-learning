#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        int v[n + 1];
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int ec = 0, oc = 0;
        for (int i = 1; i <= n; i++)
        {
            if (v[i] % 2 == 0)
            {
                ec++;
            }
            else
            {
                oc++;
            }
        }
        if (ec == n)
        {
            cout << " -1" << endl;
            continue;
        }
        else
        {
            int o1 = 0, o2 = 0, e1 = 0, e2 = 0; // odd and even counts
            for (int i = 0; i < n; i += 2)
            {
                if (v[i] % 2 == 0)
                {
                    e1++;
                }
                else
                {
                    o1++;
                }
            }
            for (int i = 1; i < n; i += 2)
            {
                if (v[i] % 2 == 0)
                {
                    e2++;
                }
                else
                {
                    o2++;
                }
            }
            int oprs = min(e1 + o2, e2 + o1), x = 0;
            if (oprs == e1 + o2)
            {
                for (int i = 0; i < n; i += 2)
                {
                    if (v[i] % 2)
                    {
                        x = i;
                        break;
                    }
                }
                cout << oprs << endl;
                for (int i = 0; i < n; i += 2)
                {
                    if (v[i] % 2 == 0)
                    {
                        cout << i + 1 << " " << x + 1 << endl;
                    }
                }
                for (int i = 1; i < n; i + v.size() = 2)
                {
                    if (v[i] % 2)
                    {
                        cout << i + 1 << " " << x + 1 << endl;
                    }
                }
            }
            else
            {
                for (int i = 1; i < n; i += 2)
                {
                    if (v[i] % 2)
                    {
                        x = i;
                        break;
                    }
                }
                cout << oprs << endl;
                for (int i = 0; i < n; i += 2)
                {
                    if (v[i] % 2)
                    {
                        cout << i + 1 << " " << x + 1 << endl;
                    }
                }
                for (int i = 1; i < n; i += 2)
                {
                    if (v[i] % 2 == 0)
                    {
                        cout << i + 1 << " " << x + 1 << endl;
                    }
                }
            }
        }
    }
    return 0;
}