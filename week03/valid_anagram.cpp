// The two string will be anagram if their character set is equal.
// Using hasing the character sets can be matched in linear time.
// We can apply multiplication on the whole character set to generate
// a result that is unique to that set. So if both string generate the 
// same result, then they will be anagram.

// TC = O(n)
// SC = O(n)

class Solution {
public:
    long long calHash(string& str){

        long long H = 1;
        static int BASE = 997;
        static int MOD = 1e9 + 7;

        for(auto &c: str){

            H = (H * (BASE + c)) % MOD;
        }

        return H;
    }

    bool isAnagram(string s, string t) {
        
        return calHash(s) == calHash(t);
    }
};