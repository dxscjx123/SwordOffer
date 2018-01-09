// 分析：
// 由于青蛙可以一次性跳多级台阶（最少情况下为直接一次跳n阶）。
// 1级台阶，跳法1次（1）
// 2级台阶，跳法2次（11,2）
// 3级台阶，跳法3次（111,12,21,3），分解为先跳一次，再跳两次或者
// 先跳两次，再跳一次，为1级和2级的总和，但最终需要加上直接1次跳
// 上3级，返回r+1

class Solution {
public:
    int jumpFloorII(int number) {
		if(number <= 2)
			return number;
		int result = 0;
		while(number != 0)
		{
			result = result + jumpFloorII(--number);
		}
		return result + 1;
    }
};