211.Sum of Left Leaf Nodes
Given a Binary Tree. Find the sum of all the leaf nodes that are left child of their parent of the given binary tree.

Examples:

Input:
       1
     /   \
    2     3
Output: 2
Input : 
         1
        /  \
       2    3
     /  \     \
    4    5     8 
  /  \        /  \
 7    2      6    9
Output: 13
Explanation: sum = 6 + 7 = 13
Input: 1
Output: 0
Explanation: There is no leaf node, so sum is 0.
Constraints:
1 <= number of nodes <=106
1 <= node->data <=105
It is guaranteed that sum will not exceed integer max value

</>CODE:
/*Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/
// function should return the sum of all
// left leaf nodes
class Solution {
  public:
  
    bool isLeave(Node* root){
        return root && root->left==NULL && root->right==NULL;
    }
    int leftLeavesSum(Node *root) {
        // Code here
        if(root==NULL){
            return 0;
        }
        int sum=0;
        
        if(isLeave(root->left)){
            sum+=root->left->data;
        }else{
            sum+=leftLeavesSum(root->left);
        }
        
        sum+=leftLeavesSum(root->right);
        
        return sum;
        
        
    }
};
