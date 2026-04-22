207. Stable Character


  
#include <bits/stdc++.h>
using namespace std;

char stableCharacter(string s) {
    int n = s.size();

    for (int i = 0; i < n; i++) {
        char ch = s[i];

        // find first and last occurrence
        int first = -1, last = -1;

        for (int j = 0; j < n; j++) {
            if (s[j] == ch) {
                if (first == -1) first = j;
                last = j;
            }
        }

        // check if all between first and last are same
        bool stable = true;
        for (int k = first; k <= last; k++) {
            if (s[k] != ch) {
                stable = false;
                break;
            }
        }

        if (stable) return ch;
    }

    return '#'; // no stable character
}
