// Two strings can be anagram if their hashes are equal.
// By generating all the hashes for the strings in the array,
// we can check which of the strings can be anagram that is 
// having the exact same hash.

// TC = O(n^2)
// SC = O(n)

class Solution {
public:
    long long calHash(string &str){

        long long H = 1;
        static int BASE = 997;
        static int MOD = 1e9 + 7;

        for(auto &c: str){

            H = (H * (BASE + c)) % MOD;
        }

        return H;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> anagrams;
        unordered_map<long long, vector<string>> hashToString;

        for(auto &str: strs){

            long long strHash = calHash(str);
            hashToString[strHash].push_back(str);
        }

        for(auto it: hashToString){

            anagrams.push_back(it.second);
        }

        return anagrams;
    }
};