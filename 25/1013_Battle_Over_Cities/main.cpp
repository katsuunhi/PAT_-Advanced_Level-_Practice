/*
Sample Input:
3 2 3
1 2
1 3
1 2 3
Sample Output:
1
0
0
*/

//从一个城市开始遍历所有城市，求连通子图的个数，输出个数-1
//没做出来，以后把图的内容单独训练
#include <iostream>
#include <string.h>

using namespace std;


int  cross(int a[], int b[]){
	for(int i = 0; i < 2; i ++)
		for(int j = 0; j < 2; j ++)
			if(a[i] == b[j] && a[i] != 0)
				return 1;
	return 0;
}

int main(){
	int city_num, road_num, check_num;
	cin >> city_num;
	cin >> road_num;
	cin >> check_num;
	int road[road_num][2];
	int road_temp[road_num][2];
	int check[check_num];
	int road_zone = 1;
	for(int i = 0; i < road_num; i ++){
		cin >> road[i][0];
		cin >> road[i][1];
	}
	
	for(int i = 0; i < check_num; i ++)
		cin >> check[i];
	int road_all[city_num][city_num] = {0};
	int city[city_num] = {0};
	for(int i = 0; i < road_num; i ++){
		raod_all[road_temp[i][0]][road_temp[i][1]] = 1;
		raod_all[road_temp[i][1]][road_temp[i][0]] = 1
	}
	for(int i = 0; i < check_num; i ++){
		road_zone = 1;
		memcpy(road_temp, road, sizeof(road)); 
		//删除对应道路
		for(int j = 0; j < road_num; j ++){
			for(int k = 0; k < 2; k ++)
				if(road_temp[j][k] == check[i])
					road_temp[j][k] = 0;
		}
		//
		for(int j = 0; j < city_num; j ++){
			if(j == i)
				continue;

		}


		/*for(int i = 0; i < road_num; i ++){
			for(int j = i + 1; j < road_num; j ++){
				if(!cross(road_temp[i], road_temp[j]))
					road_zone ++;
			}
		}
		printf("%d\n", road_zone - 1);*/
	}

	return 0;
}