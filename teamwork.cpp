#include <bits/stdlib.h>
using namespace std;
int main()
{
	string num = UI();
	if(!IsWrong(num)){
		if(IsBig(num) == 1){
			if(BigWrong(num)){
				ThrowError(2);
			}
			else{
				string Tnum = TransToSmall(num);
				print(Tnum, 1);
			}
		
		}
		else{
			if(SmallWrong){
				ThrowError(3);
			}
			else{
				string Tnum = TransToBig(num);
				print(Tnum, 2);
			}
		}
	}
	else{
		ThrowError(1);
	}
	
	return 0;
 } 
