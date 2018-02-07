// 分析：
// 由于是有序数组，可以采用二分法，如果middle大于等于k，则k在start-middle，
// 如果middle小于等于k，则k在middle+1-end，递归终止条件判断当前元素是否等于
// k，若是则将结果加1。

class Solution {
public:
	void cal_numbers(vector<int> &data, int k, int start, int end)
	{
		if (start == end)
		{
			if (data[start] == k)
				result++;
			return;
		}
		
		int middle = (start + end) / 2;
		if (data[middle] >= k)
			cal_numbers(data, k, start, middle);
		if (data[middle] <= k)
			cal_numbers(data, k, middle + 1, end);
	}
	
    int GetNumberOfK(vector<int> data ,int k) {
        if (data.empty())
			return 0;
		
		result = 0;
		int start = 0;
		int end = data.size() - 1;
		cal_numbers(data, k, start, end);
		
		return result;
    }
private:
	int result;
};