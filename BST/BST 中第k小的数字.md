230. 二叉搜索树中第K小的元素
给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。 

		class Solution {
		    //int cot = 0;
		public:
		    int kthSmallest(TreeNode* root, int& cot) {
		        if(root == nullptr){
		            return -1;
		        }
		        int left = kthSmallest(root->left, cot);
		        if( left != -1){
		            return left;
		        }
		        if(cot == 1){
		            return root->val;
		        }
		        --cot;
		        int right = kthSmallest(root->right, cot);
		        if(right != -1){
		            return right;
		        }
		        return -1;
		    }
		};