// 分析：
// 由于原数组为一个非降序数组，则新数组第一个元素不小于最后一个
// 元素，新数组由两个非降序的子数组构成。定义两个指针，分别指向
// 数组第一个和最后一个元素，数组中位数分别比较两个指针元素，以
// 此判断中位数元素属于哪个子数组，并将指针指向新的位置。最终指
// 针指向前一子数组的最大数，后一子数组的最小位（返回），相差1。

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
		if(rotateArray.size() == 0)
			return 0;
		int a_start = 0;
		int a_end = rotateArray.size() - 1;
		int middle, result = rotateArray[a_start];   
		//如果array只有两个元素，且为顺序（1，2），则不进入while循环，故需要对result赋初值
		while(rotateArray[a_start] >= rotateArray[a_end])
		{
			if(a_start+1 == a_end)
			{
				result = rotateArray[a_end];
				break;
			}
			middle = (a_start + a_end) / 2;
			if(rotateArray[middle] >= rotateArray[a_start])
				a_start = middle;
			else if(rotateArray[middle] <= rotateArray[a_end])
				a_end = middle;
		}
		return result;
	}
};