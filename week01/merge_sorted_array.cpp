// The largest numbers would be at the end of merged array. So using two pointers
// to iterate both arrays from the end and inserting the largest number between them
// into the merged array would empty out one or both of the array. The rest of the values
// can be added to merged array as they are.

// TC = O(n)
// SC = O(1)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i = m - 1, j = n - 1, k = n + m - 1;

        while(i >= 0 && j >= 0){

            if(nums1[i] > nums2[j]){

                nums1[k--] = nums1[i--];
            }
            else{

                nums1[k--] = nums2[j--];
            }
        }

        while(j>=0){

            nums1[k--] = nums2[j--];
        }
    }
};