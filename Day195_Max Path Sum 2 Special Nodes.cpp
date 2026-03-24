195.Max Path Sum 2 Special Nodes
Given a binary tree in which each node element contains a number. Find the maximum possible path sum from one special node to another special node.

Note: Here special node is a node that is connected to exactly one different node.

Examples:

Input: root = [3, 4, 5, -10, 4, N, N]
                         
Output: 16
Explanation: Maximum Sum lies between special node 4 and 5. 4 + 4 + 3 + 5 = 16.
Input: root = [-15, 5, 6, -8, 1, 3, 9, 2, -3, 0, 4, -1, 10]


Output:  27
Explanation: The maximum possible sum from one special node to another is (3 + 6 + 9 + 0 + -1 + 10 = 27)
Input: root = [3, 4, 1, -10, 4] 

                         
Output: 12
Explanation: Maximum Sum lies between special node 4 and 5. 4 + 4 + 3 + 1 = 12.
Constraints:
2  ≤  number of nodes  ≤  104
-103  ≤ node->data ≤ 103

</>CODE:
/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int PathSum(Node *root,int &sum){
        if(root==NULL){
            return 0;
        }
        // Leaf Node
        if(root->left==NULL && root->right==NULL){
            return root->data;
        }
        
        int left=PathSum(root->left,sum);
        int right=PathSum(root->right,sum);
        
        // left and right both exist
        if(root->left && root->right){
            sum=max(sum,root->data+left+right);
            return root->data+max(left,right);
        }
        // only left exist
        if(root->left){
            return root->data+left;
        }
        // only right exist
        if(root->right){
            return root->data+right;
        }
        
        
    }
  
  
  
    int maxPathSum(Node* root) {
        // code here
        int sum=INT_MIN;
        
        // if root node he special node hai
        int val=PathSum(root,sum);
        
        if(root->left && root->right){
            return sum;
        }
        
        return max(sum,val);
        
    }
};
