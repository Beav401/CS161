#include <iostream>

using namespace std;

/*************************/
int a_to_i(char);

int a_to_i(char charater) {
	int decimal;
	decimal = (int)charater;
	return decimal;
}

/****************************/
char i_to_a(int);

char i_to_a(int num) {
	char letter = (char)num;
	return letter;

}

/***********************/
int main() {
	char character;
	cout << "Give a character: ";
	cin >> character;
	//character = cin.get();
	//while (cin.get() != '\n');
	int decimal = a_to_i(character);
	
	cout << endl << "decimal value is: " << decimal << endl; 




	int number;
	cout << "Give a integer: ";
	cin >> number;
	char letter = i_to_a(number);
	cout << endl << "the character is: " << letter << endl;

	return 0;
}

