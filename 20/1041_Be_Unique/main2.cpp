//使用hash表查找，牺牲内存换取时间
//本来超时>400ms，内存400KB
//现在时间60-70ms,内存700KB
//64MB可以存储16777216个int型，一千万个，8位十进制，2^24
#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int list[n];
	int hash[10000] = {0};
	for(int i = 0; i < n; i ++){
		cin >> list[i];
		hash[list[i]] ++;
	}
	
	for(int i = 0; i < n; i ++){
		if(hash[list[i]] == 1){
			cout << list[i];
			return 0;
		}
	}
	cout << "None";
	return 0;

}