#include <iostream>
using namespace std;
int arr[20][20], completed[20], n, cost = 0;
void takeInput()
{
    int i, j;
    cout << "Enter the number of city: ";
    cin >> n;
    cout << "\nEnter the Cost Matrix\n";
    for (i = 0; i < n; i++)
    {
        cout << "\nEnter Elements of Row: " << i + 1 << "\n";
        for (j = 0; j < n; j++)
            cin >> arr[i][j];
        completed[i] = 0;
    }
    cout << "\n\nThe cost list is:";
    for (i = 0; i < n; i++)
    {
        cout << "\n";
        for (j = 0; j < n; j++)
            cout << "\t" << arr[i][j];
    }
}
int least(int c)
{
    int i, nc = 999;
    int min = 999, kmin;
    for (i = 0; i < n; i++)
    {
        if ((arr[c][i] != 0) && (completed[i] == 0))
            if (arr[c][i] + arr[i][c] < min)
            {
                min = arr[i][0] + arr[c][i];
                kmin = arr[c][i];
                nc = i;
            }
    }
    if (min != 999)
        cost += kmin;

    return nc;
}

void mincost(int city)
{
    int i, ncity;

    completed[city] = 1;

    cout << city + 1 << "--->";
    ncity = least(city);

    if (ncity == 999)
    {
        ncity = 0;
        cout << ncity + 1;
        cost += arr[city][ncity];

        return;
    }

    mincost(ncity);
}
int main()
{
    takeInput();
    cout << "\n\nThe Path is:\n";
    mincost(0); //passing 0 because starting vertex
    cout << "\n\nMinimum cost is " << cost << endl;
    cout << "Program developed by Gaurav Gupta Scholar No. 20U03030" << endl;
    return 0;
}
