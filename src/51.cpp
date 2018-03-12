// 分析：
// 判断一棵二叉树是否是镜像。采用递归方法：
// 1）既不存在左结点，也不存在右结点，是镜像；
// 2）在1）条件下，判断左右节点是否有一个不存在，若满足则不是镜像；
// 3）上述两个条件都通过，左右结点值是否相同，不相同则不是镜像；
// 4）递归遍历左结点的左子树和右节点的右子树；
// 5）递归遍历左结点的右子树和右节点的左子树

// 也可以采用对二叉树进行两次层次遍历（采用两个queue），层次遍历两个队列分别入队
// 左结点和右节点，并依此比较。

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
	void issymmetrical(TreeNode *pleft, TreeNode *pright)
	{
		if (!pleft && !pright)
			return ;
		if (!pleft || !pright)
		{
			result = false;
			return ;
		}
		if (pleft->val != pright->val)
		{
			result = false;
			return ;
		}
		issymmetrical(pleft->left, pright->right);
		issymmetrical(pleft->right, pright->left);
	}

    bool isSymmetrical(TreeNode* pRoot)
    {
		result = true;
		if (!pRoot)
			return result;
		if (!pRoot->left && !pRoot->right)
			return true;
		if (!pRoot->left || !pRoot->right)
			return false;
		issymmetrical(pRoot->left, pRoot->right);
		return result;
    }
private:
	bool result;
};