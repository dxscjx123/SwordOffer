// 分析：
// 两个指针指向两个链表，满足条件则将对应指针指向下一个结点。但两个指针
// 任意一个为空，表明一个链表遍历结束，将另一个链表的下一个结点指向当
// 前指针（因为下一个链表的剩余元素均为排序元素）

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if ((pHead1 == nullptr) && (pHead2 == nullptr))
			return nullptr;
		if (pHead1 && !pHead2)
			return pHead1;
		else if (!pHead1 && pHead2)
			return pHead2;
        struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode*));
        head->val = -1;
		head->next = nullptr;
		struct ListNode *p = head;
		while ((pHead1 != nullptr) && (pHead2 != nullptr))
		{
			if (pHead1->val > pHead2->val)
			{
				p->next = pHead2;
				pHead2 = pHead2->next;
			}
			else if (pHead1->val <= pHead2->val)
			{
				p->next = pHead1;
				pHead1 = pHead1->next;
			}
			p = p->next;
		}
		if (pHead1)
		{
		    p->next = pHead1;
		}
		else if(pHead2)
		{
		    p->next = pHead2;
		}

		return head->next;
    }
};