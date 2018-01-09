// 分析：
// 斐波拉契数列问题。递归方式下需注意函数嵌套太深。

class Solution {
public:
    int jumpFloor(int number) {
		if(number <= 2)
			return number;
		int pre = 1, next = 2;
		int result, tmp;
		for(int i = 3; i <= number; i++)
		{
			tmp = next;   //设置tmp保存前一个变量next
			next = pre + next;   //更新next
			pre = tmp;   //pre指向旧的next作为新的pre
		}
		result = next;
		return result;
    }
};