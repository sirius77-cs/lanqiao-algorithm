#include<bits/stdc++.h>
using namespace std;

struct Infor{
    int rank;
    int score;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;//读入报名数和计划数
    vector<Infor>persons(n);
    for(int i = 0; i < n; i++){
        cin >> persons[i].rank >> persons[i].score;
    }
    int M = floor(m * 1.5);
    sort(persons.begin() , persons.end() , [](const Infor &a , const Infor &b){
        if(a.score != b.score) return a.score > b.score;
        if(a.rank != b.rank) return a.rank < b.rank;
    });
    int interview_score;
    if( M >= n)interview_score = persons[n-1].score;
    else interview_score = persons[M-1].score;
    int count = 0;
    int i = 0;
    while(persons[i].score >= interview_score){
        i++;
        count++;
        if(i == n)break;
    }

    if(M >= n){
        cout << interview_score << " " << n << "\n";
        for(int i = 0; i < n; i++){
            cout << persons[i].rank << " " << persons[i].score << "\n";
        }
        return 0;
    }

    cout << interview_score << " " << count <<"\n";
    for (int i = 0; i < count; i++)
    {
        cout << persons[i].rank << " " << persons[i].score << "\n";
    }
    return 0;
}