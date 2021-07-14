/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
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
        s2 = s1;

        int min = s2.top();
        s2.pop();
        while (!s2.empty())
        {
            int val = s2.top();
            s2.pop();
            if (val < min)
            {
                min = val;
            }
        }

        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
