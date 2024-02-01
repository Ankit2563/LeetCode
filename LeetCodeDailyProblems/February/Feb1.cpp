#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> divideArray(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        int a = nums[i];
        int b = nums[++i];
        int c = nums[++i];
        if (((b - a) <= k && (c - b) <= k) && c - a <= k)
        {
            ans.push_back({a, b, c});
        }
        else
        {
            return {};
        }
    }
    return ans;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n;i++)
        cin >> a[i];

    vector<vector<int>> v = divideArray(a, k);
    return 0;
}