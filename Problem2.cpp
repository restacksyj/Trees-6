// Problem - Serialize and deserialize binary tree
//  Time Complexity : O(n)
//  Space Complexity : O(h)
//  Did this code successfully run on Leetcode : Yes
//  Any problem you faced while coding this : No

// Your code here along with comments explaining your approach
// 1. We first serialize the tree using dfs traversal postorder
// 2. Next we deserialize the tree using reverse indexing since we have
// serialized using postorder
// 3. The returned node contains the original tree
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    string res = "";
    serializeHelper(root, res);
    cout << res << endl;
    return res;
  }

  void serializeHelper(TreeNode *root, string &res) {
    // base
    if (root == nullptr) {
      res += "#,";
      return;
    }
    serializeHelper(root->right, res);
    serializeHelper(root->left, res);
    res += to_string(root->val) + ",";
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    vector<string> li;
    istringstream iss(data);
    string c;
    while (getline(iss, c, ',')) {
      li.push_back(c);
    }
    int idx = (int)li.size() - 1;
    return deserializeHelper(li, idx);
  }

  TreeNode *deserializeHelper(vector<string> &data, int &idx) {
    // base
    if (data[idx] == "#") {
      idx--;
      return nullptr;
    }
    TreeNode *root = new TreeNode(stoi(data[idx]));
    idx--;
    root->left = deserializeHelper(data, idx);
    root->right = deserializeHelper(data, idx);
    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
