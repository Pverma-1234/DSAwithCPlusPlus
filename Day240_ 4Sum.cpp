240. 4Sum

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109

</>CODE:

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int l1=i+1;l1<n-2;l1++){
                if(l1>i+1 && nums[l1]==nums[l1-1]){
                    continue;
                }
                int l2=l1+1,r=n-1;
                while(l2 < r){
                    long long sum=(long long)nums[i]+nums[l1]+nums[l2]+nums[r];
                    if(sum==target){
                        ans.push_back({nums[i],nums[l1],nums[l2],nums[r]});
                        while(l2<r && nums[l2]==nums[l2+1]) l2++;
                        while(l2<r && nums[r]==nums[r-1]) r--;
                    
                        l2++;
                        r--;
                    }else if(sum<target){
                        l2++;
                    }else{
                        r--;
                    }
                }
                    
            }
        }
        return ans;
        
    }
};
