// 分析：
// 这个题的第一反应就是回溯法，直接就用回溯法写了，但最优解的方案，后续
// 再考虑最优解的方案，先记录本题思路。
// 对于整个字符串，建立一个字符串长度的vector，用于标记哪些元素被访问，每次
// 从访问未被访问的元素。
// 需要考虑的一种特殊情况，输入为aa，输出为aa，aa，没有对元素进行排重，故建立
// 了一个set，对多余的元素进行排重。

class Solution {
public:
	void dfs(string str, string oneresult)
	{
		if (oneresult.size() == str.size())
		{
			if (setting.find(oneresult) == setting.end())
			{
				setting.insert(oneresult);
				result.push_back(oneresult);
			}
			return ;
		}
		
		for (int i = 0; i < str.size(); ++i)
		{
			if (!visit[i])
			{
				visit[i] = 1;
				dfs(str, oneresult + str[i]);
				visit[i] = 0;
			}
		}
	}

    vector<string> Permutation(string str) {
        if (str.empty())
			return vector<string>();
		string oneresult;
		visit = vector<int>(str.size(), 0);
		dfs(str, oneresult);
		return result;
    }
private:
	vector<string> result;
	set<string> setting;
	vector<int> visit;
};