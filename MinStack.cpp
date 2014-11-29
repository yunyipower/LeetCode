class MinStack {
private:
    stack<int> data_stack_;
    stack<int> min_stack_;

public:
    MinStack(){
    }
    
    void push(int x) {
        data_stack_.push(x);
	if(min_stack_.empty() || x<=min_stack_.top()) min_stack_.push(x);
    }

    void pop() {
	int popdata = data_stack_.top();
	data_stack_.pop();
	if(popdata==min_stack_.top()) min_stack_.pop();
    }

    int top() {
	return data_stack_.top();
    }

    int getMin() {
	return min_stack_.top();
    }
};
