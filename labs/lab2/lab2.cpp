#include <iostream>
#include <cmath>

using namespace std;

int main() {


	int n, max_sign, min_sign, max_usign, min_usign;
	
	cout << "The number of bytes is: ";
	cin >> n;
	n = n*8;
	max_usign = pow(2,n)-1;
	cout << " The max unsigned value stored in " << n << " bytes is: " << max_usign << endl;
	min_usign = 0;
	cout << " The min unsigned value stored in " << n << " bytes is: " << min_usign << endl;

	max_sign = pow(2,(n-1))-1;
	cout << " The max signed value stored in " << n << " bytes is: " << max_sign << endl;
	min_sign =(-1)*pow(2,(n-1));
        cout << " The min signed value stored in " << n << " bytes is: " << min_sign << endl;
	





}
