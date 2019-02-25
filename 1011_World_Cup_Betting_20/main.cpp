// Sample Input:
// 1.1 2.5 1.7
// 1.2 3.1 1.6
// 4.1 1.2 1.1
// Sample Output:
// T T W 39.31

#include <iostream>
#include <math.h>
using namespace std;
int main(){
	char wtl[3] = {'W', 'T', 'L'};
	float a[3];
	int b[3];
	float temp[3];
	for(int i = 0; i < 3; i ++){
		scanf("%f%f%f", &temp[0], &temp[1], &temp[2]);
		a[i] = temp[0];
		b[i] = 0;
		for(int j = 1; j < 3; j ++){
			if(temp[j] > a[i]){
				a[i] = temp[j];
				b[i] = j;
			}
		}
	}
	printf("%.2f %.2f %.2f\n", a[0], a[1], a[2]);
	printf("%c %c %c %.2f", wtl[b[0]], wtl[b[1]], wtl[b[2]], (a[0]*a[1]*a[2]*0.65 - 1)*2);
	
	return 0;
}
