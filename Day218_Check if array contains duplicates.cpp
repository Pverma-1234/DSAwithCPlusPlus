218. Check if array contains duplicates

Given an integer array arr[], check if the array contains any duplicate value.

Examples:

Input: arr = [4, 5, 6, 4]
Output: true
Explaination: 4 is the duplicate value.
Input: arr = [1, 2, 3, 4]
Output: false
Explaination: All values are distinct.
Constraint:
1<=arr.size()<=105
0<=arr[i]<=104

</>CODE:
class Solution {
  public:
    bool checkDuplicates(vector<int> &arr) {
        // code here
        unordered_set<int>seen;
        
        for(int i=0;i<arr.size();i++){
            if(seen.find(arr[i]) != seen.end()){
                return true;
            }
            seen.insert(arr[i]);
        }
        return false;
    }
};
