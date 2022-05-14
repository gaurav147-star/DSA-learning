#include <bits/stdc++.h>
using namespace std;

void longestConsecutiveSubsequence(vector<int> &nums)
{

    unordered_map<int, bool> m;
    for (int i = 0; i < nums.size(); i++)
    {
        m[nums[i]] = true;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (m.find(nums[i] - 1) != m.end())
        {
            m[nums[i]] = false;
        }
    }
    int msp = 0;
    int ml = 0;
    for (int val : nums)
    {
        if (m[val] == true)
        {
            int tsp = val;
            int tl = 1;
            while (m.find(tsp + tl) != m.end())
            {
                tl++;
            }
            if (tl > ml)
            {
                ml = tl;
                msp = tsp;
            }
        }
    }

    for (int i = 0; i < ml; i++)
    {
        cout << msp + i << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        arr.push_back(data);
    }
    longestConsecutiveSubsequence(arr);
}