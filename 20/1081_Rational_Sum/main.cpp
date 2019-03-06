/*

Sample Input 1:
5
2/5 4/15 1/30 -2/60 8/3
Sample Output 1:
3 1/3
Sample Input 2:
2
4/3 2/3
Sample Output 2:
2
Sample Input 3:
3
1/3 -1/6 1/8
Sample Output 3:
7/24

*/

#include <iostream>
#include <algorithm>
using namespace std;

struct rational{
	long int numerator;
	long int denominator;
};

int main(int argc, char const *argv[])
{

	int n;
	scanf("%d", &n);
	long int deno[n];
	struct rational test[n];
	for(int i = 0; i < n; i ++){
		scanf("%ld/%ld", &test[i].numerator, &test[i].denominator);
		deno[i] = test[i].denominator;
	}
	sort(deno, deno + n);
	
	for(int i = 0; i < n; i ++)
		printf("%ld/%ld ", test[i].numerator, test[i].denominator);
	return 0;
}