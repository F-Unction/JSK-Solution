#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1010;
const int mod = 1000;
int a[maxn];
int dp[maxn];
int pre[maxn][maxn];
int main()
{
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        pre[i][i] = a[i];
        for (int j = i + 1; j <= n; ++j)
        {
            pre[i][j] = pre[i][j - 1] * a[j] % mod;
        }
    }
    dp[0] = 0;
    dp[1] = a[1];
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            dp[i] = max(dp[i], dp[j] + pre[j + 1][i]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}