/*

Sample Input:
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm
Sample Output:
THU 14:04

*/
//星期范围A-G
//小时范围0-9，A-N
//分钟未必是小写字母，也可以是大写字母，但是一定是字母
//比较大小注意类型，char型要和'9'进行比较，而不是9
//预留的字符串，用二维字符数组，但是注意，要多留一位给'\0'
#include <iostream>
#include <string>
using namespace std;

char day[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main(){
	int day_num, hour, minute;
	day_num = -1;
	string  day_hour1, day_hour2, minute1, minute2;
//	scanf("%s%s%s%s", day_hour1, day_hour2, minute1, minute2);
	cin >> day_hour1;
	cin >> day_hour2;
	cin >> minute1;
	cin >> minute2;
//	cout << day_hour1.length() << day_hour2.length();

	for(int i = 0; i < (day_hour1.length() > day_hour2.length()?day_hour2.length():day_hour1.length()); i ++){
		if(day_num == -1 && day_hour1[i] >= 'A' && day_hour1[i] <= 'G' && day_hour1[i] == day_hour2[i]){
			day_num = day_hour1[i] - 'A';
			continue;
		}
		if(day_num != -1 && (day_hour1[i] >= 'A' && day_hour1[i] <= 'N' || day_hour1[i] >= '0' && day_hour1[i] <= '9') && day_hour1[i] == day_hour2[i]){
//			cout << day_hour1[i] << endl;
			if(day_hour1[i] <= '9')
				hour = day_hour1[i] - '0';
			else 
				hour = day_hour1[i] - 'A' + 10;
			break;
		}
	}
//	cout << "test";
	for(int i = 0; i < (minute1.length() > minute2.length()?minute2.length():minute1.length()); i ++){
		if((minute1[i] >= 'a' && minute1[i] <= 'z' || minute1[i] >= 'A' && minute1[i] <= 'Z') && minute1[i] == minute2[i]){
			minute = i;
			break;
		}
	}
//	printf("%s%s%s%s", day_hour1, day_hour2, minute1, minute2);
	printf("%s %02d:%02d", day[day_num], hour, minute);
	return 0;
}