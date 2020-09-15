/******************************************************************************** 
 ** assignment2.cpp
 ** Reed Boeshans
 ** 21 January 2018
 ** This is a program that gives the user the chance to make their way through an    adventure.
 ** Input: user input 1 or 2
 ** Output: result of their decision
*******************************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
	
	int x, random, start, decision1, decision2a, decision3a, decision2b, decision3b, decision4;
	srand(time(NULL));

/* This is my randomization that will be used later in the program*/
	x = rand();
	x = x % 10;
		

	cout << "There is a valuable treasure that can be found deep inside theamazon rainforest, inside an ancient temple.  We need someone to help find the treasure. To start press 1. ";
	cin >> start;

	if (start == 1) {
		cout << endl << endl << "To start your journey you must choose to travel to the temple that the treasure is in by boat or truck. (1 if boat, 2 if truck): ";
		cin >> decision1;
		if (decision1 == 1) {
			cout << endl << endl << "After choosing to travel by boat, you encountered a group of angry alligators." << endl << "You have the choice to go around or fight the alligators.  If you choose to fight them there is a 80 percent chance the alligators will attack. If you do kill the alligators the temple is right behind them. (1 to go around, 2 to fight): ";
			cin >> decision2a;
			if (decision2a == 1) {
				cout << endl << endl << " Now that you have made it past the alligators there is a fallen tree blocking the river.  You can either try to swim under and to the temple or walk on land around the fallen tree and to the temple. On land there is a risk of snakes and in the water there could be piranahas. (1 to swim, 2 to walk): ";
				cin >> decision3a;
				if (decision3a == 2) { 	
					cout << endl << endl << "Congratulations!!!! You have made it to the temple successfully and can now loot the treasure." << endl;
				}
				else {
					cout << endl << endl << "While trying to swim to the temple, you encountered piranahas and they attacked.  Unfortunatly you were unable to make it to the temple" << endl;
				}
			}
/* This is where i check the randomization*/
			else {
				if (x == 0) {
					cout << "While trying to fight the alligators you were overwhelmed and they pulled you under and you were unable to mak e it to the temple." << endl; 
				}
				else if (x == 1) {
                                        cout << "While trying to fight the alligators you were overwhelmed and they pulled you under and you were unable to mak e it to the temple." << endl;
				}
				else if (x == 2) {
                                        cout << "While trying to fight the alligators you were overwhelmed and they pulled you under and you were unable to mak e it to the temple." << endl;
                                }
				else if (x == 3) {
                                        cout << "While trying to fight the alligators you were overwhelmed and they pulled you under and you were unable to mak e it to the temple." << endl;
                                }
				else if (x == 4) {
                                        cout << "While trying to fight the alligators you were overwhelmed and they pulled you under and you were unable to mak e it to the temple." << endl;
                                }
				else if (x == 5) {
                                        cout << "While trying to fight the alligators you were overwhelmed and they pulled you under and you were unable to mak e it to the temple." << endl;
                                }
				else if (x == 6) {
                                        cout << "While trying to fight the alligators you were overwhelmed and they pulled you under and you were unable to mak e it to the temple." << endl;
                                }
				else if (x == 7) {
                                        cout << "While trying to fight the alligators you were overwhelmed and they pulled you under and you were unable to mak e it to the temple." << endl;
                                }
				else  {
					cout << "You were able to successfully fight all the alligators.  Now you have a clear path to teh temple. Congrats on making it to the temple and the treasure inside." << endl; 
				}
			}
		}
		else {
			cout << endl << endl <<"After choosing to travel by car, you encountered a group of angry jaguars in the trees." << endl << "You have the choice to go around or fight the jaguars.  If you choose to fight them there is a 80 percent chance the jaguars will attack. If you do kill the jaguars the temple is right behind them. (1 to go around, 2 to fight): ";
                        cin >> decision2b;
			if (decision2b == 1) {
				cout << endl << endl << "After choosing to drive around the jaguars, you are no longer on a gravel road, but you think you have a general direction of the temple." << endl << "While driving you must choose while you will drive through a lot of mud or drive through part of the river.  However you don't know how deep the river may be and if your car will make it. (1 to drive through mud, 2 to drive through river): ";
				cin >> decision3b;
				if (decision3b == 1) {
					cout << endl << endl << "You chose to drive through the mud.  Unfortunatly the mud was very thick and you are no stuck in it. You can eiter try to walk the rest of the way or try to push the car's engine harder to hopefully get the car moving again. (1 to walk, 2 to try harder): ";
					cin >> decision4;
					if (decision4 == 1) {
						cout << endl << endl << "After walking for a couple of hours the sun is going down and a storm is brewing.  Unfortunatly you are now lost and were unable to make it to the temple and its treasure." << endl;
					} 
					else {
						cout << endl << endl << "After trying to push the car a little harder the tires gained some traction and you were able to make it out of the mud.  Now you have a clear path to the temple. Congratulations on making it all the way to the temple and its treasure!!!!!" <<endl;
					}
				}
				else {
					cout << endl << endl << "You chose to drive through the river.  Unfortunately the river was much deeper than it looked and your car began to sink.  Surrounded by alligators and piranahas you were unable to make it to the temple and the treasure inside." << endl;
				}
			}
/* Randomization is used here as well*/
			else { 
                                if (x == 0) {
                                        cout << endl << endl << "While trying to fight the jaguars, the jaguars overwhelmed you. Unfortunatley you were unable to make it to the temple and the treasure inside it." << endl;
				}
				else if (x == 1) {
                                        cout << endl << endl << "While trying to fight the jaguars, the jaguars overwhelmed you. Unfortunatley you were unable to make it to the temple and the treasure inside it." << endl;
                                }
				else if (x == 2) {
                                        cout << endl << endl << "While trying to fight the jaguars, the jaguars overwhelmed you. Unfortunatley you were unable to make it to the temple and the treasure inside it." << endl;	
				}
				else if (x == 3) {
                                        cout << endl << endl << "While trying to fight the jaguars, the jaguars overwhelmed you. Unfortunatley you were unable to make it to the temple and the treasure inside it." << endl;
                                }
				else if (x == 4) {
                                        cout << endl << endl << "While trying to fight the jaguars, the jaguars overwhelmed you. Unfortunatley you were unable to make it to the temple and the treasure inside it." << endl;
                                }
				else if (x == 5) {
                                        cout << endl << endl << "While trying to fight the jaguars, the jaguars overwhelmed you. Unfortunatley you were unable to make it to the temple and the treasure inside it." << endl;
                                }
				else if (x == 6) {
                                        cout << endl << endl << "While trying to fight the jaguars, the jaguars overwhelmed you. Unfortunatley you were unable to make it to the temple and the treasure inside it." << endl;
                                }
				else if (x == 7) {
                                        cout << endl << endl << "While trying to fight the jaguars, the jaguars overwhelmed you. Unfortunatley you were unable to make it to the temple and the treasure inside it." << endl;
                                }
                                else  {
                                        cout << endl << endl << "You were able to successfully fight all the jaguars.  Now you have a clear path to teh temple. Congrats on making it to the temple and the treasure inside." << endl;
                                }
                        }
		}

	}
	else {
		return 0;
	}
	return 0;
}
