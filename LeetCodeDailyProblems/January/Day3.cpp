#include<bits/stdc++.h>
using namespace std;

int numberOfBeams(vector<string> &bank)
{

    vector<int> v;
    for (int i = 0; i < bank.size(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < bank[i].size(); j++)
        {
            if (bank[i][j] == '1')
            {
                cnt++;
            }
        }
        if (cnt != 0)
        {
            v.push_back(cnt);
        }
    }
    int ans = 0;
    if (v.size() >= 2)
    {
        for (int i = 0; i < v.size() - 1; i++)
        {
            ans += (v[i] * v[i + 1]);
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> bank(n);
    for (int i = 0; i < n;i++){
        cin >> bank[i];
    }
    cout << numberOfBeams(bank) << endl;

    return 0;
}