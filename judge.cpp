/*#include<bits/stdc++.h>
using namespace std;
bool Judge(string);
int main(){
	string in;
	//cout<<"请输入："; 
	cin>>in;
	int result=Judge(in);
	cout<<result;
} */
//判断类型 返回值为1表明该字体为大写或小写，返回值为0说明不合法 
bool Judge(string a){
	int l=a.length();
	//cout<<l<<endl;
	int cnt=0;
    int result;
	string number="0123456789";
	string character="零壹贰叁肆伍陆柒捌玖拾元整亿万仟佰";
	//cout<<character.size()<<endl;
	for(int i=0;i<l;i++){
		for(int j=0;j<10;j++){
			if(a[i]==number[j]){
				cnt++;
			}
		}
	}
	for(int i=0;i<l;i++){
		for(int j=0;j<34;j++){
			if(a[i]==character[j]){
				cnt++;
				break;
			}
		}
	}
	//cout<<cnt<<endl; 
	if(cnt==l){
		//说明该字体合法 
		return true;
	}
	else 
	return false;
} 

