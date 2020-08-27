#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXN = 2010;

int a[MAXN];
int dp[2][MAXN];

int main()
{
    freopen("delete.in", "r", stdin);
    freopen("delete.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        dp[0][i] = 1;
        for (int j = 0; j < i; ++j)
        {
            if (a[j] >= a[i])
            {
                dp[0][i] = max(dp[0][i], dp[0][j] + 1);
            }
        }
    }
    for (int i = n - 1; i >= 0; --i)
    {
        dp[1][i] = 1;
        for (int j = n - 1; j > i; --j)
        {
            if (a[j] >= a[i])
            {
                dp[1][i] = max(dp[1][i], dp[1][j] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans = max(ans, dp[0][i] + dp[1][i] - 1);
    }
    cout << n - ans << endl;
    return 0;
}