// 1512. Number of Good Pairs
    // Given an array of integers nums, return the number of good pairs.

    //  A pair(i, j) is called good if nums[i] == nums[j] and i < j.

#include <bits/stdc++.h>
using namespace std;

int numIdenticalPairs(vector<int> &nums)
{
    map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        m[nums[i]]++;
    }
    int sum = 0;
    for (auto i : m)
    {
        if (i.second > 1)
        {
            int n = i.second;
            sum = sum + (n) * (n - 1) / 2;
        }
    }
    return sum;
}
void input(int n,vector<int>&nums){
    for (int i = 0; i < n;i++){
        cin >> nums[i];
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    input(n, nums);
    cout << numIdenticalPairs(nums) << endl;
}