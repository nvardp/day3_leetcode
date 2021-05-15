#include<stack>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/// N700
/// You are given the root of a binary search tree (BST) and an integer val.
//Find the node in the BST that the node's value equals val and return the subtree 
//rooted with that node. If such a node does not exist, return null.
struct TreeNode {
    int val; TreeNode* left; TreeNode* right;
};
TreeNode* searchBST(TreeNode* root, int val) 
{

    if (root == NULL) {
        return NULL;
    }
    if (root->val == val)
        return root;
    else if (root->val > val) {

        return searchBST(root->left, val);
    }

    else {
        return searchBST(root->right, val);
    }

}
class myStack //Stack with queue
{
    queue<int> q1;
    queue<int> q2;
    int m_top = 0;
    /** Initialize your data structure here. */

    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
        m_top = x;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {

        while (q1.size() > 1)
        {
            m_top = q1.front();
            q1.pop();
            q2.push(m_top);
        }
        int last = q1.front();
        q1.pop();
        queue<int> empty;
        q1 = q2;
        std::swap(q2, empty);
        return last;;
    }

    /** Get the top element. */
    int top() {
        return m_top;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
};
class MyQueue  //queue with stack
{
public:
    /** Initialize your data structure here. */
    stack<int>t;
    stack<int>q;

    void push(int x) {
        t.push(x);
    }
    void exchange() {
        while (!t.empty()) {
            q.push(t.top());
            t.pop();
        }
    }
    int pop() {
        int i;
        if (q.empty())
            exchange();
        i = q.top();
        q.pop();
        return i;
    }

    /** Get the front element. */
    int peek() {
        if (q.empty())
            exchange();
        return q.top();
    }

    bool empty() {
        return q.empty() && t.empty();
    }
};

//design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
class MinStack {
public:
    /** initialize your data structure here. */
    vector<int>st;
    int mini = INT_MAX;

    void push(int val) {
        if (st.empty())
        {
            st.push_back(val);
            mini = val;
        }
        else
        {
            st.push_back(val);
            if (val < mini)
                mini = val;
        }
    }

    void pop() {
        if (st.back() > mini)
            st.pop_back();
        else
        {
            st.pop_back();
            auto minmax = std::minmax_element(st.begin(), st.end());
            mini = *minmax.first;
        }
    }

    int top() {
        return st.back();
    }

    int getMin() {

        return mini;
    }
};


//Given an integer array nums, design an algorithm to randomly shuffle the array.
class Solution {
public:
    vector<int> shuffl;
    vector<int> original;

    Solution(vector<int>& nums) {
        shuffl = nums;
        original = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int range = (shuffl.size());
        int random = int((rand() % range));
        swap(shuffl[0], shuffl[random]);
        return shuffl;
    }
};

//Given an m x n grid of characters board and a string word, return true if word exists in the grid.
//The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically 
//neighboring.The same letter cell may not be used more than once.

class Solution2 {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (dfs(board, i, j, word))
                    return true;
        return false;
    }

    bool dfs(vector<vector<char>>& board, int i, int j, string& word) {
        if (word.empty())
            return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[0])
            return false;
        char c = board[i][j];
        board[i][j] = ' ';

        string s = word.substr(1);
        bool ret = dfs(board, i - 1, j, s) || dfs(board, i + 1, j, s) || dfs(board, i, j - 1, s) || dfs(board, i, j + 1, s);
        board[i][j] = c;
        return ret;
    }
};

vector<vector<string>> suggestedProducts(vector<string>& products,    string searchWord) {
    sort(products.begin(), products.end());
    vector<vector<string>> result;
    int start, bsStart = 0, n = products.size();
    string prefix;
    for (char& c : searchWord) {
        prefix += c;

        start = lower_bound(products.begin() + bsStart, products.end(), prefix) - products.begin();
        result.push_back({});

        for (int i = start; i < min(start + 3, n) && !products[i].compare(0, prefix.length(), prefix); i++)
            result.back().push_back(products[i]);
        
        bsStart = start;
    }
    return result;
}
int main()
{
    vector<string> vec{ "mobile", "mouse", "moneypot", "monitor", "mousepad" };
    string key = "mouse";
    suggestedProducts(vec, key);
}

