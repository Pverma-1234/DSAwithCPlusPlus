229.Largest subarray with 0 sum

Given an array arr[] containing both positive and negative integers, the task is to find the length of the longest subarray with a sum equals to 0.

Note: A subarray is a contiguous part of an array, formed by selecting one or more consecutive elements while maintaining their original order.

Examples:

Input: arr[] = [15, -2, 2, -8, 1, 7, 10, 23]
Output: 5
Explanation: The longest subarray with sum equals to 0 is [-2, 2, -8, 1, 7].

Input: arr[] = [2, 10, 4]
Output: 0
Explanation: There is no subarray with a sum of 0.

Input: arr[] = [1, 0, -4, 3, 1, 0]
Output: 5
Explanation: The longest subarray with sum equals to 0 is [0, -4, 3, 1, 0]

Constraints:
1 ≤ arr.size() ≤ 106
−103 ≤ arr[i] ≤ 103

</>CODE:
class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        int sum=0;
        int maxlength=0;
        unordered_map<long long,int> mp;
        
        for(int i=0;i<arr.size();i++){
            
            sum+=arr[i];
            if(sum==0){
                maxlength=i+1;
            }
            if(mp.find(sum-0)!=mp.end()){
                int len= i - mp[sum-0];
                maxlength= max(maxlength,len);
            }
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;
            }
        }
        return maxlength;
    }
};
