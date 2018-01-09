// 分析：
// 前序遍历的第一个结点为根节点，并根据第一个结点在中序遍历中划分
// 根节点的左子树和右子树，再递归建立二叉树


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin)
	{
		if(pre.size() == 0)
			return nullptr;
		int index;
		for(int i = 0; i < vin.size(); i++)
		{
			if(vin[i] == pre[0])
			{
				index = i;
				break;
			}
		}
		vector<int> pre_start_index, pre_index_end;
		vector<int> vin_start_index, vin_index_end;
		for(int i = 1; i < 1 + index; i++)
		{
			pre_start_index.push_back(pre[i]);
		}
		for(int i = index + 1; i < pre.size(); i++)
		{
			pre_index_end.push_back(pre[i]);
		}
		for(int i = 0; i < index; i++)
		{
			vin_start_index.push_back(vin[i]);
		}
		for(int i = index + 1; i < vin.size(); i++)
		{
			vin_index_end.push_back(vin[i]);
		}
		struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode*));
		root->val = pre[0];
		root->left = reConstructBinaryTree(pre_start_index, vin_start_index);
		root->right = reConstructBinaryTree(pre_index_end, vin_index_end);
		return root;
	}
};