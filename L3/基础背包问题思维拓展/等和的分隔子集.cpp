#include <iostream>
using namespace std;
long long dp[4000];
int main()
{
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);
    int n;
    cin >> n;
    int sum = n * (n + 1) / 2;
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = sum; j >= i; --j)
        {
            dp[j] += dp[j - i];
        }
    }
    if (sum % 2 == 1)
    {
        cout << "0" << endl;
    }
    else
    {
        cout << dp[sum / 2] / 2 << endl;
    }
    return 0;
}