/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        vector<int> result;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            int cur = nums[i];
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (cur + nums[j] == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};
// @lc code=end
