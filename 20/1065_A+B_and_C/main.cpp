/*

Sample Input:
3
1 2 3
2 3 4
9223372036854775807 -9223372036854775808 0
Sample Output:
Case #1: false
Case #2: true
Case #3: false

*/

#include <iostream>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	int result[t] = {0};
	long long int a, b, c, d;
	for(int i = 0; i < t; i ++){
	scanf("%lld%lld%lld", &a, &b, &c);
//    d = a + b;
	if(a > 0 && b > 0 && (a + b) <= 0)
		result[i] = 1;
	else if(a < 0 && b < 0 && (a + b) >= 0)
		continue;
	else if((a + b) > c)
		result[i] = 1;
	}
	for(int i = 0; i < t - 1; i ++)
		printf("Case #%d: %s\n", i + 1, result[i] == 1 ?"true":"false");
	printf("Case #%d: %s", t, result[t - 1] == 1 ?"true":"false");
	return 0;
}