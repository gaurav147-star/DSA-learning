#include <bits/stdc++.h>
using namespace std;

int binarySearchIterative(int arr[], int n, int ele)
{
    int s = 0, e = n;
    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (arr[mid] == ele)
        {
            return mid;
        }
        if (arr[mid] < ele)
        {
            s = mid + 1;
        }

        else
        {
            e = mid - 1;
        }
    }
    return -1;
}

void show(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    //n-how much size of the array is
    int n;
    cin >> n;
    //taking value of the array
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    //Sort the array
    sort(arr, arr + n);
    //Sorted array
    show(arr, n);
    //which element to search
    int ele;
    cin >> ele;
    // Function call
    cout << binarySearchIterative(arr, n, ele) << endl;

    return 0;
}
