// 分析：
// 采用递归分别求二叉树左右子树的深度，如果深度之差大于1，则将结果置
// 为false，这里主要注意，空子树也是一棵平衡二叉树。

class Solution {
public:
	int TreeDepth(TreeNode *pRoot)
	{
		if (!pRoot)
			return 0;
		int nleft = TreeDepth(pRoot->left);
		int nright = TreeDepth(pRoot->right);
		if (abs(nleft - nright) > 1)
			result = false;
		return (nleft > nright) ? (nleft + 1) : (nright + 1);
	}
    bool IsBalanced_Solution(TreeNode* pRoot) {
		if (!pRoot)
			return true;
		result = true;
		TreeDepth(pRoot);
		return result;
    }
private:
	bool result;
};