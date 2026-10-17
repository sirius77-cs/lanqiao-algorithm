#include<bits/stdc++.h>
using namespace std;

struct Studentinfo{
    int chinese;
    int math;
    int english;
    int total;
    int rank;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Studentinfo> students(n);
    for(int i = 0; i < n; i++){
        cin >> students[i].chinese >> students[i].math >> students[i].english;
        students[i].rank = i + 1;
        students[i].total = students[i].chinese + students[i].math + students[i].english;
    }
    sort(students.begin(), students.end(), [](const Studentinfo &a, const Studentinfo &b){
        if(a.total != b.total) return a.total > b.total;
        if(a.chinese != b.chinese) return a.chinese > b.chinese;
        else return a.rank < b.rank;
    });
    for(int i = 0; i < 5; i++){
        cout << students[i].rank << " " << students[i].total << endl;
    }
    return 0;
}