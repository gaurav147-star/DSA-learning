#include <bits/stdc++.h>
using namespace std;

// Memorization helper
int minCostPathHelper(int **input, int m, int n, int i, int j, vector<vector<int>> output)
{
    // Base Case
    if (i == m - 1 && j == n - 1)
    {
        return input[i][j];
    }
    if (i >= m || j >= n)
    {
        return INT_MAX;
    }

    // check if ans already exists
    if (output[i][j] != -1)
    {
        return output[i][j];
    }

    // Recursive Calls
    int x = minCostPathHelper(input, m, n, i + 1, j, output);
    int y = minCostPathHelper(input, m, n, i + 1, j + 1, output);
    int z = minCostPathHelper(input, m, n, i, j + 1, output);
    // Small Calculation

    int a = min(x, min(y, z)) + input[i][j];

    output[i][j] = a;
    return a;
}

// Brute force helper
int minCostPath(int **input, int m, int n, int i, int j)
{
    // Base Case
    if (i == m - 1 && j == n - 1)
    {
        return input[i][j];
    }
    if (i >= m || j >= n)
    {
        return INT_MAX;
    }

    // Recursive Calls
    int x = minCostPath(input, m, n, i + 1, j);
    int y = minCostPath(input, m, n, i + 1, j + 1);
    int z = minCostPath(input, m, n, i, j + 1);
    // Small Calculation

    int ans = min(x, min(y, z)) + input[i][j];

    // cout<<ans<<"-";
    return ans;
}

// Brute force
int minCostPath(int **input, int m, int n)
{
    return minCostPath(input, m, n, 0, 0);
}

// Memorization
int minCostPath_Mem(int **input, int m, int n)
{
    vector<vector<int>> output(n); // initialize outer vector with col inner vectors

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            output[i].push_back(-1);
        }
    }

    return minCostPathHelper(input, m, n, 0, 0, output);
}

// DynamicProgramming
int minCostPath_DP(int **input, int m, int n)
{
    int **output = new int *[m];
    for (int i = 0; i < m; i++)
    {
        output[i] = new int[n];
    }

    // Fill the last cell i.e. destination
    output[m - 1][n - 1] = input[m - 1][n - 1];

    // Fill last row(_right to left)
    for (int j = n - 2; j >= 0; j--)
    {
        output[m - 1][j] = output[m - 1][j + 1] + input[m - 1][j];
    }

    // fill last column (bottom to up)
    for (int i = m - 2; i >= 0; i--)
    {
        output[i][n - 1] = output[i + 1][n - 1] + input[i][n - 1];
    }

    // fill remaining cells
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            output[i][j] = min(output[i][j + 1], min(output[i + 1][j + 1], output[i + 1][j])) + input[i][j];
        }
    }
    return output[0][0];
}

int main()
{
    int m, n;
    cin >> m >> n;
    int **input = new int *[m];
    for (int i = 0; i < m; i++)
    {
        input[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> input[i][j];
        }
    }

    cout << minCostPath_DP(input, m, n) << endl;
}
