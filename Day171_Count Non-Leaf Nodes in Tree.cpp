171. Count Non-Leaf Nodes in Tree
Given a Binary Tree of size n, your task is to return the count of all the non-leaf nodes of the given binary tree.

Example:

Input: 
Image
Output: 2
Explanation: Nodes 1 and 2 are the only non leaf nodes.
Input: 
          8
        /   \
       3     9
      / \
     1   6
        / \
       4   7
Output: 3
Explanation: Nodes 8, 3 and 6 are the only non leaf nodes.
Input: 
          10
        /    \
      5       20
     / \     /  \
    3   7   15   25
Output: 3
Explanation: Nodes 10, 5 and 20 are the only non leaf nodes.
Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105

</>CODE:

/*Structure of the node of the tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/
// you are required to complete this function
// the function should return the count of Non-Leaf Nodes
class Solution {
  public:
  
    void NonLeaf(Node* root,int &count){
        if(root==NULL){
            return;
        }
        if(root->left!=NULL || root->right!=NULL){
            count++;
            
        }
        NonLeaf(root->left,count);
        NonLeaf(root->right,count);
    }
    int countNonLeafNodes(Node* root) {
        // Code here
        int count=0;
        NonLeaf(root,count);
        return count;
        
    }
};

