// Sample Input 1:
// 6 110 1 10
// Sample Output 1:
// 2
// Sample Input 2:
// 1 ab 1 2
// Sample Output 2:
// Impossible

#include <iostream>
#include <math.h>
#include <string>
using namespace std;

long long int to_dec(string str, int radix){
	int bit = 0;
	long long int dec = 0;
	if(radix == 1)
		return str.length();
	for(int i = 0; i < str.length(); i ++){
		if(48 <= str[i] && str[i] <= 57)
			bit = str[i] - 48;
		if(97 <= str[i] && str[i] <= 122)
			bit = str[i] - 87;
		if(bit >= radix)
			return -1;
		dec += bit*floor(pow(radix, str.length() - i - 1));
		
	}

	return dec;
}

int main(){
	int tag, radix;
	string n1;
	string n2;
	long long int dec = 0;
	string n_1, n_2;
	cin >> n1;
	cin >> n2;
	cin >> tag;
	cin >> radix;
	if(tag == 1){
		n_1 = n1;
		n_2 = n2;
	}
	else{
		n_1 = n2;
		n_2 = n1;
	}
	dec = to_dec(n_1, radix);
	for(int i = 1; i <= 36; i ++){
		if(to_dec(n_2, i) == dec){
			printf("%d", i);
			return 0;
		}

	}
	printf("Impossible");
	return 0;
}