class Solution {
public:
    bool isValid(string s) {
        // if string doesn't start with an open bracket
        if(s[0] != '(' && s[0] != '[' && s[0] != '{') {
            return false;
        }
        stack<char> brackets;
        for(int i = 0; i < s.size(); i++) {
            brackets.push(s[i]);
        }
        // if string isn't even-sized, it can't be made up of pairs
        if(brackets.size() % 2 != 0) {
            return false;
        }
        // if the stack's top isn't a close bracket, can't be valid
        if(brackets.top() != ')' && brackets.top() != ']' && brackets.top() != '}') {
            return false;
        }
        stack<char> new_stack;
        while(!brackets.empty()) {
            if(brackets.top() == ')' || brackets.top() == ']' || brackets.top() == '}') {
                new_stack.push(brackets.top());
                brackets.pop();
                continue;
            }
            if(brackets.top() == '(' || brackets.top() == '[' || brackets.top() == '{') {
                if(!new_stack.empty() && brackets.top() == '(' && new_stack.top() == ')') {
                    brackets.pop();
                    new_stack.pop();
                }
                else if(!new_stack.empty() && brackets.top() == '[' && new_stack.top() == ']') {
                    brackets.pop();
                    new_stack.pop();
                }
                else if(!new_stack.empty() && brackets.top() == '{' && new_stack.top() == '}') {
                    brackets.pop();
                    new_stack.pop();
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};
