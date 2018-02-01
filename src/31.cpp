// 分析：
// 最容易想到的思路是循环遍历每个数，判断是否为丑数，但时间复杂度太高，在
// 线oj没有通过编译，实现代码见注释。

// 改进后的方法采用空间换时间的策略，通过一个数组来存放排序好的丑数。而每次数组
// 的更新，是直接在原数组的基础上分别乘2，乘3，乘5，并将最邻近最大值的值更新到
// 原数组中。而由于数组是一个排序数组，可以定义三个指针，分别指向乘2,3,5的结果，
// 每次更新数组后，将指针更新。

// 注意：vector在插入元素后可能导致迭代器失效。由于vector的大小是动态声明的，如
// 果大于了系统默认大小后再添加元素，为保证所有元素存放在同一块内存区，系统会重
// 新定义新的vector，这样将会导致迭代器失效。故事先指明vector的长度，reserver(index)
// 避免上述问题。

class Solution {
public:
    int Min(int number_2, int number_3, int number_5)
    {
        int tmp = (number_2 < number_3) ? number_2 : number_3;
        int min_r = (tmp < number_5) ? tmp : number_5;
        return min_r;
    }

    int GetUglyNumber_Solution(int index) {
        if (index <= 0)
            return 0;

        result.reserve(index);

        auto iter_2 = result.begin();
        auto iter_3 = result.begin();
        auto iter_5 = result.begin();

        while (result.size() <= index)
        {
            int last_num = Min(*iter_2 * 2, *iter_3 * 3, *iter_5 * 5);
            result.push_back(last_num);

            while (iter_2 != result.end() && *iter_2 * 2 <= last_num)
                iter_2++;
            while (iter_3 != result.end() && *iter_3 * 3 <= last_num)
                iter_3++;
            while (iter_5 != result.end() && *iter_5 * 5 <= last_num)
                iter_5++;
        }

        return result[result.size() - 2];
    }
private:
    vector<int> result = {1};
};

/*
class Solution {
public:
	bool uglynum(int number)
	{
		bool uglyresult = false;

        auto iter = result.rbegin();
        for (; iter != result.rend(); ++iter)
        {
            int r = *iter;
            if (number % r == 0)
                number = number / r;
            if (number == result[0])
            {
                uglyresult = true;
                break;
            }
        }

        return uglyresult;
	}

    int GetUglyNumber_Solution(int index) {
		if (index <= 1)
			return index;

		int number = 1;
		while (counts != index)
		{
            ++number;
			if (uglynum(number))
            {
                result.push_back(number);
                ++counts;
            }
		}
		return number;
    }
private:
    vector<int> result = {1, 2, 3, 5};
    int counts = 1;
};
*/