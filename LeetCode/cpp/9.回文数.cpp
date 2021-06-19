/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;

        string str = to_string(x);
        int len = str.length();
        int num = len - 1;
        for (int i = 0; i < len / 2; i++)
        {
            if (str[i] != str[num])
            {
                return false;
            }
            num--;
        }
        return true;
    }
};
// @lc code=end
