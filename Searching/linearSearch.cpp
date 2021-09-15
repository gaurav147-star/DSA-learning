#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int ele)
{
    //searhing element one by one in a array if element find return index of the array else return -1
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele)
        {
            return i;
        }
    }
    return -1;
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
    //which element to search
    int ele;
    cin >> ele;
    // Function call
    cout << linearSearch(arr, n, ele) << endl;

    return 0;
}
