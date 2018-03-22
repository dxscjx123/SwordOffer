// 分析：
// 比较类似上一条，采用dfs做深搜，并对已访问节点做标记。主要是isvalid函数的判别方式，进行了修改。

class Solution {
public:
	bool isvalid(int threshold, int cur_row, int cur_col)
	{
		bool result = true;
		int tmp = 0;
		while (cur_row)
		{
			tmp += cur_row % 10;
			cur_row = cur_row / 10;
		}
		while (cur_col)
		{
			tmp += cur_col % 10;
			cur_col = cur_col / 10;
		}
		if (tmp > threshold)
			result = false;
		return result;
	}

	void dfs(int threshold, int rows, int cols, int cur_row, int cur_col)
	{
		visit[cur_row][cur_col] = 1;
		result += 1;
		if (cur_row - 1 >= 0 && isvalid(threshold, cur_row - 1, cur_col) && !visit[cur_row - 1][cur_col])
			dfs(threshold, rows, cols, cur_row - 1, cur_col);
		if (cur_row + 1 < rows && isvalid(threshold, cur_row + 1, cur_col) && !visit[cur_row + 1][cur_col])
			dfs(threshold, rows, cols, cur_row + 1, cur_col);
		if (cur_col - 1 >= 0 && isvalid(threshold, cur_row, cur_col - 1) && !visit[cur_row][cur_col - 1])
			dfs(threshold, rows, cols, cur_row, cur_col - 1);
		if (cur_col + 1 < cols && isvalid(threshold, cur_row, cur_col + 1) && !visit[cur_row][cur_col + 1])
			dfs(threshold, rows, cols, cur_row, cur_col + 1);
	}

    int movingCount(int threshold, int rows, int cols)
    {
		if (threshold < 0)
			return 0;
        if (threshold == 0)
			return 1;
		result = 0;
		visit.resize(rows, vector<int>(cols, 0));
		dfs(threshold, rows, cols, 0, 0);
		return result;
    }
private:
	int result;
	vector<vector<int>> visit;
};