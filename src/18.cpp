// 分析：
// 如果当前节点为空或者当前节点左右儿子均为空，直接返回。否则交换左右儿子，
// 递归操作当前节点的左和右儿子

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
    void Mirror(TreeNode *pRoot) {
		if (!pRoot)
			return;
		else if ((pRoot->left == nullptr) && (pRoot->right == nullptr))
			return;
		struct TreeNode *tmp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = tmp;
		if (pRoot->left)
			Mirror(pRoot->left);
		if (pRoot->right)
			Mirror(pRoot->right);
    }
};