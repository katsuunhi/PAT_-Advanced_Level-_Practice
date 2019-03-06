//使用字符串，结果正确

#include <iostream>
#include <string>
#include <sstream>		//可以将数字变成字符串
using namespace std;

int main(){
	stringstream ss;
	string words[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	int sum = 0;
	string digit;
	int len = 0;
	int i = 0;
	cin >> digit;
	for(i = 0; i < digit.length(); i ++)
		sum += digit[i] - 48;
	ss << sum;
	digit = ss.str();
	for(i = 0; i < digit.length() - 1; i ++)
		cout << words[digit[i] - 48] << " ";
	cout << words[digit[i] - 48];
	return 0;
}

