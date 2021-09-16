#include <iostream>
using namespace std;
class Factorial
{
public:
    int factorial(int n)
    {
        if (n == 0)
        {

            return 1;
        }

        int smallOutput = factorial(n - 1);
        return n * smallOutput;
    }
};
int main()
{
    Factorial g;
    int n;
    cin >> n;
    int output = g.factorial(n);
    cout << output << endl;
}
