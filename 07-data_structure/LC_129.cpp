/*
 * LeetCode 129. 求根到叶子数字之和
 * 考点：树的 DFS（递归遍历），LeetCode 核心代码模式
 * 题意：根到叶子路径上每位数字依次拼接成一个数（如 4->9->5 = 495），求所有路径数之和。
 * 思路：DFS，val = val * 10 + node->val
 * 复杂度：时间 O(节点数)，空间 O(树高)（递归栈）
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
    int dfs(TreeNode* node, int val) {
        if (!node) return 0;                  // 空节点贡献 0
        val = val * 10 + node->val;           // 沿路径向下拼接数字
        if (!node->left && !node->right) return val;  // 叶子：返回本路径的数
        return dfs(node->left, val) + dfs(node->right, val);  // 左右子树贡献相加
    }
};
