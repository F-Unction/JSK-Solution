#include <iostream>
#include <cstdio>
using namespace std;
const int mod = 100007;
int dp[1010];
int main()
{
    freopen("stairs.in", "r", stdin);
    freopen("stairs.out", "w", stdout);
    int n;
    cin >> n;
    dp[1] = dp[0] = 1;
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    }
    cout << dp[n] << endl;
    return 0;
}