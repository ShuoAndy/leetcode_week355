/*
leetcode周赛第一题：分割字符串。

“给你一个字符串数组 words 和一个字符 separator ，请你按 separator 拆分 words 中的每个字符串。”

输入：words = ["one.two.three","four.five","six"], separator = "."
输出：["one","two","three","four","five","six"]
*/


class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans;
        int len = words.size();
        for(int i=0; i<len;i++)
        {
            int str_len=words[i].length();
            string word;
            for(int j=0;j<str_len;j++)
            {
                if(words[i][j]!=separator)
                {
                    word.push_back(words[i][j]);
                }
                else
                {
                    if(!word.empty())
                        ans.push_back(word);
                    word.clear();
                }
            }
            if(!word.empty())
                ans.push_back(word);
        }
        return ans;
    }
};