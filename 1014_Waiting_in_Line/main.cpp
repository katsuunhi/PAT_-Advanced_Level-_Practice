/*
Sample Input:
2 2 7 5
1 2 6 4 3 534 2
3 4 5 6 7
Sample Output:
08:07
08:06
08:10
17:00
Sorry
*/

#include <iostream>
using namespace std;

int main(){
	int n, m, k, q;
	scanf("%d%d%d%d", &n, &m, &k, &q);
	int time[k];
	int finish_time[k];
	int now = 0;
	for(int i = 0; i < k; i ++)
		cin >> time[i];
	int check[q];
	for(int i = 0; i < q; i ++)
		cin >> check[i];
	int queue[n][m];
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			
		}
	}
	return 0;
}