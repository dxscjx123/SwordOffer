/*
给定一棵结点数为n 二叉搜索树，请找出其中的第 k 小的TreeNode结点值。
1.返回第k小的节点值即可
2.不能查找的情况，如二叉树为空，则返回-1，或者k大于n等等，也返回-1
3.保证n个节点的值不一样

分析：题目给的是一个bst，bst的特点根据中序遍历结果即为从小到大的排列。
所以直接中序遍历bst，当遍历到第k个节点时记录结果。后续的遍历nth > k，
则无需进行遍历了。
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
    void dfs(TreeNode *proot, int k)
    {
        if (nth > k)
            return;

        if (proot->left)
            dfs(proot->left, k);

        if ((++nth) == k)
        {
            kth_ret = proot->val;
            return;
        }

        if (proot->right)
            dfs(proot->right, k);
    }

    int KthNode(TreeNode* proot, int k) {
        if (proot == nullptr)
            return -1;

        kth_ret = -1;
        nth = 0;
        dfs(proot, k);
        return kth_ret;
    }

private:
    int kth_ret;
    int nth;
};
