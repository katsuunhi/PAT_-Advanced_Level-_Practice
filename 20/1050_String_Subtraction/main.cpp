/*

Sample Input:
They are students.
aeiou
Sample Output:
Thy r stdnts.

*/
//超时
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);
//	cout << s1 << s2 << endl;
//	cout << s1.length() << endl << s2.length();
	for(int i = 0; i < s2.length(); i ++){
		for(int j = 0; j < s1.length(); j ++){
			if(s1[j] == s2[i])
				s1[j] = '\1';

		}
	}
	for(int i = 0; i < s1.length(); i ++)
		if(s1[i] != '\1')
			cout << s1[i];
	return 0;
}