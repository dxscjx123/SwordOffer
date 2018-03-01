// 分析：
// 这个题最主要的是把所有测试用例都想完整。主要有以下几点：
// 1）字符串为空，输出0；
// 2）字符串越界（上界和下界，int类型只有32位），输出0；
// 3）字符串开头有“+”或者“-”，会影响最后结果正负；
// 3）字符串有空格。这里需要细分：
	// a）空格在开头或者结尾，不影响中间数字的结果；
	// b）空格在数字中间，只会影响空格之后的数字，空格之前的正常输出。比如12 3，
	// 需正确输出12
	
class Solution {
public:
    int StrToInt(string str) {
        if (str.empty())
			return 0;
		int length = str.size();
		int index = 0;
		for (; index < length; ++index)  //查找字符串开头的空格
		{
			if (str[index] != ' ')
				break;
		}

		long long result = 0;
		bool isvalid = true;
		bool compare = true;;
		if (str[index] == '+')  //判断首字符是否是正负号
		{
			++index;  //正号直接从下一位开始
		}
		else if (str[index] == '-')
		{
			compare = false;   //负号则设置标志，从下一位开始
			++index;
		}

		for (; index < length; ++index)  //合法输入走到此处开头应该为数字
		{
			char s = str[index];
			if (s == ' ')  //数字中间存在空格
				break;
			else if (s < '0' || s > '9')  //非法输入
			{
				isvalid = false;
				break;
			}
			else if (result > 0x7fffffff || result < (signed int)0x80000000)  //越界
            {
                isvalid = false;
                break;
            }

			result = result * 10 + (s - '0');
		}

		if (!isvalid)
			return 0;
		if (!compare)
			return -result;
		return (int)result;
    }
};