
#include <bits/stdc++.h>
using namespace std;
long long solve(int n, int k, vector<vector<int>> &dp)
{
    if (k == 0)
        return 1;
    if (n <= 0 || k < 0)
        return 0;

    if (dp[n][k] != -1)
        return dp[n][k];
    long long maxi = 0;
    for (int i = n; i >= 1; i--)
    {
        maxi += solve(n - 1, k - (n - i), dp);
    }
    return dp[n][k] = maxi % (1000000007);
}
int kInversePairs(int n, int k)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    return (int)solve(n, k, dp);
}
int main()
{
    int n, k;
    cin >> n >> k;
    cout << kInversePairs(n,k);
    return 0;
}
