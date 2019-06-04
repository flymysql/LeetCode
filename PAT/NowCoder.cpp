/*
题目描述
NowCoder最近在研究一个数列：
* F(0) = 7
* F(1) = 11
* F(n) = F(n-1) + F(n-2) (n≥2)
他称之为NowCoder数列。请你帮忙确认一下数列中第n个数是否是3的倍数。

输入描述:
输入包含多组数据。
每组数据包含一个整数n，(0≤n≤1000000)。


输出描述:
对应每一组输入有一行输出。
如果F(n)是3的倍数，则输出“Yes”；否则输出“No”。
*/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
	int n;
	while(cin>>n){
		if(n%4==2)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}