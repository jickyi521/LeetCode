/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(string s)
    {
        string handlerS = "";
        int min1 = (int)'a';
        int max1 = (int)'z';
        int min2 = (int)'A';
        int max2 = (int)'Z';
        int min3 = (int)'0';
        int max3 = (int)'9';
        int diff = min1 - min2;
        for (int i = 0; i < s.length(); i++)
        {
            int curr = (int)s[i];
            if (curr >= min2 && curr <= max2)
            {
                curr += diff;
                handlerS += char(curr);
            }
            else if ((curr >= min3 && curr <= max3) || (curr >= min1 && curr <= max1))
            {
                handlerS += s[i];
            }
        }

        int len = handlerS.length();
        for (int i = 0; i < len / 2; i++)
        {
            int cur = (int)handlerS[i];
            int last = (int)handlerS[len - 1 - i];
            if (cur != last)
            {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end
