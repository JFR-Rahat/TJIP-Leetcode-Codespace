// A sliding window approach can be used to solve this
// problem. Each substring of haystack as same length of 
// the needle is compared against the needle. But instead
// of comparing string to string, we'll compare their hashes.
// The benefit of using hash is that, for each new hash of 
// substring, it does not need to be calculated from scrach.
// The previous hash can be used to generate the next hash.
// The old character of the substring will be discarded from 
// the hash and the new character will be added. This would 
// make the computation of rehashing in constant time.

// TC = O(n+m)
// SC = O(1)

class Solution {
private:
    const long long BASE = 997;
    const int MOD = 1e9 + 7;

    long long calHash(string &str, int size){

        long long H = 0;
        for(int i=0; i<size; i++){

            H = ((H * BASE) + str[i]) % MOD;
        }

        return H;
    }
    
    long long calWeight(int m){

        long long weight = 1;
        for(int i=0; i<m; i++){

            weight = (weight * BASE) % MOD;
        }

        return weight;
    }
public:
    int strStr(string haystack, string needle) {
        
        int n = haystack.size();
        int m = needle.size();

        long long needHash = calHash(needle, m);
        long long hayHash = calHash(haystack, m);
        long long weight = calWeight(m) % MOD;

        for(int i=m; i<n; i++){

            if(needHash == hayHash)
                return i-m;
            
            hayHash = (hayHash * BASE) % MOD;
            hayHash = (hayHash - ((haystack[i-m] * weight)) % MOD);
            hayHash = (hayHash + ((haystack[i]) + MOD)) % MOD;
        }

        return hayHash == needHash ? n-m : -1;
    }
};