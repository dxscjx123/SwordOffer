// 分析：
// 采用哈希表实现。

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
		set<int> nums;
		bool result = false;
		for (int i = 0; i < length; ++i)
		{
			if (nums.find(numbers[i]) == nums.end())
				nums.insert(numbers[i]);
			else
			{
				*duplication = numbers[i];
				result = true;
				break;
			}
		}
		return result;
    }
};