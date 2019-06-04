/*
题目描述
一只成熟的兔子每天能产下一胎兔子。每只小兔子的成熟期是一天。 某人领养了一只小兔子，请问第N天以后，他将会得到多少只兔子。

输入描述:
测试数据包括多组，每组一行，为整数n(1≤n≤90)。


输出描述:
对应输出第n天有几只兔子(假设没有兔子死亡现象)。

输入例子:
1
2

输出例子:
1
2
*/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
	long long int big=0, small=1,temp=0;
	long long int num[91];
	num[0]=1;
	for(int i=1;i<91;i++){
		temp=big;
		big=big+small;
		small=temp;
		num[i]=big+small;
	}
	int n=0;
	while(cin>>n){
		cout<<num[n]<<endl;
	}
	return 0;
}