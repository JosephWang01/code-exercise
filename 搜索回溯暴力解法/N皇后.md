51. N 皇后
n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。

每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
	
	class Solution {
	    vector<vector<string>> res;
	    vector<string> tmp;
	public:
	    vector<vector<string>> solveNQueens(int n) {
	        tmp.resize(n,string(n, '.'));
	        backtrack(0);
	        return res;
	    }
	
	    void backtrack(int n){
	        if(n == tmp[0].size()){
	            res.push_back(tmp);
	        }
	        for(int i = 0; i<tmp[0].size(); ++i){
	            if(!confirm(n, i)){
	                continue;
	            }
	            tmp[n][i] = 'Q';
	            backtrack(n+1);
	            tmp[n][i] = '.';
	        }
	    }
	
	    bool confirm(int row, int col){
	        int n = tmp.size();
	        // 检查列是否有皇后互相冲突
	        for (int i = 0; i < row; i++) {
	            if (tmp[i][col] == 'Q')
	            return false;
	        }
	        // 检查右上⽅是否有皇后互相冲突
	        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
	            if (tmp[i][j] == 'Q')
	            return false;
	        }
	        // 检查左上⽅是否有皇后互相冲突
	        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
	            if (tmp[i][j] == 'Q')
	            return false;
	        }
	        return true;
	    }
	};