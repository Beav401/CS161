#include <iostream>

using namespace std;

void print_array(int disks, int b[3][3]) {
        for(int i=0; i<disks; i++) {
                for(int j=0; j<3; j++) {
                        cout << b[i][j] << " ";
                }
        cout << endl;
        }
}



void towers(int disks, int b[3][3], int from_col, int to_col, int spare) {
        if (disks == 0)
                print_array(disks, b);
        else if (disks >=1) {
                towers(disks-1, b, from_col, to_col, spare);
                b[spare][to_col] = b[disks-1][from_col];
		b[disks-1][from_col] = 0;
                print_array(disks, b);
                towers(disks-1, b, spare, to_col, from_col);
        }
}


int main() {
        int b[3][3] = {{3,0,0},{2,0,0},{1,0,0}};
        int disks = 3, from_col = 0, to_col = 2, spare = 1;
        towers(disks, b, from_col, to_col, spare);


        return 0;
}

