#include <bits/stdc++.h>
using namespace std;

int postfixEvaluation(string s)
{
    stack<double> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            double op2 = st.top();
            st.pop();
            double op1 = st.top();
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
    cout << postfixEvaluation("46+2/5*7+") << endl;
    return 0;
}
