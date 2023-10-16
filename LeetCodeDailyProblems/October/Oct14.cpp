

    // 2742. Painting the Walls

    //     You are given two 0 -
    // indexed integer arrays,
    // cost and time, of size n representing the costs and the time taken to paint n different walls respectively.There are two painters available :

    // A paid painter that paints the ith wall in time[i] units of time and takes cost[i] units of money.A free painter that paints any wall in 1 unit of time at a cost of 0. But the free painter can only be used if the paid painter is already occupied.Return the minimum amount of money required to paint the n walls.
#include <bits/stdc++.h>
    using namespace std;

    int dp[501][501];
    int maxi = INT_MAX;
    int funct(int idx, int select, int remTime, vector<int> &cost, vector<int> &time)
    {
        if (remTime <= 0)
            return 0;
        if (idx == cost.size())
            return INT_MAX / 2;

        if (dp[idx][remTime] != -1)
            return dp[idx][remTime];
        // dp[select][currTime]=
        int b = funct(idx + 1, select + 1, remTime - time[idx] - 1, cost, time);
        int a = 0 + funct(idx + 1, select, remTime, cost, time);
        if (b != INT_MAX / 2)
            b += cost[idx];
        return dp[idx][remTime] = min(a, b);
    }
    int paintWalls(vector<int> &cost, vector<int> &time)
    {
        //[42,8,28,35,21,13,21,35]

        //[2,1,1,1,2,1,1,2]
        memset(dp, -1, sizeof(dp));
        int currTime = 0;
        return funct(0, 0, cost.size(), cost, time);
    }
    void input(int i, int n,vector<int>&v){
        for (int k = i; k < n;k++){
            cin >> v[k];
        }
    } 
    int main()
    {
        int n;
        cin >> n;
        vector<int> cost(n);
        vector<int> time(n);
        input(0, n, cost);
        input(0, n, time);

        cout << paintWalls(cost,time) << endl;
    }
