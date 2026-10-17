#include<bits/stdc++.h>
using namespace std;

int findrow(int n){
    int row = 1;
    int sum = 0;
    while(sum < n){
        sum += row;
        row++;
    }
    return row - 1; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin >> n;
    int row = findrow(n);
    int pos = n - row*(row-1)/2;
    int numerator,denominator;
    if(row%2 == 0){numerator = pos;denominator = row - pos +1;}
    else{numerator = row - pos +1 ; denominator = pos;}
    cout << numerator << "/" << denominator << " "; 
    return 0;
}