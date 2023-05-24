#include <iostream>
#include "Snake.h"
#include "TicTacToe.h"
#include <windows.h>

using namespace std;

bool exit_loop = true;
int game;

int main()
{
    while (exit_loop)
    {
		system("cls");

		cout << "MENU" << endl;
		cout << "1. Snake." << endl;
		cout << "2. Tic Tac Toe." << endl;
		cout << "3. Exit." << endl << endl;
		cout << "Type number: ";
		cin >> game;

		if (game == 1)
		{
			SnakeGame snakeGame;
			snakeGame.Run();

			system("pause");
			return main();
		}
		else if (game == 2)
		{
			TicTacToeGame game;
			game.Run();

			system("pause");
			return main();
		}
		else if (game == 3)
			break;
		else
		{
			cout << "Option doesn't exist. Try one more time.";
			Sleep(800);
		}
    }
}