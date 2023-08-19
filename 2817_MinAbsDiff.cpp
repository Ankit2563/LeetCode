// You are given a 0-indexed integer array nums and an integer x.

// Find the minimum absolute difference between two elements in the array that are at least x indices apart.

// In other words, find two indices i and j such that abs(i - j) >= x and abs(nums[i] - nums[j]) is minimized.

// Return an integer denoting the minimum absolute difference between two elements that are at least x indices apart.
// Input: nums = [5,3,2,10,15], x = 1
// Output: 1
// Explanation: We can select nums[1] = 3 and nums[2] = 2.
// They are at least 1 index apart, and their absolute difference is the minimum, 1.
// It can be shown that 1 is the optimal answer.

int minAbsoluteDifference(vector<int>& nums, int x) {
     set<int>s;
        
      
        if(nums.size()==1){
            return 0;
        }
        if(x==0)return 0;
      
     
        int ans=INT_MAX;
  
        for(int i=x;i<nums.size();i++){
            s.insert(nums[i-x]);
            auto it=s.lower_bound(nums[i]);
            if(it!=s.end()){
                
              ans=min(ans,abs(*it-nums[i]));  
              if(it!=s.begin()){
                  --it;
                  ans=min(ans,abs(*(it)-nums[i]));
              }

            }
            else{
                it--;
                ans=min(ans,abs(*it-nums[i])); 
            }
         
        
            
        }
        
        return ans;

    }
