
/*完美数列(25)

时间限制 1000 ms 内存限制 32768 KB 代码长度限制 100 KB 判断程序 Standard (来自 小小)
题目描述

给定一个正整数数列，和正整数p，设这个数列中的最大值是M，最小值是m，如果M <= m * p，则称这个数列是完美数列。



现在给定参数p和一些正整数，请你从中选择尽可能多的数构成一个完美数列。


输入描述:

输入第一行给出两个正整数N和p，其中N（<= 105）是输入的正整数的个数，p（<= 109）是给定的参数。第二行给出N个正整数，每个数

不超过109。


输出描述:

在一行中输出最多可以选择多少个数可以用它们组成一个完美数列。


输入例子:

10 8

2 3 20 4 5 1 6 7 8 9


输出例子:

8   

*/  //代码如下

#include <iostream>
#include<algorithm>
using  namespace std;
int main() {
    int n,big=0;double p;
    cin>>n>>p; double num[n];
    for(int i=0;i<n;i++)cin>>num[i];
    sort(num,num+n);
    for(int i=0;i<n;i++){
        for(int j=i+big;j<n;j++){
            if(num[i]*p<num[j]){if(j-i>big)big=j-i;break;}
            if(j==n-1)big=j-i+1; }
    } cout<<big;
}

