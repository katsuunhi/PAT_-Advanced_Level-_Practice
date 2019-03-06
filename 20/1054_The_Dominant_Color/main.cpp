/*

Sample Input:
5 3
0 0 255 16777215 24
24 24 0 0 24
24 0 24 24 24
Sample Output:
24

*/
//map相当于dic，用来计数非常方便
//cin要比scanf慢很多，尽量使用scanf
#include <iostream>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;

int main(){
	map<int, int> m;
	int width, height;
	// cin >> width;
	// cin >> height;
	scanf("%d%d", &width, &height);
	int image[width][height];
	for(int i = 0; i < width; i ++){
		for(int j = 0; j < height; j ++){
//			cin >> image[i][j];
			scanf("%d", &image[i][j]);
			m[image[i][j]] ++;
			if(m[image[i][j]] > width*height/2){
				cout << image[i][j];
				return 0;
			}
		}
	}
	return 0;
}
