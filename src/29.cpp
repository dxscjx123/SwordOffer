// 分析：
// 对于一个子串，如果和小于0，其对于后续最大和的计算都是没有贡献的，直接
// 抛弃，从新的位置开始重新计算子串和即可。

// 原方法中没有考虑到所有数全为负的情况：
// for (auto iter = array.begin(); iter != array.end(); ++iter)
// {
	// int curnum = *iter;
	// if (curnum + tmpsum < 0)
	// {
		// tmpsum = 0;
		// continue;
	// }
	// tmpsum += curnum;
	// if (tmpsum > sum)
		// sum = tmpsum;
// }

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
		int sum = INT_MIN;
		int tmpsum = 0;
		for (auto iter = array.begin(); iter != array.end(); ++iter)
		{
			int curnum = *iter;
			if (tmpsum <= 0)
				tmpsum = curnum;
			else 
				tmpsum += curnum;
			
			if (tmpsum > sum)
				sum = tmpsum;
		}
		return sum;
    }
};