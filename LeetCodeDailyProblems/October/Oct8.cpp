
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
int funct(int i, int j, int len1, int len2, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp)
{
    if (i == nums1.size())
    {
        if (j > nums2.size())
            return INT_MIN / 2;
        else
        {
            if (len1 == len2)
            {
                if (len1 > 0)
                    return 0;
                else
                    return INT_MIN / 2;
            }
            else
            {
                return INT_MIN / 2;
            }
        }
    }
    if (j == nums2.size())
    {
        if (i > nums1.size())
            return INT_MIN / 2;
        else
        {
            if (len1 == len2)
            {
                if (len1 > 0)
                    return 0;
                else
                    return INT_MIN / 2;
            }
            else
            {
                return INT_MIN / 2;
            }
        }
    }
    if (dp[i][j] != INT_MIN / 2)
        return dp[i][j];

    int sum1 = nums1[i] * nums2[j] + funct(i + 1, j + 1, len1 + 1, len2 + 1, nums1, nums2, dp);
    int sum2 = 0 + funct(i, j + 1, len1, len2, nums1, nums2, dp);
    int sum3 = 0 + funct(i + 1, j, len1, len2, nums1, nums2, dp);
    int sum4 = 0 + funct(i, j + 1, len1, len2, nums1, nums2, dp);

    return dp[i][j] = max(sum1, max(sum2, max(sum3, sum4)));
}

int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
{

    vector<int> v1 = nums1;
    vector<int> v2 = nums2;
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int n1 = v1.size();
    int n2 = v2.size();
    if (v1[n1 - 1] < 0 && v2[0] >= 0)
    {
        return v1[n1 - 1] * v2[0];
    }
    if (v2[n2 - 1] < 0 && v1[0] >= 0)
    {
        return v2[n2 - 1] * v1[0];
    }
    int len1 = 0, len2 = 0;
    vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), INT_MIN / 2));

    return funct(0, 0, len1, len2, nums1, nums2, dp);
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
    int n, m;
    cin >> n >> m;
    vector<int> v1(n);
    vector<int> v2(m);
    input(n,v1);
    input(m,v2);

    cout << maxDotProduct(v1,v2) << endl;
}
