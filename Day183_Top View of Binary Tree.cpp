183. Top View of Binary Tree
You are given the root of a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

Note:

Return the nodes from the leftmost node to the rightmost node.
If multiple nodes overlap at the same horizontal position, only the topmost (closest to the root) node is included in the view. 
Examples:

Input: root = [1, 2, 3]
Output: [2, 1, 3]
Explanation: The Green colored nodes represents the top view in the below Binary tree.
 
Input: root = [10, 20, 30, 40, 60, 90, 100]
Output: [40, 20, 10, 30, 100]
Explanation: The Green colored nodes represents the top view in the below Binary tree.


Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105

</>NODE:
/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    void find(Node* root,int pos,int &l,int &r){
        if(root==NULL){
            return;
        }
        l=min(pos,l);
        r=max(pos,r);
        find(root->left,pos-1,l,r);
        find(root->right,pos+1,l,r);
    }
    vector<int> topView(Node *root) {
        // code here
        int l=0,r=0;
        find(root,0,l,r);
        
        vector<int>ans(r-l+1);
        vector<bool>filled(r-l+1,0);
        
        queue<Node*>q;
        q.push(root);
        
        queue<int>index;
        index.push(-1*l);
        
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
            
            int pos=index.front();
            index.pop();
            
            if(!filled[pos]){
                filled[pos]=1;
                ans[pos]=temp->data;
            }
            
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
