// 分析：
// push方法同栈，定义一个栈stack1，将元素压入即可
// pop方法：定义另一个栈stack2。需要出队时，将stack1中的元素
// 弹出压入stack2，并返回stack1弹出的栈底元素。后续出队，若
// stack2中仍有元素，则直接弹出stack2顶部，否则将stack1弹出
// 并压入stack2，入队直接压入stack1。

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
		int stack1_size = stack1.size();
		int stack2_size = stack2.size();
		
		if(stack2_size != 0)
		{
			int result = stack2.top();
			stack2.pop();
			return result;
		}
		for(int i = 0; i < stack1_size; i++)
		{
			int tmp = stack1.top();
			stack2.push(tmp);
			stack1.pop();
		}
		int result = stack2.top();
		stack2.pop();
		return result;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

//第二次，优化了可读性
/*
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
		int ret;
        if (stack2.empty())
		{
			while (!stack1.empty())
			{
				int val = stack1.top();
				stack1.pop();
				stack2.push(val);
			}
		}
		ret = stack2.top();
		stack2.pop();
		return ret;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
*/