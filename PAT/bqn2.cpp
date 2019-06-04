/*
题目描述
NowCoder号称自己已经记住了1-100000之间所有的斐波那契数。
为了考验他，我们随便出一个数n，让他说出第n个斐波那契数。当然，斐波那契数会很大。因此，如果第n个斐波那契数不到6位，则说出该数；否则只说出最后6位。

输入描述:
输入有多组数据。
每组数据一行，包含一个整数n (1≤n≤100000)。


输出描述:
对应每一组输入，输出第n个斐波那契数的最后6位。

输入例子:
1
2
3
4
100000

输出例子:
1
2
3
5
537501
*/

#include <iostream>
#include <queue>
#include <stack>
#include <iomanip>
using namespace std;

int main()
{
    int n=0;
    int num[100001];
    num[0]=1;
    num[1]=1;
    for(int i=2;i<100001;i++){
        num[i]=(num[i-1]+num[i-2])%1000000;
    }
    while(cin>>n){
        if(n>30)cout << setw(6) << setfill('0') << num[n]<<endl;
        else cout<<num[n]<<endl;
    }
    return 0;
}