// 分析：
// 设置两个指针，一个指针先走k-1个结点，然后两个指针一起走，第一个
// 指针到链表尾，第二个指针指向倒数第k个结点。需要注意边界条件：链
// 表为空；链表元素小于k；k=0

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