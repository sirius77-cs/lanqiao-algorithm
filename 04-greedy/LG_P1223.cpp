#include<bits/stdc++.h>
using namespace std;
struct Wait{
    int rank;
    int time;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Wait>infor(n);
    for(int i = 0; i < n; i++){
        cin >> infor[i].time;
        infor[i].rank = i + 1;
    }
    sort(infor.begin(),infor.end(),[](const Wait &a , const Wait &b){
        if(a.time != b.time)return a.time < b.time;
        return a.rank < b.rank;
    });
    for(int i = 0; i < n; i++){
        cout << infor[i].rank << " ";
    }
    long long sum = 0, elapsed = 0;
    for (const auto& person : infor) {
        sum += elapsed;
        elapsed += person.time;
    }
    double aver = sum/(n * 1.0);
    cout << "\n" << fixed << setprecision(2) << aver << "\n";
    return 0;
}