#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/*****************************************************************************
 * ** is_int
 * ** indicates if given string is a integer
 * ** input: string num
 * ** output: boolean
 * * *****************************************************************************/


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

/***************************************************************************
 * ** get_int
 * ** takes a prompt as a string and turns it to a int
 * ** input: string prompt
 * ** output: int
 * ***************************************************************************/

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
 * ** get_float
 * ** takes a prompt as a string and turns it to a float
 * ** input: string literal
 * ** output: float
 * **************************************************************************/

float get_float(string prompt) {
        int length = prompt.length();
        int decimal = 0;
        float float_value = 0.0;
	if (is_int(prompt) == true) {
		float_value = (get_int(prompt)/1);
		return float_value;
	}
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
        float_value = float_value/ pow(10, (prompt.length()-decimal-1));
        return float_value;
}


/****************************************************************************
 * word_count
 * counts number of words
 * input: string
 * output: number of words
 * ****************************************************************************/

int word_count(string sentence) {
        int count = 0, i= 0;
	if (sentence.length() == 0) 
		return count;
        for (i; i < sentence.length(); i++) {
                if ((int)sentence[i] == 32) {
                        count = count + 1;
			if ((int)sentence[i+1] == 32)
				return 2;
                }
		
        }
        return count;
        }

/****************************************************************************
 * is_op
 * checks to see if a sting is an op
 * string
 * bool
 * ***************************************************************************/

bool is_op(string op) {
	int count = 0;
	for (int k=0; k<op.length(); k++) {
		if (op[k] == '/'||op[k] == '*'||op[k] == '-'||op[k] == '+')
			count += 1;
	}
	if (count > 1)
		return false;
	else { 
		return true;
	}
}


/*****************************************************************************
 * ** is_float
 * ** indicates if given string is a float
 * ** input: string num
 * ** output: boolean
 * *****************************************************************************/

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
				else
					return false;

                        }
                        if (counter = num.length());
                                return true;
                }
	}
        if (is_int(num) == true) {
                return true;
	}
        return false;
}

/***************************************************************************
 * check_eq_float
 * checks splits equation to temp and checks if it is a float
 * input: string equation and int i
 * output: bool and int i
 **************************************************************************/

bool check_eq_float(string equation, int& i) {
	string temp = "";
	for (i=i; i < equation.length(); i++) {
		if ((int)equation[i] >= 46 && (int)equation[i] <= 57) { 
			temp += (equation[i]);
		}
		else if ((int)equation[i] == 46)
			temp += equation[i];
		else if ((int)equation[i] == 32) {
			return is_float(temp);
		}
		else {
			return false;
		}
		
	}
}


/**************************************************************************
 * check_eq_op
 * checks if there is a operator
 * input: equation and i
 * output: bool and int i
 * ***********************************************************************/

bool check_eq_op(string equation, int& i) {
	string op = "";
	for (i; i < equation.length(); i++) {
		if (equation[i] == '-'||equation[i] == '+'||equation[i] == '/'||equation[i] == '+') {
			op += equation[i];
			if (equation[i] == '/') {
				if (equation[i+2] == '0')
					return false;
			}
		}
		else {
			return is_op(op);
		}
	}
}




/*****************************************************************************
* ** check_eq
* ** checks if equation is valid
* ** input: string equation
* ** output: boolean
* *****************************************************************************/

bool check_eq(string equation) {
	int i=0;
	if ((word_count(equation)%2) == 0) {
		return false;
	}
	if(check_eq_float(equation, i) == false) {
		return false;
	}
	for (int times = 0; times < (word_count(equation)/2); times++) {
		i += 1;
		if (check_eq_op(equation, i) == false) {
			return false;
		}
		i += 1;
		if (check_eq_float(equation, i) == false) {
			return false;
		}
		
	
	}
	return true;
}
/****************************************************************************
 * string_eq_temp
 * breaks the large string into a single string
 * input: string equation
 * output: string temp
 * **************************************************************************/
string string_eq_temp(string equation, int& i) {
        string temp = "";
        for (i=i; i < equation.length(); i++) {
                if ((int)equation[i] >= 46 && (int)equation[i] <= 57) {
                        temp += (equation[i]);
                }
                else if ((int)equation[i] == 46)
                        temp += equation[i];
                else if ((int)equation[i] == 32) 
                        return temp;
        }
}

/***************************************************************************
 * op_solve
 * sepeartes the opperator into own string
 * input: equation and i
 * output: op_str and i
 * ***********************************************************************/

string op_solve(string equation, int& i) {
        string op_str = "";
        op_str += equation[i];
	return op_str;
}
/*************************************************************************
 * solver
 * solves the equation
 * input: float answer, string op_str, float temp
 * output: float answer
 * **********************************************************************/
float solver(float answer, string op_str, float temp) {
	if (op_str[0] == '+')
		return (answer + temp);
	else if (op_str[0] == '-')
		return (answer - temp);
	else if (op_str[0] == '*')
		return (answer * temp);
	else if (op_str[0] == '/')
		return (answer / temp);
}


	
/****************************************************************************
 * solve_eq
 * solves the equation as long as equation is valid
 * input: string equation
 * output: float answer
 * **************************************************************************/

float solve_eq(string equation) {
	int i=0;
	float temp_float = 0, answer_float = 0;
	string op_str, answer, temp;
	answer = (string_eq_temp(equation, i));
	answer_float = get_float(answer);
	for (int times = 0;times < (word_count(equation)/2); times++) {
		i += 1;
		op_str = op_solve(equation, i);
		i += 2;
		temp = (string_eq_temp(equation, i));
		temp_float = get_float(temp);
		answer_float = solver(answer_float, op_str, temp_float);
	} 
	return answer_float;
}
/*****************************************************************************
 * standard_calc
 * takes in user input
 * user input
 * print to screen
 * ************************************************************************/

void standard_calc() {
	bool repeat = false;
	string equation = "";
	getline(cin, equation);
	do {
		cout << endl << "please give an equation with one space between operators and operands, and at the end of the equation with only positive values. If using a decimal under 1 write it as .5 instead of 0.5 for example. ";
		getline(cin, equation);
		if (check_eq(equation) == true) {
			cout << endl << "The answer of the equation is: " << solve_eq(equation) << endl;
			repeat = false;
		}
		else {
			cout << "Try again" << endl;
			repeat = true;
		}
	}while (repeat == true);

}

/*****************************************************************************
 * ** bin_flip
 * ** converts decimal to binary
 * ** input: int decimal_val
 * ** output: string
 * *****************************************************************************/

string bin_flip(string bin1) {
        string bin2 = "";
        for (int i=0; i < bin1.length(); i++) {
                bin2 += bin1[(bin1.length()-i-1)];
        }
        return bin2;
}

/*****************************************************************************
 * ** dec_to_bin
 * ** converts decimal to binary
 * ** input: int decimal_val
 * ** output: string
 * *****************************************************************************/

string dec_to_bin(int decimal_val_int) {
	string bin1 = "";
	int i = 0;
	do {
		if ((decimal_val_int % 2) == 0) {
			bin1 += '0';
			decimal_val_int = decimal_val_int/2;
		}
		else if ((decimal_val_int % 2) == 1) {
			bin1 +='1';
			decimal_val_int = decimal_val_int/2;
		}	
	}while(decimal_val_int > 0);
	return bin_flip(bin1);
}

/*****************************************************************************
 * ** dec_to_bin_calc
 * ** this function is used to prompt the user to input a decimal value
 * ** input: user input
 * ** output: print to screen
 * ***************************************************************************/

void dec_to_bin_calc() {
	bool repeat = false;
	string decimal_val;
		getline(cin,decimal_val);
	do {
		cout << " Please give a whole decimal value: ";
		getline (cin,decimal_val);
		if (is_int(decimal_val) == true) {
			int decimal_val_int = get_int(decimal_val);
		cout << " The binary value of " << decimal_val_int << " is " << dec_to_bin(decimal_val_int) << endl;
			repeat = false;
		}
		else {
			cout  << "This is not a valid decimal value. Try again" << endl;
			repeat = true;
		}		
	}while (repeat == true);
}

/************************************************************************************
 *grade_weight
 * asks for a weight and multiplies it to teh average
 * input: flaot avg
 * output: float avg
 * *********************************************************************************/

float grade_weight(float avg) {
	string choice;
	bool repeat = false;
	string weight;
	cout << "Would you like to add a weight to these grades(0-no, anything other than 0-yes): ";
	getline(cin,choice);
	if ((choice.length() > 1) || (choice[0] != '0')) {
		do {
			cout << "Enter a weight as a decimal (200% = 2, 150% = 1.5): ";
			getline(cin, weight);
			if (is_float(weight) == true) {
				return (avg * get_float(weight));
			}
			else 
				repeat = true;
		}while (repeat == true);
	}
	return avg;
}



/*************************************************************************************
 * grade_sum
 * adds the grades together and averages them
 * input; int grade_num
 * output: float average
 * **********************************************************************************/

float grade_sum(int grade_num) {
	float  sum = 0, avg = 0, grade_int = 0;
	bool repeat = false;
	string grade;
	for (int i=0; i < grade_num; i++) {
		do { 
			cout << endl << "please give a grade as an integer (98% would be 98): ";
			getline(cin, grade);
		if (is_int(grade) == true) {
			sum += get_int(grade);
			repeat = false;
		} 
		else {
			repeat = true;
			cout << "Try Again" << endl;
		}	
		} while(repeat == true);
	}
	avg = (float)sum/grade_num;
	return grade_weight(avg);
}


/*****************************************************************************
 * ** grade_calc
 * ** asks for the number of grades will be inputed
 * ** input: user input
 * ** output: grade average
 * *****************************************************************************/

void grade_calc() {
	bool repeat = true;
	string grade_num;
	getline(cin, grade_num);
	do { 
		cout << "How many grades would you like calculated as an integer: ";
		getline(cin,grade_num);
		repeat = is_int(grade_num);
	}while(repeat == false );
	float avg = grade_sum(get_int(grade_num));
	cout << "The average of the grades provided is " << avg << endl;
}


/*******************************************************************************
 * check_bin
 * checks to see if string is valid binary value
 * input string bin_val
 * output: bool
 * Taken from lecture slides
 * ***************************************************************************/

bool check_bin(string bin) {
	for(int i=0; i < bin.length(); i++) {
		if ((bin[i] != '0') && (bin[i] != '1')) 
			return false; 
	}
	return true;
}

/******************************************************************************
 * get_dec
 * takes a binary string and turns it to a integer
 * input: string bin
 * output: int dec
 * ***************************************************************************/

int get_dec(string bin) {
	int len = bin.length(), dec = 0 ;
	for (int i=0; i < len; i++) {
		if (bin[i] == '1')
			dec += pow(2, (len-i-1));
	}
	return dec;
	33;
}


/*******************************************************************************
 * bin_to_dec_calc
 * takes in user binary
 * input n/a
 * output: void
 * *****************************************************************************/

void bin_to_dec_calc() {
	bool repeat = false;
	string bin_val;
	getline(cin, bin_val);
	do { 
		cout << "Please give an positive unsigned binary value: ";
		getline(cin,bin_val);
		if (check_bin(bin_val) == true) {
			cout << "The decimal value of " << bin_val << " is "<< get_dec(bin_val) << endl;
			repeat = false;
		}
		else {
			cout << "Try Again" << endl;
			repeat = true;
		}
	}while (repeat == true);
}


/*****************************************************************************
 * ** calc_type
 * ** prompts user to pick calc type and calls function
 * ** input: N/a
 * ** output: void
 * *****************************************************************************/

void calc_type(string calc_selection) {
		if (calc_selection.length() > 1)
			cout << endl << "invalid entry" << endl;
		else if (calc_selection[0]  =='1')
			standard_calc();
		else if (calc_selection[0] == '2')
			bin_to_dec_calc();
		else if (calc_selection[0] == '3')
			dec_to_bin_calc();
		else if (calc_selection[0] == '4')
			grade_calc();
		else
			cout << endl << "invalid entry" << endl;
}

/*****************************************************************************
 * ** main
 * ** calls function
 * ** input: nothin
 * ** output: print
 * *****************************************************************************/

int main() {
	string repeat1 = "", calc_selection = "";
	do {
	cout << endl << endl << "Welcome to the calculator program." << endl << " Would you like to use a standard calculator (1), a binary to decimal (2), a decimal to binary (3), or a grade calculator (4): ";
	getline(cin, calc_selection);
	calc_type(calc_selection);
	cout << endl << "Would you like to use another calculator? (1-yes, anything else-no)";
	getline(cin, repeat1);
	} while(repeat1[0] = '1' && repeat1.length() == 1);
	return 0;
}
