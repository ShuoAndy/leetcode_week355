/*
leetcode周赛第二题：求合并后数组的最大值。

“你可以在数组上执行下述操作任意次：

选中一个同时满足 0 <= i < nums.length - 1 和 nums[i] <= nums[i + 1] 的整数 i 。将元素 nums[i + 1] 替换为 nums[i] + nums[i + 1]，

并从数组中删除元素 nums[i]。返回你可以从最终数组中获得的最大元素的值。”

输入：nums = [2,3,7,9,3]
输出：21
*/

class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int len = nums.size();
        long long next=nums[len-1]; //next是nums[i+1]
        for(int i=len-2;i>=0;i--)
        {
            if(next>=nums[i])
            {
                next=next+nums[i]; //此时next变为nums[i]
            }
            else 
            {
                next=nums[i];
            }
        }    
        return next; 
    }
};