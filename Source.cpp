#include <iostream>
#include <string>
#include <array>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

string playerName[2];
string input;
int turn = 0;
int toalMoves = 0;

int mode = 0;
int winner;

char letters[3][3] = { {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} };     // THIS ARRAY STORES LETTER WHICH USED IN BOXES (O,X)

bool gameOver = false;
bool gameDraw = false;
bool invalid = false;   // IT BECOMES TRUE WHEN USER PLAYED INVALID MOVE

void header();
int mainMenu();
void instructions();
void getName();
void start();
void checkForScore();
void checkInput(int, int);
void Horizental_Lines();
void Vertial_Lines(int, int);
void getInput(int);
void move();
void board();

int main() {
	mainMenu();
	return 0;
}

void header() {
	cout << " =============================================" << endl;
	cout << "|     ___       ___         ___               |" << endl;
	cout << "|      | o  _    |  _.  _    |  _   _         |" << endl;
	cout << "|      | | (_    | (_| (_    | (_) (/_        |" << endl;
	cout << "|                                             |" << endl;
	cout << " ================ v1.0.0 =====================" << endl;
	cout << endl << endl;
	return;
}

// BELOW FUNTIONS SHOW HOW TO PLAY GAME

void instructions() {

	system("CLS");
	header();

	cout << "We have A,B,C,D for column and 1,2,3,4 for rows." << endl;
	cout << "User have to write the desire option in this formate [column_letter][row_number] like A1 and B4." << endl;
	cout << "Common Error! Some users type a1 instead of A1... Keep in mind only Capital letter should use." << endl << endl;

	system("pause");
	system("CLS");
	mainMenu();

	return;
}

// BELOW FUNTION TAKE FULL NAME FROM USER AND ALSO STORE FIRST LETTER IN NICK NAME ARRAY FOR LATER USE

void getName() {

	system("CLS");
	header();

	if (mode == 0) {

		cout << "ENTER YOUR NAME = ";
		cin >> playerName[0];

		playerName[1] = "CPU";
	}
	else {

		for (int i = 0; i < 2; i++) {
			cout << "ENTER PLAYER " << i + 1 << " NAME = ";
			cin >> playerName[i];
		}
	}

	return;

}

//  BELOW FUNTION CREATE AND DISPLAY TABLE WITH HEADER AT TOP AND CURRENT SCORE

void board() {

	system("CLS");
	header();

	for (char alphabet = 'A'; alphabet <= 'C'; alphabet++) {
		cout << "  " << alphabet << " ";
	}
	cout << endl << endl;

	int numbers = 1, letterRow = 0, letterColumn = 0;

	for (int row = 1, numbers = 1; row <= 7; row++) {

		if (row % 2 != 0) {

			Horizental_Lines();
		}
		else {

			Vertial_Lines(numbers++, letterRow++);

		}
	}

	cout << endl;

	return;
}


// BELOW FUNTION SHOW MAIN MENU OF GAME

int mainMenu() {

	system("CLS");
	int option;

	header();

	cout << "\t" << "[0] SINGLE PLAYER" << endl;
	cout << "\t" << "[1] MULTI PLAYER" << endl;
	cout << "\t" << "[2] HOW TO PLAY?" << endl;
	cout << "\t" << "[3] QUIT" << endl << endl;

	cout << "\t" << "ENTER OPTION = ";
	cin >> option;

	switch (option) {

	case 0:
		mode = 0;
		start();
		break;
	case 1:
		mode = 1;
		start();
		break;
	case 2:
		instructions();
		break;
	case 3:
		return 0;
	default:
		mainMenu();

	}
}

// Check Input

void checkInput(int rows, int column) {

	if (letters[rows][column] == 'X' || letters[rows][column] == 'O') { // Checking for valid input
		invalid = true;
	}
	else {

		// Updaing Value in Array

		if (turn == 0) {
			letters[rows][column] = 'X';
		}
		else if (turn == 1) {
			letters[rows][column] = 'O';
		}

	}

}

// BELOW FUNTION CONTROL HORIZENTAL LINES OF THE BOARD

void Horizental_Lines() {

	cout << "+";

	for (int rows = 0; rows < 3; rows++) {

		for (int i = 0; i < 3; i++) {

			cout << "-";

		}
		cout << "+";
	}


	cout << endl;
	return;
}

// BELOW FUNTION CONTROL VERTICLE LINES OF THE BOARD

void Vertial_Lines(int numbers, int letterRow) {

	for (int column = 0; column < 3; column++) {


		cout << "|";

		if (letters[letterRow][column] != ' ') {

			cout << " " << letters[letterRow][column] << " ";
		}
		else {
			cout << "   ";
		}

	}

	cout << "|";

	cout << "  " << numbers;

	cout << endl;
	return;
}

void checkForScore() {


	// For Horizental Score

	if (letters[0][0] == 'X' && letters[0][1] == 'X' && letters[0][2] == 'X' || letters[0][0] == 'O' && letters[0][1] == 'O' && letters[0][2] == 'O') {

		winner = turn;

		gameOver = true;
	}

	if (letters[1][0] == 'X' && letters[1][1] == 'X' && letters[1][2] == 'X' || letters[1][0] == 'O' && letters[1][1] == 'O' && letters[1][2] == 'O') {

		winner = turn;

		gameOver = true;
	}

	if (letters[2][0] == 'X' && letters[2][1] == 'X' && letters[2][2] == 'X' || letters[2][0] == 'O' && letters[2][1] == 'O' && letters[2][2] == 'O') {

		winner = turn;

		gameOver = true;
	}

	// For Vertical Score

	if (letters[0][0] == 'X' && letters[1][0] == 'X' && letters[2][0] == 'X' || letters[0][0] == 'O' && letters[1][0] == 'O' && letters[2][0] == 'O') {

		winner = turn;

		gameOver = true;
	}

	if (letters[0][1] == 'X' && letters[1][1] == 'X' && letters[2][1] == 'X' || letters[0][1] == 'O' && letters[1][1] == 'O' && letters[2][1] == 'O') {

		winner = turn;

		gameOver = true;
	}

	if (letters[0][2] == 'X' && letters[1][2] == 'X' && letters[2][2] == 'X' || letters[0][2] == 'O' && letters[1][2] == 'O' && letters[2][2] == 'O') {

		winner = turn;

		gameOver = true;
	}

	// For Left Diagonal

	if (letters[0][0] == 'X' && letters[1][1] == 'X' && letters[2][2] == 'X' || letters[0][0] == 'O' && letters[1][1] == 'O' && letters[2][2] == 'O') {

		winner = turn;

		gameOver = true;
	}

	// For Right Diagonal

	if (letters[0][2] == 'X' && letters[1][1] == 'X' && letters[2][0] == 'X' || letters[0][2] == 'O' && letters[1][1] == 'O' && letters[2][0] == 'O') {

		winner = turn;

		gameOver = true;
	}



	if (gameOver == false && toalMoves == 9) {
		gameOver = true;
		gameDraw = true;
	}
}

//  BELOW FUNTION CHECK USER INPUT FOR VALIDATION AND UPDATE ARRAY

void move() {

	int column = 0, rows = 0;

	switch (input[0]) {

	case 'A':
		column = 0;
		break;
	case 'B':
		column = 1;
		break;
	case 'C':
		column = 2;
		break;
	}

	switch (input[1]) {

	case '1':
		rows = 0;
		break;
	case '2':
		rows = 1;
		break;
	case '3':
		rows = 2;
		break;
	}

	checkInput(rows, column);

	return;

}

// CPU Input 

void CPUInput() {

	string numbers;
	string alpha;

	int input1 = rand() % 3 + 1;

	switch (input1)
	{
	case 1:
		alpha = "A";
		break;
	case 2:
		alpha = "B";
		break;
	case 3:
		alpha = "C";
		break;
	}

	int input2 = rand() % 3 + 1;

	switch (input1)
	{
	case 1:
		numbers = "1";
		break;
	case 2:
		numbers = "2";
		break;
	case 3:
		numbers = "3";
		break;
	}

	input = alpha + numbers;
}

// BELOW FUNTION TAKE INPUT FROM THE USER

void getInput(int turn) {

	if (mode == 0) {

		if (turn == 1) {

			CPUInput();
		}
		else {
			cout << playerName[turn] << " Move = ";
			cin >> input;
		}

	}
	else {
		cout << playerName[turn] << " Move = ";
		cin >> input;
	}
}


// BELOW FUNTION START THE DOT AND BOXES GAME AFTER SELECTING FROM MENU

// Result

void result() {

	if (gameDraw) {
		cout << "Well Played , Match Draw !!!!";
	}
	else {
		cout << "Hurrahhhh !!!!! " << playerName[winner] << " Won The Match";
	}

	cout << endl << endl;
}

void start() {

	getName();

	do {

		board();
		getInput(turn);
		move();

		if (!invalid) {

			toalMoves++;
			board();
			checkForScore(); // This funticon will true the value of gameOver if any player won the match

			if (turn == 0) {
				turn = 1;
			}
			else {
				turn = 0;
			}

		}
		else {
			invalid = false;
		}

	} while (!gameOver);

	result();

	system("pause");
	mainMenu();
}


