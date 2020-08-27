//本题没有官方标程 下为本人自己的程序
#include <bits/stdc++.h>
using namespace std;

int sum[51], f[51][51], dp[2501];
int main()
{
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    int n, m, t;
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++)
        {
            sum[j] = sum[j - 1] + (s[j - 1] == '1');
        }

        for (int j = 1; j <= m; j++)
        {
            for (int x = 1; x <= m; x++)
            {
                f[x][j] = 0;
                for (int y = 0; y < x; y++)
                {
                    int t = sum[x] - sum[y];
                    f[x][j] = max(f[x][j], f[y][j - 1] + max(t, (x - y) - t));
                }
            }
        }

        for (int j = t; j >= 1; j--)
        {
            for (int k = 1; k <= min(m, j); k++)
            {
                dp[j] = max(dp[j], dp[j - k] + f[m][k]);
            }
        }
    }

    cout << dp[t] << endl;

    return 0;
}