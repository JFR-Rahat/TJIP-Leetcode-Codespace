// Sorting the intervals array in ascending order would
// bring up the intervals with smallest start value at the
// front. Now, starting off with a current interval, make it
// larger as long as the next interval overlaps with it. Then 
// add the merged intervals to the solution vector.

// TC = O(nlogn)
// SC = O(n)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> nonOverIntv;
        
        vector<int> currIntv = intervals[0];
        for(auto nextIntv : intervals){

            if(currIntv[1] >= nextIntv[0]){

                currIntv[1] = max(currIntv[1], nextIntv[1]);
            }
            else{

                nonOverIntv.push_back(currIntv);
                currIntv = nextIntv;
            }
        }

        nonOverIntv.push_back(currIntv);

        return nonOverIntv;
    }
};