// 分析：
// 如果不要求保持原来数组的顺序，可以类似采用快排的思想
// 两个指针指向数组开始和结尾，通过交换元素和移动指针即
// 可。但如果需要保持原数组的顺序，空间复杂度小，时间复
// 杂度大的方法：遍历数组，偶数则放到最后一位，元素前移
// 。空间复杂度为大，时间复杂度小的方法，开两个数组，分
// 别保存奇数和偶数。

/*class Solution {   //会改变数组的顺序
public:
    void reOrderArray(vector<int> &array) {
        if ( array.size() == 0 )
			return ;
		int i = 0;
		int j = array.size() - 1;
		while ( i != j )
		{
			while ( array[i] % 2 != 0 && i < j )
				i ++;
			while ( array[j] % 2 == 0 && i < j )
				j --;
			if ( i < j )
			{
				int tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
    }
};*/

class Solution {
public:
    void reOrderArray(vector<int> &array) {
		vector<int> odd, even;
		for (int i = 0; i < array.size(); i++)
		{
			if (array[i] % 2 == 0)
			{
				even.push_back(array[i]);
			}
			else
			{
				odd.push_back(array[i]);
			}
		}
		array.clear();
		for (int i = 0; i < odd.size(); i++)
		{
			array.push_back(odd[i]);
		}
		for (int i = 0; i < even.size(); i++)
		{
			array.push_back(even[i]);
		}
    }
};