#include <bits/stdc++.h>
using namespace std;
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    vector<vector<int>> K(n + 1, vector<int>(W + 1));
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +
                                  K[i - 1][w - wt[i - 1]],
                              K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    int res = K[n][W];
    cout << "The maximum value is " << res << endl;
    cout << "Item which is picked in knapsack:";
    w = W;
    for (i = n; i > 0 && res > 0; i--)
    {
        if (res == K[i - 1][w])
            continue;
        else
        {
            cout << " " << wt[i - 1];
            res = res - val[i - 1];
            w = w - wt[i - 1];
        }
    }
    return 0;
}
int main()
{
    cout << endl
         << "Program developed by Gaurav Gupta" << endl
         << "Scholar No. 20U03030" << endl
         << endl;
    int n, W;
    cout << "Enter the no. of items: ";
    cin >> n;
    cout << "Enter the Knapsack size: ";
    cin >> W;
    int val[n];
    int wt[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the profit and weight of item " << i + 1 << " :";
        cin >> val[i] >> wt[i];
    }
    cout << endl;
    knapSack(W, wt, val, n);
    cout << endl;
    return 0;
}