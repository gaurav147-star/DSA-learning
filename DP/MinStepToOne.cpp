#include <bits/stdc++.h>
using namespace std;

int minSteps(int n)
{
    // Base Case
    if (n <= 1)
    {
        return 0;
    }

    // Recursion
    int x = minSteps(n - 1);
    int y = INT_MAX, z = INT_MAX;
    if (n % 2 == 0)
    {
        y = minSteps(n / 2);
    }
    if (n % 3 == 0)
    {
        z = minSteps(n / 3);
    }

    // Calculate final output
    int ans = min(x, min(y, z)) + 1;
    return ans;
}

int minStepsHelper(int n, int *ans)
{
    // base case
    if (n <= 1)
    {
        return 0;
    }
    // Check if output already exist
    if (ans[n] != -1)
    {
        return ans[n];
    }

    // Calculate
    int x = minStepsHelper(n - 1, ans);
    int y = INT_MAX, z = INT_MAX;
    if (n % 2 == 0)
    {
        y = minStepsHelper(n / 2, ans);
    }
    if (n % 3 == 0)
    {
        z = minStepsHelper(n / 3, ans);
    }
    int output = min(x, min(y, z)) + 1;

    // Save Output for future use
    ans[n] = output;
    return output;
}

//
int minSteps_2(int n)
{
    int *ans = new int[n + 1];

    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    return minStepsHelper(n, ans);
}

int minSteps_3(int n)
{
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = 0;
    ans[2] = 1;
    ans[3] = 1;
    for (int i = 4; i <= n; i++)
    {
        int x;
        int y = INT_MAX, z = INT_MAX;
        x = ans[i - 1];
        if (i % 2 == 0)
        {
            y = ans[i / 2];
        }
        if (i % 3 == 0)
        {
            z = ans[i / 3];
        }
        ans[i] = min(x, min(y, z)) + 1;
    }
    return ans[n];
}

int main()
{
    int n;
    cin >> n;
    cout << minSteps_3(n) << endl;
}
