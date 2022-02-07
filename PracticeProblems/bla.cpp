#include <bits/stdc++.h>
using namespace std;

int largest(int arr[], int n)
{
    return *max_element(arr, arr + n);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int max = largest(arr, n);
        int c = 0;
        // cout << max << endl;
        // if (n == 2)
        // {
        //     if (arr[0] != arr[1])
        //     {
        //         c++;
        //     }
        // }

        int j = 0;
        if (n >= 2)
        {
            while (j < n - 1)
            {
                if (arr[j] + arr[j + 1] == max)
                {
                    arr[j + 1] = max;
                    c++;
                    j++;
                }
                else if (arr[j] == arr[j + 1] || arr[j] == max)
                {
                    j++;
                }
                else
                {
                    if (arr[j] + arr[j + 1] < max)
                    {
                        arr[j + 1] = arr[j] + arr[j + 1];
                        j++;
                        c++;
                    }
                    else if (arr[j] + arr[j + 1] > max)
                    {
                        arr[j + 1] = arr[j] + arr[j + 1];
                        j++;
                        c++;
                    }
                }
            }
        }
        cout << c << endl;
    }

    return 0;
}
