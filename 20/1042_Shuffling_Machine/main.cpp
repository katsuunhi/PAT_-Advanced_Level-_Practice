/*

Sample Input:
2
36 52 37 38 3 39 40 53 54 41 11 12 13 42 43 44 2 4 23 24 25 26 27 6 7 8 48 49 50 51 9 10 14 15 16 5 17 18 19 1 20 21 22 28 29 30 31 32 33 34 35 45 46 47
Sample Output:
S7 C11 C10 C12 S1 H7 H8 H9 D8 D9 S11 S12 S13 D10 D11 D12 S3 S4 S6 S10 H1 H2 C13 D2 D3 D4 H6 H3 D13 J1 J2 C1 C2 C3 C4 D1 S5 H5 H11 H12 C6 C7 C8 C9 S2 S8 S9 H10 D5 D6 D7 H4 H13 C5

*/

#include <iostream>
#include <algorithm>
using namespace std;

struct card{
	char color;
	int num;
}cards[54], new_cards[54];

void print(struct card cards[]){
	for(int i = 0; i < 53; i ++){
		cout << cards[i].color << cards[i].num << " ";
	}
	cout << cards[53].color << cards[53].num;
}
int main(){
	int j = 1;
	for(int i = 0; i < 13; i ++){
		
		cards[i].color = 'S';
		cards[i].num = j;
		j ++;
	}
	j = 1;
	for(int i = 13; i < 26; i ++){
		
		cards[i].color = 'H';
		cards[i].num = j;
		j ++;
	}
	j = 1;
	for(int i = 26; i < 39; i ++){
		
		cards[i].color = 'C';
		cards[i].num = j;
		j ++;
	}
	j = 1;
	for(int i = 39; i < 52; i ++){
		
		cards[i].color = 'D';
		cards[i].num = j;
		j ++;
	}
	j = 1;
	for(int i = 52; i < 54; i ++){
		
		cards[i].color = 'J';
		cards[i].num = j;
		j ++;
	}

	int m;
	cin >> m;
	int order[54];
	for(int i = 0; i < 54; i ++)
		cin >> order[i];

	for(int i = 0; i < m; i ++){
		
		for(int j = 0; j < 54; j ++)
			new_cards[order[j] - 1] = cards[j];
		
		for(int j = 0; j < 54; j ++)
			cards[j] = new_cards[j];
		
	}
	print(cards);
	return 0;
}