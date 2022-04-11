889. 根据前序和后序遍历构造二叉树
给定两个整数数组，preorder 和 postorder ，其中 preorder 是一个具有 无重复 值的二叉树的前序遍历，postorder 是同一棵树的后序遍历，重构并返回二叉树。

如果存在多个答案，您可以返回其中 任何 一个。




	class Solution {
	public:
	    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
	        return build(preorder, 0, preorder.size()-1, postorder, 0, postorder.size()-1);
	    }
	    TreeNode* build(vector<int>& preorder, int begin1, int end1, vector<int>& postorder, int begin2, int end2){
	        if(begin1 > end1 || begin2 > end2){
	            return nullptr;
	        }
	        TreeNode* root = new TreeNode(preorder[begin1]);
	        //这里在区间内除了root的情况下，把pre中的下一个节点当作了左子树，事实上还可能是右节点
	        if(begin1 == end1 || begin2 == end2){
	            return root;
	        }
	        int index = find(postorder, begin2, end2-1, preorder[begin1+1]);
	        int leftsize = index-begin2+1;
	        TreeNode* left = build(preorder, begin1+1, begin1+leftsize, postorder, begin2, index);
	        TreeNode* right = build(preorder, begin1+leftsize+1, end1, postorder, index+1, end2-1);
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