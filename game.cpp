
/*********************

BATTLESHIP GAME BY:
AHMED MAGED, 17104897 AND ISMAIL AHMED ZEKRY, 17105342


*********************/



/**********
*If user choose to enter their ship on line/column 9 or above,
 the program will add ship to 10, 11, 12
 It will continue outside the board's range.

*Overlapping ships.

*When a user shots and hits a ship,
 there should be a message printed that says "you hit a ship".

*Use https://www.diffchecker.com/ to know the difference between two files,
 as you can't do it between two seoerate files in github.
**********/



/*********************

BATTLESHIP GAME BY:
AHMED MAGED, 17104897 AND ISMAIL AHMED ZEKRY, 17105342


*********************/

#include "CC212VSGL.h"
#pragma comment(lib, "CC212VSGL.lib")
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <windowsx.h>
#include <Mmsystem.h>
#include <mciapi.h>
#pragma comment(lib, "winmm.lib")





void startBoard(int board[10][10]) {
	int line, column;

	for (line = 0; line < 10; line++) {
		for (column = 0; column < 10; column++) {
			board[line][column] = -1;
		}
	}
}

void showBoard(int board[10][10]) {
	int line, column;
	char v[3] = { '0' };

	CC212VSGL::setDrawingColor(GREEN);
	CC212VSGL::setDrawingThickness(2);
	CC212VSGL::beginDraw();
	CC212VSGL::fillScreen(BLACK);

	for (int i = 1; i < 12; i++) {
		CC212VSGL::drawLine(i * 100, 119, i * 100, 620);
		CC212VSGL::drawLine(100, 70 + i * 50, 1100, 70 + i * 50);
	}

	for (int i = 1; i <= 10; i++) {

		v[0]++;
		if (v[0] == ':') {
			v[0] = '1';
			v[1] = '0';
		}

		CC212VSGL::drawText(50, 85 + i * 50, v);
		CC212VSGL::drawText(50 + i * 100, 85, v);

	}

	for (line = 0; line < 10; line++) {
		for (column = 0; column < 10; column++) {
			if (board[line][column] == 1) {
				CC212VSGL::setDrawingColor(CYAN);
				CC212VSGL::drawSolidRectangle(100 + column * 100/*50*/, 120 + line * 50, 100, 50);
			}
		}
	}

	CC212VSGL::endDraw();
}


void identifyShips(int board[10][10], int p) {
	int line = 0, column = 0;

	for (int ship = 0; ship < 3; ship++) {
		printf("User %d, please enter the line of your horizontal ship %d: ", p, ship + 1);
		scanf_s("%d", &line);
		printf("User %d, please enter the column of your horizontal ship %d: ", p, ship + 1);
		scanf_s("%d", &column);
		while ( board[line - 1][column - 1] == 1 || board[line - 1][column] == 1 || board[line - 1][column + 1] == 1 || column > 10 || column < 1 || line > 10 || line < 1) 
		{

			printf("User %d, please enter another line for your horizonatal ship %d: ", p, ship + 1);
			scanf_s("%d", &line);
			printf("User %d, please enter another column for your horizontal ship %d: ", p, ship + 1);
			scanf_s("%d", &column);

		}
		if (board[line - 1][column - 1] != 1 && column < 9 && board[line - 1][column] != 1 && board[line - 1][column + 1] != 1) {
			for (int i = 0; i < 3; i++) {
				if (i == 0) {
					system("cls");
					board[line - 1][column - 1] = 1;
					showBoard(board);

				}
				else {
					system("cls");
					column++;
					board[line - 1][column - 1] = 1;
					showBoard(board);
				}
			}
		}
	}

	line = 0;
	column = 0;

	for (int ship = 0; ship < 3; ship++) {
		printf("User %d, please enter the line of your vertical ship %d: ", p, ship + 1);
		scanf_s("%d", &line);
		printf("User %d, please enter the column of your vertical ship %d: ", p, ship + 1);
		scanf_s("%d", &column);
		while ( board[line - 1][column - 1] == 1 || board[line][column - 1] == 1 || board[line + 1][column - 1] == 1  || column > 10 || column < 1 || line > 10 || line < 1)
		{

			printf("User %d, please enter another line for your vertical ship %d: ", p, ship + 1);
			scanf_s("%d", &line);
			printf("User %d, please enter another column for your vertical ship %d: ", p, ship + 1);
			scanf_s("%d", &column);

		}
		if (board[line - 1][column - 1] != 1 && line < 9 && board[line][column - 1] != 1 && board[line + 1][column - 1] != 1) {
			for (int i = 0; i < 3; i++) {
				if (i == 0) {
					system("cls");
					board[line - 1][column - 1] = 1;
					showBoard(board);
				}
				else {
					system("cls");
					line++;
					board[line - 1][column - 1] = 1;
					showBoard(board);
				}
			}
		}

	}

}
	



void shot(int board[10][10], int p) {
	int line, column;

	printf("User %d's turn\n", p);

	printf("Enter line of shot: ");
	scanf_s("%d", &line);
	printf("Enter column of shot: ");
	scanf_s("%d", &column);
	while (line < 1 || line > 10 || column < 1 || column >10) {
		printf("Enter  another line of shot: ");
		scanf_s("%d", &line);
		printf("Enter another column of shot: ");
		scanf_s("%d", &column);
	}

	if (board[line - 1][column - 1] == 1) {
		board[line - 1][column - 1] = 0;
	}
	else if (board[line - 1][column - 1] == -1) {
		board[line - 1][column - 1] = 2;
	}
}

void playboard(int board[10][10]) {
	int line, column;
	char v[3] = { '0' };

	//printf("\t1 \t2 \t3 \t4 \t5 \t6 \t7 \t8 \t9 \t10");
	//printf("\tA \tB \tC \tD \tE \tF \tG \tH \tI \tJ \tK \tL");
	//printf("\n");
	CC212VSGL::beginDraw();
	CC212VSGL::setDrawingColor(GREEN);
	CC212VSGL::setDrawingThickness(2);
	for (int i = 1; i < 12; i++)
	{
		CC212VSGL::drawLine(i * 100, 119, i * 100, 620);
		CC212VSGL::drawLine(100, 70 + i * 50, 1100, 70 + i * 50);


	}

	for (int i = 1; i <= 10; i++) {

		v[0]++;
		if (v[0] == ':') {
			v[0] = '1';
			v[1] = '0';
		}

		CC212VSGL::drawText(50, 85 + i * 50, v);
		CC212VSGL::drawText(50 + i * 100, 85, v);

	}

	for (line = 0; line < 10; line++) {

		for (column = 0; column < 10; column++) {


			for (line = 0; line < 10; line++) {

				for (column = 0; column < 10; column++) {
					if (board[line][column] == 0) {


						CC212VSGL::setDrawingColor(RED);
						CC212VSGL::drawSolidRectangle(100 + column * 100, 120 + line * 50, 100, 50);
					}
			}

		}



			for (line = 0; line < 10; line++) {

				for (column = 0; column < 10; column++) {
					if (board[line][column] == 2) {


						CC212VSGL::setDrawingColor(CYAN);
						CC212VSGL::drawSolidRectangle(100 + column * 100, 120 + line * 50, 100, 50);
					}
				}

			}

		}
	}

		
  
	CC212VSGL::endDraw();

}








int sunkenShips(int board[10][10]) {
	int shotsHit = 0;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board[i][j] == 0) {
				shotsHit++;
			}
		}
	}

	return shotsHit;
}


/*void updateInterface(char board[3][3])
{
	CC212VSGL::setDrawingColor(GREEN);
	CC212VSGL::setDrawingThickness(2);
	CC212VSGL::beginDraw();

	for (int i = 1; i <= 2; i++)
	{
		CC212VSGL::drawLine(100+i*100, 100, 100+i*100, 400);
		CC212VSGL::drawLine(100 , 100+i*100, 400, 100+i*100);

	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{

			char str[50];
			sprintf(str, "%c", board[j][i]);
			CC212VSGL::setDrawingColor(CYAN);
			CC212VSGL::setFontSizeAndBoldness(35, 1000);
			CC212VSGL::drawText(135+i*100, 125+j*100, str);
		}
	}

	CC212VSGL::endDraw();
}*/
void main() {
	

CC212VSGL::setFullScreenMode();

	/*char _board[3][3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			_board[i][j] = '-';


	char ch;
	while (true)
	{
		if (kbhit())
		{
			char sign = getch();
			ch = getch();
			if (ch == '1')
				_board[0][0] = sign;
			if (ch == '2')
				_board[0][1] = sign;
			if (ch == '3')
				_board[0][2] = sign;

			if (ch == '4')
				_board[1][0] = sign;
			if (ch == '5')
				_board[1][1] = sign;
			if (ch == '6')
				_board[1][2] = sign;

			if (ch == '7')
				_board[2][0] = sign;
			if (ch == '8')
				_board[2][1] = sign;
			if (ch == '9')
				_board[2][2] = sign;

		}
		updateInterface(_board); 
	}*/
	
		int board1[10][10], board2[10][10];
		char playAgain;
		int p = 1, s;      // 1 = player 1, 2 = player 2, s = shotHit.

		do {
			s = 0;
			// Clearing the boards.
			startBoard(board1);
			startBoard(board2); //ISMAIL.

			// User 1 identifies his ships.
			showBoard(board1);
			identifyShips(board1, p);
			

			printf("Press any key to continue...");
			_getch();
			system("cls");

			// User 2 identifies his ships.
			p = 2;
			showBoard(board2);
			identifyShips(board2, p);
			

			printf("THE GAME HAS STARTED \nPress any key to continue...");
			_getch();
			system("cls");
			p = 1;

			// The game starts.
			//printf("The game has started\n\n\n");		// we put something to tell them that the game begun.
			
			mciSendString("open \"C:\\Undertale.wav\" type mpegvideo alias mp3", NULL, 0, NULL);
			// ADD
			mciSendString("play mp3", NULL, 0, NULL);

			mciSendString("play mp3 repeat", NULL, 0, NULL);
			do {
				if (p == 1) {
					playboard(board2);
					shot(board2, p);
					playboard(board2);
					s = sunkenShips(board2); // if s = 18 player 1 wins.
					p = 2;
					printf("Press any key to continue...");
					_getch();
					system("cls");
				}
				else if (p == 2) {
					playboard(board1);
					shot(board1, p);
					playboard(board1);
					s = sunkenShips(board1); // if s = 18 player 2 wins.
					p = 1;
					printf("Press any key to continue...");
					_getch();
					system("cls");
				}
			} while (s != 18);

			// The game ends.
			if (p == 2) {
				p = 1;
				printf("User %d won.", p);
			}
			else if (p == 1) {
				p = 2;
				printf("User %d won.", p);
			}
			printf("\n\n");

			printf("Do you want to play again? [Y/N]\n");
			playAgain = _getch();	//works better than scanf.
			//scanf_s("%c", &playAgain);
			system("cls");
		} while (playAgain == 'y' || playAgain == 'Y');

		_getch();
	}
