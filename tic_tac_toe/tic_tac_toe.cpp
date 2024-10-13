// C++ program to implement tic tac toe game 
#include <iostream> 
using namespace std;

// Function to Reinitialize board
void reInitBoard(char board[3][3])
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) 
		{
			board[i][j] = ' ';
		}
	}
}

// Function to draw the Tic-Tac-Toe board 
void drawBoard(char board[3][3])
{
	cout << "-------------\n";
	for (int i = 0; i < 3; i++) {
		cout << "| ";
		for (int j = 0; j < 3; j++) {
			cout << board[i][j] << " | ";
		}
		cout << "\n-------------\n";
	}
}

// Function to check for a win 
bool checkWin(char board[3][3], char player)
{
	// Check rows, columns, and diagonals 
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == player && board[i][1] == player
			&& board[i][2] == player)
			return true;
		if (board[0][i] == player && board[1][i] == player
			&& board[2][i] == player)
			return true;
	}
	if (board[0][0] == player && board[1][1] == player
		&& board[2][2] == player)
		return true;
	if (board[0][2] == player && board[1][1] == player
		&& board[2][0] == player)
		return true;
	return false;
}

int main()
{
	// Initialize the board and players 
	char board[3][3] = { { ' ', ' ', ' ' },
						{ ' ', ' ', ' ' },
						{ ' ', ' ', ' ' } };
	char player = 'X';
	int row, col;
	int turn; // Declare turn here 
	bool quit = false;
	int player_X_score = 0; 
	int player_O_score = 0;

	cout << "Welcome to Tic-Tac-Toe!\n";

	// Game loop 
	while (!quit)
	{
		for (turn = 0; turn < 9; turn++) 
		{
			// Draw the board 
			drawBoard(board);

			// Prompt for valid input 
			while (true) 
			{
				cout << "Player " << player
					<< ", enter row (0-2) and column (0-2): ";
				cin >> row >> col;

				if (board[row][col] != ' ' || row < 0 || row > 2
					|| col < 0 || col > 2) 
				{
					cout << "Invalid move. Try again.\n";
				}
				else 
				{
					break; // Valid input, exit the loop. 
				}
			}

			// Make the move 
			board[row][col] = player;

			// Check for a win after making a move 
			if (checkWin(board, player)) 
			{
				drawBoard(board);
				cout << "Player " << player << " wins!\n";
				if (player == 'X')
				{
					player_X_score += 1;
				}
				else 
				{
					player_O_score += 1;
				}
				break; // Exit the loop after a win. 
			}

			// Switch to the other player 
			player = (player == 'X') ? 'O' : 'X';
		}

		// End of the game 
		drawBoard(board);

		// Check for a draw 
		if (turn == 9 && !checkWin(board, 'X')
			&& !checkWin(board, 'O')) 
		{
			cout << "It's a draw!\n";
		}

		cout << "Round ended! \n";
		cout << "Player O score: " << player_O_score << endl;
		cout << "Player X score: " << player_X_score << endl;
		cout << "Do you want to restart a new game?(Y/n) \n";
		char quit;
		cin >> quit;
		if (quit == 'Y' || quit == 'y')
		{
			cout << "Restarting a new game! \n";
			reInitBoard(board);
		}
		else
		{
			cout << "Game has ended!! \n";
			if (player_O_score > player_X_score) {
				cout << "Player O has won!! \n";
			}
			else {
				cout << "Player X has won!! \n";
			}
			break;
		}
	}


	return 0;
}
