#include<bits/stdc++.h>
using namespace std; 

struct Infor{
    int rank;
    string num;//票数可能会到 100 位数字
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Infor>persons(n);
    for(int i = 0; i < n; i++){
        cin >> persons[i].num;
        persons[i].rank = i+1;
    }
    sort(persons.begin(),persons.end(),[](const Infor &a, const Infor &b){
        if (a.num.size() != b.num.size())
        return a.num.size() > b.num.size();
    if (a.num != b.num)
        return a.num > b.num;
    });
    cout << persons[0].rank << "\n" << persons[0].num;
    return 0;
}