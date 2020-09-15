#include <iostream>

using namespace std;
/******************************************************************************/
void make_array(int** b, int disks) {
	*b = new int*[disks];
	for(int i=0; i<disks; i++) {
		(*b)[i] = new int[3];

	}
	


}
/*****************************************************************************/
void pop_array(int** b, int disks) {
	for (int i=0; i<disks; i++) {
		for (int j=0; j<3; j++) {
			if (j==0)
				b[i][j] = ((disks-2)+i);
			else
				b[i][j] = 0;

		}

	}
} 
/*****************************************************************************/
void print_array(int disks, int** b) {
        for(int i=0; i<disks; i++) {
                for(int j=0; j<3; j++) {
                        cout << b[i][j] << " ";
                }
        cout << endl;
        }
}


/****************************************************************************/
void towers(int disks, int** b[][3], int from_col, int to_col, int spare) {
	if (disks == 0)
		print_array(disks, b);
	else if (disks >=1) {
		towers(disks-1, b, from_col, to_col, spare);		
		b[spare][to_col] = b[disks-1][from_col];

		print_array(disks, b);
		towers(disks-1, b, spare, to_col, from_col);
	}	
	


}


int main() {
	int** b;
	int disks = 0, from_col = 0, to_col = 2, spare = 1;
	cout << "how many disks?: ";
	cin >> disks;
	make_array(&b, disks);
	pop_array(b, disks);
	towers(disks, b, from_col, to_col, spare);


	return 0;
}
