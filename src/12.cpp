class Solution {
public:
    double Power(double base, int exponent) {
        if(base == 0 && exponent <= 0)
            return 0;
		if(exponent == 0)
			return 1;
		double result = 1.0;
		if(exponent > 0)
		{
			for(int i = 1; i <= exponent; i++)
			{
				result = result * base;
			}
		}
		else if(exponent < 0)
		{
			int pow = 0 - exponent;
			for(int i = 1; i <= pow; i++)
			{
				result = result * base;
			}
			result = 1 / result;
		}
		return result;
    }
};