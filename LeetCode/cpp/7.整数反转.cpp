/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {

        string res = to_string(x);
        int len = res.length();
        int n = len - 1;
        int begin = x > 0 ? 0 : 1;
        int sum = x > 0 ? (len / 2 - 1) : len / 2;
        for (int i = begin; i <= sum; i++)
        {
            swap(res[i], res[n]);
            n--;
        }

        if (stol(res) >= 2147483647 || stol(res) <= -2147483648)
        {
            return 0;
        }
        else
        {

            int resI = stoi(res);
            return resI;
        }
    }
};
// @lc code=end
