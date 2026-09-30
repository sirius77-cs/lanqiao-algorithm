/*
 * LeetCode 452. 用最少数量的箭引爆气球
 * 考点：贪心 · 区间选点（LeetCode 核心代码模式，无 main）
 * 题意：气球用区间 [x_start, x_end] 表示，一支箭从 x 垂直射出可引爆所有
 *       覆盖 x 的气球，求引爆全部气球的最少箭数。
 * 思路：按区间右端点升序排序；箭总是打在当前未爆气球中最靠左的右端点上，
 *       依次检查后续气球的左端点是否被当前箭覆盖，覆盖不到则再射一箭。
 * 复杂度：时间 O(n log n)，空间 O(1)（不计排序开销）
 */
int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        // 按右端点升序排序：右端点越小，留给后续箭的空间越紧，贪心最优
        sort(points.begin(),points.end(),[](const vector<int>&a,const vector<int>&b){return a[1] < b[1];});
        int arrow = 1;                     // 至少一支箭
        int cur_arrow = points[0][1];      // 当前箭的位置 = 首个气球的右端点
        // int i = 1;                     // 【冗余·已注释】此变量从未使用，且被下方循环变量遮蔽
        // 从第二个气球起检查是否被当前箭覆盖
        for (int i = 1; i < points.size(); i++) {
        if (points[i][0] > cur_arrow) {    // 当前气球左端点超过箭的位置：没被覆盖
        arrow++;                           // 再射一支箭
        cur_arrow = points[i][1];          // 新箭打在该气球右端点
            }
        }
        return arrow;
    }
