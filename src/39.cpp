// 分析：
// 由于数组是递增有序的，定义头指针和尾指针。头+尾>num,尾后移，头+尾<num，
// 头前移。找到满足条件的元素，判断乘积大小是否进一步满足条件，更新结果。

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        if (array.empty())
			return vector<int>();

		int start = 0;
		int end = array.size() - 1;

		int head, tail;
		int cursum = 0;
		int product = INT_MAX;

		bool found = false;

		while (start < end)
		{
			head = array[start];
			tail = array[end];
			cursum = head + tail;
			if (cursum == sum)
			{
				int tmp_pro = head * tail;
				found = true;
				if (tmp_pro < product)
				{
					first = head;
					second = tail;
					product = tmp_pro;
				}
				start++;
				end--;
			}
			else if (cursum > sum)
				end--;
			else
				start++;
		}

        if (found)
            result = {first, second};
		return result;
    }
private:
	int first, second;
	vector<int> result;
};