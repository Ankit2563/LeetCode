
#include <bits/stdc++.h>
using namespace std;
vector<int> findErrorNums(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<int> ans;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            ans.push_back(nums[i]);
            break;
        }
    }
    int init = 1;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == init)
        {
            if (nums[i] == nums[i + 1])
            {
                i++;
            }
        }
        else
        {
            ans.push_back(init);
            break;
        }
        init++;
    }
    if (ans.size() == 1)
    {
        if (init == nums[nums.size() - 1])
        {
            ans.push_back(init + 1);
        }
        else
        {
            ans.push_back(init);
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

      vector<int>ans=findErrorNums(v);
      cout << ans[0] << " " << ans[1] << endl;
      
      return 0;
}
