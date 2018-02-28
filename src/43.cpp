// 分析：
// 这个题牛客网上没有，但是剑指offer上有。主要是计算每个结果的次数，采用递归的
// 方法，核心思想在PrintProbability中的Probability函数。

//递归版
// 计算第一个骰子的点数加上剩下n-1个骰子的点数，第二个骰子的点数加上剩下n-2个
// 骰子的点数。采用递归。
void PrintProbability(int number)
{
    if(number < 1)
        return;

    int maxSum = number * g_maxValue;
    int* pProbabilities = new int[maxSum - number + 1];
    for(int i = number; i <= maxSum; ++ i)
        pProbabilities[i - number] = 0;

    Probability(number, number, 0, pProbabilities);

    int total = pow((double)g_maxValue, number);
    for(int i = number; i <= maxSum; ++ i){
        double ratio = (double)pProbabilities[i - number] / total;
        printf("%d: %e\n", i, ratio);
    }

    delete[] pProbabilities;
}

void Probability(int original, int number, int cursum, int* pProbabilities)
{
    if (number == 0)
    {
        pProbabilities[cursum - original]++;
        cout<<"cursum :"<<cursum<<endl;
    }
    else
    {
        for (int i = 1; i <= g_maxValue; i++)
        {
            Probability(original, number - 1, cursum + i, pProbabilities);
        }
    }
}