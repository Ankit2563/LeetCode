#include <bits/stdc++.h>
using namespace std;
long long solve(int index, int n, vector<int> &arr, int k, vector<int> &dp)
{
    if (index >= n)
        return 0;
    long long maxi = 0, count = 0, ans = 0;
    if (dp[index] != -1)
        return dp[index];
    for (int i = index; i < (index + k) && i < n; i++)
    {
        if (maxi < (arr[i]))
        {
            maxi = (arr[i]);
        }
        count++;

        ans = max(ans, count * maxi + solve(i + 1, n, arr, k, dp));
    }
    return dp[index] = (int)ans;
}
int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    int n = arr.size(), ans = 0;
    vector<int> dp(n + 1, -1);
    ans = solve(0, n, arr, k, dp);
    return ans;
}
int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n;i++)
        cin >> v[i];

    cout << maxSumAfterPartitioning(v, k);
    return 0;
}