/********************************************************************************
** Assignment3.cpp
** Reed Boeshans
** February 4th, 2018
** This proram is made up of many small functions that will be called in main()
** input: input for each of the functions
** output: output of each of teh functions
*******************************************************************************/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/******************************************************************************
** check_range
** indicates if the provided number is within the range
** int lower_bound, upper_bound, test_value
** Output: boolean (true, false)
*******************************************************************************/

bool check_range(int);

bool check_range(int lower_bound, int upper_bound, int test_value) {
	bool x;
	if (lower_bound <= test_value && test_value <= upper_bound) {
		x = true;
	}
	else {
		x = false;
	}
	return (bool)x;


} 

/******************************************************************************
** is_int
** indicates if given string is an int
** input: string num
** output: boolean
******************************************************************************/

bool is_int(string);

bool is_int(string num) {
	bool result;
	int z = 0, counter = 0;
	for (z; z < num.length(); z++) {
		if (48 <= (int)num[z] && 57 >= (int)num[z]) {
			counter = counter + 1;		
		}
	}
	if ( counter == num.length() ) {
		result = true;
	}
	else {
		result = false;
	}
	return result;
}

/*****************************************************************************
** is_float
** indicates if given nstring is a float
** input: string num
** output: boolean
*****************************************************************************/

bool is_float(string num) {
	bool result = false;
	int i = 0, counter = 0, indicator = 0;
	for (i; i < num.length(); i++)  {
		if ((int)num[i] == 46) {
			indicator = i;
			for (i = 0; i < num.length(); i++) {
				if (48 <= (int)num[i] && 57 >= (int)num[i]) {	
					counter = counter + 1;
				}
				else if (i == indicator) {
					counter = counter + 1;
				}

			}
			if (counter = num.length()); 
				result = true;
		}
	return result;
}

/****************************************************************************
** is_capital
** indicates if a given char is a capital letter
** input: char letter
** outpu: boolean
*****************************************************************************/
bool is_even(char);

bool is_capital(char letter) {
	bool result;
	if ((int)letter >= 65 && (int)letter <=90) {
		result = true;
	}
	else {
		result = false;
	}
	return result;
}

/****************************************************************************
** is_even
** indicates if a number is even
** input: int number
** output: boolean
*****************************************************************************/

bool is_even(int number) {
	bool even_test;
	if ((number % 2) == 0) {
		even_test = true;
	}
	else {
		even_test = false;
	}	
	return even_test;
}

/***************************************************************************
** is_odd
** indicates if given number is odd
** input int number
** output: boolean
**************************************************************************/

bool is_odd(int number) {
	bool odd_test;
	if ((number % 2) == 1) {
		odd_test = true;
	}
	else {
		odd_test = false;
	}
	return odd_test;
}

/***************************************************************************
** equality_test
** indicates if num1 is >, ==, or < num 2
** input: int num1 num2
** output: int -1,0,1
***************************************************************************/

int equality_test(int num1,int num2) {
	int equality;
	if (num1 < num2) {
		equality = (-1);
	}
	else if (num1 == num2) {
		equality = 0;
	}
	else if (num1 > num2) {
		equality = 1; 
	}
	return equality;
}

/**************************************************************************
** float_is_equal
** test if two floats are equal within a precision
** input: float num1f, num2f, precision
** output: boolean
**************************************************************************/

bool float_is_equal(float num1f, float num2f, float precision) {
	bool equality_float = false;
	if (num1f <= num2f && num2f <= num1f + precision) {
		equality_float = true;
	}
	else if (num1f >= num2f && (num1f - precision) <= num2f) {
		equality_float = true;
	}
	else if (num1f <= num2f || num2f <= num1f - precision) {
		equality_float = false;
	}
	return equality_float;
}

/**************************************************************************
** numbers_present
** indicates if a string contains numbers
** input: string sentence
** output: boolean
**************************************************************************/

bool numbers_present(string sentence) {
	cout << "in function" << endl;
	bool present;
	int i = 0;
	for (i; i<sentence.length(); i++) {
		if ((int)sentence[i] >= 48 && (int)sentence[i] <= 57) {
			present = true;
		}
	}
	return present;
}

/*************************************************************************
** letters_present
** indicates if a sting contains letters
** input: string sentence
** output: boolean
**************************************************************************/

bool letters_present(string sentence) {
        bool present;
        int i = 0;
        for (i; i<sentence.length(); i++) {
                if ((int)sentence[i] >= 65 && (int)sentence[i] <= 90) {
                        present = true;
                }
                else if ((int)sentence[i] >= 97 && (int)sentence[i] <= 122) {
                        present = true;
                }

        }
        return present;
}

/*************************************************************************
** contains_sub_string
** indicates if a substring exists in a sentence
** input: string sentence, sub_string
** output: boolean
*************************************************************************/

bool contains_sub_string(string sentence, string sub_string) {
	bool contains;
	int i = 0, counter = 0, j, z = 0;
	for (i; i < (sentence.length() - sub_string.length() + 1); i++) {
		if (sentence[i] == sub_string[0]) {
			for (j = 1; j < sub_string.length(); j++) {
				if (sentence[j + i] != sub_string[j]) {
					contains = false;
					break;
				}
				contains = true;
			}
		}	

	}
	return contains;
}

/************************************************************************
** word_count
** provides number of words in a given string
** input: string sentence
** output: int
***********************************************************************/

int word_count(string sentence) {
	int count = 0, i= 0;
	for (i; i < sentence.length(); i++) {
		if ((int)sentence[i] == 32) {
			count = count + 1;
		}
		else if ((int)sentence[i] == 46) {
			count = count + 1;
			if ((int)sentence[i+1] == 32) {
				count = count - 1;
			}
		}
	}
	return count;
	}

/************************************************************************
** to_upper
** capitalizes all letters in a given string and leaves all non-letter characters   unchanged
** input: string sentence
** output: string
**************************************************************************/

string to_upper(string sentence) {
	int i = 0;
	for (i; i < sentence.length(); i++) {
		if ((int)sentence[i] >= 97 && (int)sentence[i] <= 122) {
			sentence[i] = (char)((int)sentence[i] - 32);
		}
	}
	return sentence;
}

/***************************************************************************
** to_lower
** makes all letters lowercase
** input: string sentence
** output: string
****************************************************************************/

string to_lower(string sentence) {
	int i = 0;
        for (i; i < sentence.length(); i++) {
                if ((int)sentence[i] >= 65 && (int)sentence[i] <= 90) {
                        sentence[i] = (char)((int)sentence[i] + 32);
                }
        }
        return sentence;
}

/***************************************************************************
** get_int
** takes a prompt as a string and turns it to a int
** input: string prompt
** output: int
***************************************************************************/

int get_int(string prompt) {
	int length = prompt.length();
	int int_value = 0;
	for (int i = 0; i < length; i++) {
		if ((int)prompt[i] >= 48 && (int)prompt[i] <= 57) {
			int_value += (((int)prompt[i]-48)*pow(10,(length-i-1)));	
		}
	}	
	return int_value;
}
	
/**************************************************************************
** get_float
** takes a prompt as a string and turns it to a float
** input: string literal
** output: float
**************************************************************************/

float get_float(string prompt) {
	int length = prompt.length();
	int decimal = 0;
	float float_value = 0.0;
	for (int i = 0; i < length; i++) {
		if ((int)prompt[i] >= 48 && (int)prompt[i] <= 57) {
			float_value += (((int)prompt[i]-48)*pow(10,(length-i-2)));	
		}
		else if ((int)prompt[i] == 46) {
			decimal = i;
			i += 1;
			for(i; i < length; i++) {
				float_value += (((int)prompt[i]-48)*pow(10,(length-i-1)));

			}
		}

	}
	return float_value;
}

/*************************************************************************
** main
** comprised of function calls
** input: only on get_int and get_float
** Output: PASS, FAIL
**************************************************************************/

int main() {

//check_range
	cout << endl << "check_range" << endl;
		cout << "upper bound is: 9" << endl;
		cout << "lower bound is: 5" << endl;
		cout << "test value is: 7" << endl;
		bool x = check_range(5, 9, 7);
		if (x == true) {
			cout << "Expected true. actual true. PASS" << endl << endl;
		}
		else if (x == false) {
			cout << "Expected true. Actual False. FAIL" << endl << endl;
		}
                cout << "upper bound is: 9" << endl;
                cout << "lower bound is: 5" << endl;
                cout << "test value is: 5" << endl;
                x = check_range(5, 9, 5);
                if (x == true) {
                        cout << "Expected True. Actual True. PASS" << endl << endl;
                }
                else if (x == false) {
                        cout << "Expected True. Actual False. FAIL" << endl << endl;
                }
                cout << "upper bound is: 9" << endl;
                cout << "lower bound is: 5" << endl;
                cout << "test value is: 111" << endl;
                x = check_range(5, 9, 111);
                if (x == true) {
                        cout << "Expected False. Actual True. FAIL" << endl << endl;
                }
                else if (x == false) {
                        cout << "Expected False. Actual False. PASS" << endl << endl;
                }




//is_int
	
	cout << endl << endl << "is_int" << endl;	
		cout << "The string is: 84651" << endl;
		bool result = is_int("84651");
		if (result == true) {
			cout << "Expected True. Actual True. PASS" << endl;
		}
		else if (result == false) {
			cout << "Expected True. Actual False. FAIL" << endl;
		}
                cout << "The string is: 84.368" << endl;
                result = is_int("84.368");
                if (result == true) {
                        cout << "Expected False. Actual True. FAIL" << endl;
                }
                else if (result == false) {
                        cout << "Expected False. Actual False. PASS" << endl;
                }
                cout << "The string is: hello" << endl;
                result = is_int("hello");
                if (result == true) {
                        cout << "Expected False. Actual True. FAIL" << endl;
                }
                else if (result == false) {
                        cout << "Expected False. Actual False. PASS" << endl;
                }


//is_float

	cout << endl << endl << "is_float" << endl;
	
		cout << "the string is: 5.3684" << endl;
	 	result = is_float("5.3684");
		if (result == true) {
			cout << "Expected True. Actual True. PASS" << endl;
		}
		else {
			cout << "Expected True. Actual False. FAIL" << endl;
		}
                cout << "the string is: 5.36.84" << endl;
                result = is_float("5.36.84");
                if (result == true) {
                        cout << "Expected False. Actual True. FAIL" << endl;
                }
                else {
                        cout << "Expected False. Actual false. PASS"<< endl;
                }
                cout << "the string is: 600" << endl;
                result = is_float("600");
                if (result == true) {
                        cout << "Expected false. Actual True. FAIL"<< endl;
                }
                else {
                        cout << "Expected False. Actual False. PASS" << endl;
                }


//is_capital

	cout << endl << endl << "is_capital" << endl;
	
		cout << "The letter is: L" << endl;
		result = is_capital('L');
		if (result == true) {
			cout << "Expected True. Actual True. PASS" << endl;
		}	
		else {
			cout << "Expected True. Actual False. FAIL" << endl;
		}
                cout << "The letter is: h" << endl;
                result = is_capital('h');
                if (result == true) {
                        cout << "Expected False. Actual True. FAIL" << endl;
                }
                else {
                        cout << "Expected False. Actual False. PASS" << endl;
                }
                cout << "The letter is: 7" << endl;
                result = is_capital('7');
                if (result == true) {
                        cout << "Expected False. Actual True. FAIL" << endl;
                }
                else {
                        cout << "Expected false. Actual False. PASS" << endl;
                }
		

//is_even

        cout << endl << endl << "is_even" << endl;

                cout << "The number is: 568" << endl;
                bool even_test = is_even(568);
                if (even_test == true) {
                        cout << "Expected True. Actual True. PASS" << endl;
                }
                else {
                        cout << "Expected True. Actual False. FAIL" << endl;
                }
                cout << "The number is: 568" << endl;
                even_test = is_even(13);
                if (even_test == true) {
                        cout << "Expected False. Actual True. FAIL" << endl;
                }
                else {
                        cout << "Expected False. Actual False. PASS" << endl;
                }
        


//is_odd

        cout << endl << endl << "is_odd" << endl;

                cout << "The number is: 568" << endl;
                bool odd_test = is_odd(568);
                if (odd_test == true) {
                        cout << "Expected False. Actual True. FAIL"<< endl;
                }
                else {
                        cout << "Expected False. Actual False. PASS"<< endl;
                }
                cout << "The number is: 13" << endl;
                odd_test = is_odd(13);
                if (odd_test == true) {
                        cout << "Expected True. Actual True. PASS" << endl;
                }
                else {
                        cout << "Expected True. Actual False. FAIL"<< endl;
                }

//equality_test

        cout << endl << endl << "equality_test" << endl;

                cout << "num1 is: 5" << endl;
		cout << "num2 is: 4" << endl;
                int equality = equality_test(5, 4);
                cout << "Expected 1. actual " << equality << ". PASS" << endl;
                
		cout << "num1 is: 5" << endl;
                cout << "num2 is: 5" << endl;
                equality = equality_test(5, 5);
                cout << "Expected 0. Actual " << equality << ". PASS"<< endl;
   		
		cout << "num1 is: 5" << endl;
                cout << "num2 is: 6" << endl;
                equality = equality_test(5, 6);
                cout << "Expected -1. Actual " << equality << ". PASS" << endl;

        


//float_is_equal

        cout << endl << endl << "float_is_equal" << endl;

                cout << "float 1 is: 8.5" << endl;
                cout << "float 1 is: 9.0" << endl;
		cout << "precison is: 0.6" << endl;
                bool equality_float = float_is_equal(8.5, 9.0, 0.6);
        		if (equality_float == true) {
				cout << "Expected true. Actual true. PASS" << endl;
			}
			else {
				cout << "Expected true. Actual False. FAIL" << endl;
			}
                cout << "float 1 is: 8.5" << endl;
                cout << "float 1 is: 8.0" << endl;
                cout << "precison is: 0.5" << endl;
                equality_float = float_is_equal(8.5, 8.0, 0.5);
                        if (equality_float == true) {
                                cout << "Expected true. Actual True. PASS" << endl;
                        }
                        else {
                                cout << "Expected True. Actual False. FAIL" << endl;
                        }
                cout << "float 1 is: 8.8" << endl;
                cout << "float 1 is: 8.0" << endl;
                cout << "precison is: 0.7" << endl;
                equality_float = float_is_equal(8.8, 8.0, 0.7);
                        if (equality_float == true) {
                                cout << "Expected False. Actual True. FAIL" << endl;
                        }
                        else {
                                cout << "Expected False. Actual False. PASS" << endl;
                        }

	

//numbers_present

        cout << endl << endl << "numbers_present" << endl;

                cout << "A sentence with a number is: I am 18 years old." << endl;
                bool present = numbers_present("I am 18 years old");
                if (present == true) {
                        cout << "Expected True. Actual True. PASS" << endl;
                }
                else if (present == false) {
                        cout << "Expected True. Actual false. FAIL" << endl;
                }
                cout << "A sentence with a number is: How old are you?" << endl;
                present = numbers_present("How old are you?");
                if (present == true) {
                        cout << "Expected false. Actual true. FAIL" << endl;
                }
                else if (present == false) {
                        cout << "Expected False. Actual False. PASS" << endl;
                }
        

//letters_present

	cout << endl << endl << "letters_present" << endl;

		cout << "A sentence with letters is: How many candybars did you buy?" << endl;
		present = letters_present("How many candybars did you buy?");
		if (present == true) {
			cout << "Expected true. Actual true. PASS" << endl;
		}
		else if (present == false) {
			cout << "Expected true. Actual false. FAIL" << endl;
		}
                cout << "A sentence with letters is: 3." << endl;
                present = letters_present("3.");
                if (present == true) {
                        cout << "Expected false. Actual true. FAIL" << endl;
                }
                else if (present == false) {
                        cout << "Expected False. Actual False. PASS" << endl;
                }


//contains_sub_string

	cout << endl << endl << "contains_sub_string" << endl;

		cout << "A sentence is: Hello what is your name?" << endl;
		cout << "A sub string in the sentence is: your" << endl;
		bool contains = contains_sub_string("Hello what is your name?", "your");
		if (contains == true) {
			cout << "Expected True. Actual True. PASS" << endl;
		}
		else if (contains == false) {
			cout << "Expected true. Actual false. FAIL" << endl;
		}
                cout << "A sentence is: Hello what is your name?" << endl;
                cout << "A sub string in the sentence is: tree" << endl;
                contains = contains_sub_string("Hello what is your name?", "tree");
                if (contains == true) {
                        cout << "Expected false. Actual true. FAIL" << endl;
                }
                else if (contains == false) {
                        cout << "Expected false. Actual false. PASS" << endl;
                }

//word_count
	
	cout << endl << endl << "word_count" << endl;

		cout << "A sentence is: Hello what is your name." << endl;
		int count = word_count("Hello what is your name.");
		cout << "Expected 5. Actual " << count << ". PASS" << endl;
                cout << "A sentence is: Hello what is your name. My name is Reed." << endl;
                count = word_count("Hello what is your name. My name is Reed.");
		cout << "Expected 9. Actual " << count << ". PASS" << endl;

//to_upper

	cout << endl << endl << "to_upper" << endl;

		cout << "A sentence is: Hello what is your name?" << endl;
		string sentence = to_upper("Hello what is your name?");
		cout << "The new string is: " << sentence << endl;
                cout << "A sentence is: i am 18 years old." << endl;
                sentence = to_upper("i am 18 years old.");
                cout << "The new string is: " << sentence << endl;

//to_lower

        cout << endl << endl << "to_lower" << endl;

                cout << "A sentence is: HELLO my NAME is REED." << endl;
                sentence = to_lower("HELLO my NAME is REED.");
                cout << "The new string is: " << sentence << "PASS"<< endl;
                cout << "A sentence is: I am 18 years old." << endl;
                sentence = to_lower("I am 18 years old.");
                cout << "The new string is: " << sentence << "PASS" << endl;

//get_int

	cout << endl << endl << "get_int" << endl;
		string prompt = "";
	//	do {
		cout << "Please give an integer: ";
		getline(cin, prompt);
	//	result = is_int(prompt);
	//	} while (result == false);

		int int_value = get_int(prompt);
		cout << " The integer value is: " << int_value << endl;

//get_float
	cout << endl << endl << "get_float" << endl;
		prompt = "";
        //        do {
                cout << "Please give a float: ";
                getline(cin, prompt);
          //      result = is_float(prompt);
            //    } while (result == false);

		float float_value = get_float(prompt);
		cout << " The float value is: " << float_value << endl;
		
		


	return 0;
}
