// 分析：
// 对于数字超过了数组长度的一半，则排序后的数组其中位数应该为该数字。
// 故利用快排的思想对数组进行排序，排序不需全部完成，当一次排序结束
// 后判断当前数是不是中位数，如果在中位数左边，则对右边数组进行快排，
// 在右边，则对左边数组进行快排，直到返回中位数。进一步判断当前中位数
// 是否满足大于一般长度的性质。


class Solution {
public:
    int Partition(vector<int> &numbers, int start, int end)
    {
        int flag = numbers[start];
        int i = start, j = end;

        while (i < j)
        {
            while (i < j && numbers[j] >= flag)
                j--;
            while (i < j && numbers[i] <= flag)
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

    bool checkvalid(vector<int> &numbers, int number)
    {
        int times = 0;
        for (auto num : numbers)
        {
            if (num == number)
                ++times;
        }

        bool result = false;
        if (times > numbers.size() / 2)
            result = true;
        return result;
    }

    int MoreThanHalfNum_Solution(vector<int> &numbers) {
        int start = 0;
        int end = numbers.size() - 1;
        int middle = (start + end) / 2;
        int index = Partition(numbers, start, end);

        while (index != middle)
        {
            if (index < middle)
            {
                index = Partition(numbers, index + 1, end);
            }
            else if (index > middle)
            {
                index = Partition(numbers, start, index - 1);
            }
        }

        int num = numbers[index];
        if (checkvalid(numbers, num))
            return num;
        return 0;
	}
};