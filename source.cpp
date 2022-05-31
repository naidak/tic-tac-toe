#include <iostream>
#include <iomanip>
using namespace std;

const int rows = 3, columns = 3;

class XO {
	int playerNum;
	char txt[rows][columns];
public:
	XO() {
		playerNum = 1;
		for (int i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < columns; j++)
			{
				txt[i][j] = ' ';
			}
		}
	}

	void Show() {
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
				cout << "+---";
			cout << "+"<<endl;
			for (int j = 0; j < columns; j++)
				cout << "|" << setw(3)<< txt[i][j];
			cout << "|"<<endl;
			
		}
		for (int j = 0; j < columns; j++)
			cout << "+---";
		cout << "+" << endl;
	}

	void IzracunajLokaciju(int location, int& row, int& col)
	{
		if (location <= 3)
		{
			row = 0;
			col = location - 1;
		}

		else if (location <= 6)
		{
			row = 1;
			col = location - 4;
		}
		
		else if (location <= 9)
		{
			row= 2;
			col= location - 7;
		}
	}

	void TypeTheSign(int location)
	{
		int r = 0, c = 0;
		IzracunajLokaciju(location, r, c);
		if (txt[r][c] == ' ' )
		{ 
			if (playerNum % 2 == 0)
				txt[r][c] = 'O';
			else
				txt[r][c] = 'X';

			playerNum++;
		}
		else
		{
			cout << "Lokacija zauzeta.\n ";
		}
	}

	bool CheckRows()
	{
		int counter;
		char firstSign;
		for (int i = 0; i < rows; i++)
		{
			firstSign = txt[i][0];
			counter = 0;
			if(firstSign !=' ')
			{
			for (int j = 0; j < columns; j++)
			{
				if (txt[i][j] == firstSign)
					counter++;
			}
			if (counter == 3)
				return true;
			}
		}
		return false;
	}

	bool CheckColumns()
	{
		int counter;
		char firstSign;
		for (int j = 0; j < columns; j++)
		{
			counter = 0;
			firstSign = txt[0][j];
			if (firstSign != ' ')
			{
				for (int i = 0; i < rows; i++)
				{
					if (txt[j][i] == firstSign)
						counter++;
				}

				if (counter == 3)
					return true;
			}
		}
		return false;
	}

	bool CheckMainDiagonal()
	{
		int counter=0;
		char firstSign = txt[0][0];
		if (firstSign != ' ')
		{
			for (int i = 0; i < rows; i++)
			{
				if (txt[i][i] == firstSign)
					counter++;
			}
		}
		if (counter == 3)
			return true;
		return false;
	}

	bool CheckSideDiagonal()
	{
		int counter;
		char firstSign = txt[0][2];
		for (int i = 0; i < columns; i++)
		{
			counter = 0;
			
			if (firstSign != ' ')
			{
				for (int j = 0; j < rows; j++)
				{
					if (txt[i][j] == firstSign && (i+j)==rows-1)
						counter++;
				}

				if (counter == 3)
					return true;
			}
		}
		return false;
	}

	bool EndOfGame()
	{
		return (CheckRows() || CheckColumns() || CheckMainDiagonal() || CheckSideDiagonal());
	}
};

int main()
{
	XO game;
	game.Show();
	int location;

	do{
		cout << "Enter the location: (1-9): ";
		cin >> location;
		game.TypeTheSign(location);
		system("cls");
		game.Show();
	} while (!game.EndOfGame());

	cout << "Congratulations!\n";

	system("pause>0");
	return 0;
}
