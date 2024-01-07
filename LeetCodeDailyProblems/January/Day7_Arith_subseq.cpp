#include <bits/stdc++.h>
using namespace std;
int numberOfArithmeticSlices(vector<int> &nums)
{
    int n = nums.size();
    int totalCount = 0;
    vector<unordered_map<long long, int>> dp(n);

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            long long diff = (long long)(nums[i]) - nums[j];
            dp[i][diff] += 1;

            if (dp[j].find(diff) != dp[j].end())
            {
                dp[i][diff] += dp[j][diff];
                totalCount += dp[j][diff];
            }
        }
    }

    return totalCount;
}
int main()
{
    int n;
    cin >> n;
    vector<int> bank(n);
    for (int i = 0; i < n; i++)
    {
        cin >> bank[i];
    }
    int ans = numberOfArithmeticSlices(bank);
    cout << ans << endl;

    return 0;
}