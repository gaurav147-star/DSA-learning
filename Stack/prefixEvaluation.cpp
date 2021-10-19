#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int prefixEvaluation(string s)
{
    stack<double> st;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            double op1 = st.top();
            st.pop();
            double op2 = st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
            case '-':
                st.push(op1 - op2);
            case '*':
                st.push(op1 * op2);
            case '/':
                st.push(op1 / op2);
                break;
            case '^':
                st.push(pow(op1, op2));
                break;

            default:
                break;
            }
        }
    }
    return st.top();
}
int main()
{
    cout << prefixEvaluation("+9*26") << endl;
}
