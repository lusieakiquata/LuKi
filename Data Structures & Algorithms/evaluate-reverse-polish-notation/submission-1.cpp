class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0; i < tokens.size(); i++){
            char c = tokens[i][tokens[i].size()-1];
            if ( c == '-'||  c == '+' || c == '*' || c == '/'){
                int x = st.top(); st.pop();
                int y = st.top(); st.pop();
                switch (c){
                    case '-':
                        st.push( y - x );
                        break;
                    case '+':
                        st.push(y + x);
                        break;
                    case '*':
                        st.push(x*y);
                        break;
                    case '/':
                        st.push(y/x);
                        break;
                    default: break;
                    }
            }
            else
            {
            int val = stoi(tokens[i]);
            st.push(val);
            }
        }
        return st.top();
    }

};
