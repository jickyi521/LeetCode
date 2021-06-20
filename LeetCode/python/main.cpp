#include <iostream>

#include <vector>

using namespace std;

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

    string arr[3]={"c","acc","ccc"};
    vector<string> ivec(arr, arr + 3 );
    cout << longestCommonPrefix(ivec) << endl;
}