185.Construct Tree from Inorder & Preorder
Given two arrays representing the inorder and preorder traversals of a binary tree, your task is to construct the binary tree and return its root.

Note: The inorder and preorder traversals contain unique values, and every value present in the preorder traversal is also found in the inorder traversal.

Examples:

Input: inorder[] = [3, 1, 4, 0, 5, 2], preorder[] = [0, 1, 3, 4, 2, 5]
Output: [0, 1, 2, 3, 4, 5]
Explanation: The tree will look like

Input: inorder[] = [2, 5, 4, 1, 3], preorder[] = [1, 4, 5, 2, 3]
Output: [1, 4, 3, 5, N, N, N, 2]
Explanation: The tree will look like

Constraints:
1 ≤ number of nodes ≤ 103
0 ≤ nodes -> data ≤ 103
Both the inorder and preorder arrays contain unique values

</>CODE:
/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int find(vector<int> &inorder,int target,int start,int end){
        for(int i=start;i<=end;i++){
            if(inorder[i]==target){
                return i;
            }
        }
        return -1;
    }
    
    Node *Tree(vector<int> &inorder,vector<int> &preorder, int instart,int inend,int &index){
        if(instart>inend){
            return NULL;
        }
        
        Node* root = new Node(preorder[index++]);
        int pos = find(inorder,root->data,instart,inend);
        
        // left
        root->left=Tree(inorder,preorder,instart,pos-1,index);
        
        // right
        root->right=Tree(inorder,preorder,pos+1,inend,index);
        
        return root;
        
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        int n=inorder.size();
        int index=0;
        Tree(inorder,preorder,0,n-1,index);
        
    }
};
