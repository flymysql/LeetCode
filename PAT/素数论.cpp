/*素数
题目描述

令Pi表示第i个素数。现任给两个正整数M <= N <= 10000，请输出PM到PN的所有素数。

输入描述:

输入在一行中给出M和N，其间以空格分隔。

输出描述:

输出从PM到PN的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。

代码 */

#include<iostream>
#include<math.h>
using namespace std;

class prime
{
    int pri;
    public:
    void set_pri(int i)
    {pri=i;}
    int get_p()
    {
        int i;
        for(i=1;i<=sqrt(pri);i++)
        {
            if(pri%i==0&&i!=pri&&i!=1)return pri;
        }
        return 0;
    }
};

int main()
{
    prime a;
    int i,j=0,m,n;
    cin>>m>>n;
    for(i=2;i<=1000000;i++)
    {
        a.set_pri(i);
        if(a.get_p()==0)
        {
            j++;
            if(m<=j&&j<n&&(j-m+1)%10!=0)cout<<i<<" ";
            if(m<=j&&j<n&&(j-m+1)%10==0)cout<<i<<endl;
            if(j==n&&j!=m)cout<<i;
            if(j==m&&j==n)cout<<i;
        }
        if(j>n)break;
    }
}
