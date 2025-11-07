109. Mansi and her series

Mansi is fond of solving mental ability questions. Today while solving some questions she came across a series which she was unable to solve. Help her to find the nth term of the series.
n  nth term
1  3
2  8
3  18
4  32
5  60
.
.
.
10  300

Example 1:

Input: n = 1
Output: 3 
Explanation: The first term of the series is 3.
Example 2:

Input: n = 2
Output: 8
Explanation: The second term of the series is 3. 

Your Task:  
You dont need to read input or print anything. Complete the function nthTerm() which takes n as input parameter and returns the nth term of the series.

Expected Time Complexity: O(nlogn)
Expected Auxiliary Space: O(n)

Constraints:
1<= n <=6000

</>CODE:
class Solution {
  public:
  bool isPrime(int n){
      if(n<=1) return false;
      for(int i=2;i*i<=n;i++){
          if(n%i==0){
              return false;
          }
      }
      return true;
  }
    int nthTerm(int n) {
        // code here
        int count=0,i=1;
        while(true){
            if(isPrime(i)) count++;
            if(count==n) break;
            i++;
        }
        return i*n + n;
        
    }
};
