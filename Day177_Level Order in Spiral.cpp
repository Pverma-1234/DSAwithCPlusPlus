177.Level Order in Spiral
Given a root binary tree and the task is to find the spiral order traversal of the tree and return the list containing the elements.
Spiral Order Traversal mean: Starting from level 0 for root node, for all the even levels we print the node's value from right to left and for all the odd levels we print the node's value from left to right.

Examples:

Input: root = [1, 3, 2]
 
Output: [1, 3, 2]
Explanation: Start with root (1), print level 0 (right to left), then level 1 (left to right).
Input: root = [10, 20, 30, 40, 60]

Output: [10, 20, 30, 60, 40]
Explanation: Start with root (10), print level 0 (right to left), level 1 (left to right), and continue alternating.
Constraints:
1  ≤ number of nodes  ≤105
0  ≤ node->data  ≤ 105

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
}; */
class Solution {
  public:
    vector<int> findSpiral(Node* root) {
        // code here
        stack<Node*>s1; // Right to Left
        stack<Node*>s2; // Left to Right 
        
        s1.push(root);
        vector<int>ans;
        
        while(!s1.empty() || !s2.empty())
        {
            if(!s1.empty())
            {
                while(!s1.empty())
                {
                    Node* temp=s1.top();
                    s1.pop();
                    ans.push_back(temp->data);
                    //right
                    if(temp->right){
                        s2.push(temp->right);
                    }
                    //left
                    if(temp->left){
                        s2.push(temp->left);
                    }
                }
            }
            else
            {
                while(!s2.empty()){
                    Node* temp=s2.top();
                    s2.pop();
                    ans.push_back(temp->data);
                    //left
                    if(temp->left){
                        s1.push(temp->left);
                    }
                    // right
                    if(temp->right){
                        s1.push(temp->right);
                    }
                }
            }
            
        }
        return ans;
        
    }
};
