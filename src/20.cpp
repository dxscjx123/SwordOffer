// 分析：
// 这个题其实思路还是很明确的，将pushV与popV第一个元素比较，如果不相同
// 则压栈，直到相同，弹栈进行比较。当pushV或popV任意一个遍历到尾部时，
// 返回当前栈是否为空。为空表明所有元素都正确弹栈，否则表明存在不能弹
// 栈元素，即弹出序列不一致。（此题进行扩展可以为判断队列入队出队顺序，
// 今日头条实习生笔试题）

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
		if (pushV.empty() || popV.empty())
			return false;
		int j = 0;
		for (int i = 0; i < pushV.size(); i++)
		{
			s.push(pushV[i]);
			while ((j < popV.size()) && (popV[j] == s.top()))
			{
				s.pop();
				j++;
			}
		}

		return s.empty();
    }
private:
	stack<int> s;
};