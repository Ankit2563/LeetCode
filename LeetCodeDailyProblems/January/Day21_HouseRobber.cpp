
#include <bits/stdc++.h>
using namespace std;
int solve(int index, vector<int> &nums, int n, vector<int> &dp)
{
    if (index == n - 1 || index == n - 2)
    {
        return nums[index];
    }
    if (index >= n)
        return 0;
    if (dp[index] != -1)
        return dp[index];

    int ans = 0;
    for (int i = index + 2; i < n; i++)
    {
        int maxi = nums[index] + solve(i, nums, n, dp);
        ans = max(ans, maxi);
    }
    return dp[index] = ans;
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 2)
        return max(nums[0], nums[1]);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> dp(n + 1, -1);
        ans = max(ans, solve(i, nums, n, dp));
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n;i++)
        cin >> v[i];

        cout <<rob(v);
    return 0;
}
