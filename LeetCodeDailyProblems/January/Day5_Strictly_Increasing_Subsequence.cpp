#include <bits/stdc++.h>
using namespace std;

int solve(int prev, int index, int length, vector<int> &nums, int n, vector<int> &dp)
{

    if (index == n)
    {
        return 0;
    }

    if (dp[index] != -1)
        return dp[index];
    int maxi = 0, maxi2 = 0;
    for (int i = index; i < n; i++)
    {

        if (prev < nums[i])
        {
            maxi = max(maxi, solve(nums[i], i + 1, length, nums, n, dp) + 1);
        }
        else
        {
            maxi2 = solve(nums[i], i + 1, length, nums, n, dp);
        }
    }
    return dp[index] = max(maxi, maxi2);
}
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n + 1, -1);
    return solve(INT_MIN, 0, 0, nums, n, dp);
}

int main()
{
    int n;
    cin >> n;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int ans = lengthOfLIS(v);
    cout << ans << endl;

    return 0;
}