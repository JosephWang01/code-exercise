700. 二叉搜索树中的搜索
给定二叉搜索树（BST）的根节点 root 和一个整数值 val。

你需要在 BST 中找到节点值等于 val 的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 null 。


	class Solution {
	public:
	    TreeNode* searchBST(TreeNode* root, int val) {
	        if(root == nullptr){
	            return nullptr;
	        }
	        if(root->val == val){
	            return root;
	        }
	        if(root->val > val){
	            TreeNode* left = searchBST(root->left, val);
	            if(left){
	                return left;
	            }
	        }else{
	            TreeNode* right = searchBST(root->right, val);
	            if(right){
	                return right;
	            }
	        }
	        return nullptr;
	    }
	};