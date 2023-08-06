// The maximum length the longest common prefix can have
// is the minimum length of the string inside the array
// of strings. While a character is present in all the strings
// at the same position, that character is added in the longest
// common prefix string. The moment any character mismatches, the 
// lcp string will stop including any further character.

// TC = O(n^2)
// SC = O(1)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int lcpLen = 0;
        int minLen = INT_MAX / 2;

        for(auto &str : strs){
            minLen = min(minLen, (int)str.size());
        }

        bool charEqual = true;
        for(int i=0; i<minLen; i++){

            for(int j=1; j<strs.size(); j++)
                charEqual &= strs[j][i] == strs[j-1][i];

            lcpLen += charEqual;
        }

        return strs[0].substr(0, lcpLen);
    }
};
