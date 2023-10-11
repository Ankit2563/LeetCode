

    // 2009. Minimum Number of Operations to Make Array Continuous

    // You are given an integer array nums.In one operation, you can replace any element in nums with any integer.

    //                                                           nums is considered continuous if both of the following conditions are fulfilled :

    //     All elements in nums are unique.The difference between the maximum element and the minimum element in nums equals nums.length -
    //                                                           1. For example,
    //     nums = [ 4, 2, 5, 3 ] is continuous, but nums = [ 1, 2, 3, 5, 6 ] is not continuous.

    //                                                     Return the minimum number of operations to make nums continuous.

   #include <bits/stdc++.h>
    using namespace std;
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[nums[i]]++;
        }
        vector<int> v;
        for (auto i : m)
        {
            v.push_back(i.first);
        }

        int res = n;
        for (int i = 0; i < v.size(); i++)
        {
            int ub, lb = v[i];
            ub = n - 1 + lb;
            int range_limit = upper_bound(v.begin(), v.end(), ub) - v.begin();
            res = min(n - (range_limit - i), res);
        }

        return res;
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
        vector<int> v1(n);

        input(n, v1);

        cout << minOperations(v1);
    }
