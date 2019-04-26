/*
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

示例 1:
给定数组 nums = [1,1,2], 
函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。 
你不需要考虑数组中超出新长度后面的元素。
示例 2:
给定 nums = [0,0,1,1,1,2,2,3,3,4],
函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
你不需要考虑数组中超出新长度后面的元素。
*/

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int tmp = 0;
            for(int j = i+1; j < nums.size(); j++)
                if(nums[i] == nums[j]) tmp++;
                else break;
            nums.erase(nums.begin()+i, nums.begin()+i+tmp);
        }
        return nums.size();
    }
};

/*
执行用时 : 268 ms, 在Remove Duplicates from Sorted Array的C++提交中击败了16.83% 的用户
内存消耗 : 9.9 MB, 在Remove Duplicates from Sorted Array的C++提交中击败了76.88% 的用户
*/