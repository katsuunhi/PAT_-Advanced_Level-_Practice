#include<stdio.h>

void display(float poly[], int length){
	int i = 0;
	for(i; i < length; i ++){
		if(i == 0 || i%2 == 1)
			printf("%d ",(int)poly[i]);
		else
			printf("%.1f ",poly[i]);
	}
	if(length == 0)
		printf("%d", (int)poly[length]);
	else
		printf("%.1f", poly[i]);
}

int main(){
	int num = 0;
	float poly_1[21], poly_2[21];
	int length_1, length_2;
	float poly[41];
	int length;
	int i, j;
	length_1 = length_2 = 0;
	length = i = j = 1;

	while(1){
		scanf("%f", &poly_1[length_1]);
		if(getchar() == '\n')
			break;
		length_1 ++;
	}
	while(1){
		scanf("%f", &poly_2[length_2]);
		if(getchar() == '\n')
			break;
		length_2 ++;
	}
	
	while(i <= length_1 && j <= length_2){
		if(poly_1[i] > poly_2[j]){
			poly[length ++] = poly_1[i ++];
			poly[length ++] = poly_1[i ++];
		}
		if(poly_1[i] < poly_2[j]){
			poly[length ++] = poly_2[j ++];
			poly[length ++] = poly_2[j ++];
		}
		if(poly_1[i] == poly_2[j]){
			if(poly_1[i + 1] + poly_2[j + 1] == 0){
				i += 2;
				j += 2;
				continue;
			}
			poly[length ++] = poly_1[i ++];
			j ++;
			poly[length ++] = poly_1[i ++] + poly_2[j ++];
		}
	}

	while(i <= length_1)
		poly[length ++] = poly_1[i ++];
	while(j <= length_2)
		poly[length ++] = poly_2[j ++];
	poly[0] = length/2;
	display(poly, length - 1);
	return 0;
}