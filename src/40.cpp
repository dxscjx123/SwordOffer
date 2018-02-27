// 分析：
// 由于需要找出的子序列为连续递增序列。设置small和big值，cursum=small+big，
// 如果cursum小于给定sum，则将big加1并增加cursum值；如果cursum大于给定sum，
// 则把cursum减去初small值将small加1,；cursum等于给定sum，将结果保存。
// small值等于(sum+1)/2时为终止条件。

// 不进行优化的方法见注释，即对cursum每次都重新计算新值，产生了冗余计算。

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > result;
		if (sum <= 2)
			return result;
		int small = 1;
		int big = 2;
		int cursum = small + big;
		while (small <= (sum + 1) / 2)
		{
			if (cursum < sum)
			{
				big++;
				cursum += big;
			}
			else if (cursum > sum)
			{
				cursum -= small;
				small++;
			}
			else
			{
				vector<int> tmp;
				for (int i = small; i <= big; i++)
					tmp.push_back(i);
				result.push_back(tmp);
				
				cursum -= small;
				small++;
			}
		}
		return result;
    }
};

/*
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > result;
		if (sum <= 2)
			return result;
		int small = 1;
		int big = 2;
		while (small <= (sum + 1) / 2)
		{
			int cursum = 0;
			for (int i = small; i <= big; i++)
				cursum += i;
			if (cursum < sum)
				big++;
			else if (cursum > sum)
				small++;
			else
			{
				vector<int> tmp;
				for (int i = small; i <= big; i++)
					tmp.push_back(i);
				result.push_back(tmp);
				small++;
			}
		}
		return result;
    }
};
*/