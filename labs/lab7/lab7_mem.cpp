#include <iostream>
#include <string>

using namespace std;
// dont understand f1 and f2
void f1(int** num) {

}

void f2(int &* num) {
	&num = new int;

}

int *f3() {
	return new int;
}

int main() {
	int num = 1;
	num = f2(&num);
	num = *f3();
3;	
	return 0;
}

