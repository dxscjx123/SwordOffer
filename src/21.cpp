// 分析：
// 二叉树的层次遍历，借助队列数据结构。将每次遍历节点的
// 左右节点入队，只要队列不为空，队首元素出队，并将队首的
// 左右节点入队。直到最后队列为空。

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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
		if (!root)
			return tree;
		tree.push_back(root->val);
		tree_node.push(root);
		while (!tree_node.empty())
		{
			TreeNode *cur_node = tree_node.front();
			tree_node.pop();
			if (cur_node->left)
			{
				tree_node.push(cur_node->left);
				tree.push_back(cur_node->left->val);
			}
			if (cur_node->right)
			{
				tree_node.push(cur_node->right);
				tree.push_back(cur_node->right->val);
			}
		}
		return tree;
    }
private:
	vector<int> tree;
	queue<TreeNode *> tree_node;
};