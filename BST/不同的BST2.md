95. 不同的二叉搜索树 II
给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从 1 到 n 互不相同的不同 二叉搜索树 。可以按 任意顺序 返回答案。




 
		class Solution {
		public:
		    vector<TreeNode*> generateTrees(int n) {
		        //自顶向下的方法：递归回溯思路
		        //可以用搜索回溯的方法穷举所有可能，传递两个参数，一个是当前还没有处理的节点个数 ，二是根节点
		        //每次节点都处理完了，去复制一颗BST并保存
		        //自底而上的方法：动态规划思路
		        return build(1, n);
		    }
		    vector<TreeNode*> build(int lf, int rt){
		        vector<TreeNode*> res;
		        if(lf > rt){
		            //res.push_back(nullptr);
		            return res;
		        }
		        for(int i = lf; i<=rt; ++i){
		            vector<TreeNode*> left = build(lf, i-1);
		            vector<TreeNode*> right = build(i+1, rt);
		            //TreeNode* root = new TreeNode(i);
		            if(left.size() > 0 && right.size() > 0){
		                for(int j = 0; j<left.size(); ++j){
		                    for(int k = 0; k < right.size(); ++k){
		                        TreeNode* root = new TreeNode(i);
		                        root->left = left[j];
		                        root->right = right[k];
		                        res.push_back(root);
		                    }
		                }
		            }else if(left.size() == 0 && right.size() > 0){
		                for(int k = 0; k < right.size(); ++k){
		                    TreeNode* root = new TreeNode(i);
		                    root->left = nullptr;
		                    root->right = right[k];
		                    res.push_back(root);
		                }
		            }else if(left.size() > 0 && right.size() == 0){
		                for(int j = 0; j<left.size(); ++j){
		                    TreeNode* root = new TreeNode(i);
		                    root->left = left[j];
		                    root->right = nullptr;
		                    res.push_back(root);
		                }
		            }else if(left.size() == 0 && right.size() == 0){
		                TreeNode* root = new TreeNode(i);
		                root->left = nullptr;
		                root->right = nullptr;
		                res.push_back(root);
		            }
		        }
		        return res;
		    }
		};