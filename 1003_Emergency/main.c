//从跟节点出发到目的节点的最短路径
//如果有多条路径，选择节点value和最大的一条路径
//输出为 路径长度 value和

// input
// 5 6 0 2
// 1 2 1 5 3
// 0 1 1
// 0 2 2
// 0 3 1
// 1 2 1
// 2 4 1
// 3 4 1

// output
// 2 4

#include <stdio.h>
#include <malloc.h>

int min_distance = 65535;
int max_rescue_team_num = 0;
int node_num;
int road_num;
int source;
int destination;
int *rescue_team;
int map[500][500] = {0};


bool in_path(int path[], int path_length, int i){
	int j;
	for(j = 0; j < path_length; j ++)
		if(i == path[j])
			return true;
	return false;
}


int func(int path[], int path_length, int distance, int rescue_team_num,int ex_row, int row){
	int i = 0;
	int j = 0;

	distance += map[ex_row][row];
	rescue_team_num += rescue_team[ex_row];

	path[path_length] = row;
	path_length ++;
	/*for(i = 0; i < path_length; i ++)
		printf("%d", path[i]);
	printf("\t%d\t%d\t%d\t\n", distance, rescue_team_num, row);*/
	for(i = 0; i < node_num; i ++){
		
		path_length = 1;
		if(in_path(path, path_length, i) || map[row][i] == 0)
			continue;
		if(i == destination){
			/*printf("：%d\n", map[row][i]);*/
			distance += map[row][i];
			rescue_team_num += rescue_team[i];
			path[path_length] = i;
			path_length ++;
			if(distance < min_distance || (distance == min_distance) && (max_rescue_team_num < rescue_team_num)){
				min_distance = distance;
				max_rescue_team_num = rescue_team_num;
			}
/*
			for(j = 0; j < path_length; j ++)
				printf("%d", path[j]);
			printf("\t%d\t%d\t%d\t\n", distance, rescue_team_num, i);*/
			distance = 0;
			rescue_team_num = 0;
			if(path_length > 1)
				return 0;
			path_length = 1;
		}

		else if(i != destination){

			if(distance > min_distance)
				return 0;
			func(path, path_length, distance, rescue_team_num, row, i);
		}
	}
	return 0;
}


int main(){

	int i, j, k, temp;
	int distance = 0;
	int rescue_team_num = 0;
	int path[500];
	int path_length = 0;
	scanf("%d%d%d%d", &node_num, &road_num, &source, &destination);
	rescue_team = (int*)malloc(sizeof(int)*node_num);
	for(i = 0; i < node_num; i ++){
		scanf("%d", &rescue_team[i]);
	}	
	rescue_team_num = rescue_team[source];
	
	for(i = 0; i < road_num; i ++){
		scanf("%d%d%d", &j, &k, &temp);
		map[j][k] = map[k][j] = temp;
	}

	func(path, path_length, distance, rescue_team_num, source, source);
	printf("%d %d", min_distance, max_rescue_team_num);
















/*	for(i = 0; i < node_num; i ++){
		for(j = 0; j < node_num; j ++)
			printf("%d\t", map[i][j]);
		printf("\n");
	}
	printf("%d\t%d\t%d\t%d\n", node_num, road_num,source,destination);
	for(i = 0; i < node_num; i ++)
		printf("%d", rescue_team[i]);*/
	return 0;
}