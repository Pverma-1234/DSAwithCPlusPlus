162.Sort a String
Given a string consisting of lowercase letters, arrange all its letters in ascending order. 

Example 1:

Input:
S = "edcab"
Output: "abcde"
Explanation: characters are in ascending
order in "abcde".
Example 2:

Input:
S = "xzy"
Output: "xyz"
Explanation: characters are in ascending
order in "xyz".


Your Task:  
You don't need to read input or print anything. Your task is to complete the function sort() which takes the string as inputs and returns the modified string.

Expected Time Complexity: O(|S| * log |S|)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ |S| ≤ 105
S contains only lowercase alphabets.

</>CODE:

string sort(string s) {
    // complete the function here
    
    vector<int> alpha(26,0);
    for(int i=0;i<s.size();i++){
        int index = s[i] - 'a';
        alpha[index]++;
    }
    string ans;
    for(int i=0;i<26;i++){
        char c = 'a' + i;
        while(alpha[i]){
            ans+=c;
            alpha[i]--;
        }
    }
    return ans;
}
