#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string n;int k;
    cin >> n;
    cin >> k;
    //thought process: 先将数字串作为string读入，然后push stack
    stack<char>st;
    for(char c : n){
        while(!st.empty() && st.top() > c && k > 0){//核心greedy，如果前一个比现在大，直接删（pop）
            st.pop();
            k--;
        }
        st.push(c);//压栈
    }

    // 如果 k 还有剩，从栈顶继续删
    while(k > 0){
        st.pop();
        k--;
    }
    string ans;
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    
    int pos = ans.find_first_not_of('0');
    if(pos == string::npos)ans = '0';
    else ans = ans.substr(pos);

    /*循环方法int i = 0;
while (i < ans.size() - 1 && ans[i] == '0') i++;
ans = ans.substr(i);*/

    cout << ans <<"\n";

}