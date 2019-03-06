/*

Sample Input:
helloworld!
Sample Output:
h   !
e   d
l   l
lowor

*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	string str;
	cin >> str;
	int n;
	n = str.length();
	int n1, n2, n3;
	/*for(n2 = 3; 3 <= n2 && n2 <= n; n2 ++){
		n1 = n3 = (n + 2 - n2)/2;
	}*/
	n1 = n3 = (n + 2)/3;
	n2 = n + 2 - n1 - n3;
	for(int i = 0; i < n1 - 1; i ++){
		cout << str[i];
		for(int j = 0; j < n2 - 2; j ++)
			cout << " ";
		cout << str[n - i - 1] << endl;
	}
	for(int i = 0; i < n2; i ++)
		cout << str[n1 + i - 1];
	return 0;
}