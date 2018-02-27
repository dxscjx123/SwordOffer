// 分析：
// 由于需要对字符串进行反转，直接想到的就是利用stack结构。

class Solution {
public:
    string ReverseSentence(string str) {
        string result;
		if (str.empty())
			return result;
		stack<string> reverse_str;
		string each_str;
		for (auto s : str)
		{
		    if (s == ' ')
            {
                reverse_str.push(each_str);
                each_str.clear();
            }
            else
                each_str += s;
		}
		reverse_str.push(each_str);

		while (!reverse_str.empty())
		{
			string tmp = reverse_str.top();
			reverse_str.pop();
			result += tmp;
			if (!reverse_str.empty())
                result += ' ';
		}
		return result;
    }
};