/*

Sample Input 1:
3
Itai nyan~
Ninjin wa iyadanyan~
uhhh nyan~
Sample Output 1:
nyan~
Sample Input 2:
3
Itai!
Ninjinnwaiyada T_T
T_T
Sample Output 2:
nai

*/
//在getline()之前要先用cin.ignore()
//在程序已经可以结束的时候要立刻结束，对比过程中如果kuchiguse == "",立刻结束
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	string first, sec, next;
	string kuchiguse;
	cin >> n;
	cin.ignore();
	getline(cin, first);
	getline(cin, sec);
	
	for(int i = 0; i < (first.size() < sec.size()?first.size():sec.size()); i ++){
		if(first[first.size() - 1 - i] != sec[sec.size() - 1 - i])
			break;
		kuchiguse += first[first.size() - 1 - i];
	}

//	cout << endl << kuchiguse << endl;
	
	for(int j = 0; j < n - 2; j ++){
		reverse(kuchiguse.begin(), kuchiguse.end());
		first = kuchiguse;
		if(kuchiguse.size() == 0){
			cout << "nai";
			return 0;
		}
		kuchiguse = "";
		getline(cin, sec);
		for(int i = 0; i < (first.size() < sec.size()?first.size():sec.size()); i ++){
			if(first[first.size() - 1 - i] != sec[sec.size() - 1 - i])
				break;
			kuchiguse += first[first.size() - 1 - i];
		}
	}
	reverse(kuchiguse.begin(), kuchiguse.end());
	
	if(kuchiguse[0] == ' ')
		cout << kuchiguse.substr(1, kuchiguse.size() - 1);
	else
		cout << kuchiguse;
	return 0;
}