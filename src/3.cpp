// 分析：
// 定义一个新vector，遍历链表，将新元素插入到vector始端

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> v_arr;
        if (head == nullptr)
			return v_arr;
		struct ListNode *phead = head;
		while(phead)
		{
			//struct ListNode *node = ListNode(phead->val);
            struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode*));
            node->val = phead->val;
            node->next = nullptr;
			v_arr.insert(v_arr.begin(), node->val);
			phead = phead -> next;
		}
		return v_arr;
    }
};