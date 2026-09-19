class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       int counts1[10000] ={0},cosnts1[10000] ={0};
        for (int i = 0; i < s1.size() ;i++){
            counts1[s1[i]]++;
            cosnts1[s1[i]]++;
        }
        int k = s1.size(), j = 0;
        for (int i = 0 ; i< s2.size(); i++){
            if (cosnts1[s2[i]] > 0){
                counts1[s2[i]]--;
                while (j < s2.size() && counts1[s2[i]] < 0 ){
                        counts1[s2[j]]++;
                        j++;
                    }
            }
            else {
                for (int k = j; k<= i ; k++ ) if (cosnts1[s2[k]] > 0) counts1[s2[k]]++;
                j = i + 1;
            }
            if (i - j + 1 == k ) return true;
        }
        return false;
    }
};
