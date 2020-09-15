#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {

int pass_length, new_pass, letters, lowercase, lowercase_len, uppercase, uppercase_len, numbers, number_len, low, up, num;
new_pass = 1;

while (new_pass == 1) {

cout << "Welcome to the password generator. How many characters do you want the password to be?: ";
cin >> pass_length;
cout << endl << "Do you want to use letters? (0-no, 1-yes) ";
cin >> letters;
	if (letters == 0) {
		lowercase_len = 0;
		uppercase_len = 0;
		cout << endl << "Do you want to use numbers (0-no, 1-yes)";
		cin >> numbers;
		if (numbers == 0) {
			number_len = 0;
// Password Genrator

			cout << endl << "Your password is: ";
			for (int i=0; i<pass_length; i++) {
				if (i < uppercase_len) {
					srand(time(NULL));
					up = rand();
					up = ((up % 26) + 65);
					cout << (char)up;
				}
				else if (uppercase_len <= i < (lowercase_len + uppercase_len)) {
					srand(time(NULL));
					low = rand();
					low = ((low % 26) + 97);
					cout << (char)low;
				}
				else if ((uppercase_len + lowercase_len) <= i < (lowercase_len + uppercase_len + number_len)) {
					srand(time(NULL));
					num = rand();
					num = (num % 10);
					cout << (int)num;
				}
			}
			cout << endl << "Would you like to create a new password? (0-no, 1-yes)";
			cin >> new_pass;
				if (new_pass == 0) {
					new_pass = 0;
				}
				else {
					new_pass = 1;
				}

// Password Generator
		}
		else if (numbers == 1) {
			cout << endl << "How many numbers should be in your password?: ";
			cin >> number_len;


                        cout << endl << "Your password is: ";
                        for (int i=0; i<pass_length; i++) {
                                if (i < uppercase_len) {
					srand(time(NULL));
                                        up = rand();
                                        up = ((up % 26) + 65);
                                        cout << (char)up;
                                }
                                else if (uppercase_len <= i < (lowercase_len + uppercase_len)) {
					srand(time(NULL));
                                        low = rand();
                                        low = ((low % 26) + 97);
                                        cout << (char)low;
                                }
                                else if ((uppercase_len + lowercase_len) <= i < (lowercase_len + uppercase_len + number_len)) {
                                        srand(time(NULL));
					num = rand();
                                        num = (num % 10);
                                        cout << (int)num;
                                }
                        }
                        cout << endl << "Would you like to create a new password? (0-no, 1-yes)";
                        cin >> new_pass;
                                if (new_pass == 0) {
                                        new_pass = 0;
                                }
                                else {
                                        new_pass = 1;
                                }


		}
	}
	else if (letters ==1) {
		cout << endl << "Would you like uppercase letters in the password? (0-no, 1-yes)";
		cin >> uppercase;
		if (uppercase == 0) {
			uppercase_len =0;
			cout << endl << "Would you like lowercase letters in the password? (0-no, 1-yes)";
			cin >> lowercase;
			if (lowercase == 0) {
				lowercase_len =0;
				cout << endl << "Do you want to use numbers (0-no, 1-yes)";
                		cin >> numbers;
                		if (numbers == 0) {
                        		number_len = 0;
// Password Generator

                        		cout << endl << "Your password is: ";
                        		for (int i=0; i<pass_length; i++) {
                                		if (i < uppercase_len) {
							srand(time(NULL));
                                        		up = rand();
                                        		up = ((up % 26) + 65);
                                        		cout << (char)up;
                                		}	
                                		else if (uppercase_len <= i < (lowercase_len + uppercase_len)) {
							srand(time(NULL));
                                        		low = rand();
                                        		low = ((low % 26) + 97);
                                        		cout << (char)low;
                                		}
                                		else if ((uppercase_len + lowercase_len) <= i < (lowercase_len + uppercase_len + number_len)) {
                                        		srand(time(NULL));
							num = rand();
                                        		num = (num % 10);
                                        		cout << (int)num;
                                		}
                        		}
					cout << endl << "Would you like to create a new password? (0-no, 1-yes)";
                        		cin >> new_pass;
					if (new_pass == 0) {
                                        	new_pass = 0;
                                	}	
                                	else {
                                        	new_pass = 1;
                                	}

				}	
                		
                		else if (numbers == 1) {
                        		cout << endl << "How many numbers should be in your password?: ";
                        		cin >> number_len;
// Password Generator

                        		cout << endl << "Your password is: ";
                        		for (int i=0; i<pass_length; i++) {
                                		if (i < uppercase_len) {
						srand(time(NULL));
                                        	up = rand();
						up = ((up % 26) + 65);
                                        	cout << (char)up;
                                	}
                                		else if (uppercase_len <= i < (lowercase_len + uppercase_len)) {
                                        	srand(time(NULL));
						low = rand();
                                        	low = ((low % 26) + 97);
                                        	cout << (char)low;
                                	}
                                		else if ((uppercase_len + lowercase_len) <= i < (lowercase_len + uppercase_len + number_len)) {
                                        	srand(time(NULL));
						num = rand();
                                        	num = (num % 10);
                                        	cout << (int)num;
                                		}	
                        		}
                        	cout << endl << "Would you like to create a new password? (0-no, 1-yes)";
                        	cin >> new_pass;
                                if (new_pass == 0) {
                                        new_pass = 0;
                                }
                                else {
                                        new_pass = 1;
                                }


                		}

			}
			else if (lowercase == 1) {
				cout << endl << "How many lowercase characters should be in the password?: ";
				cin >> lowercase_len;
				cout << endl << "Would you like numbers in the password? (0-no, 1-yes)";
				cin >> numbers;
				if (numbers == 0) {
					number_len = 0;
// Passwor generator

                        	cout << endl << "Your password is: ";
                        	for (int i=0; i<pass_length; i++) {
                                	if (i < uppercase_len) {
                                        	srand(time(NULL));
						up = rand();
                                        	up = ((up % 26) + 65);
                                        	cout << (char)up;
                                	}
                                	else if (uppercase_len <= i < (lowercase_len + uppercase_len)) {
                                        	srand(time(NULL));
						low = rand();
                                        	low = ((low % 26) + 97);
                                        	cout << (char)low;
                                	}
                                	else if ((uppercase_len + lowercase_len) <= i < (lowercase_len + uppercase_len + number_len)) {
                                        	srand(time(NULL));
						num = rand();
                                        	num = (num % 10);
                                        	cout << (int)num;
                                	}	
                        	}
                        	cout << endl << "Would you like to create a new password? (0-no, 1-yes)";
                        	cin >> new_pass;
					if (new_pass == 0) {
                                        	new_pass = 0;
                                	}
                                	else {
                                        	new_pass = 1;
                                	}					
				}
				else if (numbers == 1) {
					cout << endl << "How many numbers should be in the password?: ";
					cin >> number_len;
// Password Generator

                                cout << endl << "Your password is: ";
                                for (int i=0; i<pass_length; i++) {
                                        if (i < uppercase_len) {
						srand(time(NULL));
                                                up = rand();
                                                up = ((up % 26) + 65);
                                                cout << (char)up;
                                        }
                                        else if (uppercase_len <= i < (lowercase_len + uppercase_len)) {
                                                srand(time(NULL));
						low = rand();
                                                low = ((low % 26) + 97);
                                                cout << (char)low;
                                        }
                                        else if ((uppercase_len + lowercase_len) <= i < (lowercase_len + uppercase_len + number_len)) {
                                                srand(time(NULL));
						num = rand();
                                                num = (num % 10);
                                                cout << (int)num;
                                        }
                                }
                                cout << endl << "Would you like to create a new password? (0-no, 1-yes)";
                                cin >> new_pass;
                                if (new_pass == 0) {
                                        new_pass = 0;
                                }
                                else {
                                        new_pass = 1;
                                }

				
				}	
			}			
		}
		else if (uppercase == 1) {
			cout << endl << "How many uppercase letters should be in the password?: ";
			cin >> uppercase_len;
			cout << endl << "Would you like there to be lowercase letters in the password? (0-no, 1-yes) ";
			cin >> lowercase;
			if (lowercase == 0) {
				lowercase_len = 0;
				cout << endl << "Would you like numbers in the password? (0-no, 1-yes)";
				cin >> numbers;
				if (numbers == 0) {
					number_len = 0;
/*************************************************************************************************************************************************************/

                                cout << endl << "Your password is: ";
                                for (int i=0; i<pass_length; i++) {
                                        if (i < uppercase_len) {
						srand(time(NULL));
                                                up = rand();
                                                up = ((up % 26) + 65);
                                                cout << (char)up;
                                        }
                                        else if (uppercase_len <= i < (lowercase_len + uppercase_len)) {
                                                srand(time(NULL));
						low = rand();
                                                low = ((low % 26) + 97);
                                                cout << (char)low;
                                        }
                                        else if ((uppercase_len + lowercase_len) <= i < (lowercase_len + uppercase_len + number_len)) {
                                                srand(time(NULL));
						num = rand();
                                                num = (num % 10);
                                                cout << (int)num;
                                        }
                                }
                                cout << endl << "Would you like to create a new password? (0-no, 1-yes)";
                                cin >> new_pass;
                                if (new_pass == 0) {
                                        new_pass = 0;
                                }
                                else {
                                        new_pass = 1;
                                }

/*************************************************************************************************************************************************************/
				}
				else if (numbers == 1) {
					cout << endl << "How many numbers should be in the password?: ";
					cin >> number_len;
// Password Generator

                                cout << endl << "Your password is: ";
                                for (int i=0; i<pass_length; i++) {
                                        if (i < uppercase_len) {
						srand(time(NULL));
                                                up = rand();
                                                up = ((up % 26) + 65);
                                                cout << (char)up;
                                        }
                                        else if (uppercase_len <= i < (lowercase_len + uppercase_len)) {
                                                srand(time(NULL));
						low = rand();
                                                low = ((low % 26) + 97);
                                                cout << (char)low;
                                        }
                                        else if ((uppercase_len + lowercase_len) <= i < (lowercase_len + uppercase_len + number_len)) {
                                                srand(time(NULL));
						num = rand();
                                                num = (num % 10);
                                                cout << (int)num;
                                        }
                                }
                                cout << endl << "Would you like to create a new password? (0-no, 1-yes)";
                                cin >> new_pass;
                                if (new_pass == 0) {
                                        new_pass = 0;
                                }
                                else {
                                        new_pass = 1;
                                }
				
				} 
			}
			else if (lowercase == 1) {
				cout << endl << "How many lowercase characters should be in the password?: ";
                                cin >> lowercase_len;
                                cout << endl << "Would you like numbers in the password? (0-no, 1-yes)";
                                cin >> numbers;
                                if (numbers == 0) {
                                        number_len = 0;
// Passwor Generator

                                cout << endl << "Your password is: ";
                                for (int i=0; i<pass_length; i++) {
                                        if (i < uppercase_len) {
						srand(time(NULL));
                                                up = rand();
                                                up = ((up % 26) + 65);
                                                cout << (char)up;
                                        }
                                        else if (uppercase_len <= i < (lowercase_len + uppercase_len)) {
                                                srand(time(NULL));
						low = rand();
                                                low = ((low % 26) + 97);
                                                cout << (char)low;
                                        }
                                        else if ((uppercase_len + lowercase_len) <= i < (lowercase_len + uppercase_len + number_len)) {
                                                srand(time(NULL));
						num = rand();
                                                num = (num % 10);
                                                cout << (int)num;
                                        }
                                }
                                cout << endl << "Would you like to create a new password? (0-no, 1-yes)";
                                cin >> new_pass;
                                if (new_pass == 0) {
                                        new_pass = 0;
                                }
                                else {
                                        new_pass = 1;
                                }


                                }
                                else if (numbers == 1) {
                                        cout << endl << "How many numbers should be in the password?: ";
                                        cin >> number_len;
// Password Generator

                                cout << endl << "Your password is: ";
                                for (int i=0; i<pass_length; i++) {
                                        if (i < uppercase_len) {
						srand(time(NULL));
                                                up = rand();
                                                up = ((up % 26) + 65);
                                                cout << (char)up;
                                        }
                                        else if (uppercase_len <= i < (lowercase_len + uppercase_len)) {
                                                srand(time(NULL));
						low = rand();
                                                low = ((low % 26) + 97);
                                                cout << (char)low;
                                        }
                                        else if ((uppercase_len + lowercase_len) <= i < (lowercase_len + uppercase_len + number_len)) {
                                                srand(time(NULL));
						num = rand();
                                                num = (num % 10);
                                                cout << (int)num;
                                        }
                                }
                                cout << endl << "Would you like to create a new password? (0-no, 1-yes)";
                                cin >> new_pass;
			

				}
                        }
		}

	}

return 0;
}
}

