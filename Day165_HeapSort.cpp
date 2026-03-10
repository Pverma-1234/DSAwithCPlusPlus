165. Heap Sort
Given an array arr[]. The task is to sort the array elements by Heap Sort.

Examples:

Input: arr[] = [4, 1, 3, 9, 7]
Output: [1, 3, 4, 7, 9]
Explanation: After sorting elements using heap sort, elements will be in order as 1, 3, 4, 7, 9.
Input: arr[] = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
Explanation: After sorting elements using heap sort, elements will be in order as 1, 2, 3, 4, 5, 6, 7, 8, 9, 10.
Input: arr[] = [2, 1, 5]
Output: [1, 2, 5]
Explanation: After sorting elements using heap sort, elements will be in order as 1, 2, 5.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 106

</>CODE:


class Solution {
  public:
    void heapfy(vector<int>&arr , int n,int i){
        int parent=i;
        int left=2*i+1;
        int right=2*i+2;
        
        if(left<n && arr[left]>arr[parent]){
            parent=left;
        }
        if(right<n && arr[right]>arr[parent]){
            parent=right;
        }
        if(parent!=i){
            swap(arr[i],arr[parent]);
            heapfy(arr,n,parent);
        }
        
    }
    void heapSort(vector<int>& arr) {
        // code here
        int n=arr.size();
        for(int i=n/2;i>=0;i--){
            heapfy(arr,n,i);
        }
        
        for(int i=n-1;i>=0;i--){
            swap(arr[0],arr[i]);
            heapfy(arr,i,0);
        }
        
    }
};
