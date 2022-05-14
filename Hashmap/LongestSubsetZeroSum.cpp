#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int LongestSubsetZeroSum(vector<int> &nums)
{
    unordered_map<int, int> m;
    int n = nums.size();
    int length = 0;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];

        if (nums[i] == 0 && length == 0)
            length = 1;

        if (sum == 0)
            length = i + 1;

        if (m.find(sum) != m.end())
        {
            length = max(length, i - m[sum]);
        }
        else
        {
            m[sum] = i;
        }
    }

    return length;
}

int main()
{
    int t;
    cin >> t;
    vector<int> arr;
    for (int i = 0; i < t; i++)
    {
        ll s;
        cin >> s;
        arr.push_back(s);
    }

    arr.resize(t);

    cout << LongestSubsetZeroSum(arr) << endl;
}
