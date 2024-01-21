#include<bits/stdc++.h>
using namespace std;
int solve(int index,int m,int pow2,bool temp){
    if(index==1&&m==1&&temp==true){
        return 4;
    }
    if(index==m){
        
        if(pow2==1){
            return 2 ;
        }

        return 1;
    }
    if(index==m+1&&temp==true)
        return 1;
    if(index>m)
        return 0;
    int maxi1, maxi2 ;
    if (temp==true){
        
        int newIndex = index + (int)pow(2, pow2);
        maxi2 = solve(newIndex, m, pow2 + 1, true);
        
        maxi1=solve(index - 1, m, pow2, false);
    }
    else{
        maxi1 = 0;
        int newIndex = index + (int)pow(2, pow2);
        maxi2= solve(newIndex, m, pow2 + 1, true);
    }
    return maxi1 + maxi2;
}

int main()
{
    int m;
    cin >> m;

    cout << solve(1, m,0,true)<<endl;
    

    return 0;
}