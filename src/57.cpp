// 分析：
// 对每一个区间内的数，对10取余可以得到个位数，再一次对10做整除

class Solution {
public:
	int count_number(int num)
	{
		int count = 0;
		while (num)
		{
			if (num % 10 == 1)
				count++;
			num = num / 10;
		}
		return count;
	}

    int NumberOf1Between1AndN_Solution(int n)
    {
    	if (n < 1)
    		return 0;
    	int result = 0;
    	for (int i = 1; i <= n; ++i)
    	{
    		result += count_number(i);
    	}
    	return result;
    }
};
