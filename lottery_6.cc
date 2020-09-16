#include <stdlib.h>
#include <time.h> 
#include <iostream>

using namespace std;

int winning[6];
int ticket[6];

int ticketCounter;
int matchCounter;

const int whiteball_MAX = 69;
const int powerball_MAX = 26;

int whiteball[whiteball_MAX];
int powerball[powerball_MAX];

void fillArrayBalls();
void shuffleBalls();
void generateWinningNumbers();
void checkNumbers();

int main() {
	srand(time(NULL));

	fillArrayBalls();
	generateWinningNumbers();
	shuffleBalls();

	cout << "// Powerball lottery" << endl;
	cout << "// Match all 6 numbers and win 1.5 Billion dollars!" << endl << endl;

	cout << "Winning numbers: " << winning[0] << " " << winning[1] << " " << winning[2] << " " << winning[3] << " " << winning[4] << " PWR " << winning[5] << endl;
	cout << "--------------------------------------" << endl;

	while (matchCounter != 6) {			
		shuffleBalls();
		matchCounter = 0;

		for (int i = 0; i < 5; i++) {
			ticket[i] = whiteball[i];
			
		}

		int randNum = rand() % powerball_MAX;
		ticket[5] = powerball[randNum];

		checkNumbers();
		
		ticketCounter++;
	}

	cout << "Your numbers:     " << ticket[0] << " " << ticket[1] << " " << ticket[2] << " " << ticket[3] << " " << ticket[4] << " PWR " << ticket[5] << endl;
	cout << "Total matched:    " << matchCounter << endl << endl;

	cout << "Congratulations, you win!" << endl;
	cout << "Total tickets used: " << ticketCounter << endl;
	cout << "Total cash spent: $" << ticketCounter * 2 << endl;

	return 0;
}

void generateWinningNumbers() { //generates the winning numbers.

	shuffleBalls();

	for (int i = 0; i < 5; i++) {
		winning[i] = whiteball[i];
	}
	winning[5] = powerball[1];
}

void fillArrayBalls() { //fills whiteball and powerball arrays with numbers.
	for (int i = 0; i < whiteball_MAX; i++) {     
		whiteball[i] = i+1;
	}
	for (int i = 0; i < powerball_MAX; i++) {     
		powerball[i] = i+1;
	}
}

void shuffleBalls() { //shuffles the whiteballs and balls.

	for (int i = 0; i < whiteball_MAX; i++) {    
		int temp = whiteball[i];
		int randomIndex = rand() % whiteball_MAX;

		whiteball[i] = whiteball[randomIndex];
		whiteball[randomIndex] = temp;
	}

	for (int i = 0; i < powerball_MAX; i++) {   
		int temp = powerball[i];
		int randomIndex = rand() % powerball_MAX;

		powerball[i] = powerball[randomIndex];
		powerball[randomIndex] = temp;
	}
}

void checkNumbers() {	//checks if any numbers match.
	for (int i = 0; i < 5; i++) {
		if (ticket[i] == winning[0]) {
			matchCounter++;
		}
		else if (ticket[i] == winning[1]) {
			matchCounter++;
		}
		else if (ticket[i] == winning[2]) {
			matchCounter++;
		}
		else if (ticket[i] == winning[3]) {
			matchCounter++;
		}
		else if (ticket[i] == winning[4]) {
			matchCounter++;
		}
	}

	if (ticket[5] == winning[5]) {
		matchCounter++;
	}
}