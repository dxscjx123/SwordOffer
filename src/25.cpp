//分析：
//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
// 根据二叉搜索树的性质，对于转换后的双向链表，根节点10应该与左子树
// 最大值8结合，根节点10应该与右子树最小值12结合。而由于需要按照从
// 小到大顺序排列，采用中序遍历能够让二叉树顺序输出。而在递归构建搜索
// 的过程中，对当前遍历节点，需要设置其左节点指向上一节点，而上一节点
// 右节点设置为指向当前节点。
// 最后对双向链表进行遍历，返回链表头结点。

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
	void construct_doublelink(TreeNode *pRootOfTree, TreeNode **lastinlist)
	{
		if (pRootOfTree == nullptr)
			return ;
		
		TreeNode *current = pRootOfTree;
		if (pRootOfTree->left)
			construct_doublelink(pRootOfTree->left, lastinlist);
		
		if ((*lastinlist) != nullptr)
			(*lastinlist)->right = current;
		current->left = *lastinlist;
		*lastinlist = current;
		
		if (pRootOfTree->right)
			construct_doublelink(pRootOfTree->right, lastinlist);
	}
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
		TreeNode *lastinlist = nullptr;
		construct_doublelink(pRootOfTree, &lastinlist);
		
		TreeNode *doublelink = lastinlist;
		while (doublelink && doublelink->left != nullptr)
		{
			doublelink = doublelink->left;
		}
		return doublelink;
    }
};