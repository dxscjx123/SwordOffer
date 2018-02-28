// 分析：
// 对于5张牌（小于5张为false）将其进行排序，统计排序后0出现的次数。
// 并相应计算其他各个相邻数之间的差值和，如果差值和大于了0出现的次数，
// 则不能够排成顺子。
// 这里对数组进行排序采用快排比较合适，自行实现的快排算法在编译器上
// 没有问题，但牛客网编译提示内存超过限制。故使用了stl的sort函数。

class Solution {
public:
	int Partition(vector<int> &numbers, int start, int end)
	{
		int i = start;
		int j = end;
		int flag = numbers[i];
		while (i <= j)
		{
			while (i <= j && numbers[j] >= flag)
				j--;
			while (i <= j && numbers[i] <= flag)
				i++;
			if (i <= j)
			{
				int temp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = temp;
			}
		}
		numbers[start] = numbers[i];
		numbers[i] = flag;
		return i;
	}

	void quicksort(vector<int> &numbers, int start, int end)
	{
		if (start >= end)
			return;
		int index = Partition(numbers, start, end);
		quicksort(numbers, start, index);
		quicksort(numbers, index + 1, end);
	}

    bool IsContinuous( vector<int> numbers ) {
        if (numbers.size() < 5)
			return false;

		//quicksort(numbers, 0, numbers.size() - 1);
		sort(numbers.begin(),numbers.end());

		bool result = true;
		int zerocount = 0;
		int gapsum = 0;
		for (int i = 0; i < numbers.size(); ++i)
		{
			if (numbers[i] == 0)
				zerocount++;
			else if (i + 1 < numbers.size())
			{
				int gapcal = numbers[i+1] - numbers[i] - 1;
				if (gapcal == -1)
				{
					result = false;
					break;
				}
				gapsum = gapsum + gapcal;
			}
		}
		if (gapsum > zerocount)
			result = false;
		return result;
    }
};