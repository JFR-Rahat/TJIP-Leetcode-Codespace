// A valid combination will not have closing
// parenthesis unless the number of opening parentheses
// prior to it is greater than the closing parentheses.
// And also, the opening parentheses can be maximum n.
// So recursively including and excluding the opening
// and closing parentheses would generate all the valid
// parentheses combinations.

// TC = O(n * C_n) = n * (nCr(2n, n) / (n+1))
// SC = O(n)


class Solution {
private:
    vector<string> combinations;
    string combination;

    void generateCombinations(int open, int close, int n){
        if(open == close && open == n){
            combinations.push_back(combination);
            return;
        }

        if(open < n){
            combination.push_back('(');
            generateCombinations(open+1, close, n);
            combination.pop_back();a
        }

        if(open > close){
            combination.push_back(')');
            generateCombinations(open, close+1, n);
            combination.pop_back();
        }
    }
    void generateCombinations(int n){
        combinations.clear();
        combination.clear();
        generateCombinations(0, 0, n);
    }
public:
    vector<string> generateParenthesis(int n) {
        generateCombinations(n);
        return combinations;
    }
};