226. Max Consecutive Ones

Given a binary array nums, return the maximum number of consecutive 1's in the array.

 

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 2
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.

</>CODE:
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int currcount=0;
        int maxcount=0;
        int i=0;
        while(i<nums.size()){
            if(nums[i]==1){
                currcount++;
            }else{
                maxcount=max(maxcount,currcount);
                currcount=0;
            }
            i++;
        }
        return max(maxcount,currcount);
        
    }
};
