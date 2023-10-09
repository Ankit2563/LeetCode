// 34. Find First and Last Position of Element in Sorted Array

// Companies
//         Given an array of integers nums sorted in non -
//     decreasing order,
//     find the starting and ending position of a given target value.

//     If target is not found in the array,
//     return [ -1, -1 ].

//     You must write an algorithm with
//     O(log n) runtime complexity.

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
vector<int> searchRange(vector<int> &nums, int target)
{

    bool temp = binary_search(nums.begin(), nums.end(), target);
    if (temp == false)
        return {-1, -1};

    int idx1 = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int idx2 = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

    return {idx1, idx2 - 1};
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
    int n, target;
    cin >> n >> target;
    vector<int> v1(n);
   
    input(n, v1);


cout << searchRange(v1, target)[0] <<" "<< searchRange(v1, target)[1];
}
