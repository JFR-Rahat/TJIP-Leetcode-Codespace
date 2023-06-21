// Moving all 0's to the end of the array is same as bringing all 
// the non-zero elements to the front. Traversing the array, if we encounter
// a 0, that 0 would get replaced by the non-zero element that comes after it, not 
// necessarily immediately.

// TC = O(n)
// SC = O(1)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int posZero;
        bool lock = false;
        for(int i=0; i<nums.size(); i++){

            if(nums[i] != 0 && lock){

                swap(nums[posZero], nums[i]);
                posZero++;
            }
            else if(!lock && nums[i]==0){

                posZero = i;
                lock = true;
            }
        }
    }
};