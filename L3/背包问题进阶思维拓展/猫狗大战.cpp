//本题没有官方标程 下为本人自己的程序
#include <bits/stdc++.h>
using namespace std;

int a[201], f[201][4020];

int main()
{
    freopen("battle.in", "r", stdin);
    freopen("battle.out", "w", stdout);
    int n, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = n / 2 + 1; j >= 0; j--)
        {
            for (int k = sum / 2; k >= 0; k--)
            {
                if (f[j][k])
                {
                    f[j + 1][k + a[i]] = 1;
                }
            }
        }
    }
    for (int i = sum / 2; i >= 0; i--)
    {
        if (f[n / 2][i] || (f[n / 2 + 1][i]) && (n & 1))
        {
            cout << i << ' ' << sum - i << endl;
            break;
        }
    }
    return 0;
}