#include <iostream>
#include <algorithm>
using namespace std;

//0-31,127 不可显示字符
//32-126 可显示字符 
//hash表，答案满分，速度很快
int main(){
	int hash[128] = {0};
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);

	for(int i = 0; i < s1.length(); i ++)
		hash[s1[i]] = 1;
	
	for(int i = 0; i < s2.length(); i ++)
		hash[s2[i]] = 0;

	for(int i = 0; i < s1.length(); i ++)
		if(hash[s1[i]] != 0)
			cout << s1[i];

	return 0;
}