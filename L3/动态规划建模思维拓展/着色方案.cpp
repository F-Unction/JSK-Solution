//本题没有官方标程 下为本人自己的程序
#include <bits/stdc++.h>
using namespace std;

const int MOD = (int)1e9 + 7;
int f[16][16][16][16][16][16], a[16];

int dp(int a, int b, int c, int d, int e, int last)
{
    if (f[a][b][c][d][e][last] != -1)
    {
        return f[a][b][c][d][e][last];
    }
    if (a + b + c + d + e == 0)
    {
        return f[a][b][c][d][e][last] = 1;
    }
    long long cnt = 0;
    if (a)
    {
        cnt = (cnt + 1LL * (a - (last == 2)) * dp(a - 1, b, c, d, e, 1)) % MOD;
    }
    if (b)
    {
        cnt = (cnt + 1LL * (b - (last == 3)) * dp(a + 1, b - 1, c, d, e, 2)) % MOD;
    }
    if (c)
    {
        cnt = (cnt + 1LL * (c - (last == 4)) * dp(a, b + 1, c - 1, d, e, 3)) % MOD;
    }
    if (d)
    {
        cnt = (cnt + 1LL * (d - (last == 5)) * dp(a, b, c + 1, d - 1, e, 4)) % MOD;
    }
    if (e)
    {
        cnt = (cnt + 1LL * (e - (last == 6)) * dp(a, b, c, d + 1, e - 1, 5)) % MOD;
    }
    return f[a][b][c][d][e][last] = cnt;
}

int main()
{
    freopen("plan.in", "r", stdin);
    freopen("plan.out", "w", stdout);
    memset(f, -1, sizeof(f));
    int k;
    cin >> k;
    for (int i = 1, x; i <= k; i++)
    {
        cin >> x;
        a[x]++;
    }
    cout << dp(a[1], a[2], a[3], a[4], a[5], 0) << endl;
    return 0;
}