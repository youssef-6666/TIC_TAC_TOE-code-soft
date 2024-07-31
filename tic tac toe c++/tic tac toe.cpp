#include <iostream>
#include<Windows.h>
using namespace std;
char player ='X';
char matrix[3][3] =
{ '1','2','3',
'4','5','6',
'7','8','9' };
void Drow() // this function of design of game
{
	system("cls");
	cout << "---------" << endl;
	for (int r = 0; r < 3; r++) 
	{
		cout << "| " ;
		for (int c = 0; c < 3; c++) 
		{
			cout << matrix[r][c]<<" ";
			
		}
		cout << "| ";
		
		cout << endl;
		
	}
	cout << "---------"<<endl;
}
//*********************************************
void replace()  //this function replace number of position with x or o

{
	int pos;
	cout << "enter your position("<< player <<") : ";
	cin >> pos;
	char position = '0' + pos;
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			if (matrix[r][c] == position) {


				matrix[r][c] = player;
				
				
			}
		}		
	}
	if (player == 'X')
		player = 'O';
	else
		player = 'X';
	return;
}
char check_winner()
{
	int X = 0, O = 0, counter = 0;

	for (int r = 0; r < 3; r++)               // this check every row 3 X or O cosecoutive
	{
		for (int c = 0; c < 3; c++)
		{
			if (matrix[r][c] == 'X')
				X++;
			else if (matrix[r][c] == 'O')
				O++;
			if (X == 3)
				return 'X';
			if (O == 3)
				return 'O';
		}
		X = 0; O = 0;
	}
	//................................
	for (int c = 0; c < 3; c++)            // this check every cokum 3 X or O cosecoutive
	{
		for (int r = 0; r < 3; r++)
		{
			if (matrix[r][c] == 'X')
				X++;
			else if (matrix[r][c] == 'O')
				O++;
			if (X == 3)
				return 'X';
			if (O == 3)
				return 'O';
		}
		X = 0; O = 0;
	}
	//.............................                                   // check win like (\)

	if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X')  // check win like (\)
		return'X';
	if (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O')
		return'O';
	//.............................. // check win like (/)

	if (matrix[0][2] == 'X' && matrix[1][1] == 'X' && matrix[2][0] == 'X')  
		return'X';
	if (matrix[0][2] == 'O' && matrix[1][1] == 'O' && matrix[2][0] == 'O')
		return'O';
	//........................................ check matrix empty or not

	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			if (matrix[r][c] != 'X' && matrix[r][c] != 'O')
				counter++;
		}
	}
	if (counter == 0)
		return '='; // no winner
	return '*';
}

int main() {
	while (check_winner() == '*')
	{
		Drow();
		replace();
		check_winner();
	}

	Drow();
	if (check_winner() == 'X')
		cout << " the winer player is X " << endl;
	if (check_winner() == 'O')
		cout << " the winer player is O " << endl;

	if (check_winner() == '=')
		cout << " NO WINER ^-^ ^_^ " << endl;









	return 0;

}