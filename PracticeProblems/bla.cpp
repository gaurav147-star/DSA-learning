#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    string sr;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        sr.push_back(s[i]);
    }
    cout << sr;
    return 0;
}