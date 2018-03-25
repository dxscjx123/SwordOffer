// 分析：
// 由于需要对字符串进行反转，直接想到的就是利用stack结构。另外
// 一种方法是，先对整体做翻转，再对每一个字符串做翻转。

//方法一：stack
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

//方法二：
/*
class Solution {
public:
	void swap(char &start, char &end)
	{
		char c = start;
		start = end;
		end = c;
	}

	void reverse(string &str, int start, int end)
	{
		while (start < end)
		{
			swap(str[start], str[end]);
			start++;
			end--;
		}
	}

    string ReverseSentence(string str) {
        if (str.empty())
			return string();
		reverse(str, 0, str.size() - 1);
		int start = 0;
		int end = 0;
		while (start < str.size())
		{
			if (str[start] == ' ')
			{
				start++;
				end++;
			}
			else if (str[end] == ' ' || end == str.size())
			{
				reverse(str, start, end - 1);
				start = end + 1;
				end++;
			}
			else
				end++;
		}
		return str;
    }
};
*/