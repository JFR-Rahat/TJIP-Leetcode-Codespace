// Since it must be solved in linear time with constant space, 
// in place inexing approach can be used to solve this. It can be 
// seen that the answer lies between 1 to n+1. So we can map the answers
// with the index of the array [0, n-1]. Now whenever we find a number
// within the range of answer we go to its mapped position in the array
// and make it negative. Doing so we can keep track of whether a number is
// present by looking at its sign. Since the negative numbers and 0's is 
// not in the answer range, we need to make them larger than the answer range,
// so that they would not interfere with the actual numbers.

// TC = O(n)
// SC = O(1)

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        for(int i=0; i<nums.size(); i++){

            if(nums[i] <= 0)
                nums[i] = nums.size() + 1;
        }
        for(int i=0; i<nums.size(); i++){

            if(abs(nums[i]) && abs(nums[i]) <= nums.size()){

                nums[abs(nums[i])-1] = - abs(nums[abs(nums[i])-1]);
            }
        }

        for(int i=0; i<nums.size(); i++){

            if(nums[i] >= 0){

                return i+1;
            }
        }
        return nums.size() + 1;
    }
};