//Date: 16th Jan, 2024

#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
const int LENGTH = 4;
using namespace std;

// Function prototypes
void InitializeCards(int cards[][LENGTH]);
void ShowCards(int cards[][LENGTH], bool faceup[][LENGTH]);
// you may have more function prototypes
void CheckCards(int[][LENGTH], bool[][LENGTH], int& , int, int, int, int);
bool CheckWin(bool [][LENGTH]);
// ======================
//     main function
// ======================
int main()
{

	string name;
	ofstream outFile;
	outFile.open("output.txt");

	cout << "Welcome to my game!" << endl;
	cout << "Please enter your full name: " << endl;
	getline(cin, name);
	cout << "Find all the matching pairs on the board!" << endl;

	int nums[LENGTH][LENGTH];
	InitializeCards(nums);

	bool state[LENGTH][LENGTH] = {false};

	int turns = 0;
	bool gameState = true;
	bool completedGame = true;

	while (gameState) {
		ShowCards(nums, state);
		char dumX1, dumY1;
		cout << "[Press q to quit]" << endl;
		cout << "Enter x and y position of the first card ";
		cin >> dumX1;
		if ( dumX1 == 'q') {
			gameState = false;
			completedGame = false;
			cout << "Thanks for playing!!!" << endl;
			break;
		}
		cin >> dumY1;

		int x1 = dumX1 - '0';
		int y1 = dumY1 - '0';

		if (x1 < 0 || x1 > LENGTH-1 || y1 < 0 || y1 > LENGTH-1) {
			cout << "Invalid coordinates. Try again." << endl;
            continue;
		}

		int x2, y2;
		cout << "Enter x and y position of the second card: ";
		cin >> x2 >> y2;

		if (x2 < 0 || x2 > LENGTH-1 || y2 < 0 || y2 > LENGTH-1) {
            cout << "Invalid coordinates. Try again." << endl;
            continue;
        }

		CheckCards(nums, state, turns, x1, y1, x2, y2);
		if (CheckWin(state)) {
			gameState = false;
		}
	}

	if (!completedGame) {
        outFile << name << " don’t give up!" << endl;
    } else {
        outFile << name << " congrts you completed the game!!" << endl;
		outFile << "It took you " << turns << " to complete the game!" << endl;
    }
	outFile.close();
}

//Receives: list of cards initialized but not declared
//Returns: nothing
//Function: It fills in the array with the pairs of numbers at random positions
void InitializeCards(int cards[][LENGTH])
{
	srand(time(NULL));
	int x1, y1, x2, y2;
	int i;
	int temp;

	//Place pairs in known locations -   this is how our array looks like after
	cards[0][0] = 1; cards[0][1] = 1;//   1  1  2  2
	cards[0][2] = 2; cards[0][3] = 2;
	cards[1][0] = 3; cards[1][1] = 3;//   3  3  4  4
	cards[1][2] = 4; cards[1][3] = 4;
	cards[2][0] = 5; cards[2][1] = 5;//   5  5  6   6
	cards[2][2] = 6; cards[2][3] = 6;
	cards[3][0] = 7; cards[3][1] = 7;//   7  7  8   8
	cards[3][2] = 8; cards[3][3] = 8;

//Now that 2D has been initialized with 8 pairs, we want to shuffle the board 
// so that the pairs aren't right next to each other
	for (int i = 0; i < 30; i++) {
		//Get set of random coordinates and swap
		//First random coordinate on our 2d "grid"
		y1 = rand() % LENGTH;
		x1 = rand() % LENGTH;
		//Second random coordinate of our 2d "grid"
		y2 = rand() % LENGTH;
		x2 = rand() % LENGTH;

		//Now we swap value at (x1, y1) with value at(x2, y2)
		temp = cards[x1][y1];
		cards[x1][y1] = cards[x2][y2];
		cards[x2][y2] = temp;
		//Note: just like with 1D arrays, modifying an n-dimensional array inside
		// a function will change the array itself
	}
}

//Receives: list of cards and list of bool weather the number has been matched
//Returns: nothing
//Function: displays the board of cards, based on weather it has been matched 
// or not
void ShowCards(int cards[][LENGTH], bool faceup[][LENGTH]) {
	cout << "    0 1 2 3	" << endl;
	cout << "   =========" << endl;
	for (int i = 0; i < LENGTH; i++) {
		cout << i << " | ";
		for (int j = 0; j < LENGTH; j++) {
			if (faceup[i][j]) {
				cout << cards[i][j] << " ";
			}
			else {
				cout << "* ";
			}
			
		}
		cout << "|" << endl;
	}
	cout << "   =========" << endl;
}

//Receives: list of cards, list of bool faceup status, number of turns, and
// all coordinates (x1, y1, x2, y2)
//Returns: nothing
//Function: checks weather the inputed coords match and updates state acc, 
// also increments no. of turns
void CheckCards(int nums[][LENGTH], bool state[][LENGTH], int &turns, int x1, int y1, int x2, int y2) {
	if (nums[x1][y1] == nums[x2][y2]) {
        cout << "Match found!" << endl;
        state[x1][y1] = true;
        state[x2][y2] = true;
    } 
	else {
        cout << "No match. Try again!" << endl;
        state[x1][y1] = true;
        state[x2][y2] = true;
        ShowCards(nums, state); 
        state[x1][y1] = false;
        state[x2][y2] = false;
    }
	turns++;
}

//Receives: list of faceup state
//Returns: bool 
//Function: at the end of each turn, checks weather the game has been completed
bool CheckWin(bool faceup[][LENGTH]) {
    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j < LENGTH; j++) {
            if (!faceup[i][j]) {
                return false; 
            }
        }
    }
    return true; 
}
