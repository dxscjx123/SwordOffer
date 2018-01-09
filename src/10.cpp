// 分析：
// n*2的矩形
// 竖着放一个小矩形，剩余(n-1)*2大小
// 横着放一个小矩形，为保证覆盖，需要在底部横放一个小矩形，
// 剩余(n-2)*2大小
// 最终方法数为上述两种之和。

class Solution {
public:
    int rectCover(int number) {
		if(number <= 2)
			return number;
		return rectCover(number-1) + rectCover(number-2);
    }
};