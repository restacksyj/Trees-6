// Problem - range sum bst
//  Time Complexity : O(h)
//  Space Complexity : O(1)
//  Did this code successfully run on Leetcode : Yes
//  Any problem you faced while coding this : No

// Your code here along with comments explaining your approach
// 1. we do the inorder traversal of  the tree
// 2. We keep adding to ans if it is in the given range
// 3. In the end we return the ans
/**
 * Definition for a binary tree node.
 */
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
  int ans = 0;
  int rangeSumBST(TreeNode *root, int low, int high) {
    inorder(root, low, high);
    return ans;
  }
  void inorder(TreeNode *root, int low, int high) {
    if (!root)
      return;
    inorder(root->left, low, high);
    if (root->val >= low && root->val <= high)
      ans += root->val;
    inorder(root->right, low, high);
  }
};
