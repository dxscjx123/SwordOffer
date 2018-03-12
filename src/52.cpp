// 分析：
// 对二叉树进行层次遍历，记录每层的节点数，遍历后将其输出到result。

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
    vector<vector<int> > Print(TreeNode* pRoot) {
		if (!pRoot)
			return vector<vector<int>>();
		bfs_queue.push(pRoot);
		while (!bfs_queue.empty())
		{
			int qsize = bfs_queue.size();
			vector<int> onelevel;
			for (int i = 0; i < qsize; ++i)
			{
				TreeNode *head = bfs_queue.front();
				onelevel.push_back(head->val);
				bfs_queue.pop();
				if (head->left)
					bfs_queue.push(head->left);
				if (head->right)
					bfs_queue.push(head->right);
			}
			result.push_back(onelevel);
		}
		return result;
    }
private:
	vector<vector<int>> result;
	queue<TreeNode *> bfs_queue;
};