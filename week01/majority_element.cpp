// Finding the majority element can be done easily using Boyer-Moore
// algorithm. The concept is, to find the majority element, we need to count
// the relative frequency of the elements. Here relative frequency would be to  
// increase the frequency of the candidate element if the same element is found 
// and decrese otherwise. When frequency of the candidate element gets to zero,
// the current element becomes the candidate element.

// TC = O(n)
// SC = O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int freq = 0, majElem;
        for(int i=0; i<nums.size(); i++){

            if(freq == 0){

                majElem = nums[i];
                freq = 1;
            }
            else{

                if(majElem == nums[i])
                    freq++;
                else
                    freq--;
            }
        }

        return majElem;
    }
};