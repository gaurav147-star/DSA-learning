#include <bits/stdc++.h>
using namespace std;

int PairWithDifferenceK(vector<int> &nums, int k)
{
    unordered_map<int, int> m;

    for (int i = 0; i < nums.size(); i++)
    {
        m[nums[i]]++;
    }
    int res = 0;
    int n = nums.size();
    if (k != 0)
    {
        for (int i = 0; i < n; i++)
        {


            if (m.count(nums[i] - k) > 0)
            {
                int j = 0;
                while (j < m[nums[i] - k])
                {
                    // if ((nums[i] - k) < nums[i])
                    //     cout << nums[i] - k << " " << nums[i] << endl;
                    // else
                    //     cout << nums[i] << " " << nums[i] - k << endl;

                    j++;
                    res++;
                }
            }
           

        }
    }
    else if (k == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (m.count(nums[i]) > 0)
            {
                for (int j = 0; j < m[nums[i]] - 1; j++)
                {
                    res++;
                }
                m[nums[i]]--;
            }
        }
    }

    // for (auto x : m)
    //     cout << x.first << " " << x.second << endl;
    return res;
}

int main()
{

    int t;
    cin >> t;
    vector<int> arr;
    for (int i = 0; i < t; i++)
    {
        int s;
        cin >> s;
        arr.push_back(s);
    }
    int k;
    cin >> k;
    arr.resize(t);
    // cout << arr.size();

    cout << PairWithDifferenceK(arr, k) << endl;
}
