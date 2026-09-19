class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    unordered_set <char> ngan[9],doc[9], box[3][3];
    for(int i = 0; i < 9; i++){
        for(int j = 0; j< 9; j++){
            if (board[i][j] != '.'){
                if (!ngan[i].insert(board[i][j]).second) return false;
                if (!doc[j].insert(board[i][j]).second) return false;
                int x = i / 3;
                int y = j / 3;
                if (!box[x][y].insert(board[i][j]).second) return false;
            }
        }
    }
    return true;
    }
};
