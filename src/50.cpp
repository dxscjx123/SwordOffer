// 分析：
// 中序遍历，求二叉树给定节点的下一个节点。分为三种情况：
// 记给定节点为cur
// 1）cur->right存在，则下一个节点为cur->right的最左节点；
// 2）cur->right不存在：
	// a）cur的父节点不存在（根节点），则下一个节点为空
	// a）cur的父节点存在，且cur为其父节点的左节点，则下一个节点为其父节点；
	// b）cur的父节点存在，且cur为其父节点的右节点，需要向上逐个遍历父节点，
	// 直到找到一个节点node是其父节点的左节点，则下一个节点为node的父节点。
	
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
		TreeLinkNode *result;
		if (!pNode)
			return nullptr;
		if (pNode->right)
		{
			TreeLinkNode *node = pNode->right;
			while (node->left)
				node = node->left;
			result = node;
		}
		else
		{
			TreeLinkNode *parent = pNode->next;
			if (parent && parent->left == pNode)
				result = parent;
			else if (parent && parent->right == pNode)
			{
				while (parent->next)
				{
					if (parent->next->left == parent)
						result = parent->next;
					parent = parent->next;
				}
			}
			else if (!parent)
				result = nullptr;
		}
		return result;
    }
};