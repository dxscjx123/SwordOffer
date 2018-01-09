// 分析：
// 1、遍历一次字符串对计算空格数，并分配替换后新字符
// 串的长度；
// 2、进行替换。时间复杂度为O(n)

class Solution {
public:
	void replaceSpace(char *str,int length) {
        char *p1, *p2;
		//int length = len(src);
		int blank_count = 0;
		for(int i = 0; i < length; i++)
		{
			if(str[i] == ' ')
			{
				blank_count ++;
			}
		}
		p1 = str + length;
		p2 = str + length + 2 * blank_count;
        int length_count = p1 - str + 1;
		while (length_count != 0)
		{
			if (*p1 != ' ')
			{
				*p2 = *p1;
				p1 --;
				p2 --;
			}
			else
			{
				*p2 = '0';
				p2 --;
				*p2 = '2';
				p2 --;
				*p2 = '%';
				p1 --;
				p2 --;
			}
            length_count --;
		}
		return ;
	}
};