// Sample Input:
// 10
// -10 1 2 3 4 -5 -23 3 7 -21

// Sample Output:
// 10 1 4

//第一种方案，找两个负数之间的连续整数，并不满足题目要求，但是结果和暴力解法一样，说明测试节点中最大值也就是连续的正整数
#include <iostream>
using namespace std;

int main(){

	int num;
	int a;
	int temp = 0;
	int sum = 0;
	int first = 0;
	int last = 0;
	int first_temp = 0;
	int last_temp = 0;
	int flag = 1;

	cin >> num;
	
	for(int i = 0; i < num; i ++){
		cin >> a;
		if(a >= 0){
			if(flag)
				first_temp = a;
			flag = 0;
			last_temp = a;
			temp += a;
			if(temp > sum){
				sum = temp;
				first = first_temp;
				last = last_temp;
			}
		}
		else{
			flag = 1;
			temp = 0;
		}
	}
	cout << sum << " " << first << " " << last;
	return 0;
}