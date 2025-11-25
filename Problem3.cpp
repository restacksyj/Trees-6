// Problem - Vertical order traversal
//  Time Complexity : O(n)
//  Space Complexity : O(n)
//  Did this code successfully run on Leetcode : Yes
//  Any problem you faced while coding this : No

// Your code here along with comments explaining your approach
// 1. We use BFS traversal here, and if we are going  left we add col - 1 and
// right we use col + 1
// 2. We also keep pushing the col values in a map and keep calculating maxw and
// minw
// 3. In the end we go from minw to maxw, and push the values to our result
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
class Solution {
public:
  vector<vector<int>> verticalOrder(TreeNode *root) {
    if (!root)
      return {};
    unordered_map<int, vector<int>> m;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    int minW = 0;
    int maxW = 0;
    while (!q.empty()) {
      auto front = q.front();
      q.pop();
      TreeNode *node = front.first;
      int col = front.second;
      m[col].push_back(node->val);
      if (node->left) {
        minW = min(minW, col - 1);
        q.push({node->left, col - 1});
      }
      if (node->right) {
        maxW = max(maxW, col + 1);
        q.push({node->right, col + 1});
      }
    }

    vector<vector<int>> res;
    for (int i = minW; i <= maxW; i++) {
      res.push_back(m[i]);
    }
    return res;
  }
};
