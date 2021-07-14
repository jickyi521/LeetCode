#include <iostream>

#include <vector>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//[1]两数之和
// vector<int> twoSum(vector<int> &nums, int target)
// {
//     vector<int> result;
//     for (int i = 0; i < nums.size() - 1; i++)
//     {
//         int cur = nums[i];
//         for (int j = i + 1; j < nums.size(); j++)
//         {
//             if (cur + nums[j] == target)
//             {
//                 result.push_back(i);
//                 result.push_back(j);
//                 return result;
//             }
//         }
//     }
//     return result;
// }

//[7]整數反转
int reverse(int x)
{
    string res = to_string(x);
    int len = res.length();
    int n = len - 1;
    int begin = x > 0 ? 0 : 1;
    int sum = x > 0 ? (len / 2 - 1) : len / 2;
    for (int i = begin; i <= sum; i++)
    {
        swap(res[i], res[n]);
        n--;
    }

    if (stol(res) >= 2147483647 || stol(res) <= -2147483648)
    {
        cout << '0' << endl;
        return 0;
    }
    else
    {
        int resI = stoi(res);
        cout << resI << endl;
        return resI;
    }
}

//[9]回文数
bool isPalindrome(int x)
{
    if (x < 0)
        return false;

    string str = to_string(x);
    int len = str.length();
    int num = len - 1;
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[num])
        {
            return false;
        }
        num--;
    }
    return true;
}

//[13]罗马数字转整数
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

//[14]最长公共前缀
string longestCommonPrefix(vector<string> &strs)
{
    int count = strs.size();
    if (count == 1)
        return strs[0];

    string cur = strs[0];
    string commonStr = "", temp = "";
    for (int i = 0; i < cur.size(); i++)
    {
        temp += cur[i];
        string::size_type idx = string::npos;
        for (int j = 1; j < count; j++)
        {
            idx = strs[j].find(temp);
            // cout << idx << endl;
            if (idx != 0)
            {
                return commonStr;
            }
        }
        commonStr = temp;
    }
    return commonStr;
}

//[58]
int lengthOfLastWord(string s)
{
    string word = "", temp = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            temp = "";
        }
        else
        {
            temp = temp + s[i];
            word = temp;
        }
    }

    return word.length();
}

//[66] 加一
vector<int> plusOne(vector<int> &digits)
{
    vector<int> numN;
    int count = 0;
    for (int i = digits.size() - 1; i >= 0; i--)
    {
        int plusT = digits[i] + 1;
        if (plusT == 10)
        {
            digits[i] = 0;
        }
        else
        {
            count = i;
            digits[i] = plusT;
            break;
        }
    }

    if (digits[0] == 0)
    {
        numN.push_back(1);
        for (int i = 0; i < digits.size(); i++)
        {
            numN.push_back(digits[i]);
        }
        return numN;
    }
    else
    {
        return digits;
    }
}

//[67]
string addBinary(string a, string b)
{

    reverse(a.begin(), a.end());

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

//[94] 左中右
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

void postorder(TreeNode *root, vector<int> &res)
{

    if (root->left)
    {
        postorder(root->left, res);
    }

    if (root->right)
    {
        postorder(root->right, res);
    }

    res.push_back(root->val);
}

//[145]后序遍历
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> res;
    if (root == nullptr)
        return res;

    postorder(root, res);
    return res;
}

vector<int> postorderTraversal2(TreeNode *root)
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

TreeNode *sortedArrayToBSTTemp(vector<int> &nums, int left, int right)
{
    if (left > right)
    {
        return nullptr;
    }

    int mid = (left + right) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBSTTemp(nums, left, mid - 1);
    root->right = sortedArrayToBSTTemp(nums, mid + 1, right);

    return root;
}

//[105]将有序数组转换为二叉搜索树
TreeNode *sortedArrayToBST(vector<int> &nums)
{
    return sortedArrayToBSTTemp(nums, 0, nums.size() - 1);
}

//[111]
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

//118杨辉三角
vector<vector<int> > generate(int numRows)
{
    vector<vector<int> > res(numRows);

    for (int i = 0; i < numRows; i++)
    {
        res[i].resize(i + 1);
        res[i][0] = res[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
        }
    }
    return res;
}

//122买卖股票最佳时机2
int maxProfit2(vector<int> &prices)
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

//125验证回文串
bool isPalindrome(string s)
{
    string handlerS = "";
    int min1 = (int)'a';
    int max1 = (int)'z';
    int min2 = (int)'A';
    int max2 = (int)'Z';
    int min3 = (int)'0';
    int max3 = (int)'9';
    int diff = min1 - min2;
    for (int i = 0; i < s.length(); i++)
    {
        int curr = (int)s[i];
        if (curr >= min2 && curr <= max2)
        {
            curr += diff;
            handlerS += char(curr);
        }
        else if ((curr >= min3 && curr <= max3) || (curr >= min1 && curr <= max1))
        {
            handlerS += s[i];
        }
    }

    int len = handlerS.length();
    for (int i = 0; i < len / 2; i++)
    {
        int cur = (int)handlerS[i];
        int last = (int)handlerS[len - 1 - i];
        if (cur != last)
        {
            return false;
        }
    }

    return true;
}

class MinStack
{
public:
    /** initialize your data structure here. */

   stack<int> s1;
   stack<int> s2;
    MinStack()
    {
    }

    void push(int val)
    {
        
        s1.push(val);
    }

    void pop()
    {
        s1.pop();
    }

    int top()
    {

        return s1.top();
    }

    int getMin()
    {
        s2  = s1;

        int min = s2.top();
        s2.pop();
        while (!s2.empty())
        {
            int val = s2.top();
            s2.pop();
            if(val < min) {
                min = val;
            }
        }
        
        return min;
    }
};

int main()
{
    //[9]
    // cout << isPalindrome(-121) << endl;
    // cout << isPalindrome(121) << endl;
    // cout << isPalindrome(10) << endl;

    //[13]
    // cout << romanToInt("III") << endl;
    // cout << romanToInt("IV") << endl;
    // cout << romanToInt("IX") << endl;
    // cout << romanToInt("LVIII") << endl;
    // cout << romanToInt("MCMXCIV") << endl;

    //[14]
    // string arr[1] = {""};
    // string arr[3] = {"dog", "racecar", "car"};
    // string arr[3]={"flower","flow","flight"};
    // string arr[4]={"flower","flower","flower","flower"};

    // string arr[3] = {"c", "acc", "ccc"};
    // vector<string> ivec(arr, arr + 3);
    // cout << longestCommonPrefix(ivec) << endl;

    // string arr[3] = {"c", "acc", "ccc"};
    // vector<string> ivec(arr, arr + 3);
    // cout << longestCommonPrefix(ivec) << endl;

    //58
    // cout << lengthOfLastWord("Hello World") << endl;
    // cout << lengthOfLastWord(" ") << endl;
    // cout << lengthOfLastWord("hi") << endl;
    // cout << lengthOfLastWord("a ") << endl;

    //66
    // int arr[3] = {1,2,3};
    // vector<int> ivec(arr, arr+3);
    // plusOne(ivec);

    // int arr2[1] = {0};
    // vector<int> ivec2(arr2, arr2+1);
    // plusOne(ivec2);

    // int arr3[2] = {9, 9};
    // vector<int> ivec3(arr3, arr3 + 2);
    // plusOne(ivec3);

    //67
    // int arr[3] = {1,2,3};
    // cout << addBinary("11", "1") << endl;
    // cout << addBinary("1010", "1011") << endl;
    // cout << addBinary("0", "0") << endl;
    // cout << addBinary("1", "0") << endl;
    // cout << addBinary("1", "1") << endl;
    // cout << addBinary("1", "1111") << endl;

    //94
    // TreeNode *node7 = new TreeNode(7);
    // TreeNode *node6 = new TreeNode(6);
    // TreeNode *node5 = new TreeNode(5);
    // TreeNode *node4 = new TreeNode(4);
    // TreeNode *node3 = new TreeNode(3, node6, node7);
    // TreeNode *node2 = new TreeNode(2, node4, node5);
    // TreeNode *node1 = new TreeNode(1, node2, node3);
    // inorderTraversal(node1);

    //[100]
    //[68,41,null,-85,null,-73,-49,-98,null,null,null,-124] +  [68,41,null,-85,null,-73,-49,-98,null,null,null,-124]
    // TreeNode *node1_2 = new TreeNode(1);
    // TreeNode *node1_3 = new TreeNode(2);
    // TreeNode *node1_1 = new TreeNode(1, node1_2, node1_3);
    // TreeNode *node2_2 = new TreeNode(2);
    // TreeNode *node2_3 = new TreeNode(1);
    // TreeNode *node2_1 = new TreeNode(1, node2_3, node2_2);
    // cout << isSameTree(nullptr, nullptr);

    // TreeNode *node1_6 = new TreeNode(-124, nullptr, nullptr);
    // TreeNode *node1_5 = new TreeNode(-98, node1_6, nullptr);
    // TreeNode *node1_4 = new TreeNode(-72, node1_5, nullptr);
    // TreeNode *node1_4_2 = new TreeNode(-49, nullptr, nullptr);
    // TreeNode *node1_3 = new TreeNode(85, node1_4, node1_4_2);
    // TreeNode *node1_2 = new TreeNode(41, node1_3, nullptr);
    // TreeNode *node1_1 = new TreeNode(68, node1_2, nullptr);

    // TreeNode *node2_6 = new TreeNode(-124, nullptr, nullptr);
    // TreeNode *node2_5 = new TreeNode(-98, node2_6, nullptr);
    // TreeNode *node2_4 = new TreeNode(-72, node2_5, nullptr);
    // TreeNode *node2_4_2 = new TreeNode(-49, nullptr, nullptr);
    // TreeNode *node2_3 = new TreeNode(85, node2_4, node2_4_2);
    // TreeNode *node2_2 = new TreeNode(41, node2_3, nullptr);
    // TreeNode *node2_1 = new TreeNode(68, node2_2, nullptr);
    // cout << isSameTree(node1_1, node2_1);

    //145
    // TreeNode *node7 = new TreeNode(7);
    // TreeNode *node6 = new TreeNode(6);
    // TreeNode *node5 = new TreeNode(5);
    // TreeNode *node4 = new TreeNode(4);
    // TreeNode *node3 = new TreeNode(3, node6, node7);
    // TreeNode *node2 = new TreeNode(2, node4, node5);
    // TreeNode *node1 = new TreeNode(1, node2, node3);
    // // postorderTraversal(node1);
    // postorderTraversal2(node1);

    //101
    // TreeNode *node7 = new TreeNode(3);
    // TreeNode *node6 = new TreeNode(4);
    // TreeNode *node5 = new TreeNode(4);
    // TreeNode *node4 = new TreeNode(3);
    // TreeNode *node3 = new TreeNode(2, node6, node7);
    // TreeNode *node2 = new TreeNode(2, node4, node5);
    // TreeNode *node1 = new TreeNode(1, node2, node3);
    // isSymmetric(node1);

    // TreeNode *node3_1 = new TreeNode(3);
    // TreeNode *node3_2 = new TreeNode(3);
    // TreeNode *node2_1 = new TreeNode(2, nullptr, node3_1);
    // TreeNode *node2_2 = new TreeNode(2, nullptr, node3_2);
    // TreeNode *node1 = new TreeNode(1, node2_1, node2_2);
    // isSymmetric(node1);

    // TreeNode *node2_1 = new TreeNode(0);
    // TreeNode *node1 = new TreeNode(1, node2_1, nullptr);
    // isSymmetric(node1);

    //104
    // TreeNode *node7 = new TreeNode(3);
    // TreeNode *node6 = new TreeNode(4);
    // TreeNode *node5 = new TreeNode(4);
    // TreeNode *node4 = new TreeNode(3);
    // TreeNode *node3 = new TreeNode(2, node6, node7);
    // TreeNode *node2 = new TreeNode(2, node4, node5);
    // TreeNode *node1 = new TreeNode(1, node2, node3);
    // maxDepth(node1);

    // TreeNode *node5_1 = new TreeNode(-4);
    // TreeNode *node4_1 = new TreeNode(-7);
    // TreeNode *node4_2 = new TreeNode(-5, nullptr, node5_1);
    // TreeNode *node3_1 = new TreeNode(-7, node4_1, nullptr);
    // TreeNode *node3_2 = new TreeNode(-6, node4_2, nullptr);
    // TreeNode *node2_1 = new TreeNode(4, node3_1, node3_2);
    // TreeNode *node2_2 = new TreeNode(5);
    // TreeNode *node1 = new TreeNode(1, node2_1, node2_2);
    // maxDepth(node1);

    //[108]
    // int arr[5] = {-10, -3, 0, 5, 9};
    // vector<int> ivec(arr, arr + 5);
    // TreeNode *node = sortedArrayToBST(ivec);
    // int a = 0;

    //[111]
    // TreeNode *node3_1 = new TreeNode(15);
    // TreeNode *node3_2 = new TreeNode(7);
    // TreeNode *node2_1 = new TreeNode(9);
    // TreeNode *node2_2 = new TreeNode(20,node3_1,node3_2 );
    // TreeNode *node1 = new TreeNode(3, node2_1, node2_2);
    // minDepth(node1);

    //[110]
    // TreeNode *node3_1 = new TreeNode(15);
    // TreeNode *node3_2 = new TreeNode(7);
    // TreeNode *node2_1 = new TreeNode(9);
    // TreeNode *node2_2 = new TreeNode(20,node3_1,node3_2 );
    // TreeNode *node1 = new TreeNode(3, node2_1, node2_2);
    // isBalanced(node1);

    // TreeNode *node3 = new TreeNode(3);
    // TreeNode *node2 = new TreeNode(2, nullptr, node3);
    // TreeNode *node1 = new TreeNode(3, nullptr, node2);
    // isBalanced(node1);

    // generate(5);

    // int arr[6] = {7,1,5,3,6,4};
    // vector<int> ivec(arr, arr + 6);
    // maxProfit2(ivec);

    // int arr[2] = {1, 7};
    // vector<int> ivec2(arr, arr + 2);
    // maxProfit2(ivec2);

    //125
    // isPalindrome("A man, a plan, a canal: Panama");
    // isPalindrome("0P");

    //155
    MinStack *stack = new MinStack();
    stack->push(-2);
    stack->push(0);
    stack->push(-3);
    stack->getMin();
    stack->pop();
    stack->top();
    stack->getMin();
}