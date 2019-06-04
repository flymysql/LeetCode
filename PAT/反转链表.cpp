
/* 反转链表 (25)
时间限制 2000 ms内存限制 150400 KB代码长度限制 100 KB判断程序
题目描述

给定一个常数K以及一个单链表L，请编写程序将L中每K个结点反转。例如：给定L为1→2→3→4→5→6，K为3，则输出应该为

3→2→1→6→5→4；如果K为4，则输出应该为4→3→2→1→5→6，即最后不到K个元素不反转。

输入描述:

每个输入包含1个测试用例。每个测试用例第1行给出第1个结点的地址、结点总个数正整数N(<= 105)、以及正整数K(<=N)，即要求反转的

子链结点的个数。结点的地址是5位非负整数，NULL地址用-1表示。


接下来有N行，每行格式为：

Address Data Next

其中Address是结点地址，Data是该结点保存的整数数据，Next是下一结点的地址。

输出描述:

对每个测试用例，顺序输出反转后的链表，其上每个结点占一行，格式与输入相同。

输入例子:

00100 6 4

00000 4 99999

00100 1 12309

68237 6 -1

33218 3 00000

99999 5 68237

12309 2 33218

输出例子:

00000 4 33218

33218 3 12309

12309 2 00100

00100 1 99999

99999 5 68237

68237 6 -1   */

//代码如下
//算法关键在于对数组的使用
//用数组下标表示每组数的地址


#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int first,n,k,temp,sum=0;
    cin>>first>>n>>k;
    int lis[100001],data[100001],next[100001];
    for(int i=0;i<n;i++) 
    { cin>>temp; cin>>data[temp]>>next[temp]; }
    while(first!=-1) 
    {  lis[sum++]=first; first=next[first]; }
    for(int i=0;i <(sum - sum % k);i=i+k)
    reverse(begin(lis) + i, begin(lis) + i + k);
    for(int i=0;i<sum-1;i++)
    printf("%05d %d %05d\n", lis[i], data[lis[i]], lis[i + 1]);
    printf("%05d %d -1", lis[sum - 1], data[lis[sum - 1]]);
}
