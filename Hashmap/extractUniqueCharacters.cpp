#include <bits/stdc++.h>
using namespace std;

string extractUnique(string s)
{
    string ans;
    unordered_map<char, int> x;
    for (int i = 0; i < s.length(); i++)
    {
        x[s[i]]++;
        if (x[s[i]] == 1)
        {
            ans.push_back(s[i]);
        } 
    }
    return ans;
}

int main()
{

    string s;
    cin >> s;

    cout << extractUnique(s) << endl;
}
