/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        TreeNode *currNode = root;
        stack<TreeNode *> stackN;
        while (!stackN.empty() || currNode)
        {
            while (currNode)
            {
                stackN.push(currNode);
                currNode = currNode->left;
            }

            TreeNode *node = stackN.top();
            stackN.pop();
            res.push_back(node->val);
            currNode = node->right;
        }

        return res;
    }
};
// @lc code=end
