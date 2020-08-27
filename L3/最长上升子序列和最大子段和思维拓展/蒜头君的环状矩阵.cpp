#include <iostream>
#include <cstdio>
using namespace std;
int num[91][91];
long long sum[91][91];
int main()
{
    freopen("ring.in", "r", stdin);
    freopen("ring.out", "w", stdout);
    int N, M;
    long long nowsum, ans, t;
    cin >> N >> M;
    ans = -1000000001;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> num[i][j];
            if (ans < num[i][j])
            {
                ans = num[i][j];
            }
        }
    }
    if (ans <= 0)
    {
        cout << ans << endl;
    }
    else
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                sum[i][j] = sum[i - 1][j] + num[i][j];
            }
        }
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                for (int k = 0; k < M; k++)
                {
                    nowsum = 0;
                    for (int l = 0; l < M; l++)
                    {
                        if (i <= j)
                        {
                            t = sum[j][(k + l) % M] - sum[i - 1][(k + l) % M];
                        }
                        else
                        {
                            t = sum[N][(k + l) % M] - (sum[i - 1][(k + l) % M] - sum[j][(k + l) % M]);
                        }
                        if (nowsum + t <= 0)
                        {
                            nowsum = 0;
                        }
                        else
                        {
                            nowsum += t;
                        }
                        if (ans < nowsum)
                        {
                            ans = nowsum;
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}