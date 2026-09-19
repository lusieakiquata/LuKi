class Solution {
public:

    string encode(vector<string>& strs) {
        string rs;
        for ( string x: strs){
            rs+=to_string(x.size()) +"#" + x;
        }
        return rs;
    }

    vector<string> decode(string s) {
        if (s.empty()) {
        return {}; // Trả về vector rỗng [] ngay lập tức
        }
        vector<string> ders = {};
        int i = 0; 
        while (i < s.size()){
            int j = 0;
            while (s[i+j] != '#'){
                j++;
            }
            string so = s.substr(i, j);
            int soi = stoi(so);
            ders.push_back(s.substr(i+j+1 , soi));
            i += j + 1 + soi;
        }
        return ders;
    }
};
