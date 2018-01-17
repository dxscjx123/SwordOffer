// 分析：
// 这个题稍微麻烦的地方主要是要求栈的最小值。如果采用循环遍历返回最小值的
// 方法，时间复杂度是O(N)不是O(1)。最初想到的方法是变量min_stack，用来在每
// 次入栈比较value，并更新min_stack，但细想在出栈时无法确定最小值是否已经
// 出栈，故方法不可取。再细想，只用在每次入栈时，将比当前最小值还小的元素
// 入新栈即可。定义一个辅助栈，若新的元素比最小值还小，将其入辅助栈。出栈
// 时比较辅助栈顶，如果出栈元素等于了辅助栈顶元素，证明当前最小值出栈，将
// 辅助栈同时出栈，保证辅助栈栈顶保存的是当前栈的最小值。


class Solution {
public:
    void push(int value) {
		if (stack.empty())
		{
			stack.push_back(value);
			assist_stack.push_back(value);
		}
		else
		{
			if (stack[stack.size() - 1] > value)
				assist_stack.push_back(value);
			stack.push_back(value);
		}
    }
    void pop() {
		if (stack[stack.size() - 1] == assist_stack[assist_stack.size() - 1])
			assist_stack.pop_back();
        stack.pop_back();
    }
    int top() {
        int stack_top = stack[stack.size() - 1];
		return stack_top;
    }
    int min() {
        return assist_stack[assist_stack.size() - 1];
    }
private:
	vector<int> stack;
	vector<int> assist_stack;
};