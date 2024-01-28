
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int k)
{
    map<int, int> mp;
    mp[0] = 1;
    int sum = 0, ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        ans += mp[sum - k];
        mp[sum]++;
    }
    return ans;
}

int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
{

    int count = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        vector<int> prefSum(matrix[i].size(), 0);
        for (int j = i; j < matrix.size(); j++)
        {
            for (int k = 0; k < matrix[j].size(); k++)
            {
                prefSum[k] += matrix[j][k];
            }
            count += solve(prefSum, target);
        }
    }
    return count;
}
int main()
{
    int n,m,k;
    cin >> n>>m>>k;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    cout << numSubmatrixSumTarget(v,k);

    return 0;
}
