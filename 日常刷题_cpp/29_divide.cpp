/*
给定两个整数，被除数 a 和除数 b。
将两数相除，要求不使用乘法、除法和 mod 运算符。
返回被除数 a 除以除数 b 得到的商。

示例 1:
输入: a = 10, b = 3
输出: 3

示例 2:
输入: a = 7, b = -3
输出: -2

说明:
被除数和除数均为 32 位有符号整数。
除数不为 0。
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。
本题中，如果除法结果溢出，则返回 2^31 − 1。
*/

#include <iostream>
using namespace std;

class Solution{
public:
    int left(unsigned int &d,unsigned int x){
        int lef = x, i = 0;
        for (; i< 31 && lef<<i <= d; i++);
        if(i != 0) {
            d -= lef<<(i-1);
            return 1<<(i-1);
        }
        return 0;
    }
    int divide(int dividend, int divisor) {
        if (dividend == 0) {
            return 0;
        }
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if (divisor == INT_MIN && dividend == INT_MIN) {
            return 1;
        }
        if (divisor == INT_MIN) {
            return 0;
        }
        bool sign = (dividend^divisor) < 0;
        unsigned int dd = dividend == INT_MIN ? 0x80000000 : abs(dividend);
        unsigned int dr = abs(divisor);
        if(dr == 1) return sign ? -dd : dd;
        int tmp = left(dd, dr), result = tmp;
        while(tmp){
            tmp = left(dd, dr);
            result += tmp;
        }
        return sign ? -result : result;
    }
};

/*
执行用时 : 16 ms, 在Divide Two Integers的C++提交中击败了73.04% 的用户
内存消耗 : 8.2 MB, 在Divide Two Integers的C++提交中击败了76.92% 的用户
*/