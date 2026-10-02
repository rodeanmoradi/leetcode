class MinStack {
private:
    int min;
    stack<int> minStack;
    stack<int> minimums;

public:
    MinStack() {}

    void push(int val) {
        if (minStack.empty() or val <= min) {
            min = val;
            minimums.push(min);
        }
        minStack.push(val);
    }
    
    void pop() {
        if (minStack.top() == min) {
            minimums.pop();
            if (!minimums.empty()) min = minimums.top();
        }
        minStack.pop();
    }
    
    int top() {
        return minStack.top();
    }
    
    int getMin() {
        return min;
    }
};
