
/*插入与归并(25)

时间限制 1000 ms 内存限制 32768 KB 代码长度限制 100 KB 判断程序 Standard (来自 小小)
题目描述

根据维基百科的定义：



插入排序是迭代算法，逐一获得输入数据，逐步产生有序的输出序列。每步迭代中，算法从输入序列中取出一元素，将之插入有序序列中正确

的位置。如此迭代直到全部元素有序。



归并排序进行如下迭代操作：首先将原始序列看成N个只包含1个元素的有序子序列，然后每次迭代归并两个相邻的有序子序列，直到最后只剩

下1个有序的序列。



现给定原始序列和由某排序算法产生的中间序列，请你判断该算法究竟是哪种排序算法？


输入描述:

输入在第一行给出正整数N (<=100)；随后一行给出原始序列的N个整数；最后一行给出由某排序算法产生的中间序列。这里假设排序的目标序列是升序。数字间以

空格分隔。



输出描述:

首先在第1行中输出“Insertion Sort”表示插入排序、或“Merge Sort”表示归并排序；然后在第2行中输出用该排序算法再迭代一轮的结果序列。题目保证每组测试

的结果是唯一的。数字间以空格分隔，且行末不得有多余空格。


输入例子:

10

3 1 2 8 7 5 9 4 6 0

1 2 3 7 8 5 9 4 6 0


输出例子:

Insertion Sort

1 2 3 5 7 8 9 4 6 0
*/

//代码如下

#include <iostream>
#include<algorithm>
using namespace std;
int main() {
    int n;cin>>n; int k=0,num[n],next[n];bool t=false;
    for(int i=0;i<n;i++)cin>>num[i];
    for(int i=0;i<n;i++)cin>>next[i];
    for(int i=1;i<n;i++){
        if(next[i]>next[i+1]&&t==false){k=i+1;i=i+1;t=true;}    //判断是插入排序还是归并排序
        if(t==true&&next[i]!=num[i]){t=false;break;}
    }
    if(t==true){ cout<<"Insertion Sort"<<endl;
        for(int i=k-1;i>=0;i--){
            if(next[i]>next[i+1]){int a=next[i];next[i]=next[i+1];next[i+1]=a;}
            else break;
        }
        for(int i=0;i<n-1;i++)cout<<next[i]<<" ";cout<<next[n-1];
    }
    else {cout<<"Merge Sort"<<endl;
        for(int i=0;i<n/(2*k);i++)sort(next+2*i*k,next+2*(i+1)*k);
        for(int i=0;i<n-1;i++)cout<<next[i]<<" ";cout<<next[n-1];
    }
}

