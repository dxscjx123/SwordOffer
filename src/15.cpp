// 分析：
// 定义三个指针，指向前一结点pre，当前节点node，后一结点next。
// 1 -> 2 -> 3 -> 4
// 1）pre<-node  next，由于需要断开next，需提前进行保存
// 2）ppre<-pre  node，与1）步骤类似进行赋值
// 3）next指向空，node结点此时还未指向pre，需进行赋值后，返回node结点


/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
		ListNode *ReverseHead = nullptr;
		ListNode *pNode = pHead;
		ListNode *pPre = nullptr;
		while (pNode != nullptr)
		{
			ListNode *pNext = pNode->next;
			if (pNext == nullptr)
			{
				ReverseHead = pNode;
			}
			pNode->next = pPre;
			pPre = pNode;
			pNode = pNext;
		}
		return ReverseHead;
    }
};