#include <iostream>
#include "Snake.h"
#include "TicTacToe.h"
#include <conio.h>
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
			SnakeSetup();
			while (!gameOver)
			{
				SnakeDraw();
				SnakeInput();
				SnakeLogic();
				Sleep(40);
			}

			system("pause");
			return main();
		}
		else if (game == 2)
		{
			n = 0;

			TTTDraw();
			while (1)
			{
				n++;
				TTTInput();
				TTTDraw();
				if (TTTWin() == 'X')
				{
					cout << "X wins!" << endl;
					break;
				}
				else if (TTTWin() == 'O')
				{
					cout << "O wins!" << endl;;
					break;
				}
				else if (TTTWin() == '/' && n == 9)
				{
					cout << "It's a draw!" << endl;
					break;
				}
				TTTTogglePlayer();
			}
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