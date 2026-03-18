184.Bottom View of Binary Tree
You are given the root of a binary tree, and your task is to return its bottom view. The bottom view of a binary tree is the set of nodes visible when the tree is viewed from the bottom.

Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level order traversal is considered.

Examples :

Input: root = [1, 2, 3, 4, 5, N, 6]
    
Output: [4, 2, 5, 3, 6]
Explanation: The Green nodes represent the bottom view of below binary tree.
    
Input: root = [20, 8, 22, 5, 3, 4, 25, N, N, 10, 14, N, N, 28, N]
    
Output: [5, 10, 4, 28, 25]
Explanation: The Green nodes represent the bottom view of below binary tree.
    
Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105

</>CODE:
/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void find(Node* root,int pos,int& l,int &r){
        if(root==NULL){
            return;
        }
        l=min(pos,l);
        r=max(pos,r);
        find(root->left,pos-1,l,r);
        find(root->right,pos+1,l,r);
    }
    vector<int> bottomView(Node *root) {
        // code here
        int l=0,r=0;
        find(root,0,l,r);
        vector<int>ans(r-l+1);
        
        queue<Node*>q;
        q.push(root);
        
        queue<int>index;
        index.push(-1*l);
        
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
            int pos=index.front();
            index.pop();
            
            
            ans[pos]=temp->data;
            
            if(temp->left){
                q.push(temp->left);
                index.push(pos-1);
            }
        
            if(temp->right){
                q.push(temp->right);
                index.push(pos+1);
            }
        }
        return ans;
        
        
        
        

    }
};
