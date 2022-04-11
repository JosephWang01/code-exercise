515. 在每个树行中找最大值
给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。


		class Solution {
		public:
		    vector<int> largestValues(TreeNode* root) {
		        vector<int> res;
		        dfs(root, res, 0);
		        return res;
		    }
		    //用dfs的方法解决
		    void dfs(TreeNode* root, vector<int>& res, int depth){
		        if(root == nullptr){
		            return;
		        }
		        int sz = res.size();
		        if(depth >= sz){
		            res.push_back(root->val);
		        }else{
		            res[depth] = max(res[depth], root->val);
		        }
		        dfs(root->left, res, depth+1);
		        dfs(root->right, res, depth+1);
		    }
		};