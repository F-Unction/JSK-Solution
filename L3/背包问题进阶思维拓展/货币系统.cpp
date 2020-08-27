//本题没有官方标程 下为本人自己的程序
#include <bits/stdc++.h>
using namespace std;

int a[101];
bool vis[30001];
int main()
{
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        memset(vis, 0, (a[n] + 1) * sizeof(bool));
        vis[0] = 1;
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[a[i]])
            {
                cnt++;
            }
            int bound = a[n] - a[i];
            for (int k = 0; k <= bound; k++)
            {
                if (vis[k])
                {
                    vis[k + a[i]] = 1;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}