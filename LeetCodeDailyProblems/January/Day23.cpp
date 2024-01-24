
#include <bits/stdc++.h>
using namespace std;
int solve(int index, vector<string> &arr, set<char> se, int n)
{
    if (index >= n)
        return 0;
    int maxi1 = solve(index + 1, arr, se, n);

    bool temp = true;
    for (int i = 0; i < arr[index].size(); i++)
    {
        if (se.count(arr[index][i]))
        {
            temp = false;
            return maxi1;
        }
        se.insert(arr[index][i]);
    }

    int maxi2 = arr[index].size() + solve(index + 1, arr, se, n);
    if (temp == false)
    {
        return maxi1;
    }
    else
    {
        return max(maxi1, maxi2);
    }
}
int maxLength(vector<string> &arr)
{

    int n = arr.size();
    int ans = 0;
    set<char> se;

    ans = solve(0, arr, se, n);

    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int ans = maxLength(v);
    cout << ans  << endl;

    return 0;
}
