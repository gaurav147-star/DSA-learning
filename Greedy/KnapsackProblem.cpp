#include <bits/stdc++.h>
using namespace std;
struct Item
{
    int value;
    int weight;
};

bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}
double fractionalKnapsack(int W, struct Item arr[], int n)
{
    sort(arr, arr + n, cmp);
    int curWeight = 0;
    double finalvalue = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (curWeight + arr[i].weight <= W)
        {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
        }
        else
        {
            int remain = W - curWeight;
            finalvalue += arr[i].value * ((double)remain / (double)arr[i].weight);
            break;
        }
    }
    return finalvalue;
}

int main()
{
    int W;
    cout << "Enter the Knapsack size" << endl;
    cin >> W;
    int n;
    cout << "Enter number of items" << endl;
    cin >> n;
    Item arr[n];
    cout << "Enter profit and weight of each item" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].value >> arr[i].weight;
    }

    cout << "Maximum value we can obtain = "
         << fractionalKnapsack(W, arr, n) << endl;
  
}
