180. Kadane's Algorithm
You are given an integer array arr[]. You need to find the maximum sum of a subarray (containing at least one element) in the array arr[].

Note : A subarray is a continuous part of an array.

Examples:

Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
Output: 11
Explanation: The subarray [7, -1, 2, 3] has the largest sum 11.
Input: arr[] = [-2, -4]
Output: -2
Explanation: The subarray [-2] has the largest sum -2.
Input: arr[] = [5, 4, 1, 7, 8]
Output: 25
Explanation: The subarray [5, 4, 1, 7, 8] has the largest sum 25.
Constraints:
1 ≤ arr.size() ≤ 105
-104 ≤ arr[i] ≤ 104

</>CODE:
class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int currentsum=0;
        int maxSum=INT_MIN;
        
        for(int i=0;i<arr.size();i++){
            currentsum+=arr[i];
            maxSum=max(maxSum,currentsum);
            
            if(currentsum<0){
                currentsum=0;
            }
        }
        return maxSum;
    }
};

