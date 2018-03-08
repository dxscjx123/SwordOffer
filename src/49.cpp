// 分析：
// 说思路之前先吐槽一下这个题，题干不是说的“一个链表中包含环”，默认
// 就是一个带环的链表啊，为什么还会存在不带环链表！！！

// 这个题主要是思路，想到了比较好写。一个带环链表，如果要找到环的入口，
// 只需要设置两个指针，环的长度为n，一个指针先走n步，然后两个指针同时
// 走，当两个节点相等时即为环的入口（可以类比找链表的倒数第k个节点）。

// 然后如何计算环的长度，采用快慢指针的方法找到指针相等的节点，该节点
// 肯定位于环上，然后再从该点出发，计算遍历的步长，回到该节点时即为环
// 的长度。

class Solution {
public:
	int loopcount(ListNode *phead)
	{
		bool isfound = false;
		ListNode *fast = phead;
		ListNode *slow = phead;

		while (slow->next && fast->next->next)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
			{
				isfound = true;
				break;
			}
		}

		if (!isfound)
			return 0;

		ListNode *curnode = slow->next;  //从下一个节点出发
		int loop_len = 1;   //由于是从下一个节点出发，需要先加入当前节点
		while (curnode != slow)   //到达当前节点
		{
			loop_len++;
			curnode = curnode->next;
		}
		return loop_len;
	}

    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
		if (!pHead)
			return nullptr;
		int loop_len = loopcount(pHead);
		if (loop_len == 0)   //等于0证明没有环，返回空。
			return nullptr;
		ListNode *p = pHead;
		ListNode *q = pHead;
		while (loop_len)
		{
			p = p->next;
			loop_len--;
		}
		while (p != q)
		{
			p = p->next;
			q = q->next;
		}
		return p;
    }
};