/*
 * 洛谷 P1106 删数问题
 * 考点：贪心 + 栈（单调栈思想）
 * 题意：给一个高精度正整数 s（字符串形式），删去 k 个数字后使剩下的数最小。
 * 思路：从左往右扫描数字串入栈：当当前字符比栈顶小时，弹出栈顶（删除一个
 *       更大的高位数字收益最大），直到删满 k 个或栈不降；扫描完 k 还有剩
 *       则从栈顶（末尾）继续删。最后翻转栈得到结果，去掉前导零。
 * 复杂度：时间 O(|s|)，空间 O(|s|)
 */
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
            st.pop();               // 高位上的大数字删掉，让小数字顶上来
            k--;
        }
        st.push(c);//压栈
    }

    // 如果 k 还有剩，说明整个序列不降，从栈顶（末尾最大处）继续删
    while(k > 0){
        st.pop();
        k--;
    }
    string ans;
    while(!st.empty()){
        ans+=st.top();              // 栈是倒着的，收集后需要反转
        st.pop();
    }
    reverse(ans.begin(),ans.end());

    int pos = ans.find_first_not_of('0');   // 去前导零
    if(pos == string::npos)ans = '0';       // 全零则输出 "0"
    else ans = ans.substr(pos);

    /*循环方法int i = 0;
    while (i < ans.size() - 1 && ans[i] == '0') i++;
    ans = ans.substr(i);*/

    cout << ans <<"\n";

}
