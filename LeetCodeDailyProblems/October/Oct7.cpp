
// 1420. Build Array Where You Can Find The Maximum Exactly K Comparisons

//     You are given three integers n,

//     m and k.Consider the following algorithm to find the maximum element of an array of positive integers:
// You should build the array arr which has the following properties :

//     arr has exactly n integers.1 <= arr[i] <= m where(0 <= i < n).After applying the mentioned algorithm to arr,
//     the value search_cost is equal to k.Return the number of ways to build the array arr under the mentioned conditions.As the answer may grow large, the answer must be computed modulo 109 + 7.

// 343. Integer Break

// Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

// Return the maximum product you can get.

#include <bits/stdc++.h>
using namespace std;
int counting(int elem, vector<int> &nums)
{
    int count = 0;
    for (auto i : nums)
    {
        if (i == elem)
            count++;
    }
    return count;
}

int funct(int i, int maxi, int k, int n, int m, vector<vector<vector<int>>> &dp)
{
    if (i == n && k == 0)
        return 1;
    if (i == n && k != 0)
        return 0;
    if (k < 0)
        return 0;

    if (dp[i][maxi][k] != -1)
        return dp[i][maxi][k];
    int ans = 0;
    for (int j = 1; j <= maxi; j++)
    {
        ans = (ans + funct(i + 1, maxi, k, n, m, dp)) % 1000000007;
    }
    for (int j = maxi + 1; j <= m; j++)
    {
        ans = (ans + funct(i + 1, j, k - 1, n, m, dp)) % 1000000007;
    }

    return dp[i][maxi][k] = ans;
}
int numOfArrays(int n, int m, int k1)
{
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k1 + 1)));
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            for (int k = 0; k < k1 + 1; k++)
            {
                dp[i][j][k] = -1;
            }
        }
    }
    return funct(0, 0, k1, n, m, dp);
}
void input(int n, vector<int> &nums)
{
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    cout << numOfArrays(n,m,k) << endl;
}
