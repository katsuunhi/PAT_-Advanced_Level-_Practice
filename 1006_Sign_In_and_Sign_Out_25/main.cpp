// Each input file contains one test case. Each case contains the records for one day. The case starts with a positive integer M, which is the total number of records, followed by M lines, each in the format:

// ID_number Sign_in_time Sign_out_time
// where times are given in the format HH:MM:SS, and ID_number is a string with no more than 15 characters.


//满分答案
#include <iostream>
#include <string>

using namespace std;

struct time{
	int hour;
	int minute;
	int secend;
};
struct records{
	string ID_num;
	struct time in;
	struct time out;
}record, lock, unlock;

int main(){

	int record_count;			//行数
	cin >> record_count;
	cin >> unlock.ID_num;		//第一行赋值给lock和unlock
	scanf("%d:%d:%d", &unlock.in.hour, &unlock.in.minute, &unlock.in.secend);
	scanf("%d:%d:%d", &unlock.out.hour, &unlock.out.minute, &unlock.out.secend);
	lock = unlock; 		//结构体可以直接赋值

	for(int i = 1; i < record_count; i ++){
		cin >> record.ID_num;
		scanf("%d:%d:%d", &record.in.hour, &record.in.minute, &record.in.secend);
		scanf("%d:%d:%d", &record.out.hour, &record.out.minute, &record.out.secend);
		//如果比unlock中的时间早
		if(record.in.hour < unlock.in.hour || (record.in.hour == unlock.in.hour && record.in.minute < unlock.in.minute) || (record.in.hour == unlock.in.hour && record.in.minute == unlock.in.minute && record.in.secend < unlock.in.secend))
			unlock = record;
		//如果比lock中的时间晚
		if(record.out.hour > lock.out.hour || (record.out.hour == lock.out.hour && record.out.minute > lock.out.minute) || (record.out.hour == lock.out.hour && record.out.minute == lock.out.minute && record.out.secend > lock.out.secend))
			lock = record;
	}
	//输出 unlock.ID_num lock.ID_num
	cout << unlock.ID_num << " " << lock.ID_num;
	return 0;
}