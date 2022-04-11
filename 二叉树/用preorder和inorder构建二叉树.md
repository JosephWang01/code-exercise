105. 从前序与中序遍历序列构造二叉树
给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。  

		//递归版本
		class Solution {
		public:
		    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
		    }
		    TreeNode* build(vector<int>& preorder, int begin1, int end1, vector<int>& inorder, int begin2, int end2){
		        if(begin1 > end1 || begin2 > end2){
		            return nullptr;
		        }
		        int index = find(inorder, begin2, end2, preorder[begin1]);
		        int leftsize = index-begin2;
		        TreeNode* root = new TreeNode(preorder[begin1]);
		        TreeNode* left = build(preorder,begin1+1, begin1+leftsize, inorder, begin2, index-1 );
		        TreeNode* right = build(preorder, begin1+leftsize+1, end1, inorder, index+1, end2);
		        root->left = left;
		        root->right = right;
		        return root;
		
		    }
		    int find(vector<int>& nums, int begin ,int end, int target){
		        while(begin <= end){
		            if(nums[begin] == target){
		                return begin;
		            }
		            ++begin;
		        }
		        return -1;
		    }
		};