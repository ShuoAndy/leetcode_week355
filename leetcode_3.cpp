/*
leetcode周赛第三题： 长度递增组的最大数目。

“给你一个下标从 0 开始、长度为 n 的数组 usageLimits 。

你的任务是使用从0到n - 1的数字创建若干组，并确保每个数字i在所有组中使用的次数总共不超过 usageLimits[i] 次。此外，还必须满足以下条件：

每个组必须由不同的数字组成，也就是说，单个组内不能存在重复的数字。
每个组（除了第一个）的长度必须 严格大于 前一个组。
在满足所有条件的情况下，以整数形式返回可以创建的最大组数。”

输入：usageLimits = [1,2,5]
输出：3
*/

class Solution {
public:
    int binarySearch(int left, int right,vector<int>& usageLimits)
    {
        int ans;
        int len=right;
        while (left <= right) 
        {
            int mid = (left + right) / 2; //检查分mid个组是否可行
            int cache=0,now=1; //cache是多余可用的数字，now是当前填到第几列了
            for(int j=0;j<len;j++)
            {
                if(cache+usageLimits[j]>=now)
                {
                    cache = (cache+usageLimits[j]-now);
                    now++;
                }
                else cache+=usageLimits[j];
                
            }
            
            if (now>mid) // mid组可行
                {
                    left = mid + 1; // 结果落在 [mid+1, right] 区间
                    ans=mid;
                }
            else
                right = mid-1;
        }
        return ans;
    }

    int maxIncreasingGroups(vector<int>& usageLimits) 
    {
        sort(usageLimits.begin(), usageLimits.end());
        int len=usageLimits.size();
        return binarySearch(1,len,usageLimits);

    }
};