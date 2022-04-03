// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> findMean(int arr[], int queries[], int n, int q)
    {
        int k;
        int sum = 0;
        int i = 0;
        while (i < 2 * q)
        {

            int k = queries[i + 1] - queries[i] + 1;
            int sum = 0;
            for (int j = queries[i]; j <= queries[i + 1]; j++)
            {

                sum = sum + arr[j];
            }
            int n = sum / k;
            i = i + 2;
        }
        return n;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        int arr[n + 1], queries[2 * q + 1];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < 2 * q; i++)
        {
            cin >> queries[i];
        }

        vector<int> ans;
        Solution ob;
        ans = ob.findMean(arr, queries, n, 2 * q);

        for (int i : ans)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends