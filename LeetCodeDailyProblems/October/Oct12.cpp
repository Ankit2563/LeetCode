// 1095. Find in Mountain Array
/*

(This problem is an interactive problem.)

You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target. If such an index does not exist, return -1.

You cannot access the mountain array directly. You may only access the array using a MountainArray interface:

MountainArray.get(k) returns the element of the array at index k (0-indexed).
MountainArray.length() returns the length of the array.
Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer. Also, any solutions that attempt to circumvent the judge will result in disqualification.


*/

#include <bits/stdc++.h>
using namespace std;

 class MountainArray
{
    public:
    vector<int> v;

    public : 
    
    
    void MakeMountain(int n){
        cout << "Enter Array Element :";
        for (int i = 0; i < n;i++){
            int a;
            cin >> a;
            v.push_back(a);
        }
    }
    int get(int index){
        return v[index];
    }
    int length(){
        return v.size();
    }
    int findInMountainArray(int target, MountainArray &m)
    {
        int n = m.length();
        int s = 0, e = n - 1, mid;
        while (s <= e)
        {
            mid = s + (e - s) / 2;
            int val1 = m.get(mid);
            int val2 = m.get(mid + 1);
            if (val1 < val2)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        //  return mid;
        if (m.get(mid) == target)
            return mid;
        int s1 = 0, e1 = mid - 1, mid1;
        int s2 = mid + 1, e2 = n - 1, mid2;
        while (s1 <= e1)
        {
            mid1 = s1 + (e1 - s1) / 2;
            int val2 = m.get(mid1);
            if (val2 == target)
            {
                return mid1;
            }
            else if (val2 > target)
            {
                e1 = mid1 - 1;
            }
            else
            {
                s1 = mid1 + 1;
            }
        }
        while (s2 <= e2)
        {
            mid2 = s2 + (e2 - s2) / 2;
            int val2 = m.get(mid2);
            if (val2 == target)
            {
                return mid2;
            }
            else if (val2 < target)
            {
                e2 = mid2 - 1;
            }
            else
            {
                s2 = mid2 + 1;
            }
        }
        return -1;
    }
};
int main()
{
    MountainArray arr;
    int n;
    cout << "Enter the size of mountain" << endl;
    cin >> n;
    arr.MakeMountain(n);
    int target;
    cout << "Enter the target : " << endl;
    cin >> target;

   int no= arr.findInMountainArray(target, arr);
   cout << no << endl;
}
