// Two strings would be isomorphic, if both strings can
// be converted to the other one, by mapping the 
// characters with the same characters throughout
// the string.

// TC = O(n)
// SC = O(n)


class Solution {
public:
    bool isIsomorphicOneWay(string &s, string &t){

        unordered_map<char, char> from;
        for(int i=0; i<s.size(); i++){
            
            if(from.count(s[i]) && from[s[i]] != t[i])
                return false;

            from[s[i]] = t[i];
        }

        return true;
    }

    bool isIsomorphic(string s, string t) {
        
        return isIsomorphicOneWay(s, t) && isIsomorphicOneWay(t, s);
    }
};