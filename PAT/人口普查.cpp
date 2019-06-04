/*
人口普查(20)

时间限制 1000 ms 内存限制 32768 KB 代码长度限制 100 KB 判断程序 Standard (来自 小小)
题目描述

某城镇进行人口普查，得到了全体居民的生日。现请你写个程序，找出镇上最年长和最年轻的人。



这里确保每个输入的日期都是合法的，但不一定是合理的——假设已知镇上没有超过200岁的老人，而今天是2014年9月6日，所以超过200

岁的生日和未出生的生日都是不合理的，应该被过滤掉。


输入描述:

输入在第一行给出正整数N，取值在(0, 105]；随后N行，每行给出1个人的姓名（由不超过5个英文字母组成的字符串）、以及

按“yyyy/mm/dd”（即年/月/日）格式给出的生日。题目保证最年长和最年轻的人没有并列。



输出描述:

在一行中顺序输出有效生日的个数、最年长人和最年轻人的姓名，其间以空格分隔。


输入例子:

5

John 2001/05/12

Tom 1814/09/06

Ann 2121/01/30

James 1814/09/05

Steve 1967/11/20


输出例子:

3 Tom John
*/

//代码如下
#include <iostream>
using  namespace std;
int main() {
    string s,bname,sname;int year,moon,day,n,k=0;char t;cin>>n;
    for(int i=0,by=0,sy=750000;i<n;i++) {
        cin >> s >> year >> t >> moon >> t >> day;
        if(year*365+moon*30+day>=662386&&year*365+moon*30+day<=735386)    //直接把年龄换算成天数计算，免去了比较年月日等分情况的麻烦
        {k++;
            if(by<year*365+moon*30+day){by=year*365+moon*30+day;bname=s;}
            if(sy>year*365+moon*30+day){sy=year*365+moon*30+day;sname=s;}
            }
    }
    cout<<k<<" "<<sname<<" "<<bname;
}
