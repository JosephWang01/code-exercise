剑指 Offer II 081. 允许重复选择元素的组合

给定一个无重复元素的正整数数组 candidates 和一个正整数 target ，找出 candidates 中所有可以使数字和为目标数 target 的唯一组合。

candidates 中的数字可以无限制重复被选取。如果至少一个所选数字数量不同，则两种组合是不同的。 

对于给定的输入，保证和为 target 的唯一组合数少于 150 个。


执行用时：
8 ms
, 在所有 C++ 提交中击败了
64.26%
的用户
内存消耗：
10.8 MB
, 在所有 C++ 提交中击败了
56.57%
的用户

思路：回溯法 + 剪枝

这道题与之前的唯一区别就是同一个数字可以多次选择。这道题中每一步都从集合中取出一个元素时，存在多个选择，一种是不添加该数字，其他选择就是选择 1 次该数字，2 次该数字...。

其实归根到底，也是两种选择，一种是选择不添加，另一种是选择添加。如果选择不添加，那么只需要调用递归函数判断下一个数字。如果选择添加，那么只需要调用递归函数继续判断该数字。这样的处理就可以与之前的题目完全统一，完整的代码如下。





	class Solution {
	    vector<vector<int>> res;
	    vector<int> track;
	    int sum = 0;
	public:
	
	    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	        dfs(candidates, 0, target);
	
	        return res;
	    }
	
	    //需要去重
	    void dfs(vector<int>& candidates, int index,  int target){
	        if(index == candidates.size() || sum > target){
	            return;
	        }
	
	        track.emplace_back(candidates[index]);
	        sum += candidates[index];
	        if(sum == target){
	            res.push_back(track);
	            //return;
	        }
	
	        dfs(candidates, index, target);
	        //track.pop_back();
	
	        //dfs(candidates, index+1, target);
	        track.pop_back();
	        sum -= candidates[index];
	        dfs(candidates, index+1, target);
	
	
	    }
	};