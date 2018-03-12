// 分析：
// 方法一：对二叉树进行层次遍历，对偶数层遍历结果逆序存入result；
// 方法二：在数据量大的情况下，方法一的偶数层逆序导致性能损耗，可以考虑采用两个栈结构。
// （原因在于奇数层从左往右输出，偶数层从右往左输出），对于奇数层，先后遍历左右节点存入，
// 对于偶数层，先后遍历右左节点存入。

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

//方法一：
/*
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        if (!pRoot)
			return vector<vector<int>>();
		bfs_queue.push(pRoot);
		bool left2right = true;
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
			if (left2right)
			{
				result.push_back(onelevel);
				left2right = false;
			}
			else
			{
				vector<int> tmp(onelevel.rbegin(), onelevel.rend());
				result.push_back(tmp);
				left2right = true;
			}
		}
		return result;
    }
private:
	vector<vector<int>> result;
	queue<TreeNode *> bfs_queue;
};
*/

//方法二：
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
		if (!pRoot)
			return vector<vector<int>>();
		s1.push(pRoot);
		int layer = 1;
		while (!s1.empty() || !s2.empty())
		{
			vector<int> onelevel;
			if (layer % 2 != 0)
			{
				while (!s1.empty())
				{
					TreeNode *head = s1.top();
					onelevel.push_back(head->val);
					s1.pop();
					if (head->left)
						s2.push(head->left);
					if (head->right)
						s2.push(head->right);
				}
			}
			else
			{
				while (!s2.empty())
				{
					TreeNode *head = s2.top();
					onelevel.push_back(head->val);
					s2.pop();
					if (head->right)
						s1.push(head->right);
					if (head->left)
						s1.push(head->left);
				}
			}
			result.push_back(onelevel);
			layer++;
		}
		return result;
	}
private:
	vector<vector<int>> result;
	stack<TreeNode *> s1, s2;
};