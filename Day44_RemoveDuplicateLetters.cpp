44. Remove Duplicate Letters
Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.

</>CODE:
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last(26), used(26, 0);
        for (int i = 0; i < s.size(); ++i)
            last[s[i] - 'a'] = i; 

        string result;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (used[c - 'a']) continue;

            
            while (!result.empty() && c < result.back() && last[result.back() - 'a'] > i) {
                used[result.back() - 'a'] = 0;
                result.pop_back();
            }

            result += c;
            used[c - 'a'] = 1;
        }

        return result;
    }
};
