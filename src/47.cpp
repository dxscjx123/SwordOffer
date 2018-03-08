// 分析：
// 这个题牛客网上没有，但书上有，故写了个算法通过ide调试得到了正确结果。

// 首先是考虑树是一棵bst的情况：由于bst中，两个节点的公共节点，应该是中序
// 遍历中第一个值处于两个节点之间的。如果遍历节点值小于两个节点中的最小值，
// 则遍历左子树，大于最大值则遍历右子树。

// 第二种情况是：如果是一棵普通的多叉树，不局限于二叉查找树。如果该树中，存在
// 从子节点指向父节点的指针，则可以从两个待查找节点开始，向上遍历父节点，直到
// 找到根节点（父节点为nullptr），记录两条路径和长度，然后就可以把问题转换为找
// 两个链表的第一个公共节点（长的链表先走长度差的步数，再两个同时走）

// 第三种情况是：如果是一棵普通的多叉树，且不存在指向父节点的指针。可以考虑从
// 根节点开始，以两个目标节点为目的节点，进行dfs遍历，对于达到叶节点并且等于目的
// 节点的路径进行保存（采用回溯法深搜一棵树，满足条件的vector.push_back()，不
// 满足条件vector.pop_back()），最终找到两条路径，分别从根节点出发到两个目标节点，
// 遍历两条路径找出第一个公共节点即可。

//情况一：bst
class Solution {
public:
	TreeNode *findlowparent(TreeNode *root, TreeNode *p, TreeNode *q)
	{
		if (!root)
			return nullptr;
		int curval = root->val;
		TreeNode *head;
		if (p->val < curval && q->val > curval)
			head = root;
		else if (q->val > curval)
			head = findlowparent(root->right, p, q);
		else if (p->val < curval)
			head = findlowparent(root->left, p, q);
		return head;
	}

	TreeNode *lowparent(TreeNode *root, TreeNode *p, TreeNode *q)
	{
		if (!root)
			return nullptr;
		if (!p && !q)
			return nullptr;
		if (!p || !q)
			return nullptr;
		TreeNode *head = findlowparent(root, p, q);
		return head;
	}
};

// 情况二：一棵树，存在子节点指向父节点的指针
/*
class Solution {
public:
	TreeNode *findlowparent(TreeNode *p, TreeNode *q)
	{
		int plen = 0;
		int qlen = 0;
		TreeNode *plist = p;
		TreeNode *qlist = q;
		while (plist->parent)
		{
			plen++;
			plist = plist->parent;
		}
		while (qlist->parent)
		{
			qlen++;
			qlist = qlist->parent;
		}
		
		plist = p;
		qlist = q;
		int dif = abs(plen - qlen);
		
		if (plen > qlen)
		{
			while (dif)
			{
				plist = plist->parent;
				dif--;
			}
		}
		else if (plen < qlen)
		{
			while (dif)
			{
				qlist = qlist->parent;
				dif--;
			}
		}
		
		TreeNode *head;
		while (plist && qlist)
		{
			if (plist->val == qlist->val)
			{
				head = plist;
				break;
			}
			plist = plist->parent;
			qlist = qlist->parent;
		}
		return head;
	}

	TreeNode *lowparent(TreeNode *root, TreeNode *p, TreeNode *q)
	{
		if (!root || !q || !p)
			return nullptr;
		TreeNode *common = findlowparent(p, q);
		return common;
	}
};
*/