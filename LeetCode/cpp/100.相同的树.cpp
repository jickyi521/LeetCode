/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        else if (p == nullptr || q == nullptr)
        {
            return false;
        }

        queue<TreeNode *> v1, v2;
        v1.push(p);
        v2.push(q);

        while (v1.size() > 0 || v2.size() > 0)
        {
            int size = v1.size();
            if (size != v2.size())
                return false;

            for (int i = 0; i < size; i++)
            {
                TreeNode *node1 = v1.front();
                TreeNode *node2 = v2.front();
                v1.pop();
                v2.pop();
                if (node1->val != node2->val)
                    return false;
                if (node1->left && node2->left)
                {
                    v1.push(node1->left);
                    v2.push(node2->left);
                }
                else if (node1->left || node2->left)
                {
                    return false;
                }

                if (node1->right && node2->right)
                {
                    v1.push(node1->right);
                    v2.push(node2->right);
                }
                else if (node1->right || node2->right)
                {
                    return false;
                }
            }
        }

        return true;
    }
};
// @lc code=end
