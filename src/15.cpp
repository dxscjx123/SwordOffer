//分析：
//前指针和后指针，前指针先走k-1步，前后指针同时走，当前指针到达链
//表尾部，后指针指向倒数第k个节点

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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == nullptr)
		{
			return nullptr;
		}
		struct ListNode *first = pListHead;
		struct ListNode *second = pListHead;
		while (k != 1)
		{
			if (first->next != nullptr)
			{
				first = first->next;
			}
			else
			{
				return nullptr;
			}
			k--;
		}
		while (first->next != nullptr)
		{
			second = second->next;
			first = first->next;
		}
		return second;
    }
};