/*
实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;
        int index = 0, s = -9999;
        for (int i = nums.size()-2; i >= 0; i--){
            for (int j = nums.size()-1; j > i; j--){
                if (nums[j] > nums[i] && (nums[j] < s || s == -9999)){
                    s = nums[j];
                    index = j; 
                }
            }
            if (s != -9999){
                int tmp = nums[index];
                nums[index] = nums[i];
                nums[i] = tmp;
                sort(nums.begin()+i+1, nums.end());
                return;
            }
        }
        if (s == -9999)
            sort(nums.begin(), nums.end());
    }
};

/*
执行用时 :12 ms, 在所有 C++ 提交中击败了91.82%的用户
内存消耗 :8.7 MB, 在所有 C++ 提交中击败了81.72%的用户
*/

int main(){
    Solution s;
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(3);
    // arr.push_back(2);
    s.nextPermutation(arr);
    for (size_t i = 0; i < arr.size(); i++){
        printf("%d ", arr[i]);
    }
    return 0;
}