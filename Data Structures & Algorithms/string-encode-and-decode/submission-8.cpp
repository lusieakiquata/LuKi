class Solution {
public:

    string encode(vector<string>& strs) {
        string rs;
        for ( string x: strs){
            rs+= x +"[36]";
        }
        return rs;
    }

    vector<string> decode(string s) {
        if (s.empty()) {
        return {}; // Trả về vector rỗng [] ngay lập tức
    }
        vector<string> ders = {};
        string rs = "";
        for (int i = 0; i<s.size()-3;i++){
            if(s[i] == '[' && s[i+1] == '3' && s[i+2] =='6' &&s[i+3] == ']')
            {
                i+= 3;
                ders.push_back(rs);
                rs = "";
            }
            else
            rs.push_back(s[i]);
        }
        if (!ders.empty())
            return ders;
        else 
            return {};
    }
};
