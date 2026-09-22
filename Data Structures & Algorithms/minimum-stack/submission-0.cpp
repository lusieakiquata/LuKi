class MinStack {
public:
    int i,j;
    vector<int> stackk;
    vector<int> minst;
    MinStack() {

    }
    
    void push(int val) {
        stackk.push_back(val);
        if (minst.empty() || val <= minst[minst.size() -1]){
            minst.push_back(val);
        }
    }
    
    void pop() {


        if (!minst.empty() && minst[minst.size() -1] == stackk[stackk.size() -1]){
            minst.pop_back();
        }
                if (stackk.empty())            return;
            stackk.pop_back();
    }
    
    int top() {
        return stackk[stackk.size() - 1];
    }
    
    int getMin() {
        return minst[minst.size() -1];
        
    }
};
