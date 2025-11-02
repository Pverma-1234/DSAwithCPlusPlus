104. Count Unguarded Cells in the Grid

You are given two integers m and n representing a 0-indexed m x n grid. You are also given two 2D integer arrays guards and walls where guards[i] = [rowi, coli] and walls[j] = [rowj, colj] represent the positions of the ith guard and jth wall respectively.

A guard can see every cell in the four cardinal directions (north, east, south, or west) starting from their position unless obstructed by a wall or another guard. A cell is guarded if there is at least one guard that can see it.

Return the number of unoccupied cells that are not guarded.

 

Example 1:


Input: m = 4, n = 6, guards = [[0,0],[1,1],[2,3]], walls = [[0,1],[2,2],[1,4]]
Output: 7
Explanation: The guarded and unguarded cells are shown in red and green respectively in the above diagram.
There are a total of 7 unguarded cells, so we return 7.
Example 2:


Input: m = 3, n = 3, guards = [[1,1]], walls = [[0,1],[1,0],[2,1],[1,2]]
Output: 4
Explanation: The unguarded cells are shown in green in the above diagram.
There are a total of 4 unguarded cells, so we return 4.
 

Constraints:

1 <= m, n <= 105
2 <= m * n <= 105
1 <= guards.length, walls.length <= 5 * 104
2 <= guards.length + walls.length <= m * n
guards[i].length == walls[j].length == 2
0 <= rowi, rowj < m
0 <= coli, colj < n
All the positions in guards and walls are unique.

</>CODE:
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        auto hash = [n](int r, int c) { return (long long)r * n + c; };
        unordered_set<long long> guardSet, wallSet, guarded;
        
        for (auto &g : guards) guardSet.insert(hash(g[0], g[1]));
        for (auto &w : walls) wallSet.insert(hash(w[0], w[1]));
        
        vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        for (auto &g : guards) {
            int r = g[0], c = g[1];
            for (auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                while (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    long long key = hash(nr, nc);
                    if (guardSet.count(key) || wallSet.count(key)) break;
                    guarded.insert(key);
                    nr += dr;
                    nc += dc;
                }
            }
        }
        
        
        int total = m * n - guards.size() - walls.size();
        int unguarded = total - guarded.size();
        return unguarded;
    }
};
