//本题没有官方标程 下为本人自己的程序
#include <bits/stdc++.h>
using namespace std;

int n, a[30];
void dfs(int k, int d, int sum)
{
    if (sum == n)
    {
        cout << n << "=" << a[0];
        for (int i = 1; i < d; i++)
        {
            cout << "+" << a[i];
        }
        cout << endl;
        return;
    }
    if (sum > n)
    {
        return;
    }
    for (int i = k; i < n; i++)
    {
        a[d] = i;
        dfs(i, d + 1, sum + i);
    }
}

int main()
{
    //*
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);
    //*/
    cin >> n;
    dfs(1, 0, 0);
    return 0;
}