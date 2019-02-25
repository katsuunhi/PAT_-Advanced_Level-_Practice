//暴力方案，最后一个超时，有两个节点没有通过

#include <iostream>

using namespace std;

int main(){
	int num;
	int sequence[10000];
	int sum = 0;
	int first = 0;
	int last = 0;
	int first_temp = 0;
	int last_temp = 0;
	int sum_temp = 0;
	int flag = 1;
	cin >> num;

	for(int i = 0; i < num; i ++){
		cin >> sequence[i];
		if(sequence[i] > 0)
			flag = 0;
	}
	if(flag){
		cout << sum << " " << sequence[0] << " " << sequence[num - 1];
		return 0;
	}
	for(int i = 1; i <= num; i ++){
		for(int j = 0; j < num; j ++){
			first_temp = sequence[j];
			last_temp = sequence[j + i - 1];
			for(int k = 0; k < i; k ++){
				sum_temp += sequence[j + k];
			}
			if(sum < sum_temp){
				sum = sum_temp;
				first = first_temp;
				last = last_temp;
			}
			sum_temp = 0;
		}
	}

	cout << sum << " " << first << " " << last; 



	return 0;
}