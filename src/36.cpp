// 分析：
// 方法一：
// 对二叉树进行深度搜索（先序遍历），记录最大长度的路径并更新长度。
// 将遍历结点入栈，在回溯时，将结点出栈。
// 方法二：
// 当前节点所处的深度，等于左右子树较大值+1。空子树的深度为0，直接递归即可。

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
/*
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
    	if (pRoot == nullptr)
    		return 0;
    	int leftdepth = TreeDepth(pRoot->left);
    	int rightdepth = TreeDepth(pRoot->right);
    	int depth = (leftdepth > rightdepth) ? (leftdepth + 1) : (rightdepth + 1);
    	return depth;
    }
};
*/