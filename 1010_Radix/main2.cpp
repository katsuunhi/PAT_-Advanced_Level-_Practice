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

long long to_dec(string str, long long radix){
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
	cout << dec << endl;
	return dec;
}

long long find_min(string str){
	long long min = 37;
	int bit;
	for(long long i = 0; i < str.length(); i ++){
		if(48 <= str[i] && str[i] <= 57)
			bit = str[i] - 48;
		if(97 <= str[i] && str[i] <= 122)
			bit = str[i] - 87;
		if(min > bit)
			min = bit;
	}
	if(min == 0 || min == 1)
		return 2;
	return min + 1;
}

int main(){
	int tag;
	long long radix;
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

	long long max = dec;
	long long min = find_min(n_2);
	long long dec_2 = 0;
	cout << max << " " << min << endl;
	for(int i = 0 ; i < 3; i ++){
		radix = (max + min)/2;
		dec_2 = to_dec(n_2, radix);
		cout << "radix : " << radix << endl;
		if(dec_2 == dec){
			printf("%lld", radix);
			return 0;
		}
		if(dec_2 > dec){
			

			max = radix;
		}
		if(dec_2 < dec){
			min = radix;
		}
		if(min == max)
			break;

	}
	printf("Impossible");
	return 0;
}