// 分析：
// int型为32位（32位os），按位移位进行与操作

class Solution {
public:
     int  NumberOf1(int n) {
         int number = 0;
         for(int i = 1; i <= 32; i++)  //若改写为while(n)，对于n为负，则会陷入死循环
		 //负数首位为符号位，保持为1
         {
             if(n & 1 == 1)
                number ++;
             n = n >> 1;
         }
         return number;
     }
};

//第二次
//n & (n - 1)会将n的最右边的1置为0
/*
class Solution {
public:
     int  NumberOf1(int n) {
		 int number = 0;
		 while (n)
		 {
			 number++;
			 n = n & (n - 1);
		 }
		 return number;
     }
};
*/