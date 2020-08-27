#include <iostream>
#include <cstdio>
using namespace std;
int a[1001];
long long sum[1001];
int main()
{
    freopen("checkpoint.in", "r", stdin);
    freopen("checkpoint.out", "w", stdout);
    int n;
    long long ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        sum[i] = a[i];
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i] && sum[j] + a[i] > sum[i])
            {
                sum[i] = sum[j] + a[i];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (sum[i] > ans)
        {
            ans = sum[i];
        }
    }
    cout << ans << endl;
    return 0;
}