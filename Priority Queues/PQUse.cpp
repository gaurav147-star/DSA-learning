#include <bits/stdc++.h>
#define ppi pair<int, pair<int, int>>
using namespace std;

void kSortedArray(int input[], int n, int k)
{
    priority_queue<int> a;
    for (int i = 0; i < k; i++)
    {
        a.push(input[i]);
    }

    int j = 0;
    for (int i = k; i < n; i++)
    {
        input[j] = a.top();
        a.pop();
        a.push(input[i]);
        j++;
    }

    while (!a.empty())
    {
        input[j] = a.top();
        a.pop();
        // j++;
    }
}

void kSmallestArray(int input[], int n, int k)
{
    priority_queue<int> a;
    for (int i = 0; i < k; i++)
    {
        a.push(input[i]);
    }

    for (int i = k; i < n; i++)
    {

        if (a.top() > input[i])
        {

            a.pop();
            a.push(input[i]);
        }
    }

    while (!a.empty())
    {
        cout << '\t' << a.top();
        a.pop();
    }
}

void kLargestArray(int input[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> a;
    for (int i = 0; i < k; i++)
    {
        a.push(input[i]);
    }

    for (int i = k; i < n; i++)
    {

        if (a.top() < input[i])
        {

            a.pop();
            a.push(input[i]);
        }
    }

    while (!a.empty())
    {
        cout << '\t' << a.top();
        a.pop();
    }
}

bool isMaxHeap(int input[], int i, int n)
{
    if (i >= (n - 1) / 2)
    {
        return true;
    }

    if (input[i] >= input[2 * i + 1] && input[i] >= input[2 * i + 2] && isMaxHeap(input, (2 * i + 1), n) && isMaxHeap(input, (2 * i + 2), n))
    {
        return true;
    }
    return false;
}

void kthLargestElement(int input[], int n)
{
    priority_queue<int> a;
    for (int i = 0; i < n; i++)
    {
        a.push(input[i]);
    }
    for (int i = 0; i < n; i++)
    {
        input[i] = a.top();
        a.pop();
    }
}

vector<int> mergeKArrays(vector<vector<int>> arr)
{
    vector<int> output;

    priority_queue<ppi, vector<ppi>, greater<ppi>> pq;

    for (int i = 0; i < arr.size(); i++)
        pq.push({arr[i][0], {i, 0}});

    while (pq.empty() == false)
    {
        ppi curr = pq.top();
        pq.pop();

        // i ==> Array Number
        // j ==> Index in the array number
        int i = curr.second.first;
        int j = curr.second.second;

        output.push_back(curr.first);

        // The next element belongs to same array as
        // current.
        if (j + 1 < arr[i].size())
            pq.push({arr[i][j + 1], {i, j + 1}});
    }

    return output;
}

int main()
{
    // Max heap
    // priority_queue<int> a;
    // a.push(5);
    // a.push(8);
    // a.push(1);
    // a.push(2);
    // a.push(0);

    // cout << "Size: " << a.size() << endl;
    // cout << "Top: " << a.top() << endl;

    // while (!a.empty())
    // {
    //     cout << a.top() << endl;
    //     a.pop();
    // }

    // Min heap
    // priority_queue<int, vector<int>, greater<int>> a;
    // a.push(5);
    // a.push(8);dsa
    // a.push(1);
    // a.push(2);
    // a.push(0);

    // cout << "Size: " << a.size() << endl;
    // cout << "Top: " << a.top() << endl;

    // while (!a.empty())
    // {
    //     cout << a.top() << endl;
    //     a.pop();
    // }

    // K Sorted Array

    // int input[] = {10, 12, 6, 7, 9};
    // int k = 3;
    // kSortedArray(input, 5, k);

    // for (int i = 0; i < 5; i++)
    // {
    //     cout << input[i] << " ";
    // }
    // cout << endl;

    // K smallest elements
    // int input[] = {2, 12, 9, 16, 10, 5, 3, 20, 25, 11, 1, 8, 6};
    // int k = 4;
    // kSmallestArray(input, 13, k);

    // // for (int i = 0; i < 3; i++)
    // // {
    // //     cout << input[i] << " ";
    // // }
    // cout << endl;

    // K largest elements
    // int input[] = {2, 12, 9, 16, 10, 5, 3, 20, 25, 11, 1, 8, 6};
    // int k = 4;
    // kLargestArray(input, 13, k);

    // for (int i = 0; i < 3; i++)
    // {
    //     cout << input[i] << " ";
    // }
    // cout << endl;

    // Check Max-Heap

    // int input[] = {42, 200, 18, 6, 14, 11, 9, 4};
    // (isMaxHeap(input, 0, 8)) ? cout << "true" << endl : cout << "false" << endl;

    // Kth Largest
    // int input[] = {9, 4, 8, 7, 11, 3};
    // int input[] = {2, 6, 10, 11, 13, 4, 1, 20};
    // kthLargestElement(input, 8);
    // cout << input[4 - 1] << endl;

    // Merge K sorted arrays
    int k;
    cin >> k;
    vector<vector<int>> a(k);
    for (int i = 0; i < k; i++)
    {
        int n;
        cin >> n;
        a[i] = vector<int>(n);
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<int> output = mergeKArrays(a);
    for (auto x : output)
        cout << x << " ";
    cout << endl;
}
