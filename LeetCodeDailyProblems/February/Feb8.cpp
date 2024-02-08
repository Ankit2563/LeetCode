#include <bits/stdc++.h>
using namespace std;
long long solve(int n, vector<long long> &dp)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return INT_MAX / 2;

    if (dp[n] != -1)
        return dp[n];

    long long maxi = INT_MAX, ans;
    int m = (int)sqrt(n);

    for (int i = 1; i <= m; i++)
    {

        ans = 1 + solve(n - i * i, dp);
        if (maxi > ans)
        {
            maxi = ans;
        }
    }

    return dp[n] = maxi;
}
int numSquares(int n)
{
    vector<long long> dp(n + 1, -1);

    return solve(n, dp);
}
int main()
{
    int n;
    cin >> n;

    cout<< numSquares(n);
    return 0;
}