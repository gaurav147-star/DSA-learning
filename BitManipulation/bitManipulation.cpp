#include <bits/stdc++.h>
using namespace std;

int getBit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}

int setBit(int n, int pos)
{
    return (n | (1 << pos));
}

int clearBit(int n, int pos)
{
    int mask = ~(1 << pos);
    return n & mask;
}

int updateBit(int n, int pos, int value)
{
    int mask = ~(1 << pos);
    n = n & mask;
    return (n | (value << pos));
}

bool ispowerof2(int n)
{
    return (n && !(n & n - 1));
}

int numberOfOnes(int n)
{
    int count = 0;
    while (n)
    {
        n = (n & n - 1);
        count++;
    }
    return count;
}

void subsets(int arr[], int n)
{
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
}

int uniqueNumber(int arr[], int n)
{
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum = xorsum ^ arr[i];
    }
    return xorsum;
}

void unique2Number(int arr[], int n)
{
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum = xorsum ^ arr[i];
    }
    int tempxorsum = xorsum;
    int setbit = 0;
    int pos = 0;
    while (setbit != 1)
    {
        setbit = xorsum & 1;
        pos++;
        xorsum = xorsum >> 1;
    }
    int newxor = 0;
    for (int i = 0; i < n; i++)
    {
        if (getBit(arr[i], pos - 1))
        {
            newxor = newxor ^ arr[i];
        }
    }
    cout << newxor << " " << (newxor ^ tempxorsum) << endl;
}

int main()
{

    // cout << getBit(3, 2) << endl;
    // cout << setBit(5, 1) << endl;
    // cout << clearBit(5, 2) << endl;
    // cout << updateBit(5, 1, 1) << endl;
    // cout << ispowerof2(3) << endl;
    // cout << numberOfOnes(19) << endl;

    // int arr[7] = {1, 2, 3, 4, 3, 4, 1};
    // subsets(arr, 4);
    // cout << uniqueNumber(arr, 7) << endl;
    int arr[] = {1, 2, 3, 1, 2, 3, 5, 7};
    unique2Number(arr, 8);

    return 0;
}
