/*

Sample Input:
15 43 71
Sample Output:
#123456

*/

#include <iostream>
#include <algorithm>
using namespace std;

string atoi(int n, int radix){
	string str;
	while(n){
		if(n%radix < 10)
			str += n%radix + '0';
		else
			str += n%radix - 10 + 'A';
		n /= radix;
	}
	if(str.length() == 1)
		str += '0';
	if(str.length() == 0)
	str = "00"; 
	reverse(str.begin(), str.end());
	return str;
}

int main(){
	int red, green, blue;
	cin >> red;
	cin >> green;
	cin >> blue;

	cout << "#" << atoi(red, 13) << atoi(green, 13) << atoi(blue, 13);

	return 0;
}