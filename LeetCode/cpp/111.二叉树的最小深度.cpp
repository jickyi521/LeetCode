/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        int depth = 0, count = 1, sum = 1;
        TreeNode *currNode;
        queue<TreeNode *> q;
        q.push(root);

        while (q.size() > 0)
        {
            sum = count;
            count = 0;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                currNode = q.front();

                if (!currNode->left && !currNode->right)
                {
                    depth++;
                    return depth;
                }

                if (currNode->left)
                {
                    q.push(currNode->left);
                    count++;
                }

                if (currNode->right)
                {
                    q.push(currNode->right);
                    count++;
                }
                q.pop();
            }
            depth++;
        }

        return depth;
    }
};
// @lc code=end
