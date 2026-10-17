#include<bits/stdc++.h>
using namespace std;

bool judge_Palindrome(int date){
    int year = date / 10000;
    int month = (date / 100) % 100;
    int day = date % 100;

    if(year < 1000 || year > 9999 || month < 1 || month > 12 || day < 1 || day > 31){   
        return false;
    }
    string strmonth;
    if(month < 10){
        strmonth = "0" + to_string(month);
    } else {
        strmonth = to_string(month);
    }
    string strDay;
    if(day < 10){
        strDay = "0" + to_string(day);
    } else {
        strDay = to_string(day);
    }
    string strDate = to_string(year) + strmonth + strDay;
    string revDate = strDate;
    reverse(revDate.begin(), revDate.end());

    if(strDate == revDate){
            return true;
    } else {
            return false;
    }

}

int nextday(int date){
    int year = date / 10000;
    int month = (date / 100) % 100;
    int day = date % 100;

    //判断月份和日期的合法性
    if(year < 1000 || year > 9999 || month < 1 || month > 12 || day < 1 || day > 31){   
        return -1;
    }

    //判断闰年
    bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    //计算下一个日期
    if(month == 2){
        if(isLeapYear){
            if(day < 29){
                day++;
            } else {
                day = 1;
                month++;
            }
        } else {
            if(day < 28){
                day++;
            } else {
                day = 1;
                month++;
            }
        }
    } else if(month == 4 || month == 6 || month == 9 || month == 11){
        if(day < 30){
            day++;
        } else {
            day = 1;
            month++;
        }
    } else {
        if(day < 31){
            day++;
        } else {
            day = 1;
            month++;
        }
    }

    if(month > 12){
        month = 1;
        year++;
    }

    return year * 10000 + month * 100 + day;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int date1, date2;
    int count = 0;
    cin >> date1 >> date2;

    //判断相等情况
    if(date1 == date2){
        if(judge_Palindrome(date1)){
            cout << "1" << endl;
            return 0;
        } else {
            cout << "0" << endl;
            return 0;
        }
    }
    while(date1 != date2){
        if(judge_Palindrome(date1)){
            count++;
        } 
        date1 = nextday(date1);
    }
    cout << count << endl;

    return 0;
}