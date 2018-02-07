// 分析：
// 方法一：
// 对二叉树进行深度搜索（先序遍历），记录最大长度的路径并更新长度。
// 将遍历结点入栈，在回溯时，将结点出栈。
// 方法二：
// 见注释。感觉智商收到了暴击。。。。不过确实很简洁。

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

//方法一：
class Solution {
public:
	void preorder(TreeNode *pRoot)
	{
		dfs.push(pRoot);
		
		if (pRoot->left)
			preorder(pRoot->left);
		if (pRoot->right)
			preorder(pRoot->right);
		
		if (maxdepth < dfs.size())
			maxdepth = dfs.size();
		dfs.pop();
	}
    int TreeDepth(TreeNode* pRoot)
    {
		if (!pRoot)
			return 0;
		
		maxdepth = 0;
		preorder(pRoot);
		return maxdepth;
    }
private:
	stack<TreeNode *> dfs;
	int maxdepth;
};

//方法二：
// int TreeDepth(TreeNode *pRoot)
// {
	// if (!pRoot)
		// return 0;
	// int nleft = TreeDepth(pRoot->left);
	// int nright = TreeDepth(pRoot->right);
	// return (nleft > nright) ? (nleft + 1) : (nright + 1);
// }