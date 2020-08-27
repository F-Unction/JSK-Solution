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
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = 0;
        for (int j = i - 1; j >= 0; j -= 2)
        {
            dp[i] += dp[j];
            dp[i] %= mod;
        }
    }
    cout << dp[n] << endl;
    return 0;
}