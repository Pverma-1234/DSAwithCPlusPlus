200.Kth largest element in BST
Given a Binary Search Tree. Your task is to complete the function which will return the kth largest element without doing any modification in the Binary Search Tree.

Examples:

Input:
      4
    /   \
   2     9
k = 2 
Output: 4
Explanation: 2nd Largest element in BST is 4
Input:
       9
        \ 
          10
k = 1
Output: 10
Explanation: 1st Largest element in BST is 10
Input:
      4
    /   \
   2     9
k = 3 
Output: 2
Explanation: 3rd Largest element in BST is 2
Constraints:
1 <= number of nodes <= 105
1 <= node->data <= 105
1 <= k <= number of nodes

</>CODE:
/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
  public:
    void KLargest(Node* root,int &ans,int &k){
        if(root==NULL){
            return;
        }
        KLargest(root->right,ans,k);
        k--;
        if(k==0){
            ans=root->data;
        }
        KLargest(root->left,ans,k);
    }
    int kthLargest(Node *root, int k) {
        // Your code here
        int ans;
        KLargest(root,ans,k);
        
        return ans;
    }
};
