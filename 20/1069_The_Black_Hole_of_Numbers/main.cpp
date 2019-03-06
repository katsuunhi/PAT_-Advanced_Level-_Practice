/*

Sample Input 1:
6767
Sample Output 1:
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
Sample Input 2:
2222
Sample Output 2:
2222 - 2222 = 0000

*/
//输入为一个正整数，未必是4位，要先补位
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

//输入一个四位的字符串，输出对应的数字
int stoi(char *a){
	int digit;
	for(int i = 3; i >= 0; i --)
		digit += (a[i] - '0')*pow(10, 3 - i);
	return digit;
}

//对一个整数，转化成四位的字符串，不够补位
string IToS(int a){
	string str;
	if(a < 1000)
		str += '0';
	if(a < 100)
		str += '0';
	if(a < 10)
		str += '0';
	while(a){
		str += a%10 + '0';
		a /= 10;
	}
	cout << "length: " << str.length() << endl;
	return str;
}

//四位数字字符串，组合的最大值，冒泡排序
int get_max(string str){
	char temp;
	for(int i = 0; i < 4; i ++){
		for(int j = i + 1; j < 4; j ++){
			if(str[i] < str[j]){
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}
	}

	return stoi(str);
}

//四位数字字符串，组合的最小值，冒泡排序
int get_min(string str){
	
	char temp;
	for(int i = 0; i < 4; i ++){
		for(int j = i + 1; j < 4; j ++){
			if(str[i] > str[j]){
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}
	}

	return stoi(str);
}

int main(int argc, char const *argv[])
{
	string n;
	int num;
	int max, min;
	cin >> num;
	n = IToS(num);
	if(n[0] == n[1] && n[0] == n[2] && n[0] == n[3]){
		cout << n << " - " << n << " = 0000";
		return 0;
	}
	int digit, new_digit;
	digit = stoi(n);
	new_digit = digit;
	do{
		digit = new_digit;
		max = get_max(n);
		min = get_min(n);
		new_digit = max - min;
		printf("%04d - %04d = %04d\n", max, min, new_digit);
		if(new_digit == 6174)
			break;
		n = IToS(new_digit);
	}while(1);

	return 0;
}