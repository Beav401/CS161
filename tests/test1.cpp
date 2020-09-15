#include <iostream>
#include <cmath>
#include <string>

using namespace std;

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
	float_value = float_value/ pow(10, (prompt.length()-decimal-1));
        return float_value;
}

int main() {
	cout << get_float(".5") << endl;
	return 0;
}
