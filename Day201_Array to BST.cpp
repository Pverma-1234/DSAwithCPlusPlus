201.Array to BST
Given a sorted array arr[]. Convert it into a Height Balanced Binary Search Tree (BST) and return the root of the BST.

Height-balanced BST means a binary tree in which the depth of the left subtree and the right subtree of every node never differ by more than 1.

Note: You can return any BST, the driver code will check the BST, and print true if it is a Height-balanced BST else print false.

Examples :

Input: arr[] = [10, 20, 30]
Output: true
Explanation: Only possible Height Balanced BST will be [20, 10, 30]
 
Input: arr[] = [1, 5, 9, 14, 23, 27]
Ouput: true
Explanation: One of the possible Height Balanced BST will be [9, 1, 23, N, 5, 14, 27]

Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105

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
    Node* ArrayToBST(vector<int> &arr,int start,int end){
        if(start>end){
            return NULL;
        }
        int mid= start+(end-start)/2;
        Node* root = new Node(arr[mid]);
        root->left=ArrayToBST(arr,start,mid-1);
        root->right=ArrayToBST(arr,mid+1,end);
        
        return root;
    }
    Node* sortedArrayToBST(vector<int>& arr) {
        // code here
        return ArrayToBST(arr,0,arr.size()-1);
        
    }
};
