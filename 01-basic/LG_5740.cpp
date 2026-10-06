/*
 * 洛谷 P5740 【深基7.例9】最厉害的学生
 * 考点：结构体 + 打擂台找最大值
 * 题意：n 个学生各有语数英三科成绩，输出总分最高的学生姓名及三科成绩。
 * 思路：读入时算好 sum 存进结构体，一遍打擂台找最大总分，记录下标。
 * 复杂度：时间 O(n)，空间 O(n)
 */
#include<bits/stdc++.h>
using namespace std;

struct Student
{
    /* data */
    string name;
    int chinese;
    int math;
    int english;
    int sum;
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<Student> students(n);
    for(int i = 0; i < n; i++){
        cin >> students[i].name >> students[i].chinese >> students[i].math >> students[i].english;
        students[i].sum = students[i].chinese + students[i].math + students[i].english;  // 顺手统计总分
    }

    int maxSum = students[0].sum;   // 打擂台：记录当前最大总分
    int target = 0;                 // 对应学生下标
    for(int i = 0; i < n; i++){
        // if(students[i].sum > max){   // 【错误·已注释】max 不是变量而是 std::max 函数
        //     max = students[i].sum;   //          （int 与函数指针比较，无法通过编译）
        //     target = i;
        // }
        if(students[i].sum > maxSum){   // 【修正】与记录值 maxSum 比较
            maxSum = students[i].sum;
            target = i;
        }
    }
    cout << students[target].name << " " << students[target].chinese << " " << students[target].math << " " << students[target].english;
    return 0;
}
