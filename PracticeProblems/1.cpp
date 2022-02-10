#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vi arr;
int n;

int check(int x, int sum)
{
    int tsum = 0;
    int ans = 0;
    for (int i = 0; i < x; i++)
    {
        tsum += arr[i];
        ans++;
        if (tsum == sum)
        {
            tsum = 0;
            ans--;
        }
    }
    if (tsum != 0)
    {
        return -1;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        cin >> n;
        arr.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int ans = n - 1;
        int sum = arr[n - 1];
        for (int i = n - 1; i > 0; i--)
        {
            int temp = check(i, sum);
            if (temp != -1)
            {
                ans = min(temp + (n - 1) - i, ans);
            }
            sum += arr[i - 1];
        }
        cout << ans << endl;
    }
}