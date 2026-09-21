class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
std::unordered_map<char, int> doi = {
    {'[', 0}, {']', 1}, {'{', 2}, {'}', 3}, {'(', 4}, {')', 5}
};
        for(int i =0; i< s.size(); i++){
            if (!st.empty() && ((st.top() == 0 && doi[s[i]] == 1 ) || (st.top() == 2 && doi[s[i]] == 3 ) || (st.top() == 4 && doi[s[i]] == 5 )) ){
                st.pop();
            }
            else 
            if (doi[s[i]] == 1 ||doi[s[i]] == 3||doi[s[i]] == 5)
                {return false;}
                else st.push(doi[s[i]]);
        }
        if(st.empty()) 
        return true;
        else return false;
    }
};
