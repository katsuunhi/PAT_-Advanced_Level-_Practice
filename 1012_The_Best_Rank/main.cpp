// Sample Input:
// 5 6
// 310101 98 85 88
// 310102 70 95 88
// 310103 82 87 94
// 310104 91 91 91
// 310105 85 90 90
// 310101
// 310102
// 310103
// 310104
// 310105
// 999999
// Sample Output:
// 1 C
// 1 M
// 1 E
// 1 A
// 3 A
// N/A

#include <iostream>
#include <algorithm>
using namespace std;

struct students{
	string id;
	int grade[4];
	int rank[4];
};

void swap(struct students &a, struct students &b){
	struct students temp;
	temp = a;
	a = b;
	b = temp;
}

int get_best_rank(struct students student, int &max){
//	sort(student.rank, &student.rank[3]);
//	for(int i = 0; i < 4; i ++)
//		cout << student.rank[i] << endl;
	max = 0;
	for(int i = 1; i < 4; i ++)
		if(student.rank[i] < student.rank[max])
			max = i;
	return student.rank[max] + 1;
}
int main(){
	char symbol[4] = {'A', 'C', 'M', 'E'};
	int N, M;
	int on_list = 1;
	cin >> N;
	cin >> M;
	int max = 0;
	struct students student[N];
	string check[M];
	for(int i = 0; i < N; i ++){
		cin >> student[i].id;
		cin >> student[i].grade[1];
		cin >> student[i].grade[2];
		cin >> student[i].grade[3];
		student[i].grade[0] = (student[i].grade[3] + student[i].grade[1] + student[i].grade[2]) / 3;			
	}

	for(int i = 0; i < 4; i ++){
		for(int j = 0; j < N; j ++){
			for(int k = j + 1; k < N; k ++)
				if(student[k].grade[i] > student[j].grade[i])
					swap(student[k], student[j]);
		}
		student[0].rank[i] = 0;
		for(int j = 1; j < N; j ++){
		  if(student[j].grade[i] != student[j-1].grade[i])
			  student[j].rank[i] = j;
			else
			  student[j].rank[i] = student[j-1].rank[i];
//			cout << student[j].grade[i] << " ";
		}
//		cout << endl;
	}

	for(int i = 0; i < M; i ++)
		cin >> check[i];


	for(int i = 0; i < M - 1; i ++){
		on_list = 0;
		for(int k = 0; k < N; k ++){
			if(student[k].id == check[i]){
				int rank = get_best_rank(student[k], max);
				printf("%d %c\n", rank, symbol[max]);
				on_list = 1;
				break;
			}
		}
		if(!on_list)
			printf("N/A\n");
	}
	on_list = 0;
	for(int k = 0; k < N; k ++){
		if(student[k].id == check[M - 1]){
			int rank = get_best_rank(student[k], max);
			printf("%d %c", rank, symbol[max]);
			on_list = 1;
			break;
		}
	}
	if(!on_list)
		printf("N/A");
	return 0;
}