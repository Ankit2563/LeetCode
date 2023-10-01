// 2873. Maximum Value of an Ordered Triplet I

//     You are given a 0 -indexed integer array nums.

//     Return the maximum value over all triplets of
//     indices(i, j, k) such that i < j < k.If all such triplets have a negative value, return 0.

//     The value of a triplet of indices(i, j, k) is equal to(nums[i] - nums[j]) * nums[k] 
// Constraints :
//         3 <=nums.length <= 100 
//         1 <= nums[i] <= 106

#include <bits/stdc++.h>
using namespace std;

long long maximumTripletValue(vector<int> &nums)
{
    int maxi = nums[0];

    map<int, int> m;
    map<int, int> m1;

    for (int i = 1; i < nums.size(); i++)
    {
        m[i] = maxi;
        if (maxi < nums[i])
        {
            maxi = nums[i];
        }
    }
    int maxi2 = nums[nums.size() - 1];
    for (int j = nums.size() - 2; j >= 0; j--)
    {
        m1[j] = maxi2;
        if (maxi2 < nums[j])
        {
            maxi2 = nums[j];
        }
    }
    long long ans = 0;
    for (int i = 1; i < nums.size() - 1; i++)
    {
        if (ans < (m[i] - nums[i]) * (long long)m1[i])
        {
            ans = (m[i] - nums[i]) * (long long)m1[i];
        }
    }
    return ans;
}

int main()
{
    
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << maximumTripletValue(nums) << endl;
}
