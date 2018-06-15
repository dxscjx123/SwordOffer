// 分析：
// 由于原数组为一个非降序数组，则新数组第一个元素不小于最后一个
// 元素，新数组由两个非降序的子数组构成。定义两个指针，分别指向
// 数组第一个和最后一个元素，数组中位数分别比较两个指针元素，以
// 此判断中位数元素属于哪个子数组，并将指针指向新的位置。最终指
// 针指向前一子数组的最大数，后一子数组的最小位（返回），相差1。

// 有三种情况
// 1）新数组有序：1,2,3,4,5，这种直接判断第一个和最后一个大小，如果
// array[start] < array[end]，则直接返回array[start]即可
// 2）start，middle，end三个位置的元素都相同，这种没有办法移动start
// 或end指针，只能从start到end逐一判断
// 3）一般情况，即3,4,5,1,2，二分法判断，可以选定比较只和start比较
// 或者只和end比较。

class Solution {
public:
	int minnumber(vector<int> &rotateArray, int start, int end)
	{
		int ret = rotateArray[start];
		for (int i = start + 1; i <= end; ++i)
		{
			if (rotateArray[i] < ret)
				ret = rotateArray[i];
		}
		return ret;
	}

    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty())
			return 0;
		int result = rotateArray[0];
		int start = 0;
		int end = rotateArray.size() - 1;
		while (rotateArray[start] >= rotateArray[end])
		{
			if (start + 1 == end)
			{
				result = rotateArray[end];
				break;
			}
			int middle = (start + end) / 2;
			if (rotateArray[middle] > rotateArray[start])
				start = middle;
			else if (rotateArray[middle] < rotateArray[start])
				end = middle;
			else
			{
				result = minnumber(rotateArray, start, end);
				break;
			}
		}
		return result;
    }
};