#include <iostream>
#include <cstdlib>
#include <ctime>

const int lotteryNumbers = 10;
const int SIZE = 5;

int generateLottery(int[], int, int);
int userInput(int[], int);
int matchCounter(int[], int[], int);
void displayNumbers(int[], int[]);
void winOrLose(int);

using namespace std;

int main()
{
	int lottery[5] = { 0, 0, 0, 0, 0 };
	int user[5] = { 0, 0, 0, 0, 0 };
	int matches = 0;

	generateLottery(lottery, SIZE, lotteryNumbers);

	userInput(user, SIZE);

	matches = matchCounter(lottery, user, matches);

	displayNumbers(lottery, user);

	winOrLose(matches);

	system("pause");
	return 0;
}

int generateLottery(int lottery[], int, int)
{
	unsigned seed = time(0);
	srand(seed);

	for (int y = 0; y < SIZE; y++)
	{
		lottery[y] = rand() % lotteryNumbers;
	}

	return lottery[0], lottery[1], lottery[2], lottery[3], lottery[4];
}

int userInput(int user[], int)
{
	cout << "Lottery Simulator\n\n";

	for (int y = 0; y < SIZE; y++)
	{
		printf("\nEnter number # %d of 5 that's between 0 and 9: ", y + 1);
		cin >> user[y];

		while (user[y]<0 || user[y]>9)
		{
			cout << "Error, you must enter a number between 0 and 9: ";
			cin >> user[y];
		}

	}


	return user[0], user[1], user[2], user[3], user[4];
}

int matchCounter(int lotto[], int input[], int)
{
	int match = 0;

	for (int x = 0; x < SIZE; ++x)
	{
		if (lotto[x] == input[x])
			match = match + 1;
	}

	return match;
}

void displayNumbers(int lottery[], int user[])
{
	cout << "\nThe winning lottery numbers are: " << lottery[0] << " " << lottery[1] << " " << lottery[2] << " " << lottery[3] << " " << lottery[4] << endl;
	cout << "Your lottery numbers are: " << user[0] << " " << user[1] << " " << user[2] << " " << user[3] << " " << user[4] << endl;
}

void winOrLose(int matches)
{
	cout << "You matched " << matches << " numbers";

	if (matches != SIZE)
		cout << "\nSorry, you didn't win the jackpot. Try again.\n";
	else
		cout << "\nCongrats, you won the lottery!\n";

}