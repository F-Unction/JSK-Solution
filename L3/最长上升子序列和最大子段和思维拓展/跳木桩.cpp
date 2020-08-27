#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 1010;
int a[MAXN];
int dp[MAXN];

int main()
{
    freopen("stake.in", "r", stdin);
    freopen("stake.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        dp[i] = 1;
        for (int j = 0; j < i; ++j)
        {
            if (a[j] >= a[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}