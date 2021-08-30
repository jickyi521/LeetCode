/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start
class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string result = "";
        while (columnNumber > 0)
        {
            columnNumber--;
            result += columnNumber % 26 + 'A';
            columnNumber = columnNumber / 26;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
// @lc code=end
