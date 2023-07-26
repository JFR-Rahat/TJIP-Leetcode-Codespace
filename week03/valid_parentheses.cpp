// The opening brackets can be pushed insided a stack,
// and only be removed from the top after having the 
// closing bracket appear. To match each closing bracket to their
// specific opening type, their pairs should be kept. If the 
// stack become empty at the end of the string, it would mean
// it was a valid parantheses.

// TC = O(n)
// SC = O(n)

class Solution {
public:
    bool isOpeningBracket(char c){

        return c == '(' || c == '{' || c == '[';
    }
    bool isValid(string s) {
        
        unordered_map<char, char> bracketMap = {{')', '('}, {'}', '{'}, {']', '['}};
        stack<char> stk;
        for(auto &c : s){

            if(isOpeningBracket(c)){
                stk.push(c);
            }  
            else{
                
                if(stk.empty() || stk.top() != bracketMap[c])
                    return false;

                stk.pop();
            }
        }
        return stk.empty();

    }
};