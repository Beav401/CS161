#include <iostream>
#include <string>
using namespace std;

int main() {
	string my_str = "";
	cout << "Please give a string without spaces: ";
	getline(cin,my_str);
	int length = my_str.length();
	bool flag = false;
	for(int i=0; i<(length/2); i++) {
		if (my_str[i] == my_str[length-1]) {
			flag = (bool)true;	
		}
	}
	if (flag == true) {
		cout << "It's a palindrome" << endl;	
	}
	else {
		cout << "It's not a palindrome" << endl;	
	}

	return 0;	
}
