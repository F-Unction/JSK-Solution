//本题没有官方标程 下为本人自己的程序
#include <bits/stdc++.h>
using namespace std;

string s;
int n, k, ans = 0x3f3f3f3f;
void dfs(int dep, int x, int sum, int cnt)
{
    if (dep == n)
    {
        if (cnt == 0)
        {
            ans = min(ans, sum + x);
        }
        return;
    }
    if (n - dep - 1 < cnt)
    {
        return;
    }
    dfs(dep + 1, 10 * x + s[dep] - '0', sum, cnt);
    if (cnt)
    {
        dfs(dep + 1, 0, sum + 10 * x + s[dep] - '0', cnt - 1);
    }
}

int main()
{
    freopen("crayon.in", "r", stdin);
    freopen("crayon.out", "w", stdout);
    cin >> s >> k;
    n = s.size();
    dfs(0, 0, 0, k - 1);
    cout << ans;
    return 0;
}