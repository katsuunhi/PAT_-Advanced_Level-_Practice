//两个测试点没有通过

#include <stdio.h>

//层数 是否为叶子
int main(){
	int node[100][2] = {0};					//存储节点信息：层数，是否为叶子（从1开始）
	int node_num, node_count;				//当前节点号，总数量
	int non_leaf_node_num;					//非叶子结点数
	int parent_node = 1;					//双亲节点号
	int i = 0;	
	int child_num = 0;						//孩子节点数
	int leaf_count[100] = {0};				//每层的叶子数，下标为层数
	int level = 1;							//层数

	node[1][0] = 0;							//第一个节点的层数为0
	scanf("%d%d", &node_count, & non_leaf_node_num);
	if(node_count >= 100 || node_count <= 0){
		printf("%d", 0);
		return 0;
	}
	for(i = 0; i < node_count; i ++)
		node[i + 1][1] = 1;					//初始化所有节点为叶子结点
	for(i = 0; i < non_leaf_node_num; i ++){	//行数
		scanf("%d%d", &node_num, &child_num);	//读取前两个数，节点号和孩子个数
		node[node_num][1] = 0;					//有孩子说明该节点不是叶子节点
		parent_node = node_num;					//保存该节点为双亲节点备用
		level ++;								//存在孩子，层数+1
		for(; child_num > 0; child_num --){		//孩子节点
			scanf("%d", &node_num);
			node[node_num][0] = node[parent_node][0] + 1;	//孩子节点的层数等于双亲节点的层数 + 1
		}
	}
	for(node_num = 0; node_num < node_count; node_num ++)		//遍历node数组
		if(node[node_num + 1][1] == 1)							//如果该节点是叶子节点
			leaf_count[node[node_num + 1][0]] ++;				//对应层数叶子节点数 + 1
	printf("%d", leaf_count[0]);
	for(i = 1; i < level; i ++)
		printf(" %d", leaf_count[i]);
	return 0;
}