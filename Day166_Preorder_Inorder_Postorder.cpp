166. Preorder Traversal
Given the root of a binary tree, your task is to return its Preorder traversal.

Note: A preorder traversal first visits the node, then visits the left child (including its entire subtree), and finally visits the right child (including its entire subtree).

Examples:

Input: root = [1, 4, N, 4, 2]
   
Output: [1, 4, 4, 2]
Explanation: The preorder traversal of the given binary tree is [1, 4, 4, 2]
Input: root = [6, 3, 2, N, 1, 2, N]
    
Output: [6, 3, 1, 2, 2] 
Explanation: The preorder traversal of the given binary tree is [6, 3, 1, 2, 2] 
Constraints:
1 ≤ number of nodes ≤ 3*104
0 ≤ node->data ≤ 105

</>CODE:
/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    
    void pre(Node* root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        ans.push_back(root->data);
        pre(root->left,ans);
        pre(root->right,ans);
        
        
        
    }
    
    vector<int> preOrder(Node* root) {
        // code here
        vector<int>ans;
        pre(root,ans);
        return ans;
        
        
    }
};


-------------------------------------------------------------------------------------------------------------------------------------------------

2. Inorder Traversal
Given a root of a Binary Tree, your task is to return its Inorder Traversal.

Note: An inorder traversal first visits the left child (including its entire subtree), then visits the node, and finally visits the right child (including its entire subtree).

Examples:

Input: root = [1, 2, 3, 4, 5]
            
Output: [4, 2, 5, 1, 3]
Explanation: The inorder traversal of the given binary tree is [4, 2, 5, 1, 3].
Input: root = [8, 1, 5, N, 7, 10, 6, N, 10, 6]
              
Output: [1, 7, 10, 8, 6, 10, 5, 6]
Explanation: The inorder traversal of the given binary tree is [1, 7, 10, 8, 6, 10, 5, 6].
Constraints:
1 ≤ number of nodes ≤ 3*104
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
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    
    void in(Node* root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        in(root->left,ans);
        ans.push_back(root->data);
        in(root->right,ans);
    }
    
    vector<int> inOrder(Node* root) {
        // code here
        vector<int>ans;
        in(root,ans);
        return ans;
        
    }
};

----------------------------------------------------------------------------------------------------------------------------------------------------------

3. PostOrder Traversal
Given the root of a Binary Tree, your task is to return its Postorder Traversal.

Note: A postorder traversal first visits the left child (including its entire subtree), then visits the right child (including its entire subtree), and finally visits the node itself.

Examples:

Input: root = [19, 10, 8, 11, 13]

Output: [11, 13, 10, 8, 19]
Explanation: The postorder traversal of the given binary tree is [11, 13, 10, 8, 19].
Input: root = [11, 15, N, 7]
 
Output: [7, 15, 11]
Explanation: The postorder traversal of the given binary tree is [7, 15, 11].
Constraints:
1 ≤ number of nodes ≤ 3*104
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
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  
    void post(Node* root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        post(root->left,ans);
        post(root->right,ans);
        ans.push_back(root->data);
    }
    vector<int> postOrder(Node* root) {
        // code here
        vector<int>ans;
        post(root,ans);
        return ans;
    }
};
