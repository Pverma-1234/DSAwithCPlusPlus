182. Right View of Binary Tree
Given the root of a binary Tree. Your task is to return the right view of the binary tree. The right view of a Binary Tree is the set of nodes visible when the tree is viewed from the right side.

Examples :

Input: root = [1, 2, 3, N, N, 4, 5]
     2_2
Output: [1, 3, 5]
Input: root = [1, 2, 3, 4, N, N, N, N, 5]
     Right-view-in-binary-tree-1
Output: [1, 3, 4, 5]
Constraints:
1 ≤ number of nodes ≤ 105
0 ≤ node->data ≤ 105

</>CODE:
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
    vector<int> rightView(Node *root) {
        //  code here
        queue<Node*>q;
        q.push(root);
        
        vector<int>ans;
        while(!q.empty()){
            int n=q.size();
            ans.push_back(q.back()->data);
            
            while(n--){
                Node* temp=q.front();
                q.pop();
                
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        return ans;
    }
};
