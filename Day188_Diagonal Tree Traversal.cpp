188. Diagonal Tree Traversal
Difficulty: MediumAccuracy: 60.63%Submissions: 101K+Points: 4Average Time: 40m
Given a Binary Tree, return the diagonal traversal of the binary tree.

Consider lines of slope -1 passing between nodes. Given a Binary Tree, return a single list containing all diagonal elements in a binary tree belonging to same line.
If the diagonal element are present in two different subtrees then left subtree diagonal element should be taken first and then right subtree. 

Examples :

Input : root = [8, 3, 10, 1, 6, N, 14, N, N, 4, 7, 13]

Output : [8, 10, 14, 3, 6, 7, 13, 1, 4]
Explanation:

Diagonal Traversal of binary tree : 8 10 14 3 6 7 13 1 4
Input: root = [1, 2, N, 3, N]

Output: [1, 2, 3]
Constraints:
1 <= number of nodes<= 105
1 <= node->data <= 105

</>CODE:
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    void find(Node* root,int pos,int &l){
        if(root==NULL){
            return; 
        }
        l=max(l,pos);
        
        
        find(root->left,pos+1,l);
        find(root->right,pos,l);
    }
    void findDiagonal(Node* root,int pos,vector<vector<int>>& ans){
        if(root==NULL){
        
            return;
        }
        ans[pos].push_back(root->data);
        findDiagonal(root->left,pos+1,ans);
        findDiagonal(root->right,pos,ans);
        
    }
    vector<int> diagonal(Node *root) {
        // code here
        int l=0;
        find(root,0,l);
        
        vector<vector<int>>ans(l+1);
        findDiagonal(root,0,ans);
        vector<int>temp;
        
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                temp.push_back(ans[i][j]);
            }
        }
        return temp;
        
        
        
        
    }
};











