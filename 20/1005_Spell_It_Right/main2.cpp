//使用整形数据，判断结果有上限

#include <iostream>
#include <string>

using namespace std;

int main(){
	string words[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

	int digit;
	int sum = 0;
	int digits[100] = {0};
	int len = 0;

	cin >> digit;
	while(digit){
		sum += digit % 10;
		digit /= 10;
	}
	while(sum){
		digits[len] = sum % 10;
		len ++;
		sum /= 10;
	}
	len --;
	for(; len > 0; len --)
		cout << words[digits[len]] << " ";
	cout << words[digits[0]];

	return 0;
}
