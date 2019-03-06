/*

Sample Input:
5 1 2 4 14 9
3
1 3
2 5
4 1
Sample Output:
3
10
7

*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	long long distances[n];
	long long distance = 0;
	cin >> distances[0];
	
	for(int i = 1; i < n; i ++){
		cin >> distances[i];
		distances[i] = distances[i] + distances[i - 1];
//		cout << distances[i - 1] << " ";
	}
	distance = distances[n - 1];
//	cout << distance << endl;
//	cout << distance << endl;
	int m;
	cin >> m;
	int check[m][2];
	int temp;
	for(int i = 0; i < m; i ++){
		cin >> check[i][0];
		cin >> check[i][1];
		if(check[i][0] > check[i][1]){
			temp = check[i][0];
			check[i][0] = check[i][1];
			check[i][1] = temp;
		}

	}

	long long distance1 = 0;
	for(int i = 0; i < m; i ++){
		/*for(int j = check[i][0] - 1; j != check[i][1] - 1; j = (j + 1)%n){			
			distance1 += distances[j];
		}*/
//		cout << check[i][1] - 1 << " " << check[i][0] - 2 << endl;
		if(check[i][0] > 1)
			distance1 = distances[check[i][1] - 2] - distances[check[i][0] - 2];
		else
			distance1 = distances[check[i][1] - 2];
		if(distance1 <= distance/2)
			cout << distance1 << endl;
		else
			cout << distance - distance1 << endl;
		distance1 = 0;
	}
	

	return 0;
}