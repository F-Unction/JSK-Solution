#include <iostream>
#include <cstdio>
using namespace std;
int a[1001], b[1001];
int dp[1001][1001];
int main()
{
    freopen("log.in", "r", stdin);
    freopen("log.out", "w", stdout);
    int n, m, maxx;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        maxx = 0;
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (a[i] > b[j] && maxx < dp[i - 1][j])
            {
                maxx = dp[i - 1][j];
            }
            else if (a[i] == b[j])
            {
                dp[i][j] = maxx + 1;
            }
        }
    }
    maxx = 0;
    for (int i = 1; i <= m; i++)
    {
        if (dp[n][i] > maxx)
        {
            maxx = dp[n][i];
        }
    }
    cout << maxx << endl;
    return 0;
}