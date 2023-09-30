// 2870. Minimum Number of Operations to Make Array Empty

// You are given a 0 - indexed array nums consisting of positive integers.

//                     There are two types of operations that you can apply on the array any number of times :

//     Choose two elements with equal values and delete them from the array.Choose three elements with equal values and delete them from the array.Return the minimum number of operations required to make the array empty,
//     or -1 if it is not possible.

#include <bits/stdc++.h>
    using namespace std;

int minOperations(vector<int> &nums)
    {
        int n = nums.size(), t = 0;
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[nums[i]]++;
        }

        priority_queue<pair<int, int>> q;
        for (auto i : m)
        {
            q.push({i.second, i.first});
        }
        int o = 0;
        while (!q.empty())
        {
            pair<int, int> p = q.top();
            if (p.first == 1)
            {
                return -1;
            }
            else
            {
                int thd = p.first / 3, thr = p.first % 3;
                int twd = p.first / 2, twr = p.first % 2;
                if (thr == 0)
                {
                    o += thd;
                }
                else
                {
                    if (thr == 1)
                    {
                        o += thd - 1 + 2;
                    }
                    else if (thr == 2)
                    {
                        o += thd + 1;
                    }
                }
            }
            q.pop();
        }
        return o;
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
    cout << minOperations(nums) << endl;
}
