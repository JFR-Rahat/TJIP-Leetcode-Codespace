// To decode the string it needs to be expanded
// starting from the innermost closed section.
// A section is expanded according to the number
// attached to it. A stack can be used to keep track
// of the current decoded string. A decoded string
// is appended with the new top of the stack. By repeating
// this the stack top would have the complete decoded string.

// TC = O(n*num)
// SC = O(n)

class Solution {
public:
    string decodeString(string s) {
        
        stack<pair<string, int>> stk;
        stk.push({"", 1});
        int times = 0;

        for(auto &c: s){

            if(isdigit(c)){
                times = (times * 10) + (c-'0');
            }
            else if(c == '['){
                stk.push({"", times});
                times = 0;
            }
            else if(c == ']'){
                
                string str = stk.top().first;
                int cnt = stk.top().second;
                stk.pop();

                while(cnt--){
                    stk.top().first += str;
                }
            }
            else{

                stk.top().first.push_back(c);
            }
        }

        return stk.top().first;
    }
};s