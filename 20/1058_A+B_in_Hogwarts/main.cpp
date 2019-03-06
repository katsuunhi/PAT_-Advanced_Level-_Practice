/*

Sample Input:
3.2.1 10.16.27
Sample Output:
14.1.28

*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	long long int galleon[2];
	int sickle[2];
	int knut[2];
	scanf("%lld.%d.%d", &galleon[0], &sickle[0], &knut[0]);
	scanf("%lld.%d.%d", &galleon[1], &sickle[1], &knut[1]);
	knut[0] += knut[1];
	if(knut[0] > 28){
		knut[0] %= 29;
		sickle[0] ++;
	}
	sickle[0] += sickle[1];
	if(sickle[0] > 16){
		sickle[0] %= 17;
		galleon[0] ++;
	}
	galleon[0] += galleon[1];


	printf("%lld.%d.%d", galleon[0], sickle[0], knut[0]);
	return 0;
}