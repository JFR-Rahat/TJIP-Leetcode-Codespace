// To make the largest number, the numbers with the highest digit
// sequence needs to placed first. So the numbers should be sorted
// according to the digits and not by the whole number value. The 
// number that would generate a bigger value number string should
// be ahead.

// TC = O(nlogn)
// SC = O(n)

class Solution {
public:
    static bool isLess(int &a, int &b){

        string s_a = to_string(a);
        string s_b = to_string(b);

        return (s_a + s_b) > (s_b + s_a);
    }
    string largestNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end(), isLess);
        string largestNum = "";

        if(nums[0] == 0)
            return "0";
        
        for(auto &num : nums){

            largestNum += to_string(num);
        }

        return largestNum;
    }
};