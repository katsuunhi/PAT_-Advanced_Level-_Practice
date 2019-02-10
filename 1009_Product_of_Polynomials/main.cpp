//测试点0未通过。。。。。。。。。。不知道原因

#include <iostream>

using namespace std;

int main(){

	int k_1;
	int k_2;
	cin >> k_1;
	int N_1[k_1];
	float a_N1[k_1];


	for(int i = 0; i < k_1; i++){
//		cin >> N_1[i];
//		cin >> a_N1[i];
		scanf("%d", &N_1[i]);
		scanf("%f", &a_N1[i]);
	}

	cin >> k_2;
	int N_2[k_2];
	float a_N2[k_2];
	
	for(int i = 0; i < k_2; i ++){
//		cin >> N_2[i];

//		cin >> a_N2[i];
		scanf("%d", &N_2[i]);
		scanf("%f", &a_N2[i]);
	}

	int k_3 = 0;
	int N_3[k_1 * k_2] = {0}; 
	float a_N3[k_1 * k_2] = {0};
	for(int i = 0; i < k_1; i ++){
		for(int j = 0; j < k_2; j ++){
			N_3[k_3] = N_1[i] + N_2[j];
			a_N3[k_3] = a_N1[i] * a_N2[j];
			k_3 ++;
		}
	}
	int length = k_3;
 	for(int i = 0; i < length; i ++){
 		for(int j = i + 1; j < length; j ++){
 			if(N_3[i] == N_3[j]){
 				a_N3[i] += a_N3[j];
 				a_N3[j] = 0;
 				k_3 --;
 			}
 		}
 	}

 	for(int i = 0; i < length; i ++){
 		for(int j = i + 1; j < length; j ++){
 			if(N_3[i] < N_3[j]){
 				int temp;
 				temp = a_N3[j];
 				a_N3[j] = a_N3[i];
 				a_N3[i] = temp;
 				temp = N_3[j];
 				N_3[j] = N_3[i];
 				N_3[i] = temp;
 			}
 		}
 	}
 	printf("%d", k_3);
 	for(int i = 0; i < length; i ++){
 		if(a_N3[i] != 0)
 		// cout << " " << N_3[i] << " " << a_N3[i];
 			printf(" %d %.1f", N_3[i], a_N3[i]);
 	}
	return 0;
}