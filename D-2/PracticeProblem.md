# [Basic Practice Problem](https://www.codechef.com/CCSTART2/)

## Buy Please

<details>
<summary>Code</summary>

```cpp
#include <iostream>
using namespace std;

int main()
{
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    cout << a * x + b * y << endl;
    return 0;
}
```

</details>

## Is Both Or Not

<details>
<summary>Code</summary>

```cpp
#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    if ((N % 5 == 0 || N % 11 == 0) && N % 55 != 0)
    {
        cout << "ONE" << endl;
    }
    else if (N % 5 == 0 && N % 11 == 0)
    {
        cout << "BOTH" << endl;
    }
    else if (N % 5 != 0 || N % 11 != 0)
    {
        cout << "NONE" << endl;
    }

    return 0;
}
```

</details>

## Factors Finding

<details>
<summary>Code</summary>

```cpp
#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int ind = 0, count = 0;
    int arr[N];
    for (int i = 1; i <= N; i++)
    {
        if (N % i == 0)
        {
            arr[ind] = i;
            count++;
            ind++;
        }
    }
    cout << count << endl;
    for (int j = 0; j < count; j++)
    {
        cout << arr[j] << " ";
    }
}
```

</details>

## Reverse Me

<details>
<summary>Code</summary>

```cpp
#include <iostream>
using namespace std;

int main()
{
    int n, arr[n];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int j = n - 1; j >= 0; j--)
    {
        cout << arr[j] << " ";
    }

    return 0;
}
```

</details>

## Find Second Largest

<details>
<summary>Code</summary>

```cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{

    long int arr[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + 3);
    cout << arr[1] << endl;
}
```

</details>

## Range Odd

<details>
<summary>Code</summary>

```cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int L, R;
    cin >> L >> R;
    for (int i = L; i <= R; i++)
    {
        if (i % 2 != 0)
        {
            cout << i << " ";
        }
    }
}
```

</details>

## Raju and His Trip

<details>
<summary>Code</summary>

```cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    if (N % 5 == 0 || N % 6 == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
```

</details>

## Find Me

<details>
<summary>Code</summary>

```cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long int N, K;
    cin >> N >> K;
    long int arr[N];
    int c = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        if (arr[i] == K)
        {
            c++;
            break;
        }
    }

    if (c == 1)
    {
        cout << "1" << endl;
    }
    else
    {
        cout << "-1" << endl;
    }
}
```

</details>

## Valid Triangle Or Not

<details>
<summary>Code</summary>

```cpp
#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b > c && b + c > a && c + a > b)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
```

</details>

## Reverse Star Pattern

<details>
<summary>Code</summary>

```cpp
#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    for (int i = N; i > 0; i--)
    {
        for (int j = 0; j <= N; j++)
        {
            if (j >= i)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}
```

</details>

## Add Natural Numbers

<details>
<summary>Code</summary>

```cpp
#include <iostream>
using namespace std;
int main()
{
    long int n;
    cin >> n;
    long int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    cout << sum << endl;
}
```

</details>
