237. Spiral Matrix

Given an m x n matrix, return all elements of the matrix in spiral order.

 Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

</>CODE:
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        vector<int>ans;

        int srow=0;
        int ecol=n-1;
        int scol=0;
        int erow=m-1;


        while(srow<=erow && scol <=ecol){
            // top
            for(int j=scol;j<=ecol;j++){
                ans.push_back(matrix[srow][j]);
            }

            // right
            for(int i=srow+1;i<=erow;i++){
                ans.push_back(matrix[i][ecol]);
            }

            // bottom
            for(int j=ecol-1;j>=scol;j--){
                if(srow==erow){
                    break;
                }
                ans.push_back(matrix[erow][j]);
            }

            // left
            for(int i=erow-1;i>=srow+1;i--){
                if(scol==ecol){
                    break;
                }
                ans.push_back(matrix[i][scol]);
            }
            srow++;erow--;scol++;ecol--;


        }
        return ans;
    }
};
