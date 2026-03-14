179. All Prime Numbers less than or equal to N
Moderate
80/80
Average time to solve is 10m
Contributed by
12 upvotes
Asked in companies
Problem statement
You are given a positive integer 'N'. Your task is to return all the prime numbers less than or equal to the 'N'.

Note:

1) A prime number is a number that has only two factors: 1 and the number itself.

2) 1 is not a prime number.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 100
2 <= N <= 5000

Time Limit: 1sec
Sample Input 1:
1
5
Sample Output 1:
2 3 5
Explanation for sample input 1:
2,3 and 5 are the only prime numbers less than or equal to 5.
Sample Input 2:
1
8       
Sample Output 2:
2 3 5 7
Explanation for sample input 2:
2,3,5 and 7 are the only prime numbers less than or equal to 8.

</>CODE:
#include <bits/stdc++.h> 
vector < int > findAllPrimes(int n) 
{
    // Write your code here.
    vector<bool> prime(n+1,true);

    prime[0]=prime[1]=false;
    for(int i=2;i*i<=n;i++){
        if(prime[i]==true){
            for(int j=i*i;j<=n;j+=i){
                prime[j]=false;
            }
        }
    }
    vector<int> ans;

    for(int i=2;i<=n;i++){
        if(prime[i]){
            ans.push_back(i);
        }
    }
    return ans;
}
