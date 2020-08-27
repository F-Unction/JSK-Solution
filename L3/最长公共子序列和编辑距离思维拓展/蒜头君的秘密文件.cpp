#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
int dp[1001][1001];
int main()
{
    freopen("secret.in", "r", stdin);
    freopen("secret.out", "w", stdout);
    string A, B;
    cin >> A;
    cin >> B;
    for (int i = 1; i <= A.length(); i++)
    {
        dp[i][0] = i;
    }
    for (int i = 1; i <= B.length(); i++)
    {
        dp[0][i] = i;
    }
    for (int i = 1; i <= A.length(); i++)
    {
        for (int j = 1; j <= B.length(); j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
        }
    }
    cout << dp[A.length()][B.length()] << endl;
    return 0;
}