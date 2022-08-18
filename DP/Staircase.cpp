#include <bits/stdc++.h>
using namespace std;

// Recursion
int stairCase(int n)
{
    // Base case
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;

    return stairCase(n - 1) + stairCase(n - 2) + stairCase(n - 3);
}

int stairCaseHelper(int n, int *ans)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    // Check if output already exist
    if (ans[n] != -1)
    {
        return ans[n];
    }

    int output = stairCase(n - 1) + stairCase(n - 2) + stairCase(n - 3);
    // Save Output for future use
    ans[n] = output;
    return output;
}

int stairCase_2(int n)
{
    int *ans = new int[n + 1];

    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    return stairCaseHelper(n, ans);
}
int stairCase_3(int n)
{
    int *ans = new int[n + 1];
    ans[0] = 1;
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 4;
    for (int i = 4; i <= n; i++)
    {
        ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 3];
    }

    return ans[n];
}

int main()
{
    int n;
    cin >> n;
    cout << stairCase_3(n) << endl;
}
