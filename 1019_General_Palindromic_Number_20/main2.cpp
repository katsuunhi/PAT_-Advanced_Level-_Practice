//vector容器好用，多用这个

#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n, radix;
	int yes = 1;
	cin >> n;
	cin >> radix;
	if(n == 0){
		cout << "Yes\n0";
		return 0;
	}
	vector<int> vec;
	while(n){
		vec.push_back(n%radix);
		n /= radix;
	}
	for(int i = 0; i < vec.size()/2; i ++)
		if(vec[i] != vec[vec.size() - i - 1])
			yes = 0;
	if(yes)
		cout << "Yes\n";
	else
		cout << "No\n";
	for(int i = vec.size() - 1; i > 0; i --)
		cout << vec[i] << " ";
	cout << vec[0];
	return 0;
}