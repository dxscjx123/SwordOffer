// 分析：
// 这个题做的我很无语。最初想到的就是利用哈希表，但发现无论如何
// 都要遍历两次数组，觉得肯定有更简单的方式。结果。。。

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
		if (str.empty())
			return -1;
			
        for (auto s : str)
		{
			if (mapping.find(s) == mapping.end())
				mapping[s] = 1;
			else 
				mapping[s] += 1;
		}
		
		for (int i = 0; i < str.size(); ++i)
		{
			char s = str[i];
			if (mapping[s] == 1)
			{
				result = i;
				break;
			}
		}
		return result;
    }
private:
	unordered_map<char, int> mapping;
	int result;
};