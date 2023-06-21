// The solution needs to be in linear runtime and with constant 
// space. So the single element must be found while iterating over
// the array. Since all the rest of the elements appear twice, applying
// logical X-OR on the array would eliminate them as X-OR gives 0, for the 
// same two element. This would leave out the single element from the whole
// array.

// TC = O(n)
// SC = O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int ans = 0;
        for(auto num: nums){
            ans ^= num;
        }
        return ans;
    }
};