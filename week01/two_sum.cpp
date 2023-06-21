// Adding two numbers that add up to target such as num1 + num2 = target, 
// can be thought of as finding the number num2, which equals to target - num1.
// So tracking whether a number same as target - num1 exists in the array would be
// able to find the solution. The tracking can be done in O(1) time using unordred_map.

// TC = O(n)
// SC = O(1)

class Solution {
public:
    vector<int> twoSum(vector<int> nums, int target) {
    
       unordered_map<int, int> numPos;

        for(int i = 0; i < nums.size(); i++){
            if(numPos.find(target - nums[i]) != numPos.end())
                return {i, numPos[target - nums[i]]};

            numPos[nums[i]] = i;
        }

        return {-1, -1};
    }
};