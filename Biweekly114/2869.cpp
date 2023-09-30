// 2869. Minimum Operations to Collect Elements
    // You are given an array nums of positive integers and an integer k.

    //     In one operation,
    //     you can remove the last element of the array and add it to your collection.

    //     Return the minimum number of operations needed to collect elements 1,
    //     2, ..., k.

#include<bits/stdc++.h>
using namespace std;

int minOperations(vector<int> &nums, int k)
{
    int t = 0;
    set<int> st;
    set<int> st1;

    for (int i = 0; i < k; i++)
    {
        st.insert(i + 1);
    }
    int count = 0;

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (st == st1)
        {
            return count;
        }
        if (st.count(nums[i]))
        {
            st1.insert(nums[i]);
        }
        count++;
    }

    return count;
}


int main(){
    int k;
    cin >> k;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++){
        cin >> nums[i];
    }
    cout << minOperations(nums, k) << endl;
}
