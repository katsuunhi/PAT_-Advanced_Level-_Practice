/*

Sample Input:
1234567899
Sample Output:
Yes
2469135798

*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(){

	string digit;
	int hash[10] = {0};
	int temp;
	int carry = 0;
	cin >> digit;
	for(int i = 0; i < digit.length(); i ++)
		hash[digit[i] - '0'] ++;
//	if(digit[0] >= '5'){
	reverse(digit.begin(), digit.end());
//	cout << digit << endl;
	for(int i = 0; i < digit.length(); i ++){
		temp = (digit[i] - '0')*2;
		digit[i] = temp%10 + '0';
//		cout << digit[i] << " ";
		if(carry)
			digit[i] ++;
		carry = 0;
		if(temp > 9)
			carry = 1;
	}
	if(carry)
		digit += '1';
	for(int i = 0; i < digit.length(); i ++)
		hash[digit[i] - '0'] --;
	for(int i = 0; i < 10; i ++)
		if(hash[i] != 0){
			cout << "No\n";
			for(int i = digit.length() - 1; i >= 0; i --)
				cout << digit[i];
			return 0;
		}
	cout << "Yes\n";
	for(int i = digit.length() - 1; i >= 0; i --)
		cout << digit[i];

//	}
	return 0;
}