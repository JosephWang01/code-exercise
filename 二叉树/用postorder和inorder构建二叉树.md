106. 从中序与后序遍历序列构造二叉树
给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。




		class Solution {
		public:
		    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		        return build(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1);
		    }
		    TreeNode* build(vector<int>& postorder, int begin1, int end1, vector<int>& inorder, int begin2, int end2){
		        if(begin1 > end1 || begin2 > end2){
		            return nullptr;
		        }
		        int index = find(inorder, begin2, end2, postorder[end1]);
		        int leftsize = index-begin2;
		        TreeNode* root = new TreeNode(postorder[end1]);
		        TreeNode* left = build(postorder, begin1,  begin1 + leftsize-1, inorder, begin2, index-1 );
		        TreeNode* right = build(postorder, begin1+leftsize, end1-1, inorder, index+1, end2);
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