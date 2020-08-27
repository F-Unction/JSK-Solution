#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 1e3 + 9;
const int mod = 1e9 + 9;
int f[N];
int main()
{
    freopen("divide.in", "r", stdin);
    freopen("divide.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        memset(f, 0, sizeof f);
        f[0] = 1;
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i; j <= n; ++j)
            {
                (f[j] += f[j - i]) %= mod;
            }
        }
        cout << f[n] << endl;
    }
    return 0;
}