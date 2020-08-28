//本题没有官方标程 下为本人自己的程序
#include <bits/stdc++.h>
using namespace std;

int n, ans = 0x3f3f3f3f, a[15], b[15];

void dfs(int dep, int pro, int sum, bool sel)
{
    if (dep == n)
    {
        if (sel)
        {
            ans = min(ans, abs(sum - pro));
        }
        return;
    }
    dfs(dep + 1, pro * a[dep], sum + b[dep], 1);
    dfs(dep + 1, pro, sum, sel);
}

int main()
{
    //*
    freopen("stone.in", "r", stdin);
    freopen("stone.out", "w", stdout);
    //*/
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    dfs(0, 1, 0, 0);
    cout << ans << endl;
    return 0;
}