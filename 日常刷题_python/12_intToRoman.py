"""
罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。
数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。

示例 1:

输入: 3
输出: "III"
"""

class Solution:
    def intToRoman(self, num: int) -> str:
        val = [1000,900,500,400,100,90,50,40,10,9,5,4,1]
        r = ["M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"]
        # m = {}
        # m[1], m[4], m[5], m[9], m[10] = 'I', 'IV', 'V', 'IX', 'X'
        # m[40], m[50], m[90] , m[100] = 'XL', 'L', 'XC', 'C'
        # m[400], m[500], m[900], m[1000] = 'CD', 'D', 'CM', 'M'
        rel = ""
        for i in range(13):
            for _ in range(int(num / val[i])):
                rel += r[i]
            num %= val[i]
        return rel
"""
执行用时 : 100 ms, 在Integer to Roman的Python3提交中击败了84.11% 的用户
内存消耗 : 13.2 MB, 在Integer to Roman的Python3提交中击败了80.09% 的用户
"""