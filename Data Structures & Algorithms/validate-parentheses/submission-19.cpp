class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 != 0) {
            return false;
        }
        if(s[0] != '(' && s[0] != '[' && s[0] != '{') {
            return false;
        }
        stack<char> my_stack;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{' ) {
                my_stack.push(s[i]);
                continue;
            }
            if(!my_stack.empty() && s[i] == ')' && (my_stack.top() == '(')) {
                my_stack.pop();
                continue;
            }
            else if(!my_stack.empty() && s[i] == ']' && (my_stack.top() == '[')) {
                my_stack.pop();
                continue;
            }
            else if(!my_stack.empty() && s[i] == '}' && (my_stack.top() == '{')) {
                my_stack.pop();
                continue;
            }
            else {
                return false;
            }
        }
        return my_stack.empty();
    }
};
