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

//第二次
/*
class Solution {
public:
	void binary_search(vector<int> &data, int start, int end, int k)
	{
	    if (start > end)
            return ;
		int mid;
		
		//plan 1 begin
		while (start <= end) //查找中间项，如果data[mid]==k，则分为start-mid-1与mid+1-end进行查找
		{
			mid = (start + end) / 2;
			if (data[mid] < k)
				start = mid + 1;
			else if (data[mid] > k)
				end = mid - 1;
			else //相等，则表示已找到一个。
            {
                result++;
                break;
            }
		}
		if (start > end)
            return ;
        //plan 1 end
		
		//plan 2 begin
        mid = (start + end) / 2;
        if (data[mid] < k)
            start = mid + 1;
        else if (data[mid] > k)
            end = mid - 1;
        else
            result++;
		//plan 2 end
		
		binary_search(data, start, mid - 1, k);
		binary_search(data, mid + 1, end, k);
	}

    int GetNumberOfK(vector<int> data ,int k) {
        if (data.empty())
        	return 0;
        int start = 0;
        int end = data.size() - 1;
        result = 0;
        binary_search(data, start, end, k);
        return result;
    }
private:
	int result;
};
*/