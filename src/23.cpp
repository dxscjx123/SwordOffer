// 分析：
// 定义一个vector，对二叉树进行先序遍历，当遍历节点没有达到叶节点时，累加
// 路径和，达到叶节点判断是否等于给定值。从叶节点返回重新回溯至父节点时，
// 将累加路径和减去当前节点。

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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
		vector<vector<int> > result;
		if (!root)
			return result;
		int sumNum = 0;
		PreFindPath(root, expectNumber, result, sumNum);
		return result;
	}
	void PreFindPath(TreeNode *root, int expectNumber, vector<vector<int> > &result, int &sumNum)
	{
		sumNum += root->val;
		path.push_back(root);
		
		bool isleaf = (root->left == nullptr) && (root->right == nullptr);
		if ((sumNum == expectNumber) && isleaf)
		{
			vector<int> tmp_path;
			for (int i = 0; i < path.size(); ++i)
			{
				tmp_path.push_back(path[i]->val);
			}
			result.push_back(tmp_path);
		}
		
		if (root->left != nullptr)
			PreFindPath(root->left, expectNumber, result, sumNum);
		if (root->right != nullptr)
			PreFindPath(root->right, expectNumber, result, sumNum);
		
		sumNum -= root->val;
		path.pop_back();
	}
private:
	vector<TreeNode *> path;
};