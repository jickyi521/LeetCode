/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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

    int maxDepth(TreeNode *root)
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

    bool isBalanced(TreeNode *root)
    {
        if (!root)
            return true;

        int count = 1, sum = 1;
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

                int left = maxDepth(currNode->left);
                int right = maxDepth(currNode->right);
                if (abs(right - left) > 1)
                {
                    return false;
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
        }

        return true;
    }
};
// @lc code=end
