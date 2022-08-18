#include <bits/stdc++.h>
using namespace std;
// Brute force
int fibo(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int a = fibo(n - 1);
    int b = fibo(n - 2);
    return a + b;
}

int fibo_helper(int n, int *ans)
{
    if (n <= 1)
    {
        return n;
    }

    // Check if output already exists
    if (ans[n] != -1)
    {
        return ans[n];
    }

    int a = fibo_helper(n - 1, ans);
    int b = fibo_helper(n - 2, ans);

    // Save the output for the future use
    ans[n] = a + b;
    return ans[n];
}
//Approach - Memorization(Top-down)
int fibo_2(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    return fibo_helper(n, ans);
}


//Dynamic Programming(bottom-up)
int fibo_3(int n)
{
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        ans[i] = ans[i - 1] + ans[i - 2];
    }
    return ans[n];
}

int main()
{
    cout << "hello gaurav" << endl;
    return 0;
}
