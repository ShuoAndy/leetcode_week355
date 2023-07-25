/*
leetcode周赛第四题： 树中可以形成回文的路径数。

“给你一棵树（即，一个连通、无向且无环的图），根节点为 0 ，由编号从 0 到 n - 1 的 n 个节点组成。

这棵树用一个长度为 n 、下标从0开始的数组 parent 表示，其中 parent[i] 为节点 i 的父节点。

另给你一个长度为 n 的字符串 s ，其中 s[i] 是分配给 i 和 parent[i] 之间的边的字符。s[0] 可以忽略。

找出满足 u < v ，且从 u 到 v 的路径上分配的字符可以重新排列形成回文的所有节点对(u, v)，并返回节点对的数目。

如果一个字符串正着读和反着读都相同，那么这个字符串就是一个回文。”

输入：parent = [-1,0,0,1,1,2], s = "acaabc"
输出：8
*/

class Solution {
public:
    int mask[100005]={0};
    long long ans=0;
    unordered_map <int,int>count; 
    vector<vector<int>> father;
    string s;

    long long countPalindromePaths(vector<int>& parent, string s) {

        int len = parent.size();
        father.resize(len);
        this->s=s;

        for (int i = 1; i < len; i++) {
            father[parent[i]].push_back(i);
        }

        dfs(0,0);
        
        for(int i=0;i<len;i++)
        {
            ans += (count[mask[i]] - 1);
            for(int j=0;j<26;j++)
            {
                ans += (count[mask[i] ^ (1<<j)]); 
            }
        }
        return ans/2;
    }

    void dfs(int root, int new_mask)
    {
        mask[root]=new_mask;
        count[mask[root]] ++;
        for (int child : father[root]) 
        {
            dfs(child, new_mask ^ (1 << (s[child] - 'a')));
        }

    }
};