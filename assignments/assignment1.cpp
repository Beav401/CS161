/******************************************************************************** ** Assignment 1
 ** Reed Boeshans
 ** January 14, 2018
 ** Using the cmath library to print math equations.
*******************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int main () {

/******************************************************************************** ** These are the solutions to the first 5 equations and what the program will       print when executed
********************************************************************************/

	float result_cos = cos(2.0/3.0);
	cout << endl << " The Value of Cos(2/3) is: " << result_cos << endl;
	
	float result_sin = 2*sin(2.0/3.0);
	cout << " The Value of 2Sin(2/3) is: " << result_sin << endl;
	
	float result_tan = tan(-3.0/4.0);
	cout << " The Value of tan(-3/4) is: " << result_tan << endl;
	
	float result_log = log10(55.0);
	cout << " The Value of Log(50) is: " << result_log << endl;

	float result_ln = log(60.0);
	cout << " The value of ln(60) is: " << result_ln << endl << endl;

/******************************************************************************** ** These are the step by step equations for the 2 log equations
 * *****************************************************************************/

	float result_lnx, result_lnb, result_lnxb, x, b;
	x = 15;
	b = 2;
	result_lnx = log(x);
	result_lnb = log(b);
	result_lnxb = (log(x)/log(b));

	cout << " Find The log base 2 of 15" << endl;
	cout << " ln(15) = " << result_lnx << endl;
	cout << " ln(2) = " << result_lnb << endl; 
	cout << " ln(15)/ln(2) = " << result_lnxb << endl << endl;

	x = 40;
	b = 4;
	result_lnx = log(x);
	result_lnb = log(b);
	result_lnxb = (log(x)/log(b));
	cout << " Find the Log base 4 of 40" << endl;
	cout << " ln(40) = " << result_lnx << endl;
	cout << " ln(4) = " << result_lnb << endl;
	cout << " ln(40)/ln(4) = " << result_lnxb << endl <<endl;

/******************************************************************************** ** These are the step by step equations for the two equations that have a           variable that can be 1, 10, or 100.
 *******************************************************************************/


	float result_sinx, result_3sinx, a;
	a = 1.0;
	result_sinx = sin(a);
	result_3sinx = pow(3.0, result_sinx);
	
	cout << " Find 3 to the power of Sin(1) " << endl;
	cout << " Sin(1) = " << result_sinx << endl;
	cout << " 3 ^ Sin(1) = " << result_3sinx << endl << endl;

	a = 10;
	result_sinx = sin(a);
	result_3sinx = pow(3.0, result_sinx);

	cout << " Find 3 to the power of Sin(10)" << endl;
	cout << " Sin(10) = " << result_sinx << endl;
	cout << " 3 ^ Sin(10) = " << result_3sinx << endl << endl;

	a = 100;
	result_sinx = sin(a);
	result_3sinx = pow(3.0, result_sinx);

	cout << " Find 3 to the power of sin(100)" << endl;
	cout << " Sin(100) = " << result_sinx << endl;
	cout << " 3 ^ Sin(100) = " << result_3sinx << endl << endl;
	
	float result_sqr, result_add, result_lnsqr, result_ln2, result_final, c;
	c = 1;
	result_sqr = pow(c, 2.0);
	result_add = (result_sqr + 1.0);
	result_lnsqr = log(result_add);
	result_ln2 = log(2.0);
	result_final = (result_lnsqr/result_ln2);
	
	cout << " Find the log base 2 of (1^2 + 1)" << endl;
	cout << " 1 ^ 2 = " << result_sqr << endl;
	cout << " 1 + 1 = " << result_add << endl;
	cout << " ln(2) = " << result_lnsqr << endl;
	cout << " ln(2) = " << result_ln2 << endl;
	cout << " ln(2)/ln(2) = " << result_final << endl <<endl;
	
	c = 10;
        result_sqr = pow(c, 2.0);
        result_add = (result_sqr + 1.0);
        result_lnsqr = log(result_add);
        result_ln2 = log(2.0);
        result_final = (result_lnsqr/result_ln2);

        cout << " Find the log base 2 of (10^2 + 1)" << endl;
        cout << " 10 ^ 2 = " << result_sqr << endl;
        cout << " 100 + 1 = " << result_add << endl;
        cout << " ln(101) = " << result_lnsqr << endl;
        cout << " ln(2) = " << result_ln2 << endl;
        cout << " ln(101)/ln(2) = " << result_final << endl <<endl;

	c = 100;
        result_sqr = pow(c, 2.0);
        result_add = (result_sqr + 1.0);
        result_lnsqr = log(result_add);
        result_ln2 = log(2.0);
        result_final = (result_lnsqr/result_ln2);

        cout << " Find the log base 2 of (100^2 + 1)" << endl;
        cout << " 100 ^ 2 = " << result_sqr << endl;
        cout << " 10000 + 1 = " << result_add << endl;
        cout << " ln(10001) = " << result_lnsqr << endl;
        cout << " ln(2) = " << result_ln2 << endl;
        cout << " ln(10001)/ln(2) = " << result_final << endl <<endl;





	return 0;
}
