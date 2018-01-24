// 分析：
// 分为两步进行。第一步，对原链表进行复制，并返回复制后的头结点；第二步
// 对复制后的链表的random指针进行处理，具体处理方式为在第一步中对原节点对应
// 的复制节点，建立<原，复制后>的hash表，用于在O(1)复杂度内找到原节点的random
// 节点。

class Solution {
public:
	RandomListNode *CloneNode(RandomListNode *pHead)
	{
		RandomListNode *cpHead = new RandomListNode(-1);

		RandomListNode *cpNode = cpHead;
		RandomListNode *pNode = pHead;
		while (pNode)
		{
			RandomListNode *tmp_cpNode = new RandomListNode(0);
			tmp_cpNode->label = pNode->label;
			tmp_cpNode->next = pNode->next;
			tmp_cpNode->random = nullptr;
			cpNode->next = tmp_cpNode;

			cpNode = cpNode->next;

            mapping[pNode] = cpNode;

			pNode = pNode->next;
		}
		return cpHead->next;
	}

	void SetSiblingNode(RandomListNode *cpHead, RandomListNode *pHead)
	{
		RandomListNode *pNode = pHead;
		RandomListNode *cpNode = cpHead;
		while (pNode && cpNode)
		{
		    RandomListNode *pSibNode = pNode->random;
		    RandomListNode *cpSibNode;
		    if (pSibNode != nullptr)
                cpSibNode = mapping[pSibNode];
            else
                cpSibNode = nullptr;
			cpNode->random = cpSibNode;

			cpNode = cpNode->next;
			pNode = pNode->next;
		}
	}

    RandomListNode* Clone(RandomListNode* pHead)
    {
		if (!pHead)
			return nullptr;

		RandomListNode *cpHead = CloneNode(pHead);
		SetSiblingNode(cpHead, pHead);

		return cpHead;
    }
private:
	unordered_map<RandomListNode *, RandomListNode *> mapping;
};