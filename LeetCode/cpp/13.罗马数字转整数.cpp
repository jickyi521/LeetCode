/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution
{
public:
    int romanToInt(string s)
    {
        int sum = 0;
        int len = s.length();
        for (int i = 0; i < len; i++)
        {
            char cur = s[i];
            if (cur == 'I')
            {
                if ((i < len - 1))
                {
                    if (s[i + 1] == 'V')
                    {
                        sum += 4;
                        i++;
                    }
                    else if (s[i + 1] == 'X')
                    {
                        sum += 9;
                        i++;
                    }
                    else
                    {
                        sum++;
                    }
                }
                else
                {
                    sum++;
                }
            }
            else if (cur == 'V')
            {
                sum += 5;
            }
            else if (cur == 'X')
            {
                if ((i < len - 1))
                {
                    if (s[i + 1] == 'L')
                    {
                        sum += 40;
                        i++;
                    }
                    else if (s[i + 1] == 'C')
                    {
                        sum += 90;
                        i++;
                    }
                    else
                    {
                        sum += 10;
                    }
                }
                else
                {
                    sum += 10;
                }
            }
            else if (cur == 'L')
            {
                sum += 50;
            }
            else if (cur == 'C')
            {
                if ((i < len - 1))
                {
                    if (s[i + 1] == 'D')
                    {
                        sum += 400;
                        i++;
                    }
                    else if (s[i + 1] == 'M')
                    {
                        sum += 900;
                        i++;
                    }
                    else
                    {
                        sum += 100;
                    }
                }
                else
                {
                    sum += 100;
                }
            }
            else if (cur == 'D')
            {
                sum += 500;
            }
            else if (cur == 'M')
            {
                sum += 1000;
            }
            else
            {
                //empty
            }
        }

        return sum;
    }
};
// @lc code=end
