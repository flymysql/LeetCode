"""
在由若干 0 和 1  组成的数组 A 中，有多少个和为 S 的非空子数组。
示例：

输入：A = [1,0,1,0,1], S = 2
输出：4
解释：
如下面黑体所示，有 4 个满足题目要求的子数组：
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
 
提示：
A.length <= 30000
0 <= S <= A.length
A[i] 为 0 或 1
"""
class Solution:
    def numSubarraysWithSum(self, A, S: int) -> int:
        i, j, num = 0, 0, 0
        le = len(A)
        su = A[0]
        while j < le:
            if su == S:
                break
            su += A[j]
            j += 1
        while le - i > S and j < le:
            if su == S:
                num += 1
                tmp = j
                while j < le:
                    if j+1 < le and A[j+1] == 0:
                        j += 1
                        num += 1
                    else:
                        j = tmp + 1
                        i += 1
                        break
        return num

s = Solution()
print(s.numSubarraysWithSum([0,1,1,1,1],3))