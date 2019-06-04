
/*
月饼 (25)

时间限制 1000 ms 内存限制 32768 KB 代码长度限制 100 KB 判断程序 Standard (来自 小小)
题目描述

月饼是中国人在中秋佳节时吃的一种传统食品，不同地区有许多不同风味的月饼。现给定所有种类月饼的库存量、总售价、以及市场的最大需

求量，请你计算可以获得的最大收益是多少。



注意：销售时允许取出一部分库存。样例给出的情形是这样的：假如我们有3种月饼，其库存量分别为18、15、10万吨，总售价分别为75、

72、45亿元。如果市场的最大需求量只有20万吨，那么我们最大收益策略应该是卖出全部15万吨第2种月饼、以及5万吨第3种月饼，获得

 72 + 45/2 = 94.5（亿元）。


输入描述:

每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N表示月饼的种类数、以及不超过500（以万吨为单位）的正整数

D表示市场最大需求量。随后一行给出N个正数表示每种月饼的库存量（以万吨为单位）；最后一行给出N个正数表示每种月饼的总售价（以亿

元为单位）。数字间以空格分隔。



输出描述:

对每组测试用例，在一行中输出最大收益，以亿元为单位并精确到小数点后2位。
*/

//代码如下

#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
    int n,d,index=0;double max=0.0;double al=0.0;
    cin>>n>>d;
    int *a=new int[n];
    int *b=new int[n];
    double *c=new double[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    for(int i=0;i<n;i++) c[i]=(double)b[i]/a[i];
    while(true)
    {
        for(int i=0;i<n;i++)
        {
            if (max<c[i])
                {
                    max=c[i];
                    index=i;
                }
        }
        max=0.0;
        if (a[index]<=d)
        {
            d=d-a[index];
            al=al+b[index];
        }
        else
        {
            al=al+d*c[index];
            break;
        }
        c[index]=0;

    }
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<al<<endl;
    return 0;

}
