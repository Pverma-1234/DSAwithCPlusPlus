96. Closest Prime Numbers in Range

Given two positive integers left and right, find the two integers num1 and num2 such that:

left <= num1 < num2 <= right .
Both num1 and num2 are prime numbers.
num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.
Return the positive integer array ans = [num1, num2]. If there are multiple pairs satisfying these conditions, return the one with the smallest num1 value. If no such numbers exist, return [-1, -1].

 

Example 1:

Input: left = 10, right = 19
Output: [11,13]
Explanation: The prime numbers between 10 and 19 are 11, 13, 17, and 19.
The closest gap between any pair is 2, which can be achieved by [11,13] or [17,19].
Since 11 is smaller than 17, we return the first pair.
Example 2:

Input: left = 4, right = 6
Output: [-1,-1]
Explanation: There exists only one prime number in the given range, so the conditions cannot be satisfied.
 

Constraints:

1 <= left <= right <= 106

</>CODE:
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        if (right < 2) {
            return {-1, -1};
        }

        vector<bool> isPrime(right + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= right; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= right; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        vector<int> primesInRange;
        for (int i = max(2, left); i <= right; i++) {
            if (isPrime[i]) primesInRange.push_back(i);
        }

        if (primesInRange.size() < 2) return {-1, -1};

        int minDiff = INT_MAX;
        vector<int> result = {-1, -1};

        for (int i = 1; i < primesInRange.size(); i++) {
            int diff = primesInRange[i] - primesInRange[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                result = {primesInRange[i - 1], primesInRange[i]};
            }
        }

        return result;
    }
};
