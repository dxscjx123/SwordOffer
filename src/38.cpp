// 分析：
// 异或运算的应用。如果数组中，只有一个数出现了一次，其他都出现了2次。则
// 直接对数组遍历，并将所有数字进行异或，最终得到的结果即为只出现一次的数字。
// 因为相同数字异或结果为0，出现2次的通过异或操作都消除。
// 现在考虑数组中有两个数字只出现了一次。对于数组，将其所有元素进行异或得到
// xor_r，这个xor_r应该为这两个数字进行异或得到的结果，而由于这两个数字不同，
// xor_r中至少有一位为1，产生这个1的原因是由两个数字（a和b）在对应位上的二进
// 制值一个为0，一个为1导致。找到这个位，对原数组遍历，并将元素在该位上为0或
// 为1，分为两个子数组，显然的，两个子数组中，a和b分别出现，而其他元素都成对
// 出现在两个子数组中，从而对两个子数组做异或，得到a和b。

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
		int xor_r = 0;
		for(int i = 0; i < data.size(); i++)
			xor_r ^= data[i];
		
		int location = 0;
		int bit = 0x1;
		while (!(xor_r & bit))
		{
			bit = bit << 1;
			location++;
		}
		
		for (int i = 0; i < data.size(); i++)
		{
			int isbit1 = (data[i] & (0x1 << location));
			if (isbit1)
				*num1 ^= data[i];
			else
				*num2 ^= data[i];
		}
    }
};