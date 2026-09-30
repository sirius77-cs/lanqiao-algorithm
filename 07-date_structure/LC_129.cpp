// 129. 求根到叶子数字之和
// 思路：DFS，val = val * 10 + node->val
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
    int dfs(TreeNode* node, int val) {
        if (!node) return 0;
        val = val * 10 + node->val;
        if (!node->left && !node->right) return val;
        return dfs(node->left, val) + dfs(node->right, val);
    }
};