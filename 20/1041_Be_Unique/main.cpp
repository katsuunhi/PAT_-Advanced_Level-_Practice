/*

Sample Input 1:
7 5 31 5 88 67 88 17
Sample Output 1:
31
Sample Input 2:
5 888 666 666 888 888
Sample Output 2:
None

*/
//超时，16分
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
	int temp;
	cin >> n;
	int vec[n];
	for(int i = 0; i < n; i ++)
		cin >> vec[i];
	int flag[n] = {0};
	for(int i = 0; i < n; i ++){
		if(flag[i])
			continue;
		for(int j = i + 1; j < n; j ++)
			if(vec[i] == vec[j]){
				flag[i] = flag[j] = 1;
			}
	}
	for(int i = 0; i < n; i ++)
		if(!flag[i]){
			cout << vec[i];
			return 0;
		}
	cout << "None";
	return 0;
}