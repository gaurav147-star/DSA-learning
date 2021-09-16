#include <iostream>
using namespace std;

class strings_recursion
{

public:
    int length(char s[]);
    void removeX(char s[]);
};

int strings_recursion::length(char s[])
{
    if (s[0] == '\0')
    {
        return 0;
    }
    int smallStringLength = length(s + 1);
    return 1 + smallStringLength;
}

void strings_recursion::removeX(char s[])
{
    if (s[0] == '\0')
    {
        return;
    }
    if (s[0] != 'x')
    {
        removeX(s + 1);
    }
    else
    {
        int i = 1;
        for (; s[i] != '\0'; i++)
        {
            s[i - 1] = s[i];
        }
        s[i - 1] = s[i];
        removeX(s);
    }
}

int main()
{
    strings_recursion l;
    char str[100];
    cin >> str;

    cout << l.length(str) << endl;
    l.removeX(str);
    cout << str << endl;
    cout << l.length(str) << endl;
}
