//Allan Martin attempt 1 checkers

#include <iostream>

using namespace std;


char initialrow = 0;
int initialcolumn = 0;
char finalrow = 0;
int finalcolumn = 0;

void move(char(&board)[8][8]);
void inputMove();
void pickpiece();

int main()
{
	char board[8][8];
	//defines the initial location of the piece

	move(board[8][8]);
	
	system("PAUSE");
	return 0;
}

void move(char(&board)[8][8])
{
	while (true)
	{
		pickpiece();
		inputMove();
		//call check move function here

		int row1 = 0;
		int row2 = 0;
		row1 = initialrow - 65; //changes the capital letters to the arrays values
		row2 = finalrow - 65;
		char temp = 0;
		
		switch (checkMove)
		{
			case 1: //regular move -> swaps the location of initial and final
			{
				temp = board[row2][finalcolumn];
				board[row2][finalcolumn] = board[row1][initialcolumn];
				board[row1][initialcolumn] = temp;
				

			}
			case 2: //jump move -> swaps location of initial and final, also removes the piece that was jumped
			{
				if (board[(row2 - row1) / 2][(finalcolumn - initialcolumn) / 2] == 'r' || board[(row2 - row1) / 2][(finalcolumn - initialcolumn) / 2] == 'R')
				{
					//redpiecesleft -= 1; not sure whether you wanted these here or not kenneth.
				}
				else
				{
					//blackpiecesleft -=1;
				}

				board[(row2 - row1) / 2][(finalcolumn - initialcolumn) / 2] = ' ';
				temp = board[row2][finalcolumn];
				board[row2][finalcolumn] = board[row1][initialcolumn];
				board[row1][initialcolumn] = temp;
			}
			
		}

		
	}
}

void pickpiece()
{
	cout << "Please input a valid location for a friendly piece. Input in the form: A 4 \n:";
	cin >> initialrow >> initialcolumn;
}

void inputMove()
{
	

	cout << "Please input a valid location to move the selected piece to \n: ";
	cin >> finalrow >> finalcolumn;
}

