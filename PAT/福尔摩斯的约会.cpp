
/*福尔摩斯的约会 (20)

时间限制 1000 ms 内存限制 32768 KB 代码长度限制 100 KB 判断程序 Standard (来自 小小)
题目描述

大侦探福尔摩斯接到一张奇怪的字条：“我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm”。大侦探很

 快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，因为前面两字符串中第1对相同的大写英文字母（大小写有区分）是

 第4个字母'D'，代表星期四；第2对相同的字符是'E'，那是第5个英文字母，代表一天里的第14个钟头（于是一天的0点到23点由数字0到9、

 以及大写字母A到N表示）；后面两字符串第1对相同的英文字母's'出现在第4个位置（从0开始计数）上，代表第4分钟。现给定两对字符串，

 请帮助福尔摩斯解码得到约会的时间。


输入描述:

输入在4行中分别给出4个非空、不包含空格、且长度不超过60的字符串。



输出描述:

在一行中输出约会的时间，格式为“DAY HH:MM”，其中“DAY”是某星期的3字符缩写，即MON表示星期一，TUE表示星期二，WED表示星期三，THU表示星期

四，FRI表示星期五，SAT表示星期六，SUN表示星期日。题目输入保证每个测试存在唯一解。


输入例子:

3485djDkxh4hhGE

2984akDfkkkkggEdsb

s&hgsfdk

d&Hyscvnm


输出例子:

THU 14:04  */

//代码如下

#include<iostream>
#include<string.h>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    char key1[60],key2[60],key3[60],key4[60];
    cin>>key1>>key2>>key3>>key4;    //输入四个字符串
    int i=0,j=0;
    for(i=0;i<60;i++)
    {
        if(key1[i]>='A'&&key1[i]<='G'&&key1[i]==key2[i]&&j==0)
        {
            j++;
            switch(key1[i])     //判断星期几
    {
       		case 'A':cout<<"MON ";continue;
       		case 'B':cout<<"TUE ";continue;
       		case 'C':cout<<"WED ";continue;
       		case 'D':cout<<"THU ";continue;
       		case 'E':cout<<"FRI ";continue;
       		case 'F':cout<<"SAT ";continue;
       		case 'G':cout<<"SUN ";continue;
        }
        }               //判断时刻
        if(j==1&&isupper(key1[i])&&key1[i]==key2[i]&&key1[i]>='A'&&key1[i]<='N'){cout<<key1[i]-'A'+10<<":";break;}
        if(j==1&&key1[i]==key2[i]&&isdigit(key1[i])) {cout<<'0'<<dec<<key1[i]-'0'<<":";break;} 
    }
    for(i=0;key3[i]&&key4[i];i++)    //判断分钟
    {
            if( isalpha(key3[i])&& key3[i]==key4[i])
            {
                 cout<<i/10<<i%10<<endl;
                break;
            }
    }
}


