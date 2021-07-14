/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    // void postorder(TreeNode *root, vector<int> &res)
    // {

    //     if (root->left)
    //     {
    //         postorder(root->left, res);
    //     }

    //     if (root->right)
    //     {
    //         postorder(root->right, res);
    //     }

    //     res.push_back(root->val);
    // }

    // vector<int> postorderTraversal(TreeNode *root)
    // {
    //     vector<int> res;
    //     if (root == nullptr)
    //         return res;

    //     postorder(root, res);
    //     return res;
    // }

    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        TreeNode *currNode = root;
        TreeNode *preNode;
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
            currNode = node->right;
            if (currNode == nullptr || preNode == currNode)
            {
                currNode = nullptr;
                preNode = node;
                res.push_back(node->val);
            }
            else
            {
                stackN.push(node);
            }
        }
        return res;
    }
};
// @lc code=end
