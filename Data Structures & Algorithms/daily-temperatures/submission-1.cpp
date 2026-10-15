class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int , int >> st;
        vector<int> res;
        for(int i = temperatures.size() - 1 ; i >= 0 ; i--){
            int x = temperatures[i];
            while(!st.empty() && st.top().first <= x) {
                st.pop();
            }
            if (st.empty())
            res.push_back(0);
            else
                res.push_back(st.top().second - i );
            st.push({x, i});
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
