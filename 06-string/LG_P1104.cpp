#include<bits/stdc++.h>
using namespace std; 

struct Studinfo{
    string name;
    int y;
    int m;
    int d;
    int rank;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Studinfo>students(n);
    for(int i = 0; i < n; i++){
        cin >> students[i].name >> students[i].y >> students[i].m >> students[i].d;
        students[i].rank = i;
    }
    sort(students.begin(), students.end(), [](const Studinfo &a, const Studinfo &b){
        if(a.y != b.y) return a.y < b.y;
        if(a.m != b.m) return a.m < b.m;
        if(a.d != b.d) return a.d < b.d;
        else return a.rank > b.rank;
    });
    for(int i = 0; i < n; i++){
        cout << students[i].name << "\n";
    }
    return 0;
}