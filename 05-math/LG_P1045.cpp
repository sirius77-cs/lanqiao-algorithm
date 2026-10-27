#include<bits/stdc++.h>
using namespace std;

vector<int>mul(vector<int>& A,vector<int>& B){
    vector<int>C(500,0);

    for(int i = 0; i < 500;i++){
        if(A[i]==0)continue;
        for(int j = 0; j + i < 500; j++){
            C[i+j] += A[i] * B[j];
        }
    }
    int carry = 0;
    for(int i = 0; i < 500; i++){
        C[i] += carry;
        carry = C[i]/10;
        C[i] %= 10;
    }
    return C;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int p;
    cin >> p;
    int ans1;
    ans1 = floor(p * log10(2)) + 1;
    cout << ans1 << "\n";
    vector<int> ans(500, 0); ans[0] = 1;
    vector<int> base(500, 0); base[0] = 2;
    while(p > 0){
        if(p%2==1)ans = mul(ans,base);
        base = mul(base,base);
        p/=2;
    }
    ans[0]--;
    for(int i = 499; i >= 0; i--){
        cout << ans[i];
        if((500 - i) % 50 == 0) cout << "\n";
    }
    return 0;
}