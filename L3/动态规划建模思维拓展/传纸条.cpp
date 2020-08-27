//本题没有官方标程 下为本人自己的程序
#include <bits/stdc++.h>
using namespace std;

int a[51][51], dp[51][51];
int main()
{
    freopen("pass.in", "r", stdin);
    freopen("pass.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    dp[1][1] = a[1][1];
    for (int step = 2; step < n + m; step++)
    {
        int l = max(1, step - m);
        int r = min(n, step);
        for (int i = r; i >= l; i--)
        {
            for (int p = r; p >= i + 1; p--)
            {
                int v = max(max(dp[i][p], dp[i][p - 1]), max(dp[i - 1][p], dp[i - 1][p - 1]));
                dp[i][p] = v + a[i][step - i] + a[p][step - p];
            }
        }
    }

    cout << dp[n - 1][n] + a[n][m] << endl;
    return 0;
}