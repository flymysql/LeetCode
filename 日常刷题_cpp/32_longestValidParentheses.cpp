/* 
给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
示例 1:

输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"
示例 2:

输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"
*/
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>  
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.length() == 0) return 0;
        vector<int> ss;
        int max = 0,tmp = 0, index = 1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ')') {
                if(!ss.empty()){
                    ss.pop_back();
                    tmp++;
                }
                else {
                    if (max < tmp) max = tmp;
                    tmp = 0;
                    index = 1;
                    ss.clear();
                }
            }
            else {
                ss.push_back(index);
                index++;
            }
        }
        if (!ss.empty()){
            int mtmp = ss[0]-1;
            for (int j = 1; j < ss.size(); j++)
                mtmp = mtmp > ss[j]-ss[j-1]-1 ? mtmp : ss[j]-ss[j-1]-1;
            tmp = mtmp > index - ss.back()-1 ? mtmp : index - ss.back()-1;
        }
        max = max > tmp ? max : tmp;
        return max*2;
    }
};


/* 
执行用时 :12 ms, 在所有 C++ 提交中击败了79.79%的用户
内存消耗 :9.4 MB, 在所有 C++ 提交中击败了89.97%的用户
*/

int main() {
    Solution s;
    string ss = "(()";
    printf("%d\n", s.longestValidParentheses(ss));
    return 0;
}