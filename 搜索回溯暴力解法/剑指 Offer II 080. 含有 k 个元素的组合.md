剑指 Offer II 080. 含有 k 个元素的组合
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

执行用时：
4 ms
, 在所有 C++ 提交中击败了
99.33%
的用户
内存消耗：
18.4 MB
, 在所有 C++ 提交中击败了
31.38%
的用户


	class Solution {
	public:
	    vector<vector<int>> res;
	    vector<int> track;
	    vector<vector<int>> combine(int n, int k) {
	        dfs(n, k, 1);
	
	        return res;
	    }
	    void dfs(int n, int k, int cur){
	        if(cur > n || track.size() >= k){
	            //track.push_back(cur);
	            return;
	            
	        }
	
	        track.push_back(cur);
	        if(track.size() == k){
	            res.push_back(track);
	            //return;
	        }
	        //剪枝以后代码效率就上去了
	        if(k-track.size() <= n-cur)    dfs(n, k, cur+1);
	        track.pop_back();
	        if(k-track.size()-1 <= n-cur)    dfs(n, k, cur+1);
	        //}
	    }
	};