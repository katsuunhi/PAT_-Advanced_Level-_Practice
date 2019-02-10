/*

Sample Input:
73 10
23 2
23 10
-2
Sample Output:
Yes
Yes
No

*/

#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int atoi(string a, int radix){
	int num = 0;
	for(int i = 0; i < a.length(); i ++){
		num += (a[i] - '0') * floor(pow(radix, a.length() - i - 1)); //floor()，向上取整，必须要
	}
	return num;
}

string itoa(int a, int radix){
	string n = "";
	while(a){
		n += a%radix + '0';
		a = a/radix;
	}
	reverse(n.begin(), n.end());
	return n;
}

int is_prime(int num){
	if(num == 0 || num == 1)					// 判断是否为0,1，必须要
		return 0;
	for(int i = 2; i <= sqrt(num); i ++)		// <= ，必须要
		if(num % i == 0)
			return 0;
	return 1;
}

/*int main(){
	int a = 123;
	string temp = "123";
	cout << "itoa " << itoa(a, 2);
	cout << "atoi " << atoi(temp, 8);
	return 0;
}*/
int main(){
	int n[10000];
	int radix[10000];
	int num = 0;
	string temp;
	cin >> n[0];
	while(n[num] > 0){
		scanf("%d", &radix[num]);
		num ++;
		cin >> n[num];
	}
	for(int i = 0; i < num; i ++){
		temp = itoa(n[i], radix[i]);
		reverse(temp.begin(), temp.end());
		if(is_prime(n[i]) && is_prime(atoi(temp, radix[i]))){
			cout << "Yes" << endl;
		}
		else
			cout << "No" << endl;
	}
	return 0;
}