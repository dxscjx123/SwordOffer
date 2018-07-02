// 分析：
// 这个题的实质是一个归并排序。但在最后对有序数组进行合并时，采用从两个
// 数组的最后一个下标开始往前合并，并统计逆序的次数。因为两个数组的末尾
// 下标分别是两个子数组的最大值，当前一最大值大于后一最大值，则逆序数等
// 于后一数组的现有长度。

class Solution {
public:
	void merge(vector<int> &data, int start, int middle, int end)
	{
		stack<int> tmp;
		int i = middle, j = end;
		while (i >= start && j >= middle + 1)
		{
			if (data[i] > data[j])
			{
				tmp.push(data[i]);
				i--;
				result += (j - middle);
			}
			else
			{
				tmp.push(data[j]);
				j--;
			}
		}
		while (i >= start)
		{
			tmp.push(data[i]);
			i--;
		}
		while (j >= middle + 1)
		{
			tmp.push(data[j]);
			j--;
		}
		for (int k = start; k <= end; k++)
		{
			int s_tmp = tmp.top();
			data[k] = s_tmp;
			tmp.pop();
		}
	}

	void merge_sort(vector<int> &data, int start, int end)
	{
		if (start == end)
			return;

		int middle = (start + end) / 2;
		merge_sort(data, start, middle);
		merge_sort(data, middle+1, end);

		merge(data, start, middle, end);
	}

    int InversePairs(vector<int> data) {
        if (data.empty())
			return 0;

        result = 0;
		int length = data.size() - 1;
		merge_sort(data, 0, length);

		return result % 1000000007;
    }

private:
	unsigned long result;
};

//第二次
/*
class Solution {
public:
	void merge(vector<int> &data, int start_1, int end_1, int start_2, int end_2)
	{
		int i = end_1;
		int j = end_2;
		while (i >= start_1 && j >= start_2)
		{
			if (data[i] > data[j])
			{
				result += (j - start_2 + 1);
				i--;
			}
			else
				j--;
		}
		auto iter_begin = data.begin() + start_1;
		auto iter_end = data.begin() + end_2 + 1;
		sort(iter_begin, iter_end);
	}

	void mergesort(vector<int> &data, int start, int end)
	{
		if (start >= end)
			return ;
		int middle = (start + end) / 2;
		mergesort(data, start, middle);
		mergesort(data, middle + 1, end);
		merge(data, start, middle, middle + 1, end);
	}

    int InversePairs(vector<int> data) {
        if (data.empty())
        	return 0;
        result = 0;
        int start = 0;
        int end = data.size() - 1;
        mergesort(data, start, end);
    	return result % 1000000007;
    }
private:
	unsigned long result;
};
*/