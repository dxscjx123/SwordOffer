// 分析：
// 先描述正确思路：1）首先找到与待查找二叉树根节点相同的结点，从
// 该结点出发，遍历该结点子树看是否与待查找树相同，全部相同则
// 找到，此处的遍历过程可采用递归。2）如果当前结点与待查找二叉树
// 结点不同，则递归遍历当前节点的左右子树，返回步骤1。
// 这个题对递归的考查比较深。

// 最初考虑的思路：大致思路也为先找到与待查找根结点相同的位置，再
// 从该位置进行遍历。考虑采用层次遍历（用队列的方式），先遍历得到
// 相同点的位置结点，再从该结点进行遍历与待查找树比较。但问题在于
// 第一次遍历查找相同点时，由于是比较元素值，对于[8,8,7,#,#,9,2]与
// 待查找二叉树[8,9,2]，会返回第一个元素8，而不是返回第二个元素8，
// 故不能返回正确根节点
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
		if ((pRoot1 == nullptr) || (pRoot2 == nullptr))
			return false;
		bool result = false;
		if (pRoot1)
		{
			if (pRoot1->val == pRoot2->val)
				result = HasSubtree_deep(pRoot1, pRoot2);
			if (!result)
				result = HasSubtree(pRoot1->left, pRoot2);
			if (!result)
				result = HasSubtree(pRoot1->right, pRoot2);
		}
		return result;
    }
private:
	bool HasSubtree_deep(TreeNode *pRoot1, TreeNode *pRoot2)
	{
		if (pRoot2 == nullptr)
			return true;
		if (pRoot1 == nullptr)
			return false;
		if (pRoot1->val != pRoot2->val)
			return false;
		return HasSubtree_deep(pRoot1->left, pRoot2->left) &&
			HasSubtree_deep(pRoot1->right, pRoot2->right);
	}
};