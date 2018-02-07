// 分析：
// 找出两个链表的第一个公共节点，有两种思路：
// 第一种：
// 遍历两个链表，将遍历节点压栈，对最终两个栈中的元素进行出栈，由于栈顶元素
// 为两个链表的末尾元素，比较相同进行保存后弹栈，直到比较到不相同的元素，返回
// 先前保存的结果即为第一个公共节点。这个方法需要额外两个空间保存栈。
// 第二种：
// 如果两个链表长度相等，则直接遍历两个链表，比较当前节点是否相同即可。但对于
// 长度不相等的链表，不能这样进行比较，那考虑将长度不相等的链表转换为相同长度。
// 方法为遍历两个链表，计算两个链表的长度。将长的链表先行遍历（长-短）个元素，
// 此时两个链表长度相同，再同时遍历。

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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if (!pHead1 || !pHead2)
			return nullptr;
		
		ListNode *pNode1 = pHead1;
		ListNode *pNode2 = pHead2;
		int length1 = 0;
		int length2 = 0;
		while (pNode1)
		{
			length1++;
			pNode1 = pNode1->next;
		}
		while (pNode2)
		{
			length2++;
			pNode2 = pNode2->next;
		}
		
		pNode1 = pHead1;
		pNode2 = pHead2;
		if (length1 > length2)
		{
			int dis = length1 - length2;
			while (dis)
			{
				pNode1 = pNode1->next;
				dis--;
			}
		}
		else if (length1 < length2)
		{
			int dis = length2 - length1;
			while (dis)
			{
				pNode2 = pNode2->next;
				dis--;
			}
		}
		
		ListNode *result = nullptr;
		while (pNode1 && pNode2)
		{
			if (pNode1 == pNode2)
			{
				result = pNode1;
				break;
			}
			pNode1 = pNode1->next;
			pNode2 = pNode2->next;
		}
		
		return result;
    }
};