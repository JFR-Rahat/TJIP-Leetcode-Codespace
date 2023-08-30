// In order to generate all the subsets,
// an element of the array may or may not be added.
// So recursively including and excluding the elements,
// would generate all the different subsets.

// TC = O(2^n)
// SC = O(n)

class Solution {
private:
    vector<vector<int>> allSubsets;

   void createSubsets(vector<int>& nums, vector<int>& subset, int pos){

        if(pos >= nums.size()){
            allSubsets.push_back(subset);
            return;
        }

        
        subset.push_back(nums[pos]);
        createSubsets(nums, subset, pos+1);
        subset.pop_back();
        createSubsets(nums, subset, pos+1);
    }
    void createSubsets(vector<int>& nums){
        allSubsets.clear();
        vector<int> subset;
        createSubsets(nums, subset, 0);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        createSubsets(nums);
        return allSubsets;
    }
};