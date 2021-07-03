/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> numN;
        int count = 0;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            int plusT = digits[i] + 1;
            if (plusT == 10)
            {
                digits[i] = 0;
            }
            else
            {
                count = i;
                digits[i] = plusT;
                break;
            }
        }

        if (digits[0] == 0)
        {
            numN.push_back(1);
            for (int i = 0; i < digits.size(); i++)
            {
                numN.push_back(digits[i]);
            }
            return numN;
        }
        else
        {
            return digits;
        }
    }
};
// @lc code=end
