// 分析：
// 方法一：最开始想到的思路是利用快排。首先对原数组一个数进行快排，其位置确定
// 后如果在k的左边，则还需要对该位置到end进行快排，直到确定了k的位置。
// 则k位置左边的数即为最小的k个数，然后利用快排对最小k个数进行排序，返回
// 排序后的结果。该算法在编译器上测试正常，但牛客网未能通过，错误为递归
// 层次太多。原因为边界判断少加，在GetLeastNumbers_Solution开始加上边界
// 判断即可。

// 方法二：采用multiset，multiset采用红黑树实现，其第一个元素即为最大值，
// 每次插入都将会被调整到合适位置。

//方法一：利用快排
class Solution {
public:
	int Partition(vector<int> &input, int start, int end)
	{
		int flag = input[start];
		int i = start, j = end;

		while (i < j)
		{
			while (i < j && input[j] >= flag)
				j--;
			while (i < j && input[i] <= flag)
				i++;
			if (i < j)
			{
				int tmp = input[j];
				input[j] = input[i];
				input[i] = tmp;
			}
		}
		input[start] = input[i];
		input[i] = flag;

		return i;
	}

	void quicksort(vector<int> &input, int start, int end)
	{
		int index;
		if (start < end)
		{
			index = Partition(input, start, end);
			quicksort(input, start, index - 1);
			quicksort(input, index + 1, end);
		}
	}

    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (input.size() < k)
            return result;
        if (input.size() == k)
            return input;
        if (k <= 0)
            return result;
        
        int start = 0;
		int end = input.size() - 1;
		int index = Partition(input, start, end);

		while (index != k)
		{
			if (index < k)
			{
				index = Partition(input, index + 1, end);
			}
			else if (index > k)
			{
				index = Partition(input, start, index - 1);
			}
		}

		end = index;
		quicksort(input, start, end);

		for (int i = 0; i < k; i++)
		{
			int tmp = input[i];
			result.push_back(tmp);
		}

		return result;
    }
private:
	vector<int> result;
};

//方法二：利用红黑树
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		if (input.size() < k)
			return vector<int>();
		multiset<int, greater<int>> inset; //采用升序
		for (auto num : input)
		{
			if (inset.size() < k)
                inset.insert(num);
			else
			{
				auto iter = inset.begin();
				if (*iter > num)
				{
					inset.erase(iter);
					inset.insert(num);
				}
			}
		}

        result = vector<int>(inset.begin(), inset.end());
		return result;
    }
private:
	vector<int> result;
};