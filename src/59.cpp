/*
给定一个长度为 n 的非降序数组和一个非负数整数 k ，要求统计 k 在数组中出现的次数.

分析：
直接使用递归+二分的方式，由于是非降序数组，中位数mid如果大于k，则需要统计的部分在start-mid区间，
中位数mid如果小于k，则需要统计的部分在mid-end区间。中位数mid如果等于k，则需要统计的部分分别在
start-mid与mid-end区间。
终止条件：区间内只包含一个元素，如果值等于k，则找到一个元素，如果不等于k，则当次dfs没有找到元素。
*/

class Solution {
public:
    void dfs(vector<int> &data, int start, int end, int k)
    {
        int mid = start + (end - start) / 2;

        if (start == end - 1)
        {
            if (data[start] == k)
                count++;
            return;
        }

        if (data[mid] > k)
            dfs(data, start, mid, k);
        else if (data[mid] < k)
            dfs(data, mid, end, k);
        else
        {
            dfs(data, start, mid, k);
            dfs(data, mid, end, k);
        }
    }

    int GetNumberOfK(vector<int> data ,int k) {
        if (data.empty())
            return 0;

        count = 0;
        dfs(data, 0, data.size(), k);
        return count;
    }

private:
    int count;
};