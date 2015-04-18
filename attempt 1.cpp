//Allan Martin attempt 1 checkers

#include <iostream>

using namespace std;



int main()
{
	char board[8][8];
	char row1 = 0;
	int column1 = 0;
	cout << "Select current piece location (ex -> A,4): \n";
	cin >> board[row1][column1];
	row1 -= 65;

	//playerMove(Player);

	system("PAUSE");
	return 0;
}

/*void playerMove(char turn)
{
	if (turn == Player1)
	{
		cout << "Select current piece location (ex -> A 4): \n";
		cin >> board[row1][column1];
		if (row1 column)

	}
}*/