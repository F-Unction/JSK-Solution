#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 100010;
int a[maxn], dp[maxn];
int main()
{
    freopen("spring.in", "r", stdin);
    freopen("spring.out", "w", stdout);
    int n;
    cin >> n;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = n; i >= 1; --i)
    {
        dp[i] = dp[i + a[i]] + 1;
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}