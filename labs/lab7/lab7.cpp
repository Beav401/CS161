#include <iostream>
#include <string.h>

using namespace std;

/*****************************************************************************
 * get_string
 * prompts user for string and stores in str variable
 * input: N/A
 * output: str variable
 * **************************************************************************/

void get_string(char* arr) {
	cout << endl <<"Give a sentence: ";
	cin.getline(arr, 256, '\n');
}

/****************************************************************************
 * set_replace_string
 * makes a copy of string, and changes all non spaces into dashes
 * input: string str, dash_str
 * output: dash_str
 * ************************************************************************/

void set_replace_string(char * arr, char * dash_arr) {
	int len = 256;
	for (int i=0;i < len; i++) {
		if (arr[i] == '\0') 
			break;
		else if(arr[i] != ' ')
			dash_arr[i] = '_';
		else if (arr[i] == ' ')
			dash_arr[i] = ' ';
	}
}

/*****************************************************************************
 * get_search_replace
 * takes in a character and the strings. replaces the dashes with the letter if it is located there.  It then returns the number of those letters in original string.
 * input: string, char;
 * output: int num_letters
 * **************************************************************************/

int get_search_replace(char char_look, char * arr, char* dash_arr) {
	dash_arr[256] = {};
	int len = 256, count = 0;
	for (int i=0; i < len; i++) {
		if (arr[i] == '\0')
			break;
		else if(arr[i] == char_look) {
			count += 1;
			dash_arr[i] = char_look;	
		}
		else if (arr[i] == ' ')
			dash_arr[i] = ' ';
		else 
			dash_arr[i] = '_';
	}
	return count;
	}




int main() {
	char arr[256] = {};
	char dash_arr[256] = {};
	char char_look;
	get_string(arr);
	set_replace_string(arr, dash_arr);
	cout << endl << dash_arr << endl;
	cout << " Provide a character: ";
	cin >> char_look;
	int num_letters = get_search_replace(char_look, arr, dash_arr);
	cout << endl << " The number of " << char_look << "'s in the string is " << num_letters << endl;
	cout << endl << dash_arr << endl;

	return 0;
}

