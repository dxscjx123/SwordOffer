// 分析：
// 二维数组右上角的元素i是该行的最大值，是该列的最小值。
// 比较待查元素j与i，j>i删除所在行，反之删除所在列

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
		if (array.size() == 0)
			return false;
        int rows = array.size();
		int columns = array[0].size();
		int row = 0, column = columns - 1;
		while (row < rows && column >= 0)
		{
			int compare = array[row][column];
			if (target == compare)
				return true;
			if (target < compare)
			{
				column --;
			}
			else if (target > compare)
			{
				row ++;
			}
		}
		return false;
    }
};