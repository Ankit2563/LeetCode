#include <bits/stdc++.h>
using namespace std;
int minOperations(vector<int> &nums)
{
    int op = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        int cnt = 0, num = nums[i];
        while (i < nums.size() && nums[i] == num)
        {
            cnt++;
            i++;
        }
        if (cnt == 1)
            return -1;
        else
        {
            if (cnt % 3 == 0)
            {
                op += cnt / 3;
            }
            else if (cnt % 3 == 1 || cnt % 3 == 2)
            {
                op += (cnt / 3) + 1;
            }
        }
        i--;
    }
    return op;
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
     int ans = minOperations(bank);
     cout << ans << endl;

     return 0;
}