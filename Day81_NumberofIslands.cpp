81. Number of Islands

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.

</>CODE:
class Solution {
public:
    void dfs(int i,int j,vector<vector<bool>>&vis,vector<vector<char>>&grid,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || grid[i][j]!='1'){
            return;
        }
        vis[i][j]=true;
        dfs(i-1,j,vis,grid,n,m); //top
        dfs(i+1,j,vis,grid,n,m); //bottom
        dfs(i,j-1,vis,grid,n,m); //left
        dfs(i,j+1,vis,grid,n,m); //right
    }
    int numIslands(vector<vector<char>>& grid) {
        int island=0;
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<bool>>vis(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(i,j,vis,grid,n,m);
                    island++;
                }
            }
        }
        return island;
    }
};
