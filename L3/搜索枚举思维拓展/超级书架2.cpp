//本题没有官方标程 下为本人自己的程序
#include <bits/stdc++.h>
using namespace std;

int a[25], n, m, ans;

void dfs(int u, int sum)
{
    if (u == n + 1 || sum >= m)
    {
        if (sum >= m && sum - m < ans)
        {
            ans = sum - m;
        }
        return;
    }
    dfs(u + 1, sum + a[u]);
    dfs(u + 1, sum);
}

int main()
{
    freopen("shelf.in", "r", stdin);
    freopen("shelf.out", "w", stdout);
    cin >> n >> m;
    ans = -m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ans += a[i];
    }
    dfs(0, 0);
    cout << ans;
    return 0;
}