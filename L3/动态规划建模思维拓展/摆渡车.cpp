//本题没有官方标程 下为本人自己的程序
#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int dp[501][201], t[501];

int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }
    sort(t + 1, t + 1 + n);
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < 2 * m; i++)
    {
        dp[1][i] = i;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j + t[i] - t[i - 1] < 2 * m; j++)
        {
            dp[i][j] = min(dp[i][j], dp[i - 1][j + t[i] - t[i - 1]] + j);
        }
        int mn = INF, pos = 0;
        for (; pos <= min(t[i] - t[i - 1] - m, 2 * m - 1); pos++)
        {
            mn = min(mn, dp[i - 1][pos]);
        }
        for (int j = 0; j < 2 * m; j++)
        {
            dp[i][j] = min(dp[i][j], mn + j);
            if (t[i] - t[i - 1] + (j + 1) - pos >= m && pos < 2 * m - 1)
            {
                mn = min(mn, dp[i - 1][pos++]);
            }
        }
    }
    int mn = INF;
    for (int i = 0; i < 2 * m; i++)
    {
        mn = min(mn, dp[n][i]);
    }
    cout << mn;
    return 0;
}