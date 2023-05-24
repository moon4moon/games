#pragma once
#include <iostream>

using namespace std;

class TicTacToeGame
{
private:
    char matrix[3][3];
    char player;

public:
    void TicTacToeGameSetUp()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                matrix[i][j] = '1' + i * 3 + j;
            }
        }
        player = 'X';
    }

    void Draw()
    {
        system("cls");
        cout << "Tic Tac Toe v1.0" << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void Input()
    {
        int a;
        cout << "It's " << player << " turn. Press the number of the field: ";
        cin >> a;

        int row = (a - 1) / 3;
        int col = (a - 1) % 3;

        if (matrix[row][col] == 'X' || matrix[row][col] == 'O')
        {
            cout << "Field is already in use try again!" << endl;
            Input();
        }
        else
        {
            matrix[row][col] = player;
        }
    }

    void TogglePlayer()
    {
        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }

    char CheckWin()
    {
        for (int i = 0; i < 3; i++)
        {
            if (matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2])
                return matrix[i][0];

            if (matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i])
                return matrix[0][i];
        }

        if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
            return matrix[0][0];

        if (matrix[2][0] == matrix[1][1] && matrix[1][1] == matrix[0][2])
            return matrix[2][0];

        return '/';
    }

    void Run()
    {
        char result = '/';
        int turns = 0;

        TicTacToeGameSetUp();

        while (result == '/' && turns < 9)
        {
            Draw();
            Input();
            result = CheckWin();
            TogglePlayer();
            turns++;
        }

        Draw();

        if (result == 'X')
            cout << "Player X wins!" << endl;
        else if (result == 'O')
            cout << "Player O wins!" << endl;
        else
            cout << "It's a draw!" << endl;
    }
};