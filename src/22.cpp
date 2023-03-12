// 分析：
// 一个7个节点的后序遍历的例子：4,8,6,12,16,14,10。根据后序遍历的
// 性质，10为二叉搜索树的根节点。而对应的，根节点的左子树都小于根节点
// 右子树都大于根节点。通过遍历给定序列，找出左右子树分界位置。并判断
// 左右子树的所有节点是否满足左子树小于根节点，右子树大于根节点的性质。
// 若不满足，直接返回false。否则根据是否存在左右子树，递归判断左右子树
// 是否是一个二叉搜索树。
// 一个小技巧是，子树只有在不满足一定条件下返回false，而不能判断是否一定
// 满足true，故定义left=right=true，如果left与right被赋值为false，则不满足
// 条件，否则满足。

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.empty())
			return false;
		vector<int> left_node, right_node;
		int length = sequence.size();
		int boundary;
		bool left = true;
		bool right = true;
		for (boundary = 0; boundary < length - 1; ++boundary)
		{
			if (sequence[boundary] > sequence[length - 1])
			{
				break;
			}
			left_node.push_back(sequence[boundary]);
		}

		for (int i = boundary; i < length - 1; ++i)
		{
			if (sequence[i] < sequence[length - 1])
            {
                return false;
            }
			right_node.push_back(sequence[i]);
		}

		if (boundary > 0)
			left = VerifySquenceOfBST(left_node);
		if (boundary < length - 1)
			right = VerifySquenceOfBST(right_node);

		return (left && right);
    }
};

//第二次
class Solution {
public:
    bool dfs(vector<int> &sequence, int start, int end)
    {
        int i;
        int boundary;
        int root;
        bool left = true;
        bool right = true;

        if (start >= end)
            return true;

        root = sequence[end];

        for (i = start; i <= end - 1; i++)
        {
            if (sequence[i] > root)
                break;
        }
        boundary = i;
        for (i = boundary; i <= end - 1; i++)
        {
            if (sequence[i] < root)
                return false;
        }

        if (boundary > start)
            left = dfs(sequence, start, boundary - 1);

        if (end > boundary)
            right = dfs(sequence, boundary, end - 1);

        return left && right;
    }

    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty())
            return false;

        return dfs(sequence, 0, sequence.size() - 1);
    }
};
