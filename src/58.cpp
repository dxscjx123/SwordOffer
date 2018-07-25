// 分析：
// 用一个哈希表来维护元素的个数，每次插入元素，更新哈希表
// 返回结果，遍历string，判断哈希值
// 优化：
// 由于存储的是单个字符，占用1个字节，即8位，共有256个值
// 故可直接使用char hash[256]来表示哈希表结构

class Solution
{
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
        str.push_back(ch);
        hash[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        for (auto ch : str)
            if (hash[ch] == 1) return ch;
        return '#';
    }
private:
    string str;
    char hash[256];
};