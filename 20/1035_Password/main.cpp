/*

Sample Input 1:
3
Team000002 Rlsp0dfa
Team000003 perfectpwd
Team000001 R1spOdfa
Sample Output 1:
2
Team000002 RLsp%dfa
Team000001 R@spodfa
Sample Input 2:
1
team110 abcdefg332
Sample Output 2:
There is 1 account and no account is modified
Sample Input 3:
2
team110 abcdefg222
team220 abcdefg333
Sample Output 3:
There are 2 accounts and no account is modified

*/

#include <iostream>
#include <algorithm>
using namespace std;

struct account{
	string name;
	string password;
	int modified = 0;
};


int main(){
	int n;
	int m = 0;
	cin >> n;
	struct account accounts[n];
	for(int i = 0; i < n; i ++){
		cin >> accounts[i].name;
		cin >> accounts[i].password;
	}
	for(int i = 0; i < n ; i ++){
		for(int j = 0; j < accounts[i].password.length(); j ++){
//			cout << accounts[i].password[j] << accounts[i].modified;
			switch(accounts[i].password[j]){
				case '1':
					accounts[i].password[j] = '@';
					accounts[i].modified = 1;
					continue;
				case '0':
					accounts[i].password[j] = '%';
					accounts[i].modified = 1;
					
					continue;
				case 'l':
					accounts[i].password[j] = 'L';
					accounts[i].modified = 1;
					
					continue;
				case 'O':
					accounts[i].password[j] = 'o';
					accounts[i].modified = 1;
					
					continue;
				default:
					continue;
			}
			
		}
		if(accounts[i].modified)
			m ++;
	}
	if(m > 0){
		cout << m;
		for(int i = 0; i < n; i ++){
			if(accounts[i].modified){
		
				cout << "\n" << accounts[i].name << " " << accounts[i].password;
			}
		}
	}
	if(m == 0 && n > 1)
		cout << "There are " << n << " accounts and no account is modified";
	if(n == 1)
		cout << "There is 1 account and no account is modified";
	return 0;
}