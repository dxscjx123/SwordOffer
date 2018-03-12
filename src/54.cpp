// 分析：
// 由于是一棵bst树，直接对树进行中序遍历，得到的即为一个有序数组。
// 在遍历过程中递减k，当k为0时表示当前遍历节点为第k个结点。

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
	void inorder(TreeNode *root, int &k)
	{
		if (!root)
			return ;
		inorder(root->left, k);
		k--;
		if (k == 0)
			result = root;
		inorder(root->right, k);
	}

    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
		if (!pRoot || k == 0)
			return nullptr;
		result = nullptr;
		inorder(pRoot, k);
		return result;
    }
private:
	TreeNode *result;
};