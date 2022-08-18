#include <bits/stdc++.h>
using namespace std;

int minimumCount(int n)
{

    if (sqrt(n) - floor(sqrt(n)) == 0)
        return 1;
    if (n <= 3)
        return n;

    int res = n;

    for (int x = 1; x <= n; x++)
    {
        int temp = x * x;
        if (temp > n)
            break;
        else
            res = min(res, 1 + minimumCount(n - temp));
    }
    return res;
}

int minimumCountHelper(int n, int *ans)
{
    if (sqrt(n) - floor(sqrt(n)) == 0)
        return 1;
    if (n <= 3)
        return n;
    // Check if output already exist
    if (ans[n] != -1)
    {
        return ans[n];
    }
    int res = n;
    for (int x = 1; x <= n; x++)
    {
        int temp = x * x;
        if (temp > n)
            break;
        else
            res = min(res, 1 + minimumCountHelper(n - temp, ans));
        ans[n] = res;
    }
    return res;
}

int minimumCount_2(int n)
{
    int *ans = new int[n + 1];

    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    return minimumCountHelper(n, ans);
}

int minimumCount_3(int n)
{
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 3;
    int res = n;
    for (int i = 4; i <= n; i++)
    {
        // max value is i as i can
        // always be represented
        // as 1*1 + 1*1 + ...
        ans[i] = i;

        // Go through all smaller numbers to
        // to recursively find minimum
        for (int x = 1; x <= ceil(sqrt(i)); x++)
        {
            int temp = x * x;
            if (temp > i)
                break;
            else
                ans[i] = min(ans[i], 1 + ans[i - temp]);
        }
    }
    return ans[n];
}

int main()
{
    int n;
    cin >> n;
    cout << minimumCount_3(n) << endl;
}
