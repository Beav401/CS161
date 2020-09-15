#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {

	int x;
	srand(time(NULL));
	
	x = rand();
	x = x % 6;
	cout << "x = " << x << endl;
	


	if (x == 0) {
		cout << "Bummer, I'm zero!!!" << endl;
	}
	else if (x == 1||x == 3||x == 5) {
		cout << "I'm an odd number!" << endl;
	}
	else {
		cout << "I'm an even number!" << endl;
	}
}

