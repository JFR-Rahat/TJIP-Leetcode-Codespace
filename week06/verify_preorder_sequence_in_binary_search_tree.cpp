// For the left child of any subroot, its value must be
// smaller than its subroot value and the right child's
// value must be greater than the subroot value. So, picking
// up al the elements as subroot and then recursively traversing
// to its left and right would be the preorder traversal. If the
// condition holds for all the values, then the prorder is verified
// to be true.

// TC = O(n)
// SC = O(1)

class Solution {
private:
    bool verifyPreorder(vector<int>& preorder, int &currPos, int minVal, int maxVal){

        if(currPos == preorder.size()) return true;

        int currVal = preorder[currPos];
        if(currVal < minVal || currVal > maxVal) return false;

        currPos++;
        return verifyPreorder(preorder, currPos, minVal, currVal-1) ||
                verifyPreorder(preorder, currPos, currVal+1, maxVal);
    }
public:
    bool verifyPreorder(vector<int>& preorder) {
        
        int currPos = 0;
        return verifyPreorder(preorder, currPos, INT_MIN, INT_MAX);
    }
};