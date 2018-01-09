// 分析：
// 递归方式需注意函数嵌套太深


/*class Solution {   //递归
public:
    int Fibonacci(int n) {
		if(n <= 1)
			return n;
		if(n == 2)
			return 1;
		return Fibonacci(n-1) + Fibonacci(n-2);
    }
};*/
class Solution {   //不采用递归
public:
    int Fibonacci(int n) {
		if(n <= 1)
			return n;
        if(n == 2)
            return 1;
		int first = 1;
		int second = 1;
		int result;
		for(int i = 3; i <= n; i++)
		{
            int tmp = second;
			second = first + second;
			first = tmp;
			result = second;
		}
		return result;
    }
};