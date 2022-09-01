/*********************************************************************
************** PROGRAMMING AND FUNDAMENTAL PROJECT*********************
************** ***SUBMITTED BY ************** *************************
******************ALI HAIDER    200982********************************
**********************************************************************/

/*     *****  *   ****     *****   *     ****     ***** ****   ****
		 *    *   *          *    * *    *          *   *  *   *
		 *    *   *          *   *****   *          *   *  *   ****
		 *    *   *          *  *     *  *          *   *  *   * 
		 *    *   ****       * *       * ****       *   ****   ****
************************************************************************/
#include<iostream>
using namespace std;
int number, rows, columns, i, j;
char turn = 'X', table[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
bool draw = false;
/*****************************************************
**************function for print table****************
******************************************************/
void display_table()
{
	system("cls");
	cout << "\tT i c   T a c    T o e  G a m e" << endl;
	cout << "\nPlayer 1 [X]\nPlayer 2 [O]\n\n\n" << endl;
	cout << "\t     |     |     \n";
	cout << "\t   " << table[0][0] << " |  " << table[0][1] << "  |  " << table[0][2] << "  \n";
	cout << "\t_____|_____|_____\n";
	cout << "\t     |     |     \n";
	cout << "\t   " << table[1][0] << " |  " << table[1][1] << "  |  " << table[1][2] << "  \n";
	cout << "\t_____|_____|_____\n";
	cout << "\t     |     |     \n";
	cout << "\t   " << table[2][0] << " |  " << table[2][1] << "  |  " << table[2][2] << "  \n";
	cout << "\t     |     |     \n";
}
/*********************************************
********function used for player turn*********
**********************************************/
void player_turn()
{
	if (turn == 'X')
		cout << "\nPlayer 1 [X] turn: ";
	if (turn == 'O')
		cout << "\nPlayer 2 [O] turn: ";
	cin >> number;
	switch (number)
	{
	case 1:
	{
		rows = 0; columns = 0; break;
	}
	case 2:
	{
		rows = 0; columns = 1; break;
	}
	case 3:
	{
		rows = 0; columns = 2; break;
	}
	case 4:
	{
		rows = 1; columns = 0; break;
	}
	case 5:
	{
		rows = 1; columns = 1; break;
	}
	case 6:
	{
		rows = 1; columns = 2; break;
	}
	case 7:
	{
		rows = 2; columns = 0; break;
	}
	case 8:
	{
		rows = 2; columns = 1; break;
	}
	case 9:
	{
		rows = 2; columns = 2; break;
	}
	default:
	{
		cout << "I n v a l i d   C h o i c e";
		break;
	}

	}
	if (turn == 'X' && table[rows][columns] != 'X' && table[rows][columns] != 'O')
	{
		table[rows][columns] = 'X';
		turn = 'O';
	}
	else if (turn == 'O' && table[rows][columns] != 'X' && table[rows][columns] != 'O')
	{
		table[rows][columns] = 'O';
		turn = 'X';
	}
	else
	{
		cout << "Box already filled \n Please try other";
		player_turn();
	}


}
/***********************************************
*********function for game over****************
***********************************************/
bool over_game()
{
	//	player wins
	//	for rows and columns
	for (int i = 0; i < 3; i++)
		if ((table[i][0] == table[i][1] && table[i][0] == table[i][2]) || (table[0][i] == table[1][i] && table[0][i] == table[2][i]))
			return false;

	//	for diagnals
	if ((table[0][0] == table[1][1] && table[0][0] == table[2][2]) || (table[0][2] == table[1][1] && table[0][2] == table[2][0]))
		return false;

	// emty box
	else
	{
		for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			{
				if (table[i][j] != 'X' && table[i][j] != 'O')
				return true;
			}
		draw = true;
	    return false;
	        
	}
}
/********************************************************
***************main function*****************************
*********************************************************/
int main()
{
	while (over_game())
	{
		display_table();
		player_turn();
		display_table();
		over_game();
	}
	if (turn == 'O' && draw == false)
		cout << "Player 1 [X]  wins the game!!!!\n\n\t**Congratulations**";
	else if (turn == 'X' && draw == false)
		cout << "Player 2 [O]  wins the game!!!!\n\n\t**Congratulations**";
	else if (draw == true)
		cout << "\t\tG A M E  D R A W";
	return 0;
}
/********************************************************
***************project end*****************************
*********************************************************/
