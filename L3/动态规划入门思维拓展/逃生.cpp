//本题没有官方标程 下为本人自己的程序
#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f, maxn = 1001;
int a[maxn][maxn], dp[maxn][maxn];
int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("escape.in");
    fout.open("escape.out");
    int n, m, x, y, v, c, xx[4] = {-1, -1, 1, 1}, yy[4] = {-1, 1, -1, 1};
    fin >> n >> m >> x >> y >> v >> c;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            fin >> a[i][j];
        }
    }
    for (int t = 0; t < 4; t++)
    {
        for (int i = x; i > 0 && i <= n; i -= xx[t])
        {
            for (int j = y; j > 0 && j <= m; j -= yy[t])
            {
                if (i == x && j == y)
                {
                    dp[i][j] = v;
                }
                else if (i == x)
                {
                    dp[i][j] = min(c, dp[i][j + yy[t]] + a[i][j]);
                }
                else if (j == y)
                {
                    dp[i][j] = min(c, dp[i + xx[t]][j] + a[i][j]);
                }
                else
                {
                    dp[i][j] = min(c, max(dp[i + xx[t]][j], dp[i][j + yy[t]]) + a[i][j]);
                }
                if (dp[i][j] <= 0)
                {
                    dp[i][j] = -INF;
                }
            }
        }
    }
    int ans = max(max(dp[1][1], dp[1][m]), max(dp[n][1], dp[n][m]));
    if (ans <= 0)
    {
        fout << -1;
    }
    else
    {
        fout << ans;
    }
    return 0;
}