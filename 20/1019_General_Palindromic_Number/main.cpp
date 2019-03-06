/*

Sample Input 1:
27 2
Sample Output 1:
Yes
1 1 0 1 1
Sample Input 2:
121 5
Sample Output 2:
No
4 4 1

*/

#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;


string itoa(int a, int radix){
	string n;
	while(a){
		if(a%radix <= 9)
//			printf("%c\n", a%radix + '0');
			n += a%radix + '0';
		else
			n += a%radix - 10 + 'a';
//			printf("%c\n", a%radix + 'a' - 10);
		a = a/radix;
	}
	reverse(n.begin(), n.end());
	return n;
}

/*int main(){
	int a;
	int radix;
	string n;
	scanf("%d%d", &a, &radix);
	n = itoa(a, radix);
//	printf("%s", n);

	cout << n;
	return 0;
}*/

int main(){
	int n, b;
	scanf("%d%d", &n, &b);

	string str;
	str = itoa(n, b);
	string temp = str;
	reverse(temp.begin(), temp.end());
	if(temp == str)//strcmp(temp.c_str(), str.c_str()))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	if(str == ""){
		cout << "0";
		return 0;
	}
	cout << str[0];
	for(int i = 1; i < str.length(); i ++)
		cout << " " << str[i];
	
	return 0;
}
