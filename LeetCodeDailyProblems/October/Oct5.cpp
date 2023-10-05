// 229. Majority Element II

    // Given an integer array of size n, find all elements that appear more than ⌊ n / 3 ⌋ times.

// 1512. Number of Good Pairs
// Given an array of integers nums, return the number of good pairs.

//  A pair(i, j) is called good if nums[i] == nums[j] and i < j.

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
vector<int> majorityElement(vector<int> &nums)
{
    int num1 = -1;
    int num2 = -1;
    int c1 = 0;
    int c2 = 0;
    vector<int> ans;
    for (auto i : nums)
    {
        if (i == num1)
        {
            c1++;
        }
        else if (i == num2)
        {
            c2++;
        }
        else if (c1 == 0)
        {
            num1 = i;
            c1 = 1;
        }
        else if (c2 == 0)
        {
            num2 = i;
            c2 = 1;
        }
        else
        {
            c1--;
            c2--;
        }
    }
    if (c1 > 0)
    {
        int count = counting(num1, nums);
        if (count > floor(nums.size() / 3))
            ans.push_back(num1);
    }
    if (c2 > 0)
    {
        int count = counting(num2, nums);
        if (count > floor(nums.size() / 3))
            ans.push_back(num2);
    }
    return ans;
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
    int n;
    cin >> n;
    vector<int> nums(n);
    int element;
    cin >> element;
    input(n, nums);
   vector<int>req= majorityElement(nums);
   for(auto i:req){
        cout << i << " ";
   }
}