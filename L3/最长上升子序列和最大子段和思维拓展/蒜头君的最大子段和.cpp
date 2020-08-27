#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
long long num[1000001];
int main()
{
    freopen("max.in", "r", stdin);
    freopen("max.out", "w", stdout);
    int N;
    long long sum, ans;
    cin >> N;
    ans = -1000000001;
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
        ans = max(ans, num[i]);
    }
    if (ans <= 0)
    {
        cout << ans << endl;
    }
    else
    {
        sum = 0;
        for (int i = 0; i < N; i++)
        {
            if (sum + num[i] < 0)
            {
                sum = 0;
            }
            else
            {
                sum += num[i];
            }
            ans = max(ans, sum);
        }
        cout << ans << endl;
    }
    return 0;
}