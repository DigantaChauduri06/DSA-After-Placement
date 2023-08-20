class MinStack {
    vector<int> stack;
    priority_queue<int, vector<int>, greater<int>> pq; 
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stack.push_back(val);
        pq.push(val);
    }
    void _removeFromPQ(int back) {
        // cout << back << endl;
        vector<int> temp;
        // int last = INT_MIN;
        // cout << "INITIAL SIZE = " << pq.size() << endl; 
        while (!pq.empty()) {
            if (pq.top() == back) {
                pq.pop();
                // cout << "deleted" << endl;
                break;
            }
            temp.push_back(pq.top());
            pq.pop();
        }
        // cout << "LATER SIZE = " << pq.size() << endl; 
        for (auto &i : temp) {
            pq.push(i);
        }
    }
    void pop() {
        int back = stack.back();
        stack.pop_back();
        _removeFromPQ(back);
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        // cout << pq.size() << " " << stack.size() << endl;
        return pq.top();
    }
};
/*
    
*/


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */