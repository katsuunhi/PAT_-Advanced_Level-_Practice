#include <stdio.h>
#include <math.h>

int main(){
	int a, b, sum;
	int temp = 0;	//用来计算逗号个数的中间变量
	int dot = 0;    //逗号的个数
	scanf("%d %d", &a, &b);
	sum = a + b;
	//提取负号
	if(sum < 0){
		printf("-");
		sum = -sum;
	}
	//计算逗号的个数
	temp = sum;
	while(temp/1000){
		dot ++;
		temp /= 1000;
	}
	//最高的三位数，不用加逗号
	printf("%d",sum/(int)(pow(1000,dot)));
	sum = sum%(int)(pow(1000,dot));
	for(dot = dot - 1; dot >= 0; dot --){
		printf(",%03d",sum/(int)(pow(1000,dot))); //保留三位，不够左侧补0
		sum = sum%(int)(pow(1000,dot));
	}
	return 0;
}