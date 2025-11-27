133. Maximum Subarray Sum With Length Divisible by K

You are given an array of integers nums and an integer k.

Return the maximum sum of a subarray of nums, such that the size of the subarray is divisible by k.

 

Example 1:

Input: nums = [1,2], k = 1

Output: 3

Explanation:

The subarray [1, 2] with sum 3 has length equal to 2 which is divisible by 1.

Example 2:

Input: nums = [-1,-2,-3,-4,-5], k = 4

Output: -10

Explanation:

The maximum sum subarray is [-1, -2, -3, -4] which has length equal to 4 which is divisible by 4.

Example 3:

Input: nums = [-5,1,2,-3,4], k = 2

Output: 4

Explanation:

The maximum sum subarray is [1, 2, -3, 4] which has length equal to 4 which is divisible by 2.

 

Constraints:

1 <= k <= nums.length <= 2 * 105
-109 <= nums[i] <= 109

</>CODE:
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> bestMin(k, LLONG_MAX);
        
        long long prefix = 0;
        long long ans = LLONG_MIN;

        // prefix index 0 -> mod 0 has value 0
        bestMin[0] = 0;

        for (int i = 1; i <= n; i++) {
            prefix += nums[i - 1];
            int mod = i % k;

            if (bestMin[mod] != LLONG_MAX)
                ans = max(ans, prefix - bestMin[mod]);

            bestMin[mod] = min(bestMin[mod], prefix);
        }

        return ans;
    }
};
