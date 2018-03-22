// 分析：
// 对图进行深搜，对遍历的节点进行标记，标记节点不再进行访问。

class Solution {
public:
	bool isvalid(char *matrix, int row, int col, char *str, int str_len)
	{
		bool result = true;
		if (matrix[row * matrix_cols + col] != str[str_len])
			result = false;
		return result;
	}

	void findpath(char *matrix, int matrix_cur, char *str, int str_len)
	{
		visit[matrix_cur] = 1;
		str_len++;
		if (str_len == strlen(str))
		{
			result = true;
			return ;
		}
		int row = matrix_cur / matrix_cols;
		int col = matrix_cur % matrix_cols;
		if (row - 1 >= 0 && isvalid(matrix, row - 1, col, str, str_len) && !visit[(row - 1) * matrix_cols + col])
			findpath(matrix, (row - 1) * matrix_cols + col, str, str_len);
		if (row + 1 < matrix_rows && isvalid(matrix, row + 1, col, str, str_len) && !visit[(row + 1) *matrix_cols + col])
			findpath(matrix, (row + 1) *matrix_cols + col, str, str_len);
		if (col - 1 >= 0 && isvalid(matrix, row, col - 1, str, str_len) && !visit[row * matrix_cols + (col - 1)])
			findpath(matrix, row * matrix_cols + (col - 1), str, str_len);
		if (col + 1 < matrix_cols && isvalid(matrix, row, col + 1, str, str_len) && !visit[row * matrix_cols + (col + 1)])
			findpath(matrix, row * matrix_cols + (col + 1), str, str_len);
	}

    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
		if (rows == 0 && cols == 0)
			return false;

		result = false;
		visit = new int[rows * cols];
		memset(visit, 0, sizeof(int) * rows * cols);
		matrix_rows = rows;
		matrix_cols = cols;

		for (int i = 0; i < rows * cols; ++i)
		{
			char c = str[0];
			if (matrix[i] == c)
            {
				findpath(matrix, i, str, 0);
            }
			memset(visit, 0, sizeof(int) * rows * cols);
		}
		delete []visit;
		return result;
    }
private:
	bool result;
	int *visit;
	int matrix_rows;
	int matrix_cols;
};