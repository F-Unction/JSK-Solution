//本题没有官方标程 下为本人自己的程序
#include <bits/stdc++.h>
using namespace std;

int s[351], dp[41][41][41][41], k[6];
int main()
{
    freopen("turtle.in", "r", stdin);
    freopen("turtle.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    for (int i = 1, x; i <= m; i++)
    {
        cin >> x;
        k[x]++;
    }
    for (int a = 0; a <= k[1]; a++)
    {
        for (int b = 0; b <= k[2]; b++)
        {
            for (int c = 0; c <= k[3]; c++)
            {
                for (int d = 0; d <= k[4]; d++)
                {
                    int p = 1 + a + 2 * b + 3 * c + 4 * d, v = s[p];
                    if (a)
                    {
                        v = max(v, dp[a - 1][b][c][d] + s[p]);
                    }
                    if (b)
                    {
                        v = max(v, dp[a][b - 1][c][d] + s[p]);
                    }
                    if (c)
                    {
                        v = max(v, dp[a][b][c - 1][d] + s[p]);
                    }
                    if (d)
                    {
                        v = max(v, dp[a][b][c][d - 1] + s[p]);
                    }
                    dp[a][b][c][d] = v;
                }
            }
        }
    }
    cout << dp[k[1]][k[2]][k[3]][k[4]] << endl;
    return 0;
}