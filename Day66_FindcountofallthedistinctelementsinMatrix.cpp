66. Given a N x N matrix M. Write a program to find count of all the distinct elements common to all rows of the matrix. Print count of such elements.

Example 1:

Input: 
N = 4
M = {{2, 1, 4, 3},
     {1, 2, 3, 2},
     {3, 6, 2, 3},
     {5, 2, 5, 3}}
Output: 
2
Explaination: Only 2 and 3 are common in all rows.
Example 2:

Input: 
N = 5
M = {{12, 1, 14, 3, 16},
     {14, 2, 1, 3, 35},
     {14, 1, 14, 3, 11},
     {14, 5, 3, 2, 1},
     {1, 18, 3, 21, 14}}
Output: 
3
Explaination: 14, 3 and 1 are common in all the rows.
Your Task:
You do not need to read input or print anything. Your task is to complete the function distinct() which takes the matrix and n as input parameters and returns the number of distinct elements present in every row.

Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 100
1 ≤ M[i][j] ≤ 1000

</>CODE:
// User function Template for C++

class Solution {
  public:
    int distinct(vector<vector<int>> M, int N) {
        int cnt = 0;
        set<int> s;

        
        for(int k = 0; k < N; k++){
            s.insert(M[0][k]);
        }
        
       
        for(auto x : s){
            int check[N] = {1};  
                    

            for(int i = 1; i < N; i++){
                for(int j = 0; j < N; j++){
                    if(M[i][j] == x){
                        check[i] = 1;   
                    }
                }
            }

            int c = 0;
            for(int i = 0; i < N; i++){
                if(check[i] == 1){
                    c++;
                }
            }

            if(c == N){   
                cnt++;
            }
        }
        
        return cnt;
    }
};
