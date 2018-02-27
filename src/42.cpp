// 分析：
// 从n处分隔，对0-n-1进行翻转，再对n-length-1进行翻转，最后对0-length-1进行翻转。

class Solution {
public:
	void Reverse(string &str, int begin, int end)
	{
		while (begin <= end)
		{
			char s = str[begin];
			str[begin] = str[end];
			str[end] = s;
			
			begin++;
			end--;
		}
	}
	
    string LeftRotateString(string str, int n) {
        if (str.empty() || n == 0 || n == str.size())
			return str;
		int length = str.size();
		Reverse(str, 0, n - 1);
		Reverse(str, n, length - 1);
		Reverse(str, 0, length - 1);
		return str;
    }
};