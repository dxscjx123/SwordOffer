/*
给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

分析：
对于bst而言，两个节点公共祖先的一个特点为，left <= ancestor <= right。
而如果ancestor < left，则需要查找的节点在右子树，如果ancestor > right,
则需要查找的节点在左子树。

额外需要注意，对于如下bst：按照上面的方式，节点7与节点12都会满足节点1与节点14公共节点
的条件，但是由于采用dfs是中序遍历的顺序，故节点7会先于节点12被遍历，我们只需要在找
到第一个节点的时候，标记found即可。

    7
1       12
      11  14

*/


/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode *root, int left, int right)
    {
        if (found)
            return;

        if (root->val >= left && root->val <= right)
        {
            found = true;
            result = root->val;
            return;
        }

        if (root->right != nullptr && root->val < left)
            dfs(root->right, left, right);

        if (root->left != nullptr && root->val > right)
            dfs(root->left, left, right);
    }

    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        if (root == nullptr)
            return -1;

        result = -1;
        found = false;

        int left = (p < q) ? p : q;
        int right = (p > q) ? p : q;

        dfs(root, left, right);
        return result;
    }

private:
    int result;
    bool found;
};
