// 分析：
// 这已经是第n次用快排思想做offer的题了- -。。
// 假设两个数12,13，1213<1312，则有12<13，这个结论的证明百度一大堆，
// 不再简述。利用这个结论，将待比较的两个数转换为string类型后进行比较，
// 并将整个数组进行从小到大的排序，最终将数组遍历并输出。
// 这里主要在于对INT_MIN的判断，compare函数中直接对string进行比较即可，
// string对运算符的重载能直接对两个字符串进行比较。

//更新了采用STL自带的sort进行排序的方法。

class Solution {
public:
	bool compare(int number, int flag)
	{
		string s_num = to_string(number);
		string s_flag = to_string(flag);

		string num_flag = s_num + s_flag;
		string flag_num = s_flag + s_num;

        if (num_flag < flag_num)
			return true;
		else if (num_flag > flag_num)
			return false;
		return true;
	}

	int Partition(vector<int> &numbers, int start, int end)
	{
		int flag = numbers[start];

		int i = start;
		int j = end;
		while (i < j)
		{
			while (i < j && !compare(numbers[j], flag))
				j--;
			while (i < j && compare(numbers[i], flag))
				i++;
			if (i < j)
			{
				int tmp = numbers[j];
				numbers[j] = numbers[i];
				numbers[i] = tmp;
			}
		}
		numbers[start] = numbers[i];
		numbers[i] = flag;

		return i;
	}

	void quicksort(vector<int> &numbers, int start, int end)
	{
		if (start < end)
		{
			int index = Partition(numbers, start, end);
			quicksort(numbers, start, index - 1);
			quicksort(numbers, index + 1, end);
		}
	}

    string PrintMinNumber(vector<int> &numbers) {
		if (numbers.empty())
			return result;

		/*int start = 0;
		int end = numbers.size() - 1;
		quicksort(numbers, start, end);*/

		auto newfun = bind(&Solution::compare, this, placeholders::_1, placeholders::_2);
		sort(numbers.begin(), numbers.end(), newfun);

		for (int i = 0; i < numbers.size(); ++i)
		{
			string tmp = to_string(numbers[i]);
			result += tmp;
		}

		return result;
	}
private:
	string result;
};