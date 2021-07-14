/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buy = prices[0];
        int sell = 0;
        int earn = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (sell > 0 && prices[i] < sell)
            {
                earn += (sell - buy);
                buy = prices[i];
                sell = 0;
            }
            else if (sell == 0 && prices[i] < buy)
            {
                buy = prices[i];
            }
            else if (prices[i] > buy)
            {
                sell = prices[i];
            }
        }

        if (sell > buy)
        {
            earn += (sell - buy);
        }

        return earn;
    }
};
// @lc code=end
