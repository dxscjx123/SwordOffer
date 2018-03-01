// 分析：
// 建立循环链表，从初始值开始遍历。删除节点的操作可以为将next节点值复制给
// 当前节点，并删除next节点。直到当前节点的next指向自身，表明链表中只有一个
// 节点。

// 书上采用stl的list结构实现循环链表，当每次遍历到尾节点将其移动到初始节点即可。

class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
		if (n <= 1)
			return n - 1;
		
		ListNode *head = new ListNode(0);
		ListNode *curnode = head;
		for (int i = 1; i < n; ++i)
		{
			ListNode *node = new ListNode(i);
			curnode->next = node;
			curnode = curnode->next;
		}
		curnode->next = head;
		
		curnode = head;
		while (curnode->next != curnode)
		{
			int i = m;
			while (i != 1)
			{
				curnode = curnode->next;
				i--;
			}
			curnode->val = curnode->next->val;
			curnode->next = curnode->next->next;
		}
		
		return curnode->val;
    }
	
private:
	struct ListNode
	{
		int val;
		ListNode *next;
		ListNode(int x):val(x), next(nullptr){}
	};
};