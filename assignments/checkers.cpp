/*****************************************************************************
 * checkers.cpp
 * Reed Boeshans
 * 3/19/18
 * this file allow two users to play checkers
 * input: user input
 * output: print to screen
 * *************************************************************************/


#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

/******************************************************************************
 * get_int
 * takes a string and turns to int
 * parameters: string
 * Pre-conditions: sting is valid
 * output: integer value of string
******************************************************************************/
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

/******************************************************************************
 * cstr_check
 * checks to see if c-string is valid for size of board
 * parmaeters: c-string
 * pre_conditions: c-string is created and populated
 * output: boolean
 * **************************************************************************/

bool cstr_check(char* str) {
	if (str[0] == '1') {
		if (str[1] == '0' || str[1] == '2') {
			if (str[2] == '\0') 
				return true;
			else
				return false;
		}
		else 
			return false;
	}
	else if (str[0] == '8') {
		if (str[1] == '\0')
			return true;
		else 
			return false;
	}
	else 
		return false;
}

/*******************************************************************************
 * get_int_cstr
 * takes a c-string and turns it to an int
 * parameters: c-string
 * pre-conditions: c-string is valid 
 * output: integer size
 * ****************************************************************************/
int get_int_cstr(char* str) {
	int result = 0;
	for (int i=0; i<strlen(str); i++) {
		result += (((int)str[i]-48) * (pow(10,(strlen(str)-i-1))));
	}
	return result;
}
/******************************************************************************
 * get_size
 * takes in user input as a string and returns an int
 * parameters: none
 * preconditions: command line argument was invalid
 * output: int
 * ***************************************************************************/
int get_size() {
	string size_str;
	int size;
	bool repeat = false;
	do{
	cout << "How Big would you like your board. Only give one length.(8x8 = 8): ";
	getline(cin, size_str);
	size = get_int(size_str);
	if (size == 10|| size == 8|| size == 12) {
		return size;
	}
	else 
		repeat = true;
	}while (repeat == true);
	return size;





}
/******************************************************************************
 * delete_board
 * takes in the array of a board and deletes the dynamic memmory
 * parameters: board array
 * pre-conditions: board is created
 * output: N/A
 * ***************************************************************************/
void delete_board(char** board, int size) {
	for (int i=0; i<size; i++) {
		delete [] board[i];
	}
	delete [] board;
	board = NULL;
}
/******************************************************************************
 * print_board
 * takes in the board and then prints it out
 * parmaters: board array, size
 * preconditions: board is populated
 * output: print to screen
 * ****************************************************************************/
void print_board(char** board, int size) {
	for(int i=0; i<size; i++) {
		for (int j=0; j< size; j++) {
			if (i%2 == 0 && j%2 == 0)
				cout << "|\033[30;47m " << board[i][j] << " ";
                        else if (i%2 == 1 && j%2 == 1)
                                cout << "|\033[30;47m " << board[i][j] << " ";
			else 
				cout << "|\033[0m " << board[i][j] << " ";
			cout << "\033[0m";
		}
		cout << endl;
	}
}
/*******************************************************************************
 * pop_board_start
 * takes in board array and size populating the board with b and r in all rows except the middle 2
 * parameters: size and board array
 * precondtions: board of size "size" is created
 * output: populated arrayi
 * ****************************************************************************/
void pop_board_start(char** board, int size) {
	for (int i=0; i<size; i++) {
		for (int j=0; j<size; j++) {
			if (i <((size/2)-1)) {
                        	if (i%2 == 0 && j%2 == 0)
                                	board[i][j] = ' ';
                        	else if (i%2 == 1 && j%2 == 1)
                                	board[i][j] = ' ';
				else 
					board[i][j] = 'r';
			}
			else if (i>=((size/2+1))) {
                                if (i%2 == 0 && j%2 == 0)
                                        board[i][j] = ' ';
                                else if (i%2 == 1 && j%2 == 1)
                                        board[i][j] = ' ';
                                else
                                        board[i][j] = 'b';
			}
			else 
				board[i][j] = ' ';

		}
	}





}
/*******************************************************************************
 * add one char
 * this goes throught the user input adding one character at a time to movement
 * parameters: moement array, next character
 * preconditions: input buffer was clear before input and there is now input
 * output: populates movement array
 * ***************************************************************************/
void add_one_char(char** movement, char c) {
	char* temp = new char[strlen(*movement)+2];
	for (int i=0; i< strlen(*movement); i++) {
		temp[i] = (*movement)[i];
	}
	temp[strlen(*movement)] = c;
	temp[strlen(*movement)+1] = '\0';
	delete [] (*movement);
	(*movement) = new char[strlen(temp)+1];
	strcpy((*movement), temp);
	delete [] temp;
}
/*****************************************************************************
 * word_count
 * counts the numeber of spaces or '\0' in a array
 * paramters: movement array
 * preconditions: movement is created
 * output: int
 * **************************************************************************/

int word_count(char* movement) {
        int count = 0, i= 0;
        if (strlen(movement) == 0)
                return count;
        for (i; i <= strlen(movement); i++) {
                if (movement[i] == ' '|| movement[i] == '\0') {
                        count = count + 1;
                        if ((int)movement[i+1] == 32)
                                return 0;
                }

        }
        return count;
        }

/******************************************************************************
 * check_num
 * checks to make sure there is a number and if it is somewhat valid
 * parameters: movement, i
 * precondition: word count and strlen is true 
 * output bool
 * ***************************************************************************/
bool check_num(char* movement,int &i, int size) {
	int num =0;
	if ((int)movement[i] >= 48 && (int)movement[i] <= 57) {
		num = (((int)movement[i]-48)*10);
		i +=1;
		if ((int)movement[i] >= 48 && (int)movement[i] <= 57) {
			num += ((int)movement[i]-48);
			if (num >= size)
				return false;
			else 
				return true;
		}
		
	}
	else 
		return false;
	



}
/******************************************************************************
 * get_number
 * gets the integer value from a array
 * paramters: movemetn array, i
 * preconditions: movement[i] is a number
 * output: int
 * ***************************************************************************/
int get_number(char* movement, int i) {
	int num =0;
	num = (((int)movement[i]-48)*10);
	i+=1;
	num += ((int)movement[i]-48);
	return num;
}
/*****************************************************************************
 * check piece
 * checks to make sure there is a correc tpiece in the location they are trying to move
 * parameters: board, player, col, row
 * preconditions: num1c, num1r are created
 * output: bool
 * ***************************************************************************/
bool check_piece(char** board, int player, int col, int row) {
	if (player == 0) {
		if (board[row][col] == 'r' || board[row][col] == 'R')
			return true;
	}
	else if(player == 1){
		if (board[row][col] == 'b' || board[row][col] == 'B')
			return true;
	}
	return false;	
}
/*****************************************************************************
 * check_jump
 * checks if a move will be jumping over an oppenents piece
 * paramters: board, num1c, num1r, num2c, num2r
 * preconditions: piece is moving left or right 2 and up or down 2
 * output: boolean
 * ***************************************************************************/
bool check_jump(char** board, int num1c, int num1r, int num2c, int num2r, int player) {
	if (player == 0) {
		if ((board[(num1r+num2r)/2][(num1c+num2c)/2] == 'b') || (board[(num1r+num2r)/2][(num1c+num2c)/2] == 'B'))
			if (board[num2r][num2c] == ' ')
				return true;

	}
	else if(player == 1){
	      	if ((board[(num1r+num2r)/2][(num1c+num2c)/2] == 'r') || (board[(num1r+num2r)/2][(num1c+num2c)/2] == 'R'))
			if (board[num2r][num2c] == ' ')
				return true;

        }
	return false;
}
/******************************************************************************
 * check open
 * checks to make sure if the piece is moving diagnolly 1 that the spot is open
 * parmaeters: board, num2c, num2r
 * preconditions: the piece is only moving diagnolly by 1 spot
 * output: bool
 *****************************************************************************/
bool check_open(char** board, int num2c, int num2r) {
	if (board[num2r][num2c] == ' ')
		return true;
	else 
		return false;
}
/*****************************************************************************
 * assign_moves
 * assigns the coordinate values of the moves
 * parameters: movement, all the num's, i
 * preconditions: movement is coreectly written
 * output: assigns ints
 * *************************************************************************/
void assign_moves(char* movement, int &num1c, int &num1r, int &num2c, int &num2r, int i) {
	if (i == 0)
		num1c = get_number(movement, i);
	else if (i == 3)
		num1r = get_number(movement, i);
	else if (i == 6)
		num2c = get_number(movement, i);
	else if (i == 9)
		num2r = get_number(movement, i);
}
/******************************************************************************
 * valid_move
 * checks to make sure move is valid on board
 * paramters: movement, board, player
 * preconditions: the movement array are numbers
 * output: boolean
 * ***************************************************************************/
bool valid_move(char* movement, char** board, int player) {
	int num1c=0, num1r=0, num2c=0, num2r=0;
	for (int i=0; i<strlen(movement); i++) {
                assign_moves(movement, num1c, num1r, num2c, num2r, i);
	}
	if (abs(num2c - num1c) > 2)
		return false;
	if (abs(num2r - num1r) > 2)
		return false;
	if (num2r == num1r || num1c == num2c)
		return false;
	if (check_piece(board, player, num1c, num1r) == false)
		return false;
	if (abs(num2r-num1r) == 2 && abs(num2c-num1c) == 2)
		if (check_jump(board, num1c, num1r, num2c, num2r, player) == false)
			return false;
	if (abs(num2r-num1r) == 1 && abs(num2c-num1c) == 1)
		if (check_open(board, num2c, num2r) == false)
			return false;
	if ((board[num1r][num1c] == 'r') && (num2r <= num1r))	
		return false;
	if ((board[num1r][num1c] == 'b') && (num2r >= num1r))
                return false;
	return true;






}
/******************************************************************************
 * check_movement
 * checks to make sure user input is valid
 * paramters: board, movement, size, player
 * preconditions: movement has been populated as c-style string
 * output: boolean
 * ***************************************************************************/
bool check_movement(char** board, char* movement, int size, int player) {
	if (word_count(movement) != 2)
		return false;
	if (strlen(movement) != 11)
		return false;
	for (int i=0; i<strlen(movement); i++) {
		if (i == 0 || i == 3 || i == 6 || i == 9) {
			if(check_num(movement, i, size) == false)
				return false;		
		}
		else if(i == 2 || i==8) {
			if (movement[i] != ',')
				return false;
		}
		else if (i == 5) {
			if (movement[i] != ' ')
				return false;
		} 
	}
	if (valid_move(movement, board, player) == false) {
		return false;
	}
	return true;





}
/*****************************************************************************
 * get_moves
 * assigns the coordinate values of the moves
 * parameters: movement, all the num's, i
 * preconditions: movement is coreectly written
 * output: assigns int
 * *************************************************************************/
void get_moves(char* movement, int &col1, int &row1, int &col2, int &row2, int i) {
        if (i == 0)
                col1 = get_number(movement, i);
        else if (i == 3)
                row1 = get_number(movement, i);
        else if (i == 6)
                col2 = get_number(movement, i);
        else if (i == 9)
                row2 = get_number(movement, i);
}
/*****************************************************************************
 * if normal
 * this will move the piece if it is a normal piece (not king)
 * parmaters: board, all rows and cols, captured_r, captured_b, size
 * preconditions: the piece being moved is not a king
 * output: changed board
 * *************************************************************************/
void if_normal(char** board, int row1, int col1, int row2, int col2, int &captured_b, int &captured_r, int size, int player) {
	if (abs(row2-row1) == 2 && abs(col2-col1) == 2) {
		board[row1][col1] = ' ';
		if (player == 0){
			board[row2][col2] = 'r';
			captured_b += 1;
			board[(row1+row2)/2][(col1+col2)/2] = ' ';

		}
		else {
			board[row2][col2] = 'b';
			captured_r += 1;
			board[(row1+row2)/2][(col1+col2)/2] = ' ';

		}
	}
	else {
		board[row2][col2] = board[row1][col1];
		board[row1][col1] = ' ';
	}
	if (player == 0 && row2 == (size-1))
		board[row2][col2] = 'R';
	else if (player == 1 && row2 == 0)
		board[row2][col2] = 'B';
}
/*****************************************************************************
 * if_king
 * this will move kinged pieces
 * parameters: board, all rows and cols, captured_r, captured_b
 * preconditions: the piece being moved is a king
 * output: changed board
 * ***************************************************************************/
void if_king(char** board, int row1, int col1, int row2, int col2, int &captured_b, int &captured_r, int player) {
        if (abs(row2-row1) == 2 && abs(col2-col1) == 2) {
                board[row1][col1] = ' ';
                if (player == 0){
                        board[row2][col2] = 'R';
                        captured_b += 1;
			board[(row1+row2)/2][(col1+col2)/2] = ' ';
                }
                else {
                        board[row2][col2] = 'B';
                        captured_r += 1;
			board[(row1+row2)/2][(col1+col2)/2] = ' ';

                }
        }
        else {
                board[row2][col2] = board[row1][col1];
                board[row1][col1] = ' ';
        }
}
/******************************************************************************
 * move piece
 * takes the string inputed and moves the correct pieces
 * parameters: board, movement, captured_r, captured_b, player
 * preconditions: string is valid and moves are valid
 * output: prints to screen
 * ***************************************************************************/
void move_piece(char** board, char* movement, int &captured_r, int &captured_b, int player, int size) {
	int row1, col1, row2, col2;
	for (int i=0;i<strlen(movement);i++) {
		get_moves(movement, col1, row1, col2, row2, i);
	}
	if (board[row1][col1] == 'r' || board[row1][col1] == 'b') {
		if_normal(board, row1, col1, row2, col2, captured_b, captured_r, size, player);
	}
	else
		if_king(board, row1, col1, row2, col2, captured_b, captured_r, player);




}
/*******************************************************************************
 * game_turn
 * asks for user input of move and checks validity. if valid it moves piece
 * parameters: board, captured array, size, player turn number
 * preconditions: N/a
 * output: print to screen
 * ****************************************************************************/
void game_turn(char** board, int &captured_r,int &captured_b, int size, int player) {
	bool repeat;
	char* movement = new char;
	*movement = '\0';
	cout << "Player " << player << "'s turn. " << endl;
	do{
		cout << "Please give piece locations using coordintate plane starting at 0 to the chosen size. (ex. col 2 row 10 = 02,10). then put a space between your two places." << endl;
		while(cin.peek() != '\n') {
			add_one_char(&movement, cin.get());		
		}
		cin.ignore();
		cin.clear();
		if (check_movement(board, movement, size, player) == false) {
			*movement ='\0';
			repeat = true;
		}
		else 
			repeat = false;
	}while(repeat == true);
	move_piece(board, movement, captured_r, captured_b, player, size);
	delete [] movement;
//	*movement = '\0';
} 

/******************************************************************************
 * winner
 * checks to see who the winner is
 * parameters: captured_r, captured_b
 * pre-conditions: someone had captured all opposing pieces
 * output: print to screen
 * ***************************************************************************/
void winner(int captured_r, int captured_b, int size) {
	if (captured_b == ((size/2)*3))
		cout << endl << endl << "PLAYER 0 WINS!!!!!!!!" << endl << endl;
	else 
		cout << endl << endl << "PLAYER 1 WINS!!!!!!!!" << endl << endl;
}
/*******************************************************************************
 * game
 * takes in the size of board, creates the board and then runs the game functions
 * parameters: int size
 * pre-conditions: size is a valid integer
 * output: print to screen
 * **************************************************************************/
void game(int size) {
	char** board;
	int captured_r = 0, captured_b = 0, j=0;
	board = new char*[size];
	for (int i=0; i<size; i++) {
		board[i] = new char[size];
	}
	pop_board_start(board, size);
	do{
		j=0;
			print_board(board, size);
			game_turn(board, captured_r, captured_b, size, j);
			cout  << "You have captured " << captured_b << " black pieces"<< endl << endl;
			if (captured_b == ((size/2)*3))
				break;
		j=1;
                        print_board(board, size);
                        game_turn(board, captured_r, captured_b, size, j);
			cout << "You have captured " << captured_r << " red pieces" << endl << endl;
	}while(captured_r != ((size/2)*3));
	print_board(board, size);
	winner(captured_r, captured_b, size);

	delete_board(board, size);
}
/****************************************************************************
 * main
 * takes in command line argument
 * parameters: n/a
 * preconditions: n/a
 * output: print to screen
 * *************************************************************************/

int main(int argc, char** argv) {
	char* str;
	int size;
	bool repeat = false;
	do {
	if (argc != 2) {
		size = get_size();
		repeat = false;
	}
	else {
		str = new char[strlen(argv[1])+1];
		strcpy(str, argv[1]);
		if (cstr_check(str) == true) {
			size = get_int_cstr(str);
			repeat = false;
		}
		else { 
			repeat = true;
			argc = 3;
		}

	}
	}while(repeat == true);
	delete [] str;
	game(size);
	return 0;
}
