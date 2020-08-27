#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 10010;
int dp[maxn][2]; // 1 代表和前面组合，0 代码没有和前面组合
int w[maxn];
int main()
{
    freopen("happy.in", "r", stdin);
    freopen("happy.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> w[i];
    }
    dp[1][0] = 0;
    for (int i = 2; i <= n; ++i)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = dp[i - 1][0] + w[i] * w[i - 1];
    }
    cout << max(dp[n][0], dp[n][1]) << endl;
    return 0;
}