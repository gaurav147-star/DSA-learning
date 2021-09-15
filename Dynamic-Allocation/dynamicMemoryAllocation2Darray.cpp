#include <iostream>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    int **p = new int *[m];
    for (int i = 0; i < m; i++)
    {
        p[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> p[i][j];
        }
    }
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            cout << p[x][y] << " ";
        }
        cout << endl;
    }
}
