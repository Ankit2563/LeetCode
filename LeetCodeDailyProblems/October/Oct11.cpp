


    // 2251. Number of Flowers in Full Bloom

    // You are given a 0 - indexed 2D integer array flowers, where flowers[i] = [ starti, endi ] means the ith flower will be in full bloom from starti to endi(inclusive).You are also given a 0 - indexed integer array people of size n, where people[i] is the time that the ith person will arrive to see the flowers.

    //                                                                                                                                                                                                                                      Return an integer array answer of size n,
    //      where answer[i] is the number of flowers that are in full bloom when the ith person arrives.
#include <bits/stdc++.h>
    using namespace std;

    vector<int> fullBloomFlowers(vector<vector<int>> &f, vector<int> &p)
    {
        sort(f.begin(), f.end());
        vector<int> arv;
        vector<int> dep;
        for (int i = 0; i < f.size(); i++)
        {
            arv.push_back(f[i][0]);
            dep.push_back(f[i][1]);
        }
        sort(arv.begin(), arv.end());
        sort(dep.begin(), dep.end());
        int n = p.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {

            int idx1 = upper_bound(arv.begin(), arv.end(), p[i]) - arv.begin();
            int idx2 = lower_bound(dep.begin(), dep.end(), p[i]) - dep.begin();
            ans.push_back(abs(idx2 - idx1));
        }

        return ans;
    }

    int main()
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> flower(n,vector<int>(2));
        vector<int> person;
        for (int i = 0; i < n;i++){
            cin >> flower[i][0] >> flower[i][1];
            
        }
        for (int i = 0; i < m;i++){
            cin >> person[i];
        }

        vector<int> ans = fullBloomFlowers(flower, person);
        for (int i = 0; i < ans.size();i++){
            cout << person[i] << " ";
        }
        cout << endl;
    }
