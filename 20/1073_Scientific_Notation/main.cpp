/*

Sample Input 1:
+1.23400E-03
Sample Output 1:
0.00123400
Sample Input 2:
-1.2E+10
Sample Output 2:
-12000000000

*/
//有一个测试点超时，不知道原因。。。。
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	string str;

	cin >> str;
//	scanf("%s", str);
	int e = 0;
	string coe, exp;
	while(1){
		if(str[e] == '.'){
			e ++;
			continue;
		}
		if(str[e] == 'E')
			break;
		coe += str[e];
		e ++;
	}
	e ++;
/*	int index_e = str.find('E');
	coe = str.substr(0, index_e);
	exp = str.substr(index_e + 1, str.size() - index_e - 1);*/
	while(e < str.length()){
		exp += str[e];
		e ++;
	}
//	cout << coe << endl << exp << endl;
	int exp_digit = 0;
	for(int i = 1; i < exp.length(); i ++){
		exp_digit += (exp[i] - '0')*pow(10, exp.length() - i - 1);
	}
	if(coe[0] == '-')
		cout << '-';
	if(exp[0] == '+'){
		for(int i = 1; i < coe.length(); i ++){
			printf("%c", coe[i]);
		}
		for(int i = 0; i < exp_digit - coe.length() + 2; i ++)
//			cout << '0';
			printf("0");
	}
	else{
		if(exp_digit == 0)
			cout << "0.";
		for(int i = 0; i < exp_digit; i ++){
//			cout << '0';
			printf("0");
			if(i == 0)
				cout << '.';
		}
		for(int i = 1; i < coe.length(); i ++){
			/*if(coe[i] == '.')
				continue;*/
			// cout << coe[i];
			printf("%c", coe[i]);
		}
	}
	return 0;
}