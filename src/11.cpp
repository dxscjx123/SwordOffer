// 分析：
// int型为32位（32位os），按位移位进行与操作

class Solution {
public:
     int  NumberOf1(int n) {
         int number = 0;
         for(int i = 1; i <= 32; i++)  //若改写为while(n)，对于n为负，则会陷入死循环
         {
             if(n & 1 == 1)
                number ++;
             n = n >> 1;
         }
         return number;
     }
};