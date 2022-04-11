98. 验证二叉搜索树
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

有效 二叉搜索树定义如下：

节点的左子树只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。

tip:
1.	需要注意题意，确认子树都是BST，再确认root作为根节点是否BST；
2.	如果传递INT_MIN 和 INT_MAX会卡到边界值；
3.	可以用null节点来处理，也可以用long型存储更大的值。

	class Solution {
	public:
	    bool isValidBST(TreeNode* root) {
	        return isValid(root, nullptr, nullptr);
	    }
	    bool isValid(TreeNode* root, TreeNode* min , TreeNode* max){
	        if(root == nullptr){
	            return true;
	        }
	        if(max != nullptr && root->val >= max->val){
	            return false;
	        }
	        if(min != nullptr && root->val <= min->val){
	            return false;
	        }
	        return isValid(root->left, min, root)&&isValid(root->right, root, max);
	    }
	};