#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int playerChoice();
int computerChoice();
void outcome(int, int);

int main() {

	int player;
	int opponent;

	opponent = computerChoice();

	cout << "Welcome to ROCK PAPER SCISSORS!\n";
	cout << "Are you ready...? SHOOT!\n";
	player = playerChoice();

	if (player < 0 || player > 3) {
		cout << "SHOOT AGAIN!\n";
	}
	else {
		outcome(player, opponent);
	}

	return 0;
}



int playerChoice() {
	int choice;
	cout << "1. Rock\n2. Paper\n3. Scissors\n";
	cin >> choice;

	switch (choice) {
	case 1: cout << "You've shot... ROCK!\n";
		break;
	case 2: cout << "You've shot... PAPER!\n";
		break;
	case 3: cout << "You've shot... SCISSORS!\n";
		break;
	default: cout << "Pick one of the three available.\n";
	}
	
	return choice;
}

int computerChoice() {
	const int MIN_VALUE = 1;
	const int MAX_VALUE = 3;
	int choice;

	unsigned seed = time(0);
	srand(seed);

	choice = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;

	return choice;
}

void outcome(int player, int computer) {
	if (computer == 1) {
		cout << "The computer has shot... ROCK!\n";
		if (player == 1) {
			cout << "Tie game! SHOOT AGAIN!\n";
		}
		else if (player == 2) {
			cout << "ROCK COVERED BY PAPER! You win!\n";
		}
		else if (player == 3) {
			cout << "ROCK BREAKS SCISSORS! You lose!\n";
		}
	}
	else if (computer == 2) {
		cout << "The computer has shot... PAPER!\n";
		if (player == 1) {
			cout << "PAPER COVERS ROCK! You lose!\n";
		}
		else if (player == 2) {
			cout << "Tie game! SHOOT AGAIN!\n";
		}
		else if (player == 3) {
			cout << "PAPER CUT BY SCISSORS! You win!\n";
		}
	}
	else if (computer == 3) {
		cout << "The computer has shot... SCISSORS!\n";
		if (player == 1) {
			cout << "SCISSORS BROKEN BY ROCK! You win!\n";
		}
		else if (player == 2) {
			cout << "SCISSORS CUTS PAPER! You lose!\n";
		}
		else if (player == 3) {
			cout << "Tie game! SHOOT AGAIN!\n";
		}
	}
}