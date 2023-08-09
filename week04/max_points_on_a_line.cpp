// All the points having the same slope value
// lies on the same line. So for each points,
// counting every possible slope and then
// we can figure out the maximum number of
// points through this. 

// TC = O(n^2logn)
// SC = O(n)

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        map<pair<int, int>, int> slope_points;
        int maxPoints = 0;

        for(int i=0; i<points.size(); i++){
            slope_points.clear();

            for(int j=i+1; j<points.size(); j++){

                int dy = points[j][1] - points[i][1];
                int dx = points[j][0] - points[i][0];

                int gcd = __gcd(dy, dx);
                dy /= gcd;
                dx /= gcd;

                slope_points[{dx, dy}]++;
            }

            for(auto &slope: slope_points){
                maxPoints = max(maxPoints, slope.second);
            }
        }

        return maxPoints + 1;
    }
};
