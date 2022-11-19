#include <iostream>
#include <istream>
#include <streambuf>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iterator>
#include <regex>
#include <dirent.h>
#include <algorithm>
#include <ctype.h>
#include <math.h>
using namespace std;

//vector<string> a={"零壹贰叁肆伍陆柒捌玖拾"};
//vector<string> b={"佰","仟","万","亿"};
string str1[10]={"零","壹","贰","叁","肆","伍","陆","柒","捌","玖"},str2[5]={"拾","佰","仟","万","亿"};
string str[30]={"零","壹","贰","叁","肆","伍","陆","柒","捌","玖","拾","佰","仟", "万",   "亿"};
            //    0   1   2    3    4   5    6   7    8   9    10   100 1000 10000  100000

int convert(string str){
    for (int i=0; i<10; i++) {
        if (str==str1[i]) return i;
    }
    for (int i=0; i<5; i++) {
        if (str==str2[i]) return 10*pow(10,i);
    }
    return -1;
}

bool isChinesenum(string n) {
    int num=0;
//    char x[100][4];
    string x[100];
//    if (n.size()>25) return false;
    for (int i=0;i<n.size();i+=3) {
        char a[4];
        a[0]=n[i];
        a[1]=n[i+1];
        a[2]=n[i+2];
//        num*=10;
        x[num++]=a;
//        strcpy(x[num++], a);
        cout<<x[num-1];
        if (convert(a)==100000||convert(a)==10000||convert(a)==1000||convert(a)==100||convert(a)==10) {
//            for (int i=num-2; i<num; i++) {
                if (convert(x[num-2])<0||convert(x[num-2])>10) return false;
//            }
        }
//        num+=convert(a);
    }
    cout<<endl;
    return true;
};

/*
int main() {
//    string str="玖仟玖佰玖拾玖亿玖仟玖佰玖拾玖万玖仟玖佰玖拾玖元整";
    
//    string s="零壹贰叁肆伍陆柒捌玖拾";

//    cout<<s[0]+s[1]+s[2]<<endl;
//    for (int i=0; i<15; i++) {
//        cout<<convert(str[i])<<" ";
//    }
//    cout<<isChinesenum("玖仟玖佰玖拾玖亿玖仟玖佰玖拾玖万玖仟玖佰玖拾玖元整");
//    cout<<endl;
    string n;
    cin>>n;
    isChinesenum(n);
    return 0;
}
*/