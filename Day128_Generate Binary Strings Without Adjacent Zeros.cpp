128. Generate Binary Strings Without Adjacent Zeros

You are given a positive integer n.

A binary string x is valid if all substrings of x of length 2 contain at least one "1".

Return all valid strings with length n, in any order.

 

Example 1:

Input: n = 3

Output: ["010","011","101","110","111"]

Explanation:

The valid strings of length 3 are: "010", "011", "101", "110", and "111".

Example 2:

Input: n = 1

Output: ["0","1"]

Explanation:

The valid strings of length 1 are: "0" and "1".

 
Constraints:
1 <= n <= 18

</>CODE:
class Solution {
public:
    void generate(int idx,string& s, vector<string>&res ,int pre){
        if(idx==s.size()){
            res.push_back(s);
            return;
        }
        if(pre!=0){
            s[idx]='0',pre=0;
            generate(idx+1,s,res,pre);
        }
        s[idx]='1',pre=1;
        generate(idx+1,s,res,pre);
    }

    vector<string> validStrings(int n) {
        string s(n,'\0');
        vector<string> res;
        generate(0,s,res,1);
        return res;
    }
};
