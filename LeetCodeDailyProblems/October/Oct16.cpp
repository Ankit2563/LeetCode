

    // 119. Pascal's Triangle II
    // Given an integer rowIndex, return the rowIndexth(0 - indexed) row of the Pascal's triangle.

    //     In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

#include <bits/stdc++.h>
    using namespace std;
    int MOD = 1000000007;
    vector<int> getRow(int numRows)
    {
        numRows++;
        vector<vector<int>> ans(numRows);
        ans[0].push_back(1);

        if (numRows == 1)
        {
            return ans[0];
        }

        for (int i = 1; i < numRows; i++)
        {
            ans[i].push_back(1);
            for (int j = 1; j < i; j++)
            {
                ans[i].push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
            }
            ans[i].push_back(1);
        }

        return ans[numRows - 1];
    }
    void input(int i, int n, vector<int> &v)
    {
        for (int k = i; k < n; k++)
        {
            cin >> v[k];
        }
    }
    int main()
    {
        int n;
        cin >>n;

        cout << getRow(n) << endl;
    }