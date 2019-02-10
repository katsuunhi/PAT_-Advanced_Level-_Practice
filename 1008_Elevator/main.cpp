// Sample Input:
// 3 2 3 1
// Sample Output:
// 41

//6 up,4 down, 5 stop.
//有点容易，只考虑该层和上层，求层数差，再加上对应的时间
//但是实际的电梯应该会更麻烦，比如如果需要停的层数是 2 3 1 4,比较合理的方法应该是先去四楼，再回一楼，也就是实际停的顺序是2341,耗时56秒，2314耗时64秒
#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int time = 0;
	int floor = 0;
	int previous_floor = 0;
	int floor_num;
	cin >> floor_num;
	while(1){
		cin >> floor;
		time += ((floor - previous_floor) > 0 ? 6 : 4)*abs(floor - previous_floor);
		time += 5;
//		cout << time << endl;
		previous_floor = floor;
		if(cin.get() == '\n')
			break;

	}

	cout << time;



	return 0;
}