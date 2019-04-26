/*
实现 strStr() 函数。给定一个 haystack 字符串和一个 needle 字符串，
在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:
输入: haystack = "hello", needle = "ll"
输出: 2

示例 2:
输入: haystack = "aaaaa", needle = "bba"
输出: -1
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int r, h = haystack.size(), n = needle.size();
        if(h < n) return -1;
        else if(n == 0) return 0;
        for(size_t i = 0; i <= h - n; i++){
            if(n > 1)
                r = rand() % (n-1);
            else r = 0;
            if(haystack[i+r] == needle[r]){
                int j = 0;
                for (; j < n; j++)
                    if(haystack[i+j] != needle[j]) break;
                if(j == n) return i;
            }
        }
        return -1;
    }
};

/*
执行用时 : 16 ms, 在Implement strStr()的C++提交中击败了46.65% 的用户
内存消耗 : 9.1 MB, 在Implement strStr()的C++提交中击败了80.95% 的用户
*/