#include <bits/stdc++.h>
using namespace std;
// Brute Force
int balancedBts(int h)
{
    if (h <= 1)
    {
        return 1;
    }
    int mod = (int)(pow(10, 9)) + 7;
    int x = balancedBts(h - 1);
    int y = balancedBts(h - 2);

    int temp1 = (int)(((long)(x)*x) % mod);
    int temp2 = (int)((2 * (long)(x)*y) % mod);
    int ans = (temp1 + temp2) % mod;
    return ans;
}

int balancedBtsHelper(int h, int *ans)
{
    if (h <= 1)
    {
        return 1;
    }
    int mod = (int)(pow(10, 9)) + 7;
    int x = balancedBtsHelper(h - 1, ans);
    int y = balancedBtsHelper(h - 2, ans);

    int temp1 = (int)(((long)(x)*x) % mod);
    int temp2 = (int)((2 * (long)(x)*y) % mod);
    int output = (temp1 + temp2) % mod;
    ans[h] = output;
    return output;
}
//Memorization
int balancedBts_2(int h)
{
    int *ans = new int[h + 1];

    for (int i = 0; i <= h; i++)
    {
        ans[i] = -1;
    }
    return balancedBtsHelper(h, ans);
}

//Dynamic Programming
int balancedBts_3(int h)
{
    int *ans = new int[h + 1];
    ans[0] = 1;
    ans[1] = 1;
    for (int i = 2; i <= h; i++)
    {
        int mod = (int)(pow(10, 9)) + 7;
        int x = ans[i - 1];
        int y = ans[i - 2];

        int temp1 = (int)(((long)(x)*x) % mod);
        int temp2 = (int)((2 * (long)(x)*y) % mod);
        ans[i] = (temp1 + temp2) % mod;
    }
    return ans[h];
}

int main()
{
    int h;
    cin >> h;
    cout << balancedBts_3(h) << endl;
}
