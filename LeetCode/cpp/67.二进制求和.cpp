/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution
{
public:
    string addBinary(string a, string b)
    {
        string response = "";
        int sizeA = a.length();
        int sizeB = b.length();
        int sizeMax = sizeA > sizeB ? sizeA : sizeB;
        int sizeMin = sizeA > sizeB ? sizeB : sizeA;

        bool plusOne = false;
        for (int i = 0; i < sizeMax; i++)
        {
            if (i < sizeMin)
            {
                if (a[sizeA - i - 1] == '0' && b[sizeB - i - 1] == '0')
                {
                    if (plusOne)
                    {
                        response = '1' + response;
                    }
                    else
                    {
                        response = '0' + response;
                    }
                    plusOne = false;
                }
                else if (a[sizeA - i - 1] == '1' && b[sizeB - i - 1] == '1')
                {
                    if (plusOne)
                    {
                        response = '1' + response;
                    }
                    else
                    {
                        response = '0' + response;
                        plusOne = false;
                    }
                    plusOne = true;
                }
                else
                {
                    if (plusOne)
                    {
                        response = '0' + response;
                        plusOne = true;
                    }
                    else
                    {
                        response = '1' + response;
                        plusOne = false;
                    }
                }
            }
            else
            {
                if (sizeA > sizeB)
                {
                    if (a[sizeA - i - 1] == '0')
                    {
                        char temp = plusOne ? '1' : '0';
                        response = temp + response;
                        plusOne = false;
                    }
                    else
                    {
                        char temp = plusOne ? '0' : '1';
                        response = temp + response;
                        plusOne = plusOne ? true : false;
                    }
                }
                else
                {
                    if (b[sizeB - i - 1] == '0')
                    {
                        char temp = plusOne ? '1' : '0';
                        response = temp + response;
                        plusOne = false;
                    }
                    else
                    {
                        char temp = plusOne ? '0' : '1';
                        response = temp + response;
                        plusOne = plusOne ? true : false;
                    }
                }
            }
        }
        if (plusOne)
        {
            response = '1' + response;
        }

        return response;
    }
};
// @lc code=end
