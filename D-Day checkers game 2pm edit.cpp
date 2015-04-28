//Kenneth Fernandez, Allan Martin, and Chris Charters checkers
//4/18/15 4:20 PM graphics
//4/25/15 3:10 PM king_me game_on game_over
//4/25/15 5:15 PM black and red pieces and updated game over
//4/27/15 7:00 PM added Allan's move, imputmove, and pickpiece
//4/28/15 3:51 AM basic game function WORKING!!! Needs additional security..

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;

void display_board(char board[8][8]); //every outside function has to be passed a board array
void king_me(char board[8][8]);
int b_pieces(char board[8][8]);
int r_pieces(char board[8][8]);
void game_over(char board[8][8]);
void movePiece(char(&board)[8][8]);
void inputMove();
void pickpiece();
int checkMove(char(&board)[8][8]);
bool checkSelected(char(&board)[8][8]);


bool game_on = true;
unsigned int initialrow = 0;
unsigned int initialcolumn = 0;
unsigned int finalrow = 0;
unsigned int finalcolumn = 0;
int Red_Score = 0;
int Black_Score = 0;

int main()
{
	char board[8][8] =									//	An 2D array holding each Location, Color, and Type:
	{												//
		{ ' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b' },	//
		{ 'b', ' ', 'b', ' ', 'b', ' ', 'b', ' ' },	//	Location is the array board [ii][jj]
		{ ' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b' },	//
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },	//	Color is either r or b (red or black)
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },	//
		{ 'r', ' ', 'r', ' ', 'r', ' ', 'r', ' ' },	//	Type is either lowercase or uppercase
		{ ' ', 'r', ' ', 'r', ' ', 'r', ' ', 'r' },	//		Lowercase for unkinged (r and b)
		{ 'r', ' ', 'r', ' ', 'r', ' ', 'r', ' ' },	//		Uppercase for kinged (R and B)
	};												//

	while (game_on == true)
	{
		display_board(board);//	Outside display function called
		movePiece(board);
		king_me(board);// checks to see if pieces are kinged
		b_pieces(board);
		r_pieces(board);
		game_over(board);// determines the piece number left and changes the game_on to true or false MUST BE LAST IN THE WHILE LOOP!!

		Red_Score = b_pieces(board);
		Black_Score = r_pieces(board);

		cout << "Red Score : " << Red_Score << endl;
		cout << "Black Score : " << Black_Score << endl;
		cout << "Next player." << endl;
	}

	if (Red_Score > Black_Score)
		cout << "Red Wins!!" << endl;

	else if (Black_Score > Red_Score)
		cout << "Black Wins!!" << endl;

	cout << "GAME OVER!" << endl;

	return 0;
}

// functions----------------------------------------------------------------------------------------------------
void display_board(char b[8][8])//Outside display function
{
	cout << "  ==================================================================================\n\n\n";
	cout << "        0         1         2         3         4         5         6         7     \n";
	cout << "   _________________________________________________________________________________\n";
	cout << "   |         |         |         |         |         |         |         |         |\n";
	cout << "   |         |         |         |         |         |         |         |         |\n";
	cout << " A |    " << b[0][0] << "    |    " << b[0][1] << "    |    " << b[0][2] << "    |    " << b[0][3] << "    |    " << b[0][4] << "    |    " << b[0][5] << "    |    " << b[0][6] << "    |    " << b[0][7] << "    |\n";
	cout << "   |         |         |         |         |         |         |         |         |\n";
	cout << "   |_________|_________|_________|_________|_________|_________|_________|_________|\n";
	cout << "   |         |         |         |         |         |         |         |         |\n";
	cout << "   |         |         |         |         |         |         |         |         |\n";
	cout << " B |    " << b[1][0] << "    |    " << b[1][1] << "    |    " << b[1][2] << "    |    " << b[1][3] << "    |    " << b[1][4] << "    |    " << b[1][5] << "    |    " << b[1][6] << "    |    " << b[1][7] << "    |\n";
	cout << "   |         |         |         |         |         |         |         |         |\n";
	cout << "   |_________|_________|_________|_________|_________|_________|_________|_________|\n";
	cout << "   |         |         |         |         |         |         |         |         |\n";
	cout << "   |         |         |         |         |         |         |         |         |\n";
	cout << " C |    " << b[2][0] << "    |    " << b[2][1] << "    |    " << b[2][2] << "    |    " << b[2][3] << "    |    " << b[2][4] << "    |    " << b[2][5] << "    |    " << b[2][6] << "    |    " << b[2][7] << "    |\n";
	cout << "   |         |         |         |         |         |         |         |         |\n";
	cout << "   |_________|_________|_________|_________|_________|_________|_________|_________|\n";
	cout << "   |         |         |         |         |         |         |         |         |\n";
	cout << "   |         |         |         |         |         |         |         |         |\n";
	cout << " D |    " << b[3][0] << "    |    " << b[3][1] << "    |    " << b[3][2] << "    |    " << b[3][3] << "    |    " << b[3][4] << "    |    " << b[3][5] << "    |    " << b[3][6] << "    |    " << b[3][7] << "    |\n";
	cout << "   |         |         |         |         |         |         |         |         |\n";
	cout << "   |_________|_________|_________|_________|_________|_________|_________|_________|\n";
	cout << "   |         |         |         |         |         |         |         |         |\n";
	cout << "   |         |         |         |         |         |         |         |         |\n";
	cout << " E |    " << b[4][0] << "    |    " << b[4][1] << "    |    " << b[4][2] << "    |    " << b[4][3] << "    |    " << b[4][4] << "    |    " << b[4][5] << "    |    " << b[4][6] << "    |    " << b[4][7] << "    |\n";
	cout << "   |         |         |         |         |         |         |         |         |\n";
	cout << "   |_________|_________|_________|_________|_________|_________|_________|_________|\n";
	cout << "   |         |         |         |         |         |         |         |         |\n";
	cout << "   |         |         |         |         |         |         |         |         |\n";
	cout << " F |    " << b[5][0] << "    |    " << b[5][1] << "    |    " << b[5][2] << "    |    " << b[5][3] << "    |    " << b[5][4] << "    |    " << b[5][5] << "    |    " << b[5][6] << "    |    " << b[5][7] << "    |\n";
	cout << "   |         |         |         |         |         |         |         |         |\n";
	cout << "   |_________|_________|_________|_________|_________|_________|_________|_________|\n";
	cout << "   |         |         |         |         |         |         |         |         |\n";
	cout << "   |         |         |         |         |         |         |         |         |\n";
	cout << " G |    " << b[6][0] << "    |    " << b[6][1] << "    |    " << b[6][2] << "    |    " << b[6][3] << "    |    " << b[6][4] << "    |    " << b[6][5] << "    |    " << b[6][6] << "    |    " << b[6][7] << "    |\n";
	cout << "   |         |         |         |         |         |         |         |         |\n";
	cout << "   |_________|_________|_________|_________|_________|_________|_________|_________|\n";
	cout << "   |         |         |         |         |         |         |         |         |\n";
	cout << "   |         |         |         |         |         |         |         |         |\n";
	cout << " H |    " << b[7][0] << "    |    " << b[7][1] << "    |    " << b[7][2] << "    |    " << b[7][3] << "    |    " << b[7][4] << "    |    " << b[7][5] << "    |    " << b[7][6] << "    |    " << b[7][7] << "    |\n";
	cout << "   |         |         |         |         |         |         |         |         |\n";
	cout << "   |_________|_________|_________|_________|_________|_________|_________|_________|\n";
}

void movePiece(char(&board)[8][8])
{
		while (true)
		{
			pickpiece();

			if (checkSelected(board) == true)
			{
				while (true)
				{
					inputMove();

					if (checkMove(board) != 0)
					{
						break;
					}
					while (true)
					{
						pickpiece();

						if (checkSelected(board) == true)
						{
							break;
						}
					}
				}
				break;
			}
			
		}
			
	while (true)
	{
		char temp = 0;
		char moveagain = 'N';

		switch (checkMove(board))
		{
		case 1: //regular move -> swaps the location of initial and final
		{
			temp = board[finalrow][finalcolumn];
			board[finalrow][finalcolumn] = board[initialrow][initialcolumn];
			board[initialrow][initialcolumn] = temp;
			break;
		}

		case 2: //jump move -> swaps location of initial and final, also removes the piece that was jumped
		{
			board[((int)(finalrow - initialrow) / 2) + initialrow][((int)(finalcolumn - initialcolumn) / 2) + initialcolumn] = ' ';
			temp = board[finalrow][finalcolumn];
			board[finalrow][finalcolumn] = board[initialrow][initialcolumn];
			board[initialrow][initialcolumn] = temp;
			cout << "Can you jump again? enter Y or N:";
			cin >> moveagain;

			while (moveagain != 'Y' && moveagain != 'N')
			{
				cout << "Invalid input.  Please enter Y or N\n ";
				cout << "Can you like to jump again? enter Y or N: ";
				cin >> moveagain;
			}

			if (moveagain == 'Y')
			{
				initialrow = finalrow;
				initialcolumn = finalcolumn;

				display_board(board);

				break;
			}

			else if (moveagain == 'N')
			{
				break;
			}
		}
		}

		if (moveagain == 'N') //breaks out of the big while loop to proceed with the game
		{
			break;
		}
	}
}

void pickpiece()
{
	string input;
	cout << "Please input a valid location for a friendly piece. Input in the form: A4 \n:";
	getline(cin, input);
	initialrow = input[0] - 65;
	initialcolumn = input[1] - 48;
}

void inputMove()
{
	string input;
	cout << "Please input a valid location to move the selected piece to. Input in the form: A4 \n: ";
	getline(cin, input);
	finalrow = input[0] - 65;
	finalcolumn = input[1] - 48;
}


void king_me(char b[8][8])// turns pieces into kings if conditions are met
{
	for (int ii = 0; ii < 8; ++ii)
	{
		if (b[0][ii] == 'r')
		{
			b[0][ii] = 'R';
		}
		else if (b[7][ii] == 'b')
		{
			b[7][ii] = 'B';
		}
	}
}

int b_pieces(char b[8][8])
{
	int bNum = 0;
	for (int ii = 0; ii < 8; ++ii)
	{
		for (int jj = 0; jj < 8; ++jj)
		{
			if (b[ii][jj] == 'b' || b[ii][jj] == 'B')
			{
				bNum++;
			}
		}
	}
	int bTaken = 12 - bNum;

	return bTaken;
}

int r_pieces(char b[8][8])
{
	int rNum = 0;
	for (int ii = 0; ii < 8; ++ii)
	{
		for (int jj = 0; jj < 8; ++jj)
		{
			if (b[ii][jj] == 'r' || b[ii][jj] == 'R')
			{
				rNum++;
			}
		}
	}
	int rTaken = 12 - rNum;

	return rTaken;
}

void game_over(char b[8][8]) // runs every turn to check the number of pieces left
{
	int rTaken = r_pieces(b);
	int bTaken = b_pieces(b);

	if (rTaken == 12 || bTaken == 12)
	{
		game_on = false;
	}

}

int checkMove(char(&board)[8][8])
{
	if (abs((int)(finalrow - initialrow)) == 1 && finalrow >= 0 && finalrow <=7)
	{
		if (abs((int)(finalcolumn - initialcolumn)) == 1 && finalcolumn >= 0 && finalcolumn <=7)
		{
			if ((board[initialrow][initialcolumn] == 'r' && (int)(finalrow - initialrow) <0 && board[finalrow][finalcolumn] == ' ') || (board[initialrow][initialcolumn] == 'b' && (int)(finalrow - initialrow) >0 && board[finalrow][finalcolumn] == ' '))
				return 1;
			else if ((board[initialrow][initialcolumn] == 'R' && board[finalrow][finalcolumn] == ' ') || (board[initialrow][initialcolumn] == 'B' && board[finalrow][finalcolumn] == ' '))
				return 1;
			else
			{
				cout << "Invalid move." << endl;
				return 0;
			}
		}
		else
		{
			cout << "Invalid move." << endl;
			return 0;
		}
	}
	else if (abs((int)(finalrow - initialrow)) == 2 && board[finalrow][finalcolumn] == ' ' && board[(int)(finalrow - initialrow) / 2 + initialrow][((int)(finalcolumn - initialcolumn)) / 2 + initialcolumn] != ' ' && finalrow >= 0 && finalrow <= 7 && finalcolumn >= 0 && finalcolumn <= 7)
	{
		if ((board[initialrow][initialcolumn] == 'r' && (int)(finalrow - initialrow) <0 && board[(int)(finalrow - initialrow) / 2 + initialrow][((int)(finalcolumn - initialcolumn)) / 2 + initialcolumn] != 'r' && board[(int)(finalrow - initialrow) / 2 + initialrow][((int)(finalcolumn - initialcolumn)) / 2 + initialcolumn] != 'R') || (board[initialrow][initialcolumn] == 'b' && (int)(finalrow - initialrow) >0 && board[(int)(finalrow - initialrow) / 2 + initialrow][((int)(finalcolumn - initialcolumn)) / 2 + initialcolumn] != 'b' && board[(int)(finalrow - initialrow) / 2 + initialrow][((int)(finalcolumn - initialcolumn)) / 2 + initialcolumn] != 'B'))
			return 2;
		else if ((board[initialrow][initialcolumn] == 'R' && board[(int)(finalrow - initialrow) / 2 + initialrow][((int)(finalcolumn - initialcolumn)) / 2 + initialcolumn] != 'r' && board[(int)(finalrow - initialrow) / 2 + initialrow][((int)(finalcolumn - initialcolumn)) / 2 + initialcolumn] != 'R') || (board[initialrow][initialcolumn] == 'B' && board[(int)(finalrow - initialrow) / 2 + initialrow][((int)(finalcolumn - initialcolumn)) / 2 + initialcolumn] != 'b' && board[(int)(finalrow - initialrow) / 2 + initialrow][((int)(finalcolumn - initialcolumn)) / 2 + initialcolumn] != 'B'))
			return 2;
		else
		{
			cout << "Invalid input." << endl;
			return 0;
		}
	}
	else
	{
		cout << "Invalid input." << endl;
		return 0;
	}
}

bool checkSelected(char(&board)[8][8])
{
	if (board[initialrow][initialcolumn] != 'r' && board[initialrow][initialcolumn] != 'b' && board[initialrow][initialcolumn] != 'R' && board[initialrow][initialcolumn] != 'B')
	{
		cout << "Invalid selection." << endl;
		return false;
	}
	else
		return true;
}