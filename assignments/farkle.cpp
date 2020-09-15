/*******************************************************************************
 * Farkle
 * Reed Boeshans
 * 03/04/18
 * This program will replicate the game of Farkle giving the user the chance to pick the number of players and make their own decisions on how they will play
 * input: user input
 * output: score and winner
 * *****************************************************************************/

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;


/*******************************************************************************
 * is_int
 * check if a string is a integer
 * parameters: string
 * output: boolean
 * ***************************************************************************/

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

/*******************************************************************************
 * get_int
 * turns a string into a integer
 * parmaeters: string
 * pre_conditions: string is a valid integer
 * output: integer value
 * ****************************************************************************/

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

  
/*******************************************************************************
 * get players
 * This function will ask for user input and return an integer
 * parameters: none
 * pre-conditions: N/A
 * post: return an integer
 * ****************************************************************************/

int get_players() {
	int player_num = 0;
	do{
	string player_num_str = "";
	cout << "How many players would you like to play with?: ";
	getline(cin, player_num_str);
	if (is_int(player_num_str) == true){
		player_num = get_int(player_num_str);	
		if (player_num > 1)
			return player_num;
	}
	cout << endl << "TRY AGAIN" << endl;
	} while (true);
}

/*******************************************************************************
 * pop_score_arr
 * this function will populate the array with zero's
 * parameters: array, number of players
 * precondition: there is an array created on the heap
 * output: a score array with values of 0
 * ****************************************************************************/

void pop_score_arr(int* score, int num_of_players) {
	for(int i=0; i<num_of_players; i++) {
		score[i] = 0;
	}
}

/****************************************************************************
 * create_score_arr
 * this function will be used to call all of the functions that create the array
 * parameters; none
 * preconditions: none
 * output: an array with all zero's
 * **************************************************************************/

void create_score_arr(int& num_of_players, int* score) {
	num_of_players = get_players();
	score = new int[num_of_players];
	pop_score_arr(score, num_of_players);
}

/*****************************************************************************
 * delete_score_arr
 * this function will delete the score array of the heap
 * parameters: the array
 * precondition: N/A
 * output: set array equal to null on stack
 * **************************************************************************/

void delete_score_arr(int* score) {
	delete [] score;
	score = NULL;
}

/******************************************************************************
 * single_1
 * this function will check if the stored dice have single 1's
 * parameters: array, number of dice stored
 * precondition: the array and number of dice is valid
 * output: boolean
 * ***************************************************************************/

bool single_1(int* stored_dice) {
	if (stored_dice[0]>0)
		return true;
	else
		return false;
}

/*****************************************************************************
 * single_5
 * this function will check if the stored dice have single 5's
 * parameters: array, number of dice stored
 * precondition: teh array and dice number is valid
 * output: boolean
 * ***************************************************************************/

bool single_5(int* stored_dice) {
        if (stored_dice[4]>0)
                return true;
        else
                return false;
}

/*****************************************************************************
 * three_1
 * this will check if there are three ones
 * parameters: array, number of dice stored
 * precondition: the array and dice number are valid
 * output: boolean
 * **************************************************************************/

bool three_1(int* stored_dice) {
	if (stored_dice[0] == 3)
		return true;
	else 
		return false;
}

/*****************************************************************************
 * three_2
 * this will check if there are three twos
 * parameters: array, number of dice stored
 * precondition: the array and dice number are valid
 * output: boolean
 * **************************************************************************/

bool three_2(int* stored_dice) {
        if (stored_dice[1] == 3)
                return true;
        else
                return false;
}

/*****************************************************************************
 * three_3
 * this will check if there are three threes
 * parameters: array, number of dice stored
 * precondition: the array and dice number are valid
 * output: boolean
 * **************************************************************************/

bool three_3(int* stored_dice) {
        if (stored_dice[2] == 3)
                return true;
        else
                return false;
}

/*****************************************************************************
 * three_4
 * this will check if there are three fourss
 * parameters: array, number of dice stored
 * precondition: the array and dice number are valid
 * output: boolean
 * **************************************************************************/

bool three_4(int* stored_dice) {
        if (stored_dice[3] == 3)
                return true;
        else
                return false;
}

/*****************************************************************************
 * three_5
 * this will check if there are three fives
 * parameters: array, number of dice stored
 * precondition: the array and dice number are valid
 * output: boolean
 * **************************************************************************/

bool three_5(int* stored_dice) {
        if (stored_dice[4] == 3)
                return true;
        else
                return false;
}

/*****************************************************************************
 * three_6
 * this will check if there are three sixes
 * parameters: array, number of dice stored
 * precondition: the array and dice number are valid
 * output: boolean
 * **************************************************************************/

bool three_6(int* stored_dice) {
        if (stored_dice[5] == 3)
                return true;
        else
                return false;
}

/*****************************************************************************
 * four of a kind
 * this will check if there is a four of a kind
 * parameters: array,
 * precondition: the array and dice number are valid
 * output: boolean
 * **************************************************************************/

bool four_kind(int* stored_dice) {
	for(int i=0; i<6; i++) {
        	if (stored_dice[i] == 4)
                	return true;
	}
	return false;
}

/****************************************************************************
 * five of a kind
 * this will check for a five of kind
 * parameters: stored dice array
 * preconditions: the array is valid
 * output: boolean
 * **************************************************************************/

bool five_kind(int* stored_dice) {
        for(int i=0; i<6; i++) {
                if (stored_dice[i] == 5)
                        return true;
        }
        return false;
}

/****************************************************************************
 * six of a kind
 * this will check for a six of a kind
 * parameters: stored dice array
 * preconditions: the array is valid
 * output: boolean
 * **************************************************************************/

bool six_kind(int* stored_dice) {
        for(int i=0; i<6; i++) {
                if (stored_dice[i] == 6)
                        return true;
        }
        return false;
}

/***************************************************************************
 * one_to_six
 * this will check for a 1 to 6 straight
 * parameters: stored dice array
 * preconditions: the array is valid
 * output: boolean
 * ************************************************************************/

bool one_to_six(int* stored_dice) {
	for(int i=0; i<6; i++) {
		if (stored_dice[i] != 1)
			return false;
	}
	return true;
}

/*****************************************************************************
 * three_pairs
 * this will check for three pairs
 * parameters: stored dice array
 * preconditions: the array is valid
 * output: boolean
 * **************************************************************************/

bool three_pairs(int* stored_dice) {
	int count = 0;
	for(int i=0; i<6; i++) {
		if (stored_dice[i] == 2)
			count += 1;
	}
	if (count == 3)
		return true;
	else 
		return false;
}

/*****************************************************************************
 * four_and_pair
 * this will check for a four of a kind and a pair
 * parameters: stored dice array
 * preconditions: the array is valid
 * output: boolean
 * **************************************************************************/

bool four_and_pair(int* stored_dice) {
	for(int i=0; i<6; i++) {
		if (stored_dice[i] == 4) {
			for(int j=0; j<6; j++) {
				if (stored_dice[j] == 2)
					return true;
			}
		}
	}
	return false;
}

/****************************************************************************
 * two_triplets
 * this will check for two triplets
 * parameters: stored dice array
 * preconditions: the array is valid
 * output: boolean
 * **************************************************************************/

bool two_triplets(int* stored_dice) {
	int holder = 0;
        for(int i=0; i<6; i++) {
                if (stored_dice[i] == 4) {
			holder = i;	
                        for(int j=0; j<6; j++) {
				if (j = holder) {
				}
                                else if (stored_dice[j] == 2)
                                        return true;
                        }
                }
        }
        return false;
}

/***************************************************************************
 * triple and 1
 * checks for a triple and a one
 * parameters: stored dice array
 * preconditions: the array is valid
 * output: boolean
 * ************************************************************************/
bool triple_and_1(int* stored_dice) {
	int jump = 0;
	for (int i=0; i<6; i++) {
		if (stored_dice[i] == 3) {
			if (stored_dice[0] == 1)
				return true;
			else 
				return false;
		}
	}
	return false;
}

/***************************************************************************
 * triple and 5
 * checks for a triple and a five
 * parameters: stored dice array
 * preconditions: the array is valid
 * output: boolean
 * ************************************************************************/
bool triple_and_5(int* stored_dice) {
        int jump = 0;
        for (int i=0; i<6; i++) {
                if (stored_dice[i] == 3) {
                        if (stored_dice[4] == 1)
                        	return true;
			else 
				return false;
                }
        }
        return false;
}

/***************************************************************************
 * triple 1 5
 * checks for a triple and a five and a one
 * parameters: stored dice array
 * preconditions: the array is valid
 * output: boolean
 * ************************************************************************/
bool triple_1_5(int* stored_dice) {
        int jump = 0;
        for (int i=0; i<6; i++) {
                if (stored_dice[i] == 3) {
                        if (stored_dice[4] == 1 && stored_dice[0] == 1)
                                return true;
                        else
                                return false;
                }
        }
        return false;
}

/***************************************************************************
 * triple 5 5
 * checks for a triple and 2 fives
 * parameters: stored dice array
 * preconditions: the array is valid
 * output: boolean
 * ************************************************************************/
bool triple_5_5(int* stored_dice) {
        for (int i=0; i<6; i++) {
                if (stored_dice[i] == 3) {
                        if (stored_dice[4] == 2)
                                return true;
                        else
                                return false;
                }
        }
        return false;
}

/***************************************************************************
 * triple 1 1 
 * checks for a triple and a 1 and a 1
 * parameters: stored dice array
 * preconditions: the array is valid
 * output: boolean
 * ************************************************************************/
bool triple_1_1(int* stored_dice) {
        for (int i=0; i<6; i++) {
                if (stored_dice[i] == 3) {
                        if (stored_dice[0] == 2)
                                return true;
                        else
                                return false;
                }
        }
        return false;
}



/***************************************************************************
 * quad and 1
 * checks for a four kind and a five
 * parameters: stored dice array
 * preconditions: the array is valid
 * output: boolean
 * ************************************************************************/
bool quad_and_1(int* stored_dice) {
        for (int i=0; i<6; i++) {
                if (stored_dice[i] == 4) {
                        if(stored_dice[0] == 1)
				return true;
			else
				return false;
                }
        }
        return false;
}

/***************************************************************************
 * quad and 5
 * checks for a triple and a five
 * parameters: stored dice array
 * preconditions: the array is valid
 * output: boolean
 * ************************************************************************/
bool quad_and_5(int* stored_dice) {
        for (int i=0; i<6; i++) {
                if (stored_dice[i] == 4) {
                	if (stored_dice[4] == 1)
				return true;
			else 
				return false;
                }
        }
        return false;
}

/***************************************************************************
 * quad_1_5
 * checks for a quad  and a five and a one
 * parameters: stored dice array
 * preconditions: the array is valid
 * output: boolean
 * ************************************************************************/
bool quad_1_5(int* stored_dice) {
        for (int i=0; i<6; i++) {
                if (stored_dice[i] == 4) {
                        if (stored_dice[4] == 1 && stored_dice[0] == 1)
                                return true;
                        else
                                return false;
                }
        }
        return false;
}


/***************************************************************************
 * five and 1
 * checks for a 5 kind and a 1
 * parameters: stored dice array
 * preconditions: the array is valid
 * output: boolean
 * ************************************************************************/
bool five_and_1(int* stored_dice) {
        int jump = 0;
        for (int i=0; i<6; i++) {
                if (stored_dice[i] == 5) {
                	if (stored_dice[0] == 1)
				return true;
			else 
				return false;
                }
        }
        return false;
}

/***************************************************************************
 * five and 5
 * checks for a five kind and a five
 * parameters: stored dice array
 * preconditions: the array is valid
 * output: boolean
 * ************************************************************************/
bool five_and_5(int* stored_dice) {
        int jump = 0;
        for (int i=0; i<6; i++) {
                if (stored_dice[i] == 5) {
                        if (stored_dice[4] == 1)
				return true;
			else 
				return false;
                }
        }
        return false;
}



/***************************************************************************
 * if_1_dice
 * this will run the check funtions that can only be used for 1 dice
 * parmaeters: stored_dice array
 * preconditions: you know how many dice are stored
 * output: boolean
 * ************************************************************************/

bool if_1_dice(int* stored_dice) {
	if (single_1(stored_dice) == true)
		return true;
	else if (single_5(stored_dice) == true) 
		return true;
	else 
		return false;
}
/*************************************************************************
 * if 1 dice options
 * this will give an option of scoring if condition is true
 * parameters: stored dice array
 * preconditions: valid stored dice array
 * output: print to screen
 * *********************************************************************/
void if_1_dice_opt(int* stored_dice) {
        if (single_1(stored_dice) == true)
                cout << "Single 1's. Option 1" << endl;
        if (single_5(stored_dice) == true)
                cout << "Single 5's. Option 2" << endl;
		
}


/**************************************************************************
 * if 2 dice
 * this will run the check functions that can only be used for 2 dice
 * parameters: stored dice array
 * preconditions: properly populated array, and number of stored dice
 * output: boolean
 * ***********************************************************************/

bool if_2_dice(int* stored_dice) {
        if (single_1(stored_dice) == true)
                return true;
        else if (single_5(stored_dice) == true)
                return true;
        else
                return false;
}

/*************************************************************************
 * if 2 dice options
 * this will give an option of scoring if condition is true
 * parameters: stored dice array
 * preconditions: valid stored dice array
 * output: print to screen
 * *********************************************************************/
void if_2_dice_opt(int* stored_dice) {
	if (single_1(stored_dice) == true && single_5(stored_dice) == true)
		cout << "Both single 1's and 5's. option 0" << endl;
        if (single_1(stored_dice) == true)
                cout << "Single 1's. Option 1" << endl;
        if (single_5(stored_dice) == true)
                cout << "Single 5's. Option 2" << endl;

}


/**************************************************************************
 * if 3 dice
 * this will run the check functions that can only be used for 3 dice
 * parameters: stored dice array
 * preconditions: properly populated array, and number of stored dice
 * output: boolean
 * ***********************************************************************/

bool if_3_dice(int* stored_dice) {
        if (if_2_dice(stored_dice) == true)
		return true;
	else if (three_1(stored_dice) == true)
		return true;
        else if (three_2(stored_dice) == true)
                return true;
        else if (three_3(stored_dice) == true)
                return true;
        else if (three_4(stored_dice) == true)
                return true;
        else if (three_5(stored_dice) == true)
                return true;
        else if (three_6(stored_dice) == true)
                return true;
        else
                return false;
}

/**************************************************************************
 * if 3 dice option
 * this will print the scoring options to the user
 * parameters: stored dice array
 * preconditions: properly populated array, and number of stored dice
 * output: print to screen
 * ***********************************************************************/

void if_3_dice_opt(int* stored_dice) {
        if_2_dice_opt(stored_dice);     
        if (three_1(stored_dice) == true)
                cout << "Three 1's. option 3" << endl;
        if (three_2(stored_dice) == true)
                cout << "Three 2's. option 4" << endl;
        if (three_3(stored_dice) == true)
                cout << "Three 3's. option 5" << endl;
        if (three_4(stored_dice) == true)
                cout << "Three 4's. option 6" << endl;
        if (three_5(stored_dice) == true)
                cout << "Three 5's. option 7" << endl;
        if (three_6(stored_dice) == true)
                cout << "Three 6's. option 8" << endl;
}


/****************************************************************************
 * if 4 dice
 * this will run the check functions that can only be used for 4 dice
 * parameters: stored dice array
 * preconditions: properly populated array
 * output: boolean
 * *************************************************************************/

bool if_4_dice(int* stored_dice) {
	if (if_3_dice(stored_dice) == true)
		return true;
	else if (four_kind(stored_dice) == true)
		return true;
	else if (triple_and_1(stored_dice) == true)
		return true;
	else if (triple_and_5(stored_dice) == true)
		return true;
	else 
		return false;


}

/**************************************************************************
 * if 4 dice option
 * this will print the scoring options to the user
 * parameters: stored dice array
 * preconditions: properly populated array, and number of stored dice
 * output: print to screen
 * ***********************************************************************/

void if_4_dice_opt(int* stored_dice) {
	if_3_dice_opt(stored_dice);
	if (four_kind(stored_dice) == true)
		cout << "Four kind. option 9" << endl;
	if (triple_and_1(stored_dice) == true)
		cout << "Triple and a 1. option 10" << endl;
        if (triple_and_5(stored_dice) == true)
                cout << "Triple and a 5. option 11" << endl;
}

/****************************************************************************
 * if 5 dice
 * this will run the check functions that can only be used for  dice
 * parameters: stored dice array
 * preconditions: properly populated array
 * output: boolean
 * *************************************************************************/

bool if_5_dice(int* stored_dice) {
        if (if_4_dice(stored_dice) == true)
                return true;
        else if (five_kind(stored_dice) == true)
                return true;
        else if (triple_1_5(stored_dice) == true)
                return true;
        else if (triple_1_1(stored_dice) == true)
                return true;
        else if (triple_5_5(stored_dice) == true)
                return true;
	else if (quad_and_5(stored_dice) == true)
		return true;
	else if (quad_and_1(stored_dice) == true)
		return true;
	else if (quad_1_5(stored_dice) == true)
		return true;
	else 
		return false;

}

/**************************************************************************
 * if 5 dice option
 * this will print the scoring options to the user
 * parameters: stored dice array
 * preconditions: properly populated array, and number of stored dice
 * output: print to screen
 * ***********************************************************************/

void if_5_dice_opt(int* stored_dice) {
        if_4_dice_opt(stored_dice);
        if (five_kind(stored_dice) == true)
                cout << "Five kind. Option 12" << endl;
	if (triple_1_5(stored_dice) == true)
		cout << "triple and a 1 and 5. option 13" << endl;
        if (triple_1_1(stored_dice) == true)
                cout << "triple and a 1 and 1. option 14" << endl;
        if (triple_5_5(stored_dice) == true)
                cout << "triple and a 5 and 5. option 15" << endl;
        if (quad_and_1(stored_dice) == true)
                cout << "four kind and a 1. option 16" << endl;
        if (quad_and_5(stored_dice) == true)
                cout << "four kind and a 5. option 17" << endl;
        if (quad_1_5(stored_dice) == true)
                cout << "four kind and a 1 and 5. option 18" << endl;



}

/****************************************************************************
 * if 6 dice
 * this will run the check functions that can only be used for  dice
 * parameters: stored dice array
 * preconditions: properly populated array
 * output: boolean
 * *************************************************************************/

bool if_6_dice(int* stored_dice) {
        if (if_5_dice(stored_dice) == true)
                return true;
        else if (six_kind(stored_dice) == true)
                return true;
	else if (one_to_six(stored_dice) == true)
		return true;
	else if (three_pairs(stored_dice) == true)
		return true;
	else if (four_and_pair(stored_dice) == true)
		return true;
	else if (two_triplets(stored_dice) == true)
		return true;
        else if (stored_dice == 0)
                return true;
	else 
		return false;
}

/****************************************************************************
 * if 6 dice opt
 * this will show the user their scoring options
 * parameters: stored dice array
 * preconditions: properly poulated array
 * output: print to screen
 * *************************************************************************/

void if_6_dice_opt(int* stored_dice) {
        if_5_dice_opt(stored_dice);
        if (six_kind(stored_dice) == true)
                cout << "Six Kind. option 19" << endl;
        if (one_to_six(stored_dice) == true)
                cout << "1-6 straight. option 20" << endl;
        if (three_pairs(stored_dice) == true)
                cout << "Three pairs. option 21" << endl;
        if (four_and_pair(stored_dice) == true)
                cout << "Four kind and a pair. option 22" << endl;
        if (two_triplets(stored_dice) == true)
                cout << "Two triplets. option 23" << endl;
}

/*****************************************************************************
 * populate dice
 * this function will assign random values to the dice
 * parameters: dice array, number stored
 * preconditions: dice array is created
 * output: a populated array
 * **************************************************************************/

void populate_dice(int* dice, int num_dice_strd) {
	for (int i=0; i<(6-num_dice_strd); i++){
		dice[i] = ((rand() % 6) + 1);

	}
	for (int j=(6-num_dice_strd); j<6; j++) {
		dice[j] = 0;

	}
}
/*****************************************************************************
 * check_dice_strd
 * take iput from user, check if a valid int and then return the number
 * parameters: num_dice_strd
 * preconditions: none
 * output: int number of dice stored
 * **************************************************************************/

int check_dice_strd(int num_dice_strd) {
	string dice_num_strd = "";
	int number_dice_strd = 0;
	bool repeat =false;
	do{
		cout << "How many dice would you like stored?(0 would result in a FARKLE): ";
		getline(cin, dice_num_strd);
		if (is_int(dice_num_strd) == true){
			number_dice_strd = get_int(dice_num_strd);
			if (number_dice_strd > 6-num_dice_strd)
				repeat = true;
				
		}
		else 
			repeat = true;
	}while(repeat == true);
	return number_dice_strd;
}
/******************************************************************************
 * dice_print
 * print out the contents of the dice array
 * parameters; dice array
 * preconditions: dice array is created and valid
 * output: prints the dice
 * ***************************************************************************/

void dice_print(int* dice) { 
	for (int i=0; i<6; i++) {
		cout << dice[i] << " ";
	}	
	cout << endl;
} 

/******************************************************************************
 * dice_roller
 * create and roll dice randomly
 * parameters: stored dice array
 * preconditions:
 * output: 
 * **************************************************************************/

void dice_roller(int& num_dice_strd, int& number_dice_stored, int* dice) {
	populate_dice(dice, num_dice_strd);
	cout << endl << "The dice are: ";
	dice_print(dice);
	number_dice_stored = check_dice_strd(num_dice_strd);
	num_dice_strd += number_dice_stored;
}
/******************************************************************************
 * pop_stored_dice
 * this will populate the array that holds how many of each number was stored
 * parameters: number_dice_stored, stored dice array
 * preconditions: stored dice array is created, and number of dice stored is valid
 * output: populated array 
 * **************************************************************************/
void pop_stored_dice(int number_dice_stored, int num_dice_strd, int* stored_dice, int* dice){
	string dice_index = "";
	int dice_index_int = 0, dice_value = 0;
	bool repeat = false, repeat2 = false;
	do {
		for (int i=0; i < number_dice_stored; i++){
			do{
			cout << "What dice would you like to store? (numbered 0-5 going from left to right): ";
			getline(cin, dice_index);
			if(is_int(dice_index) == true) { 
				dice_index_int = get_int(dice_index);
				dice_value = dice[dice_index_int];
				stored_dice[dice_value-1] = stored_dice[dice_value-1] + 1;	
				repeat = false;
			}
			else
				repeat = true;
			}while(repeat == true);
		}
		if (if_6_dice(stored_dice) == false) {
			repeat2 = true;
			cout << "Try agian"<< endl;
		}
		else
			repeat2 =false;
		
	}while(repeat2 == true);
	
}

/*****************************************************************************
 * options
 * this function checks for options and then displays them if there are any
 * parameters: number_dice_stored, stored dice array
 * preconditions: stored dice array has been properly populated
 * output: print to screen the options for user
 * **************************************************************************/

void options(int number_dice_stored, int* stored_dice, int& option_num) {
	string option_str  ="";
	bool repeat = false;
	if(if_6_dice(stored_dice) == true) {
		cout << "Your options for scoring are: "<< endl << endl;
		if_6_dice_opt(stored_dice);
		do{
			cout << endl << "What option do you select as number?(option 3 = 3): ";
			getline(cin, option_str);
			if(is_int(option_str) == true) {
				option_num = get_int(option_str);
				if (option_num > 23 && option_num >= 0)
					repeat = true;
			}
			else
				repeat = true;		
		}while(repeat == true);
	}
	cout << "end" << option_num << endl;
}
/***************************************************************************
 * single_func
 * calculates points if only 1's or 5's or both
 * parameters: stored dice array
 * preconditions: 
 * output: score
 * *************************************************************************/

int single_func(int* stored_dice) {
	int times = 0, score1 = 0;
	if (stored_dice[0] >= 1) {
		times = stored_dice[0];
		for (int i=0; i < times; i++) {
			score1 += 100;
		}	
	}
	if (stored_dice[4] >= 1){
		times = stored_dice[4];
		for (int j=0; j<times; j++) {
			score1 += 50;
		}
	}
	return score1;
} 

/**************************************************************************
 * triple_func
 * calculates points for a triple
 * parmaters: stored dice array
 * preconditions: dice array is created
 * output: score
 * ***********************************************************************/

int triple_func(int* stored_dice) {
	if (stored_dice[0] == 3)
		return 300;
	for (int i=1; i<6; i++) {
		if (stored_dice[i] == 3)
			return (100 + 100*i);
	}
}


/****************************************************************************
 * option1
 * adds the score of options 0-4 go 
 * parameters: option_num, i, score, stored dice
 * preconditions: option_num has been selected
 * output: prints to screen and updates score array
 * *************************************************************************/
void option1(int option_num, int i, int* score, int* stored_dice) {
	cout << "score is" << score[0] << endl;
	if (option_num == 0) 
		score[i] = (score[i] + single_func(stored_dice));
	else if (option_num == 1){
		cout << "scoring" <<  score[0] << endl;
		score[0] = (score[0] + single_func(stored_dice));
		}
	else if (option_num == 2)
		score[i] = (score[i] + single_func(stored_dice));
	else if (option_num == 3)
		score[i] = (score[i] + 300);
	else if (option_num == 4)
		score[i] = (score[i] + 200);
}

/*****************************************************************************
 * option2
 * adds the score of options 5-8
 * parameters: option_num, i, score array
 * preconditions: option num has been created
 * output: updates score array
 * **************************************************************************/

void option2(int option_num, int i, int* score) {
	if (option_num == 5)
		score[i] = (score[i] + 300);
	else if (option_num == 6)
		score[i] = (score[i] + 400);
	else if (option_num == 7)	
		score[i] = (score[i] + 500);
	else if (option_num == 8)
		score[i] = (score[i] + 600);
}

/**************************************************************************
 * option3
 * adds the scor eof options 9-13
 * parameters: option_num, i, score array, stored_dice array
 * preconditions: option num has been created
 * output: updates score array
 * ***********************************************************************/

void option3(int option_num, int i, int* score, int* stored_dice) {
	if (option_num == 9)
		score[i] = (score[i] + 1000);
	else if (option_num == 10)
		score[i] = (score[i] + (triple_func(stored_dice) + 100));
	else if (option_num == 11)
		score[i] = (score[i] + (triple_func(stored_dice)+ 50));
	else if (option_num == 12)
		score[i] = (score[i] + 2000);
	else if (option_num == 13)
		score[i] = (score[i] + (triple_func(stored_dice) + 150));
}

/****************************************************************************
 * option4
 * adds the scpre of options 14 - 18
 * parameters: option_num, i, score array, stored_dice array
 * preconditions: option num created
 * output: updates score array
 * ************************************************************************/

void option4(int option_num, int i, int* score, int* stored_dice) {
        if (option_num == 14)
                score[i] = (score[i] + (triple_func(stored_dice) + 200));
        else if (option_num == 15)
                score[i] = (score[i] + (triple_func(stored_dice) + 100));
        else if (option_num == 16)
                score[i] = (score[i] + 1100);
        else if (option_num == 17)
                score[i] = (score[i] + 1050);
        else if (option_num == 18)
                score[i] = (score[i] + 1150);
}

/***************************************************************************
 * option5
 * adds the score of options 19-23
 * parameters: option_num, i, score array, stored_dice array
 * preconditions: everything has been created
 * output: updates score array
 * ************************************************************************/

void option5(int option_num, int i, int* score, int* stored_dice) {
	if (option_num == 19)
		score[i] = (score[i] + 3000);
        else if (option_num == 20)
                score[i] = (score[i] + 1500);
        else if (option_num == 21)
                score[i] = (score[i] + 1500);
        else if (option_num == 22)
                score[i] = (score[i] + 1500);
        else if (option_num == 23)
                score[i] = (score[i] + 2500);
}

	
/*****************************************************************************
 * scoring fun
 * based on the option picked this will assign points to the player
 * parameters: option_num, i
 * preconditions: option_num has been selected
 * output: prints to screen
 * **************************************************************************/

void scoring_fun(int option_num, int i, int* score, int* stored_dice) {
	if (option_num >= 0 && option_num < 5)
		option1(option_num, i, score, stored_dice);
	else if (option_num >= 5 && option_num < 9)
		option2(option_num, i, score);
        else if (option_num >= 9 && option_num < 14)
		option3(option_num, i, score, stored_dice);
        else if (option_num >= 14 && option_num < 19)
		option4(option_num, i, score, stored_dice);
        else if (option_num >= 19 && option_num <= 23)
		option5(option_num, i, score, stored_dice);



}
/****************************************************************************
 * get_winner
 * this will compare the scores of all players and pick the winner
 * parameters: score array, number of players
 * preconditions: score array is valid and number of players is valid
 * output: player number of winner
 * *************************************************************************/

int get_winner(int* score, int num_of_players) {
	int count = 0;
	for (int i=0; i<num_of_players; i++) {
		count = 0;
		for (int j=0; j<num_of_players; j++) {
			if (j == i) {
			}
			else if (score[i] >= score[j])
				count += 1;
		}
		if (count == (num_of_players-1))
			return i;
	}
}
/****************************************************************************
 * pop_stored_dice_zero
 * populates the stored_dice array with zeroes
 * parameters: stored_dice array
 * preconditions: array is created
 * output: stored_dice array with all zeroes
 * **************************************************************************/

void pop_stored_dice_zero(int* stored_dice) {
	for (int i=0; i<6; i++) {
		stored_dice[i] = 0;
	}
}
/*****************************************************************************
 * check_10000
 * this will check if any players have a score over 10000
 * parameters: score array
 * precondions: score array is created
 * output: boolean
 * **************************************************************************/

bool check_10000(int* score, int num_of_players) {
	for (int i=0; i<num_of_players; i++) {
		if (score[i] >= 10000)
			return true;

	}
	return false;
}

/*****************************************************************************
 * last_turn
 * this will call the functions that will allow all other players to have one last turn
 * parameters: num_of_players, score, number_dice_stored, num_dice_strd, stored_dice, dice, option_num
 * preconditions: one player has scored 10000 points
 * output: print to screen, announce winner
 * **************************************************************************/

void last_turn(int num_of_players, int*score, int number_dice_stored, int num_dice_strd, int* stored_dice, int* dice, int option_num, int winner) {
	for (int i=0; i<num_of_players; i++) {
		num_dice_strd = 0;
		if (i == winner) {
		}
		else {
                        cout << endl << "Player " << i << "'s turn" << endl;
                        do{
                                pop_stored_dice_zero(stored_dice);
                                dice_roller(num_dice_strd, number_dice_stored, dice);
                                if (number_dice_stored == 0) {
                                        cout << "You're turn is over" << endl;
                                        break;
                                }
                                pop_stored_dice(number_dice_stored, num_dice_strd, stored_dice, dice);
                                options(number_dice_stored, stored_dice, option_num);
				scoring_fun(option_num, i, score, stored_dice);
				cout << endl << "Player " << i << "'s score is: " << score[i] << endl;

                        }while(num_dice_strd != 6 || number_dice_stored == 0 );
		}	
	}
	winner = get_winner(score, num_of_players);
	cout << endl << endl << "THE WINNER IS PLAYER " << winner << endl;
}


/******************************************************************************
 * player_turns
 * this will control the main portion of the game
 * parameters: num_of_players, 
 * preconditions: number of players is valid
 * output: print to screed
 * ***************************************************************************/

void player_turns(int num_of_players, int* score) {
	int i=0, num_dice_strd = 0, number_dice_stored = 0, option_num = 0, winner;
	int stored_dice[6];
	int dice[6];
	do {
		for(i=0; i < num_of_players; i++) {
			num_dice_strd = 0;
			cout << endl << "Player " << i << "'s turn" << endl; 
			do{
				pop_stored_dice_zero(stored_dice); 
				dice_roller(num_dice_strd, number_dice_stored, dice);
				if (number_dice_stored == 0) {
					cout << "You're turn is over" << endl;
					break;
				}	
				pop_stored_dice(number_dice_stored, num_dice_strd, stored_dice, dice);
				options(number_dice_stored, stored_dice, option_num);
				scoring_fun(option_num, i, score, stored_dice);
				cout << endl << "Player " << i << "score is: " << score[i] << endl;
			}while(num_dice_strd != 6 || number_dice_stored == 0 );
			cout << "End of turn score is: " << score[i] << endl << endl;
			if (score[i] >= 10000) {
				winner = i;
				break;
			}
		}
	}while(check_10000(score, num_of_players) == false);
	last_turn(num_of_players, score, number_dice_stored, num_dice_strd, stored_dice, dice, option_num, winner);
}

/******************************************************************************
 * start_game
 * this will welcome the player and call all the functions as well as ask if the players would like to play agian
 * parmaeters: none
 * preconditions: none
 * output: print to screen
 * ***************************************************************************/

void start_game() {
	int num_of_players = 0, first_10000 = 0;
	int* score;
	string repeat_str = "";
	bool repeat5 = false;
	do {
		cout << endl << "Welcome to Farkle!" << endl;
		num_of_players = get_players();
		score = new int[num_of_players];
		pop_score_arr(score, num_of_players);
		player_turns(num_of_players, score);
		delete_score_arr(score);
		cout << endl << "Would you like to play again? (1 for yes, anything else no): ";
		getline(cin, repeat_str);
		if (is_int(repeat_str) == true){
			if (get_int(repeat_str) == 1)
				repeat5 = true;
			else 
				repeat5 = false;
				
		}
	}while(repeat5 = true);


}


/******************************************************************************
 * main
******************************************************************************/
int main() {
	srand(time(NULL));
	start_game();
	return 0;
}
