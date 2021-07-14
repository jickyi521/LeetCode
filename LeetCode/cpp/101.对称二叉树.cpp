/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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

    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return false;

        vector<TreeNode *> v1;
        vector<TreeNode *> v2;
        v1.push_back(root);
        TreeNode *currNode;
        int count = 0;
        int sum = maxDepth(root);
        while (!v1.empty())
        {
            int size = v1.size();
            for (int i = 0; i < size; i++)
            {
                currNode = v1[i];
                if (i < size / 2)
                {
                    TreeNode *anotherNode = v1[size - i - 1];
                    if (currNode->val != anotherNode->val)
                    {
                        return false;
                    }
                }

                if (currNode->left)
                {
                    v2.push_back(currNode->left);
                }
                else
                {
                    v2.push_back(new TreeNode(-999));
                }

                if (currNode->right)
                {
                    v2.push_back(currNode->right);
                }
                else
                {
                    v2.push_back(new TreeNode(-999));
                }
            }
            v1 = v2;
            vector<TreeNode *> temp;
            v2 = temp;
            count++;

            if (count == sum)
            {
                return true;
            }
        }

        return true;
    }
};
// @lc code=end
