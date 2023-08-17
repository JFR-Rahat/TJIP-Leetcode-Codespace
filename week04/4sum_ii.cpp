// For 4 individual numbers to be summed to 0,
// any 2 numbers need to have sum that is equal to
// the negative sum of the other 2 numbers. That is
// a1 + a2 = - (a3 + a4). A map can be used to count
// the occurance of a sum from different elements
// and then the tuples can be calculated.

// TC = O(n^2)
// SC = O(n)


class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> pair_sum;

        for(auto &x: nums1){
            for(auto &y: nums2){
                pair_sum[x+y]++;
            }
        }

        int tuple = 0;
        for(auto &x: nums3){
            for(auto &y: nums4){
                tuple += pair_sum[-(x+y)];
            }
        }

        return tuple;
    }
};