#include <iostream>
	
using namespace std;

void f2(int* score) {
	score[0] = 1;
}


void f1(int* score) {
	5+2;
	f2(score);


}




int main() {
	int* score = new int[5];
	for (int i=0; i<5; i++) {
		score[i] = 0;
	}
	f1(score);
	
	cout << score[0] << endl;

	return 0;
}
