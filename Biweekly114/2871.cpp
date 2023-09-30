// 2871. Split Array Into Maximum Number of Subarrays

// You are given an array nums consisting of non - negative integers.

//                                                 We define the score of subarray nums[l..r] such that l <=
//         r as nums[l] AND nums[l + 1] AND... AND nums[r] where AND is the bitwise AND operation.

//         Consider splitting the array into one or
//     more subarrays such that the following conditions are satisfied :

//     Each element of the array belongs to exactly one subarray.The sum of scores of the subarrays is the minimum possible.Return the maximum number of subarrays in a split that satisfies the conditions above.

//     A subarray is a contiguous part of an array.

#include <bits/stdc++.h>
using namespace std;

int funct(vector<int> nums)
{
    if (nums.size() == 1)
    {
        return 1;
    }

    int ans = 0, i = 0, j = 0, andOp = nums[0];
    while (j != nums.size())
    {
        andOp = andOp & nums[j];
        if (andOp == 0)
        {
            if (j != nums.size() - 1)
            {
                andOp = nums[j + 1];
            }
            ans++;
        }
        j++;
    }
    if (ans > 1 && andOp != 0)
        return ans;
    return max(ans, 1);
}
int maxSubarrays(vector<int> &nums)
{
    return funct(nums);
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
    cout << maxSubarrays(nums) << endl;
}
