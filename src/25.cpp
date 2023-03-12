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
// 这里的一个技巧是参数传入了二维指针，即双向链表节点的地址
//  ______
// |0x1000|   地址：0x8000（&p）
// |______|

//  ______
// | 数据 |   地址：0x1000
// |______|  
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

//第二次
/*
首先根据分析，最终的双向链表，对于一个节点cur来说，cur->left指向的应该为原本的bst中的cur节点左子树的最大节点
，即从cur开始遍历到左子树的最右结点。同理，cur->right指向的应该为原本bst中的cur节点右子树的最小节点，即从
cur开始遍历到右子树的最左节点。那么对于任意节点cur而言
cur->left = 左子树的最右节点
cur->right = 右子树的最左节点
然后再递归处理cur节点的左右子树。
需要注意的是，在设置cur->left与cur->right之前，首先需要先dfs处理完左右子树，否则会破坏原本的cur->left与
cur->right节点。
*/

class Solution {
public:
	void dfs(TreeNode *root)
	{
		TreeNode *cur, *pre;
		if (root->left)
		{
			dfs(root->left);
			cur = root->left;
			pre = nullptr;
			while (cur)
			{
				pre = cur;
				cur = cur->right;
			}
			root->left = pre;
			pre->right = root;
		}

		if (root->right)
		{
			dfs(root->right);
			cur = root->right;
			pre = nullptr;
			while (cur)
			{
				pre = cur;
				cur = cur->left;
			}
			root->right = pre;
			pre->left = root;
		}
	}

    TreeNode* Convert(TreeNode* pRootOfTree) {
		TreeNode *head = nullptr;

        if (pRootOfTree == nullptr)
			return nullptr;

		dfs(pRootOfTree);

		while (pRootOfTree)
		{
			head = pRootOfTree;
			pRootOfTree = pRootOfTree->left;
		}

		return head;
    }
};