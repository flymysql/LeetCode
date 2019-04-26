/*
给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。
给定的字符串只含有小写英文字母，并且长度不超过10000。

示例 1:
输入: "abab"
输出: True

解释: 可由子字符串 "ab" 重复两次构成。
*/
#include <string>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    vector<int> list(int n){
        vector<int> result;
        for (size_t i = 1; i <= n/2; i++)
            if(n%i == 0) result.push_back(i);
        return result;
    }
    bool repeated_str(string &s, int x){
        for (size_t i = 0; i < x; i++){
            char tmp = s[i];
            for (size_t j = i+x; j < s.size(); j += x)
                if(s[j] != tmp) return false;
        }
        return true;
    }
    bool repeatedSubstringPattern(string s) {
        int le = s.size();
        if(le == 1) return false;
        vector<int> n = list(le);
        for (size_t i = 0; i < n.size(); i++)
            if(repeated_str(s, n[i])) return true;
        return false;
    }
}; 

/*
执行用时 : 36 ms, 在Repeated Substring Pattern的C++提交中击败了97.16% 的用户
内存消耗 : 11.4 MB, 在Repeated Substring Pattern的C++提交中击败了99.44% 的用户
*/