// Water can be trapped in a position if there is a bar at either
// side of it, having more height than itself. So we can use two 
// pointers to keep track of trapped water from both sides of the map.
// We go to the position which has the lowest height as it has the possiblity 
// of trapping water more. Now the amount of trapped water would be difference
// between the height of that position and maximum height of the bar on that side.

// TC = O(n)
// SC = O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        
        int l = 0, r = height.size()-1, baseL = 0, baseR = 0;
        int water = 0;
        while(l < r){

            baseL = max(baseL, height[l]);
            baseR = max(baseR, height[r]);

            if(height[l] < height[r]){

                water += baseL - height[l];
                l++;
            }
            else{

                water += baseR - height[r];
                r--;
            }
        }

        return water;
    }
};