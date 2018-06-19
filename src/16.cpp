// 分析：
// 两个指针指向两个链表，满足条件则将对应指针指向下一个结点。但两个指针
// 任意一个为空，表明一个链表遍历结束，将另一个链表的下一个结点指向当
// 前指针（因为下一个链表的剩余元素均为排序元素）

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
		if (!pHead1 && !pHead2)
			return nullptr;
		if (!pHead1)
			return pHead2;
		if (!pHead2)
			return pHead1;
		ListNode *head = new ListNode(-1);
		ListNode *cur = head;
		while (pHead1 && pHead2)
		{
			if (pHead1->val <= pHead2->val)
			{
				cur->next = pHead1;
				pHead1 = pHead1->next;
			}
			else
			{
				cur->next = pHead2;
				pHead2 = pHead2->next;
			}
			cur = cur->next;
		}
		if (pHead1)
			cur->next = pHead1;
		else if (pHead2)
			cur->next = pHead2;
		return head->next;
    }
};

//第二次
/*
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
		if (!pHead1)
			return pHead2;
		else if (!pHead2)
			return pHead1;
		ListNode *head = nullptr;
		if (pHead1->val <= pHead2->val)
		{
			head = pHead1;
			head->next = Merge(pHead1->next, pHead2);
		}
		else
		{
			head = pHead2;
			head->next = Merge(pHead1, pHead2->next);
		}
		return head;
    }
};
*/