int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        sort(points.begin(),points.end(),[](const vector<int>&a,const vector<int>&b){return a[1] < b[1];});
        int arrow = 1;
        int cur_arrow = points[0][1];// 当前箭的位置
        int i = 1;
        //i代表已引爆气球个数
        for (int i = 1; i < points.size(); i++) {
        if (points[i][0] > cur_arrow) {// 当前气球没被覆盖
        arrow++;
        cur_arrow = points[i][1];
            }
        }
        return arrow;
    }