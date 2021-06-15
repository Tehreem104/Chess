#include<iostream>
#include<string>
#include<conio.h>
#include"Header.h"
#include<windows.h>
#include<string>
#include<fstream>
using namespace std;

bool stringCompare(char A1[], char A2[])
{
	int s1 = strlen(A1);
	int s2 = strlen(A2);

	if (s1 == s2)
	{
		for (int i = 0; A1[i] != 0; i++)
		{
			if (A1[i] != A2[i])
				return false;
		}
		return true;
	}
	return false;
}
void setColor(unsigned short color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void myoutline(int x1, int y1, int color)
{
	// x=180 y=40
	// x main difference 50 y main 10
	// x main difference 50 y main 10

	myRect(x1, y1, x1 + 50, y1 + 2, 255, 255, 255, 255, 255, 255);
	myRect(x1, y1 + 20, x1 + 50, y1 + 25, 255, 255, 255, 255, 255, 255);
	myRect(x1, y1, x1 + 5, y1 + 25, 255, 255, 255, 255, 255, 255);
	myRect(x1 + 50, y1, x1 + 55, y1 + 25, 255, 255, 255, 255, 255, 255);
}

struct node
{
	int row;
	int col;
	node* next;
};
class LL
{
private:
	node* first;

public:

	LL()
	{
		first = nullptr;
	}

	void insert(int r, int c)
	{
		node* temp = new node;
		temp->row = r;
		temp->col = c;
		temp->next = nullptr;

		if (first == nullptr)
			first = temp;
		else
		{
			node* curr = first;
			while (curr->next != 0)
			{
				curr = curr->next;
			}

			curr->next = temp;
		}
	}

	bool isValid(int r, int c)
	{
		node* curr = first;

		while (curr != 0)
		{
			if (curr->row == r && curr->col == c)
				return true;
			curr = curr->next;
		}
		return false;
	}
};

class Piece
{
private:
	char Name[10];

public:
	Piece(const char N[])
	{
		strcpy_s(Name, N);
	}

	virtual void Print()
	{
		cout << Name;
	}

	char* GetName()
	{
		return Name;
	}

	virtual bool Movement(Piece*** P, int player, int r, int c, bool& gameOver)
	{
		P[r - 2][c] = P[r][c];
		P[r][c] = NULL;
		return true;
	}

};

//-->1
class King :public Piece
{
public:
	King(const char N[]) :Piece(N)
	{

	}
	void Print() {
		Piece::Print();
	}
	void GetName()
	{
		Piece::GetName();
	}
	bool Movement(Piece*** P, int player, int r, int c, bool &gameOver)
	{

		if (player == 1)
		{
			LL Pos;
			Piece* temp;
			bool flag = 0;

			if (r - 1 >= 0) // upper bound
			{
				temp = P[r - 1][c];
				if (temp)
				{
					char* arr = temp->GetName();

					if (temp == NULL || arr[1] == '2')
					{
						flag = 1;
						//cout << "R:" << r - 1 << "C:" << c;
						cout << r - 1 << " " << c << " , ";
						Pos.insert(r - 1, c);
					}

				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << r - 1 << "C:" << c;
					cout << r - 1 << " " << c << " , ";
					Pos.insert(r - 1, c);
				}
			}

			if (r + 1 <= 7) // lower bound
			{
				temp = P[r + 1][c];
				if (temp)
				{
					char* arr = temp->GetName();

					if (temp == NULL || arr[1] == '2')
					{
						flag = 1;
						//cout << "R:" << r + 1 << "C:" << c;
						cout << r + 1 << " " << c << " , ";
						Pos.insert(r + 1, c);
					}

				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << r + 1 << "C:" << c;
					cout << r + 1 << " " << c << " , ";
					Pos.insert(r + 1, c);
				}
			}

			if (c + 1 <= 7) // right bound
			{
				Piece* temp;
				temp = P[r][c + 1];
				if (temp)
				{
					char* arr = temp->GetName();
					if (temp == NULL || arr[1] == '2')
					{
						flag = 1;
						//cout << "R:" << r << "C:" << c + 1;
						cout << r << " " << c + 1 << " , ";
						Pos.insert(r, c + 1);
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << r << "C:" << c + 1;
					cout << r << " " << c + 1 << " , ";
					Pos.insert(r, c + 1);
				}
			}
			if (c - 1 >= 0) // left bound
			{
				Piece* temp;
				temp = P[r][c - 1];
				if (temp)
				{
					char* arr = temp->GetName();

					if (temp == NULL || arr[1] == '2')
					{
						flag = 1;
						//cout << "R:" << r << "C:" << c - 1;
						cout << r << " " << c - 1 << " , ";
						Pos.insert(r, c - 1);
					}
				}
				if (temp == NULL )
				{
					flag = 1;
					//cout << "R:" << r << "C:" << c - 1;
					cout << r << " " << c - 1 << " , ";
					Pos.insert(r, c - 1);
				}
			}
			if (c - 1 >= 0 && r - 1 >= 0)
			{
				temp = P[r - 1][c - 1];
				if (temp)
				{
					char* arr = temp->GetName();
					if (temp == NULL || arr[1] == '2')
					{
						flag = 1;
						//cout << "R:" << r - 1 << "C:" << c - 1;
						cout << r - 1 << " " << c - 1 << " , ";
						Pos.insert(r - 1, c - 1);
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << r - 1 << "C:" << c - 1;
					cout << r - 1 << " " << c - 1 << " , ";
					Pos.insert(r - 1, c - 1);
				}

			}
			if (c + 1 <= 7 && r - 1 >= 0)
			{
				temp = P[r - 1][c + 1];
				if (temp)
				{
					char* arr = temp->GetName();

					if (temp == NULL || arr[1] == '2')
					{
						flag = 1;
						//cout << "R:" << r - 1 << "C:" << c + 1;
						cout << r - 1 << " " << c + 1 << " , ";
						Pos.insert(r - 1, c + 1);
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << r - 1 << "C:" << c + 1;
					cout << r - 1 << " " << c + 1 << " , ";
					Pos.insert(r - 1, c + 1);
				}
			}

			if (r + 1 <= 7 && c - 1 >= 0)
			{

				temp = P[r + 1][c - 1];
				if (temp)
				{
					char* arr = temp->GetName();

					if (temp == NULL || arr[1] == '2')
					{
						flag = 1;
						//cout << "R:" << r + 1 << "C:" << c - 1;
						cout << r + 1 << " " << c - 1 << " , ";
						Pos.insert(r + 1, c - 1);
					}

				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << r + 1 << "C:" << c - 1;
					cout << r + 1 << " " << c - 1 << " , ";
					Pos.insert(r + 1, c - 1);
				}

			}
			if (r + 1 <= 7 && c + 1 <= 7)
			{
				temp = P[r + 1][c + 1];
				if (temp)
				{
					char* arr = temp->GetName();

					if (temp == NULL || arr[1] == '2')
					{
						flag = 1;
						//cout << "R:" << r + 1 << "C:" << c + 1;
						cout << r + 1 << " " << c + 1 << " , ";
						Pos.insert(r + 1, c + 1);
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << r + 1 << "C:" << c + 1;
					cout << r + 1 << " " << c + 1 << " , ";
					Pos.insert(r + 1, c + 1);
				}
			}
			if (flag == 1)
			{

				char option;
				cout << "\nIf you want to change piece press Y ELSE press N " << endl;
				cin >> option;
				if (option == 'y' || option == 'Y')
				{
					cout << "\nYou have entered yes to change the piece so enter new positions" << endl;
					return false;
				}
				else if (option == 'n' || option == 'N')
				{
					cout << "Fine you do not want to change your piece...";
					int row = 0;
					int col = 0;


					bool valid = 0;

					while (!valid)
					{
						cout << "\nSELECT A POSITION FROM AVAILABLE POSITIONS:\n";
						cout << "Row:";
						cin >> row;
						cout << "Col:";
						cin >> col;

						valid = Pos.isValid(row, col);
						if (valid == 0)
						{
							cout << "this position is invalid please ";
						}
					}

					if (P[row][col]) {
						char* arr;
						arr = P[row][col]->GetName();
						char arr1[] = "K2";
						if (stringCompare(arr1, arr))
						{
							gameOver = 1;
						}
					}

					P[row][col] = P[r][c];
					P[r][c] = NULL;
				}
			}
			else
			{
				cout << "\nNO AVAILABLE POSITIONS\n";
				return false;
			}
			return true;
		}

		if (player == 2)
		{
			Piece* temp;
			bool flag = 0;
			LL Pos;
			if (r - 1 >= 0) // upper bound
			{
				temp = P[r - 1][c];
				if (temp)
				{
					char* arr = temp->GetName();
					if (temp == NULL || arr[1] == '1')
					{
						flag = 1;
						//cout << "R:" << r - 1 << "C:" << c;
						cout << r - 1 << " " << c << " , ";
						Pos.insert(r - 1, c);
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << r - 1 << "C:" << c;
					cout << r - 1 << " " << c << " , ";
					Pos.insert(r - 1, c);
				}
			}
			if (r + 1 <= 7) // lower bound
			{

				temp = P[r + 1][c];
				if (temp)
				{
					char* arr = temp->GetName();
					if (temp == NULL || arr[1] == '1')
					{
						flag = 1;
						//cout << "R:" << r + 1 << "C:" << c;
						cout << r + 1 << " " << c << " , ";
						Pos.insert(r + 1, c);
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << r + 1 << "C:" << c;
					cout << r + 1 << " " << c << " , ";
					Pos.insert(r + 1, c);
				}
			}
			if (c + 1 <= 7) // right bound
			{
				temp = P[r][c + 1];
				if (temp)
				{
					char* arr = temp->GetName();

					if (temp == NULL || arr[1] == '1')
					{
						flag = 1;
						cout << "R:" << r << "C:" << c + 1;
						cout << r << " " << c + 1 << " , ";
						Pos.insert(r, c + 1);
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					cout << "R:" << r << "C:" << c + 1;
					cout << r << " " << c + 1 << " , ";
					Pos.insert(r, c + 1);
				}
			}
			if (c - 1 >= 0) // left bound
			{
				temp = P[r][c - 1];
				if (temp)
				{
					char* arr = temp->GetName();

					if (temp == NULL || arr[1] == '1')
					{

						flag = 1;
						cout << "R:" << r << "C:" << c - 1;
						Pos.insert(r, c - 1);
					}
				}
				if (temp == NULL)
				{

					flag = 1;
					cout << "R:" << r << "C:" << c - 1;
					Pos.insert(r, c - 1);
				}
			}
			if (c - 1 >= 0 && r - 1 >= 0)
			{
				temp = P[r - 1][c - 1];
				if (temp)
				{
					char* arr = temp->GetName();

					if (temp == NULL || arr[1] == '1')
					{
						flag = 1;
						//cout << "R:" << r - 1 << "C:" << c - 1;
						cout << r - 1 << " " << c - 1 << " , ";
						Pos.insert(r - 1, c - 1);
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << r - 1 << "C:" << c - 1;
					cout << r - 1 << " " << c - 1 << " , ";
					Pos.insert(r - 1, c - 1);
				}
			}

			if (c + 1 <= 7 && r - 1 >= 0)
			{
				temp = P[r - 1][c + 1];
				if (temp)
				{
					char* arr = temp->GetName();
					if (temp == NULL || arr[1] == '1')
					{
						flag = 1;
						//cout << "R:" << r - 1 << "C:" << c + 1;
						cout << r - 1 << " " << c + 1 << " , ";
						Pos.insert(r - 1, c + 1);
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << r - 1 << "C:" << c + 1;
					cout << r - 1 << " " << c + 1 << " , ";
					Pos.insert(r - 1, c + 1);
				}
			}

			if (r + 1 <= 7 && c - 1 >= 0)
			{

				temp = P[r + 1][c - 1];
				if (temp)
				{
					char* arr = temp->GetName();

					if (temp == NULL || arr[1] == '1')
					{
						flag = 1;
						//	cout << "R:" << r + 1 << "C:" << c - 1;
						cout << r + 1 << " " << c - 1 << " , ";
						Pos.insert(r + 1, c - 1);
					}
				}

				if (temp == NULL)
				{
					flag = 1;
					//	cout << "R:" << r + 1 << "C:" << c - 1;
					cout << r + 1 << " " << c - 1 << " , ";
					Pos.insert(r + 1, c - 1);
				}
			}

			if (r + 1 <= 7 && c + 1 <= 7)
			{

				temp = P[r + 1][c + 1];
				if (temp)
				{
					char* arr = temp->GetName();

					if (temp == NULL || arr[1] == '1')
					{
						flag = 1;
						//cout << "R:" << r + 1 << "C:" << c + 1;
						cout << r + 1 << " " << c + 1 << " , ";
						Pos.insert(r + 1, c + 1);

					}
				}
				if (temp == NULL )
				{
					flag = 1;
					//cout << "R:" << r + 1 << "C:" << c + 1;
					cout << r + 1 << " " << c + 1 << " , ";
					Pos.insert(r + 1, c + 1);

				}
			}

			if (flag == 1)
			{

				char option;
				cout << "\nIf you want to change piece press Y ELSE press N" << endl;
				cin >> option;
				if (option == 'y' || option == 'Y')
				{
					cout << "\nYou have entered yes to change the piece so enter new positions" << endl;
					return false;
				}
				else if (option == 'n' || option == 'N')
				{
					cout << "Fine you do not want to change your piece...";
					int row = 0;
					int col = 0;
					bool valid = 0;

					while (!valid)
					{
						cout << "\nSELECT A POSITION FROM AVAILABLE POSITIONS:\n";
						cout << "Row:";
						cin >> row;
						cout << "Col:";
						cin >> col;

						valid = Pos.isValid(row, col);
						if (valid == 0)
						{
							cout << "this position is invalid please ";
						}
					}

					if (P[row][col])
					{
						char* arr;
						arr = P[row][col]->GetName();
						char arr1[] = "K1";
						if (stringCompare(arr1, arr))
						{
							gameOver = 1;
						}
					}

					P[row][col] = P[r][c];
					P[r][c] = NULL;
				}
			}
			else
			{
				cout << "\nNO AVAILABLE POSITIONS\n";
				return false;
			}
			return true;
		}
	}
};

//-->2
class Queen :public Piece
{
public:
	Queen(const char N[]) :Piece(N)
	{

	}
	void Print()
	{
		Piece::Print();
	}
	void GetName()
	{
		Piece::GetName();
	}
	bool Movement(Piece*** P, int player, int r, int c, bool &gameOver)
	{
		if (player == 1)
		{
			LL POS;
			Piece *temp;
			bool flag = 0;
			int i = r;
			cout << "Available positions" << endl;
			while (i < 7) // DOWN
			{
				temp = P[i + 1][c];
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '2')
					{

						flag = 1;
						//cout << "R:" << i + 1 << "C:" << c;
						cout << i + 1 << " " << c << " , ";
						POS.insert(i + 1, c);
						break;

					}
				}
				char* arr = temp->GetName();
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '1')
					{
						break;
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << i + 1 << "C:" << c;
					cout << i + 1 << " " << c << " , ";
					POS.insert(i + 1, c);
				}

				i++;
			}
			i = r;

			while (i > 0) // UP
			{
				temp = P[i - 1][c];
				if (temp) 
				{
					char* arr = temp->GetName();
					if (arr[1] == '2')
					{
						flag = 1;
						//cout << "R:" << i - 1 << "C:" << c;
						cout << i - 1 << " " << c << " , ";
						POS.insert(i - 1, c);
						break;

					}
				}
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '1')
					{
						break;
					}
				}

				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << i - 1 << "C:" << c;
					cout << i - 1 << " " << c << " , ";
					POS.insert(i - 1, c);

				}

				i--;

			}

			i = r;
			int j = c;
			while (j < 7) //righht
			{
				temp = P[i][j + 1];
				if (temp) 
				{
					char* arr = temp->GetName();
					if (arr[1] == '2')
					{
						flag = 1;
						//cout << "R:" << i << "C:" << j + 1;
						cout << i << " " << j + 1 << " , ";
						POS.insert(i, j + 1);
						break;
					}
				}
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '1')
					{
						break;
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << i << "C:" << j + 1;
					cout << i << " " << j + 1 << " , ";
					POS.insert(i, j + 1);
				}

				j++;
			}
			i = r;
			j = c;
			while (j > 0) //left
			{
				temp = P[i][j - 1];
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '2')
					{
						flag = 1;
						//cout << "R:" << i << "C:" << j - 1;
						cout << i << " " << j - 1 << " , ";
						POS.insert(i, j - 1);
						break;

					}
				}
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '1')
					{
						break;
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << i << "C:" << j - 1;
					cout << i << " " << j - 1 << " , ";
					POS.insert(i, j - 1);
				}

				j--;
			}
			i = r;
			j = c;
			while (i < 7 && j < 7) // Right DOWN
			{
				temp = P[i + 1][j + 1];
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '2')
					{
						flag = 1;
						//cout << "R:" << i + 1 << "C:" << j + 1;
						cout << i + 1 << " " << j + 1 << " , ";
						POS.insert(i + 1, j + 1);
						break;

					}
				}
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '1')
					{
						break;
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << i + 1 << "C:" << j + 1;
					cout << i + 1 << " " << j + 1 << " , ";
					POS.insert(i + 1, j + 1);
				}
				i++;
				j++;
			}

			i = r;
			j = c;

			while (i > 0 && j > 0) // UP LEFT
			{
				temp = P[i - 1][j - 1];
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '2')
					{
						flag = 1;
						//cout << "R:" << i - 1 << "C:" << j - 1;
						cout << i - 1 << " " << j - 1 << " , ";
						POS.insert(i - 1, j - 1);
						break;

					}
				}
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '1')
					{
						break;
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					cout << "R:" << i - 1 << "C:" << j - 1;
					POS.insert(i - 1, j - 1);
				}

				i--;
				j--;

			}

			i = r;
			j = c;
			while (i > 0 && j < 7) //right up
			{
				temp = P[i - 1][j + 1];
				if (temp) {
					char* arr = temp->GetName();
					if (arr[1] == '2')
					{
						flag = 1;
						//cout << "R:" << i - 1 << "C:" << j + 1;
						cout << i - 1 << " " << j + 1 << " , ";
						POS.insert(i - 1, j + 1);
						break;

					}
				}
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '1')
					{
						break;
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << i - 1 << "C:" << j + 1;
					cout << i - 1 << " " << j + 1 << " , ";
					POS.insert(i - 1, j + 1);
				}

				i--;
				j++;
			}
			i = r;
			j = c;
			while (j > 0 && i < 7) //left down
			{
				temp = P[i + 1][j - 1];
				if (temp) {
					char* arr = temp->GetName();
					if (arr[1] == '2')
					{
						flag = 1;
						//cout << "R:" << i + 1 << "C:" << j - 1;
						cout << i + 1 << " " << j - 1 << " , ";
						POS.insert(i + 1, j - 1);
						break;

					}
				}
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '1')
					{
						break;
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << i + 1 << "C:" << j - 1;
					cout << i + 1 << " " << j - 1 << " , ";
					POS.insert(i + 1, j - 1);
				}

				i++;
				j--;
			}


			if (flag == 1)
			{
				char option;
				cout << "\nIf you want to change piece Press Y else press N" << endl;
				cin >> option;
				if (option == 'y' || option == 'Y')
				{
					cout << "\nYou have entered yes to change the piece so enter new positions" << endl;
					return false;
				}
				else if (option == 'n' || option == 'N')
				{
					cout << "Fine you do not want to change your piece...";
					int row = 0;
					int col = 0;
					bool valid = 0;
					while (!valid)
					{
						cout << "\nSELECT A POSITION FROM AVAILABLE POSITIONS:\n";
						cout << "Row:";
						cin >> row;
						cout << "Col:";
						cin >> col;

						valid = POS.isValid(row, col);
						if (valid == 0)
						{
							cout << "this position is invalid please ";
						}
					}

					if (P[row][col]) {
						char* arr;
						arr = P[row][col]->GetName();
						char arr1[] = "K2";
						if (stringCompare(arr1, arr))
						{
							gameOver = 1;
						}
					}

					P[row][col] = P[r][c];
					P[r][c] = NULL;
				}
			}
			else
			{
				cout << "\nNO AVAILABLE POSITIONS\n";
				return false;
			}
			return true;
		}

		if (player == 2)
		{
			Piece *temp;
			bool flag = 0;
			LL Pos;
			int i = r;
			cout << "Available positions" << endl;
			// DOWN
			while (i < 7)
			{
				temp = P[i + 1][c];
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '1')
					{
						flag = 1;
						//cout << "R:" << i + 1 << "C:" << c;
						cout << i + 1 << " " << c << " , ";
						Pos.insert(i + 1, c);
						break;

					}
				}
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '2')
					{
						break;
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					cout << "R:" << i + 1 << "C:" << c;
					Pos.insert(i + 1, c);
				}

				i++;
			}
			i = r;
			// UP
			while (i > 0)
			{
				temp = P[i - 1][c];
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '1')
					{
						flag = 1;
						//cout << "R:" << i - 1 << "C:" << c;
						cout << i - 1 << " " << c << " , ";
						Pos.insert(i - 1, c);
						break;

					}
				}
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '2')
					{
						break;
					}
				}

				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << i - 1 << "C:" << c;
					cout << i - 1 << " " << c << " ";
					Pos.insert(i - 1, c);
				}

				i--;

			}
			i = r;
			int j = c;
			//righht
			while (j < 7)
			{
				temp = P[i][j + 1];
				if (temp) {
					char* arr = temp->GetName();
					if (arr[1] == '1')
					{
						flag = 1;
						//cout << "R:" << i << "C:" << j + 1;
						cout << i << " " << j + 1 << " , ";
						Pos.insert(i, j + 1);
						break;

					}
				}
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '2')
					{
						break;
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << i << "C:" << j + 1;
					cout << i << " " << j + 1 << " , ";
					Pos.insert(i, j + 1);
				}

				j++;
			}
			i = r;
			j = c;
			//left
			while (j > 0)
			{
				temp = P[i][j - 1];
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '1')
					{
						flag = 1;
						//cout << "R:" << i << "C:" << j - 1;
						cout << i << " " << j - 1 << " , ";
						Pos.insert(i, j - 1);
						break;

					}
				}
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '2')
					{
						break;
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << i << "C:" << j - 1;
					cout << i << " " << j - 1 << " , ";
					Pos.insert(i, j - 1);
				}

				j--;
			}
			i = r;
			j = c;
			// Right DOWN
			while (i < 7 && j < 7)
			{
				temp = P[i + 1][j + 1];
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '1')
					{
						flag = 1;
						//cout << "R:" << i + 1 << "C:" << j + 1;
						cout << i + 1 << " " << j + 1 << " , ";
						Pos.insert(i + 1, j + 1);
						break;

					}
				}
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '2')
					{
						break;
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << i + 1 << "C:" << j + 1;
					cout << i + 1 << " " << j + 1 << " , ";
					Pos.insert(i + 1, j + 1);
				}

				i++;
				j++;
			}
			i = r;
			j = c;
			// UP LEFT
			while (i > 0 && j > 0)
			{
				temp = P[i - 1][j - 1];
				if (temp) {
					char* arr = temp->GetName();
					if (arr[1] == '1')
					{
						flag = 1;
						//cout << "R:" << i - 1 << "C:" << j - 1;
						cout << i - 1 << " " << j - 1 << " , ";
						Pos.insert(i - 1, j - 1);
						break;

					}
				}
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '2')
					{
						break;
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << i - 1 << "C:" << j - 1;
					cout << i - 1 << " " << j - 1 << " , ";
					Pos.insert(i - 1, j - 1);
				}

				i--;
				j--;

			}
			i = r;
			j = c;
			//righht up
			while (i > 0 && j < 7)
			{
				temp = P[i - 1][j + 1];
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '1')
					{
						flag = 1;
						//cout << "R:" << i - 1 << "C:" << j + 1;
						cout << i - 1 << " " << j + 1 << " , ";
						Pos.insert(i - 1, j + 1);
						break;

					}
				}
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '2')
					{
						break;
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << i - 1 << "C:" << j + 1;
					cout << i - 1 << " " << j + 1 << " , ";
					Pos.insert(i - 1, j + 1);
				}

				i--;
				j++;
			}
			i = r;
			j = c;
			//left down
			while (j > 0 && i < 7)
			{
				temp = P[i + 1][j - 1];
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '1')
					{
						flag = 1;
						//cout << "R:" << i + 1 << "C:" << j - 1;
						cout << i + 1 << " " << j - 1 << " , ";
						Pos.insert(i + 1, j - 1);
						break;

					}
				}
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '2')
					{
						break;
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << i + 1 << "C:" << j - 1;
					cout << i + 1 << " " << j - 1 << " , ";
					Pos.insert(i + 1, j - 1);
				}

				i++;
				j--;
			}

			if (flag == 1)
			{

				char option;
				cout << "\nIf you want to change piece Press  Y ELSE press N" << endl;
				cin >> option;
				if (option == 'y' || option == 'Y')
				{
					cout << "\nYou have entered yes to change the piece so enter new positions" << endl;
					return false;
				}
				else if (option == 'n' || option == 'N')
				{
					cout << "Fine you do not want to change your piece...";
					int row = 0;
					int col = 0;

					bool valid = 0;

					while (!valid)
					{
						cout << "\nSELECT A POSITION FROM AVAILABLE POSITIONS:\n";
						cout << "Row:";
						cin >> row;
						cout << "Col:";
						cin >> col;

						valid = Pos.isValid(row, col);
						if (valid == 0)
						{
							cout << "this position is invalid please ";
						}
					}

					if (P[row][col]) {
						char* arr;
						arr = P[row][col]->GetName();
						char arr1[] = "K1";
						if (stringCompare(arr1, arr))
						{
							gameOver = 1;
						}
					}

					P[row][col] = P[r][c];
					P[r][c] = NULL;
				}
			}
			else
			{
				cout << "NO AVAILABLE POSITIONS\n";
				return false;
			}
			return true;
		}

	}
};

//-->3
class Knight :public Piece
{
public:
	Knight(const char N[]) :Piece(N)
	{

	}
	void Print() {
		Piece::Print();
	}

	void GetName()
	{
		Piece::GetName();
	}
	bool Movement(Piece*** P, int player, int r, int c, bool& gameOver)
	{
		if (player == 1)
		{
			LL Pos;
			Piece* temp;
			bool flag = 0;

			if (r - 2 >= 0 && c + 1 <= 7) // upper right bound
			{
				temp = P[r - 2][c + 1];
				if (temp)
				{
					char* arr = temp->GetName();

					if (arr[1] == '2')
					{
						flag = 1;
						//cout << "R:" << r - 2 << "C:" << c + 1;
						cout << r - 2 << " " << c + 1 << " , ";
						Pos.insert(r - 2, c + 1);
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << r - 2 << "C:" << c + 1;
					cout << r - 2 << " " << c + 1 << " , ";
					Pos.insert(r - 2, c + 1);
				}
			}
			if (r - 2 >= 0 && c - 1 >= 0) // upper left bound
			{
				temp = P[r - 2][c - 1];
				if (temp)
				{
					char* arr = temp->GetName();

					if (arr[1] == '2')
					{
						flag = 1;
						//cout << "R:" << r - 2 << "C:" << c - 1;
						cout << r - 2 << " " << c - 1 << " , ";
						Pos.insert(r - 2, c - 1);
					}
				}
				if (temp==NULL)
				{
					flag = 1;
					//cout << "R:" << r - 2 << "C:" << c - 1;
					cout << r - 2 << " " << c - 1 << " , ";
					Pos.insert(r - 2, c - 1);
				}

			}
			if (r + 2 <= 7 && c + 1 <= 7) // lower right bound
			{

				temp = P[r + 2][c + 1];
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '2')
					{
						flag = 1;
						//cout << "R:" << r + 2 << "C:" << c + 1;
						cout << r + 2 << " " << c + 1 << " , ";
						Pos.insert(r + 2, c + 1);
					}

				}
				if(temp == NULL)
				{ 
					flag = 1;
					//cout << "R:" << r + 2 << "C:" << c + 1;
					cout << r + 2 << " " << c + 1 << " , ";
					Pos.insert(r + 2, c + 1);
				}
			}
			if (r + 2 <= 7 && c - 1 >= 0) // lower left bound
			{

				temp = P[r + 2][c - 1];
				if (temp)
				{
					char* arr = temp->GetName();
					if (temp == NULL || arr[1] == '2')
					{
						flag = 1;
						//cout << "R:" << r + 2 << "C:" << c - 1;
						cout << r + 2 << " " << c - 1 << " , ";
						Pos.insert(r + 2, c - 1);
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << r + 2 << "C:" << c - 1;
					cout << r + 2 << " " << c - 1 << " , ";
					Pos.insert(r + 2, c - 1);
				}
			}
			if (r + 1 <= 7 && c + 2 <= 7) // right down bound
			{
				temp = P[r + 1][c + 2];
				if (temp)
				{
					char* arr = temp->GetName();

					if (arr[1] == '2')
					{
						flag = 1;
						//cout << "R:" << r + 1 << "C:" << c + 2;
						cout << r + 2 << " " << c + 2 << " , ";
						Pos.insert(r + 1, c + 2);
					}

				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << r + 1 << "C:" << c + 2;
					cout << r + 2 << " " << c + 2 << " , ";
					Pos.insert(r + 1, c + 2);
				}
			}
			if (r - 1 >= 0 && c + 2 <= 7) //  right up bound
			{

				temp = P[r - 1][c + 2];
				if (temp)
				{
					char* arr = temp->GetName();

					if (temp == NULL || arr[1] == '2')
					{
						flag = 1;
						//cout << "R:" << r - 1 << "C:" << c + 2;
						cout << r - 1 << " " << c + 2 << " , ";
						Pos.insert(r - 1, c + 2);
					}

				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << r - 1 << "C:" << c + 2;
					cout << r - 1 << " " << c + 2 << " , ";
					Pos.insert(r - 1, c + 2);
				}

			}
			if (r + 1 <= 7 && c - 2 >= 0) // left down bound
			{

				temp = P[r + 1][c - 2];
				if (temp)
				{
					char* arr = temp->GetName();

					if (arr[1] == '2')
					{
						flag = 1;
						//	cout << "R:" << r + 1 << "C:" << c - 2;
						cout << r + 1 << " " << c - 2 << " , ";
						Pos.insert(r + 1, c - 2);
					}

				}

				if (temp == NULL)
				{
					flag = 1;
					//	cout << "R:" << r + 1 << "C:" << c - 2;
					cout << r + 1 << " " << c - 2 << " , ";
					Pos.insert(r + 1, c - 2);
				}
			}
			if (r - 1 >= 0 && c - 2 >= 0) // left up bound
			{

				temp = P[r - 1][c - 2];
				if (temp)
				{
					char* arr = temp->GetName();
					if (temp == NULL || arr[1] == '2')
					{
						flag = 1;
						//cout << "R:" << r - 1 << "C:" << c - 2;
						cout << r - 1 << " " << c - 2 << " , ";
						Pos.insert(r - 1, c - 2);
					}

				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << r - 1 << "C:" << c - 2;
					cout << r - 1 << " " << c - 2 << " , ";
					Pos.insert(r - 1, c - 2);
				}
			}
			if (flag == 1)
			{

				char option;
				cout << "\nIf you want to change piece enter Y" << endl;
				cin >> option;
				if (option == 'y' || option == 'Y')
				{
					cout << "\nYou have entered yes to change the piece so enter new positions" << endl;
					return false;
				}
				else if (option == 'n' || option == 'N')
				{
					cout << "Fine you do not want to change your piece...";
					int row = 0;
					int col = 0;
					bool valid = 0;

					while (!valid)
					{
						cout << "\nSELECT A POSITION FROM AVAILABLE POSITIONS:\n";
						cout << "Row:";
						cin >> row;
						cout << "Col:";
						cin >> col;

						valid = Pos.isValid(row, col);
						if (valid == 0)
						{
							cout << "this position is invalid please ";
						}
					}

					if (P[row][col]) 
					{
						char* arr;
						arr = P[row][col]->GetName();
						char arr1[] = "K2";
						if (stringCompare(arr1, arr))
						{
							gameOver = 1;
						}
					}

					P[row][col] = P[r][c];
					P[r][c] = NULL;
				}
			}
			else
			{
				cout << "\nNO AVAILABLE POSITIONS\n";
				return false;
			}
			return true;

		}

		if (player == 2)
		{
			LL Pos;
			Piece* temp;
			bool flag = 0;

			if (r - 2 >= 0 && c + 1 <= 7) // upper right bound
			{

				temp = P[r - 2][c + 1];
				if (temp)
				{
					char* arr = temp->GetName();
					if (temp == NULL || arr[1] == '1')
					{
						flag = 1;
						//cout << "R:" << r - 2 << "C:" << c + 1;
						cout << r - 2 << " " << c + 1 << " , ";
						Pos.insert(r - 2, c + 1);
					}

				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << r - 2 << "C:" << c + 1;
					cout << r - 2 << " " << c + 1 << " , ";
					Pos.insert(r - 2, c + 1);
				}
			}
			if (r - 2 >= 0 && c - 1 >= 0) // upper left bound
			{

				temp = P[r - 2][c - 1];
				if (temp)
				{
					char* arr = temp->GetName();

					if(arr[1] == '1')
					{
						flag = 1;
						//cout << "R:" << r - 2 << "C:" << c - 1;
						cout << r - 2 << " " << c - 1 << " , ";
						Pos.insert(r - 2, c - 1);
					}

				}

				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << r - 2 << "C:" << c - 1;
					cout << r - 2 << " " << c - 1 << " , ";
					Pos.insert(r - 2, c - 1);
				}

			}
			if (r + 2 <= 7 && c + 1 <= 7) // lower right bound
			{

				temp = P[r + 2][c + 1];
				if (temp)
				{
					char* arr = temp->GetName();

					if (temp == NULL || arr[1] == '1')
					{
						flag = 1;
						//cout << "R:" << r + 2 << "C:" << c + 1;
						cout << r + 2 << " " << c + 1 << " , ";
						Pos.insert(r + 2, c + 1);
					}

				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << r + 2 << "C:" << c + 1;
					cout << r + 2 << " " << c + 1 << " , ";
					Pos.insert(r + 2, c + 1);
				}

			}
			if (r + 2 <= 7 && c - 1 >= 0) // lower left bound
			{

				temp = P[r + 2][c - 1];
				if (temp)
				{
					char* arr = temp->GetName();

					if (temp == NULL || arr[1] == '1')
					{
						flag = 1;
						//cout << "R:" << r + 2 << "C:" << c - 1;
						cout << r + 2 << " " << c - 1 << " , ";
						Pos.insert(r + 2, c - 1);
					}

				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << r + 2 << "C:" << c - 1;
					cout << r + 2 << " " << c - 1 << " , ";
					Pos.insert(r + 2, c - 1);
				}
			}
			if (r + 1 <= 7 && c + 2 <= 7) // right down bound
			{

				temp = P[r + 1][c + 2];
				if (temp)
				{
					char* arr = temp->GetName();

					if (temp == NULL || arr[1] == '1')
					{
						flag = 1;
						//	cout << "R:" << r + 1 << "C:" << c + 2;
						cout << r + 1 << " " << c + 2 << " , ";
						Pos.insert(r + 1, c + 2);
					}

				}
				if (temp == NULL)
				{
					flag = 1;
					//	cout << "R:" << r + 1 << "C:" << c + 2;
					cout << r + 1 << " " << c + 2 << " , ";
					Pos.insert(r + 1, c + 2);
				}
			}
			if (r - 1 >= 0 && c + 2 <= 7) //  right up bound
			{

				temp = P[r - 1][c + 2];
				if (temp)
				{
					char* arr = temp->GetName();

					if (temp == NULL || arr[1] == '1')
					{
						flag = 1;
						//cout << "R:" << r - 1 << "C:" << c + 2;
						cout << r - 1 << " " << c + 2 << " , ";
						Pos.insert(r - 1, c + 2);
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << r - 1 << "C:" << c + 2;
					cout << r - 1 << " " << c + 2 << " , ";
					Pos.insert(r - 1, c + 2);
				}
			}
			if (r + 1 <= 7 && c - 2 >= 0) // left down bound
			{

				temp = P[r + 1][c - 2];
				if (temp)
				{
					char* arr = temp->GetName();

					if (temp == NULL || arr[1] == '1')
					{
						flag = 1;
						//  cout << "R:" << r + 1 << "C:" << c - 2;
						cout << r + 1 << " " << c - 2 << " , ";
						Pos.insert(r + 1, c - 2);
					}

				}

				if (temp == NULL)
				{
					flag = 1;
					//  cout << "R:" << r + 1 << "C:" << c - 2;
					cout << r + 1 << " " << c - 2 << " , ";
					Pos.insert(r + 1, c - 2);
				}

			}
			if (r - 1 >= 0 && c - 2 >= 0) // left up bound
			{

				temp = P[r - 1][c - 2];
				if (temp)
				{
					char* arr = temp->GetName();

					if (temp == NULL || arr[1] == '1')
					{
						flag = 1;
						//cout << "R:" << r - 1 << "C:" << c - 2;
						cout << r - 1 << " " << c - 2 << " , ";
						Pos.insert(r - 1, c - 2);
					}

				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << r - 1 << "C:" << c - 2;
					cout << r - 1 << " " << c - 2 << " , ";
					Pos.insert(r - 1, c - 2);
				}
			}
			if (flag == 1)
			{

				char option;
				cout << "\nIf you want to change piece enter Y" << endl;
				cin >> option;
				if (option == 'y' || option == 'Y')
				{
					cout << "\nYou have entered yes to change the piece so enter new positions" << endl;
					return false;
				}
				else if (option == 'n' || option == 'N')
				{
					cout << "Fine you do not want to change your piece...";
					int row = 0;
					int col = 0;
					bool valid = 0;

					while (!valid)
					{
						cout << "\nSELECT A POSITION FROM AVAILABLE POSITIONS:\n";
						cout << "Row:";
						cin >> row;
						cout << "Col:";
						cin >> col;

						valid = Pos.isValid(row, col);
						if (valid == 0)
						{
							cout << "this position is invalid please ";
						}
					}

					if (P[row][col]) {
						char* arr;
						arr = P[row][col]->GetName();
						char arr1[] = "K1";
						if (stringCompare(arr1, arr))
						{
							gameOver = 1;
						}
					}
					P[row][col] = P[r][c];
					P[r][c] = NULL;
				}
			}
			else
			{
				cout << "\nNO AVAILABLE POSITIONS\n";
				return false;
			}
			return true;
		}
	}

};

//-->4
class Rook :public Piece
{
public:
	Rook(const char N[]) :Piece(N)
	{

	}
	void Print() {
		Piece::Print();
	}
	void GetName()
	{
		Piece::GetName();
	}
	bool Movement(Piece*** P, int player, int r, int c, bool& gameOver)
	{
		if (player == 1)
		{
			LL POS;

			Piece *temp;
			bool flag = 0;
			int i = r;
			cout << "Available positions" << endl;
			while (i < 7) // DOWN
			{
				temp = P[i + 1][c];
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '2')
					{
						flag = 1;
						//cout << "R:" << i + 1 << "C:" << c;
						cout << i + 1 << " " << c << " , ";
						POS.insert(i + 1, c);
						break;

					}
				}
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '1')
					{
						break;
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << i + 1 << "C:" << c;
					cout << i + 1 << " " << c << " , ";
					POS.insert(i + 1, c);
				}

				i++;
			}
			i = r;
			while (i > 0) // UP
			{
				temp = P[i - 1][c];
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '2')
					{
						flag = 1;
						//cout << "R:" << i - 1 << "C:" << c;
						cout << i - 1 << " " << c << " , ";
						POS.insert(i - 1, c);
						break;

					}
				}
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '1')
					{
						break;
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << i - 1 << "C:" << c;
					cout << i - 1 << " " << c << " , ";
					POS.insert(i - 1, c);
				}
				i--;

			}

			i = r;
			int j = c;
			while (j < 7) //righht
			{
				temp = P[i][j + 1];
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '2')
					{
						flag = 1;
						//cout << "R:" << i << "C:" << j + 1;
						cout << i << " " << j + 1 << " , ";
						POS.insert(i, j + 1);
						break;

					}
				}
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '1')
					{
						break;
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << i << "C:" << j + 1;
					cout << i << " " << j + 1 << " , ";
					POS.insert(i, j + 1);
				}

				j++;
			}
			i = r;
			j = c;
			while (j > 0) //left
			{
				temp = P[i][j - 1];
				if (temp) {
					char* arr = temp->GetName();
					if (arr[1] == '2')
					{
						flag = 1;
						//cout << "R:" << i << "C:" << j - 1;
						cout << i << " " << j - 1 << " , ";
						POS.insert(i, j - 1);
						break;

					}
				}
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '1')
					{
						break;
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << i << "C:" << j - 1;
					cout << i << " " << j - 1 << " , ";
					POS.insert(i, j - 1);
				}

				j--;
			}

			if (flag == 1)
			{

				char option;
				cout << "\nIf you want to change piece enter Y  ELSE press  n " << endl;
				cin >> option;
				if (option == 'y' || option == 'Y')
				{
					cout << "\nYou have entered yes to change the piece so enter new positions" << endl;
					return false;
				}
				else if (option == 'n' || option == 'N')
				{
					cout << "Fine you do not want to change your piece...";
					int row = 0;
					int col = 0;

					bool valid = 0;

					while (!valid)
					{
						cout << "\nSELECT A POSITION FROM AVAILABLE POSITIONS:\n";
						cout << "Row:";
						cin >> row;
						cout << "Col:";
						cin >> col;

						valid = POS.isValid(row, col);
						if (valid == 0)
						{
							cout << "this position is invalid please ";
						}
					}

					if (P[row][col]) {
						char* arr;
						arr = P[row][col]->GetName();
						char arr1[] = "K2";
						if (stringCompare(arr1, arr))
						{
							gameOver = 1;
						}
					}

					P[row][col] = P[r][c];
					P[r][c] = NULL;
				}
			}
			else
			{
				cout << "\nNO AVAILABLE POSITIONS\n";
				return false;
			}
			return true;


		}
		if (player == 2)
		{
			Piece *temp;
			bool flag = 0;
			LL Pos;
			int i = r;
			cout << "Available positions" << endl;
			while (i < 7) // DOWN
			{
				temp = P[i + 1][c];
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '1')
					{
						flag = 1;
						//cout << "R:" << i + 1 << "C:" << c;
						cout << i + 1 << " " << c << " , ";
						Pos.insert(i + 1, c);
						break;

					}
				}
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '2')
					{
						break;
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << i + 1 << "C:" << c;
					cout << i + 1 << " " << c << " , ";
					Pos.insert(i + 1, c);
				}

				i++;
			}
			i = r;

			while (i > 0) // UP
			{
				temp = P[i - 1][c];
				if (temp) {
					char* arr = temp->GetName();
					if (arr[1] == '1')
					{
						flag = 1;
						//cout << "R:" << i - 1 << "C:" << c;
						cout << i - 1 << " " << c << " , ";
						Pos.insert(i - 1, c);
						break;

					}
				}
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '2')
					{
						break;
					}
				}

				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << i - 1 << "C:" << c;
					cout << i - 1 << " " << c << " , ";
					Pos.insert(i - 1, c);
				}


				i--;

			}

			i = r;
			int j = c;
			while (j < 7) //righht
			{
				temp = P[i][j + 1];
				if (temp) {
					char* arr = temp->GetName();
					if (arr[1] == '1')
					{
						flag = 1;
						//cout << "R:" << i << "C:" << j + 1;
						cout << i << " " << j + 1 << " , ";
						Pos.insert(i, j + 1);
						break;

					}
				}
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '2')
					{
						break;
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << i << "C:" << j + 1;
					cout << i << " " << j + 1 << " , ";
					Pos.insert(i, j + 1);
				}

				j++;
			}
			i = r;
			j = c;
			while (j > 0) //left
			{
				temp = P[i][j - 1];
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '1')
					{
						flag = 1;
						//cout << "R:" << i << "C:" << j - 1;
						cout << i << " " << j - 1 << " , ";
						Pos.insert(i, j - 1);
						break;

					}
				}
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '2')
					{
						break;
					}
				}

				if (temp == NULL)
				{
					flag = 1;
					//	cout << "R:" << i << "C:" << j - 1;
					cout << i << " " << j - 1 << " , ";
					Pos.insert(i, j - 1);
				}

				j--;
			}

			if (flag == 1)
			{
				char option;
				cout << "\nIf you want to change piece enter Y else press N" << endl;
				cin >> option;
				if (option == 'y' || option == 'Y')
				{
					cout << "\nYou have entered yes to change the piece so enter new positions" << endl;
					return false;
				}
				else if (option == 'n' || option == 'N')
				{
					cout << "Fine you do not want to change your piece...";
					int row = 0;
					int col = 0;

					bool valid = 0;

					while (!valid)
					{
						cout << "\nSELECT A POSITION FROM AVAILABLE POSITIONS:\n";
						cout << "Row:";
						cin >> row;
						cout << "Col:";
						cin >> col;

						valid = Pos.isValid(row, col);
						if (valid == 0)
						{
							cout << "this position is invalid please ";
						}
					}

					if (P[row][col]) {
						char* arr;
						arr = P[row][col]->GetName();
						char arr1[] = "K1";
						if (stringCompare(arr1, arr))
						{
							gameOver = 1;
						}
					}

					P[row][col] = P[r][c];
					P[r][c] = NULL;
				}
			}
			else
			{
				cout << "NO AVAILABLE POSITIONS\n";
				return false;
			}
			return true;
		}

	}
};

////-->5
class Bishap : public Piece
{
public:
	Bishap(const char N[]) :Piece(N)
	{

	}
	void Print() {
		Piece::Print();
	}
	void GetName()
	{
		Piece::GetName();
	}
	bool Movement(Piece*** P, int player, int r, int c, bool& gameOver)
	{
		if (player == 1)
		{
			LL pos;
			Piece *temp;
			bool flag = 0;
			int i = r;
			int j = c;
			cout << "Available positions" << endl;
			while (i < 7 && j < 7) // Right DOWN
			{
				temp = P[i + 1][j + 1];
				if (temp) 
				{
					char* arr = temp->GetName();
					if (arr[1] == '2')
					{
						flag = 1;
						//cout << "R:" << i + 1 << "C:" << j + 1;
						cout << i + 1 << " " << j + 1 << " , ";
						pos.insert(i + 1, j + 1);
						break;

					}
				}
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '1')
					{
						break;
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << i + 1 << "C:" << j + 1;
					cout << i + 1 << " " << j + 1 << " , ";
					pos.insert(i + 1, j + 1);

				}
				i++;
				j++;
			}

			i = r;
			j = c;

			while (i > 0 && j > 0) // UP LEFT
			{
				temp = P[i - 1][j - 1];
				if (temp) {
					char* arr = temp->GetName();
					if (arr[1] == '2')
					{
						flag = 1;
						//cout << "R:" << i - 1 << "C:" << j - 1;
						cout << i - 1 << " " << j - 1 << " , ";
						pos.insert(i - 1, j - 1);
						break;

					}
				}
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '1')
					{
						break;
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << i - 1 << "C:" << j - 1;
					cout << i - 1 << " " << j - 1 << " , ";
					pos.insert(i - 1, j - 1);
				}

				i--;
				j--;

			}

			i = r;
			j = c;
			while (i > 0 && j < 7) //righht up
			{
				temp = P[i - 1][j + 1];
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '2')
					{
						flag = 1;
						//cout << "R:" << i - 1 << "C:" << j + 1;
						cout << i - 1 << " " << j + 1 << " , ";
						pos.insert(i - 1, j + 1);
						break;

					}
				}
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '1')
					{
						break;
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					cout << "R:" << i - 1 << "C:" << j + 1;
					cout << i - 1 << " " << j + 1 << " , ";
					pos.insert(i - 1, j + 1);
				}

				i--;
				j++;
			}

			while (j > 0 && i < 7) //left down
			{
				temp = P[i + 1][j - 1];
				if (temp) {
					char* arr = temp->GetName();
					if (arr[1] == '2')
					{
						flag = 1;
						//cout << "R:" << i + 1 << "C:" << j - 1;
						cout << i + 1 << " " << j - 1 << " , ";
						pos.insert(i + 1, j - 1);
						break;

					}
				}
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '1')
					{
						break;
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					cout << "R:" << i + 1 << "C:" << j - 1;
					pos.insert(i + 1, j - 1);
				}

				i++;
				j--;
			}

			if (flag == 1)
			{
				char option;
				cout << "\nIf you want to change piece Press Y ELSE press N" << endl;
				cin >> option;
				if (option == 'y' || option == 'Y')
				{
					cout << "\nYou have entered yes to change the piece so enter new positions" << endl;
					return false;
				}
				else if (option == 'n' || option == 'N')
				{
					cout << "Fine you do not want to change your piece...";
					int row = 0;
					int col = 0;
					bool valid = 0;

					while (!valid)
					{
						cout << "\nSELECT A POSITION FROM AVAILABLE POSITIONS:\n";
						cout << "Row:";
						cin >> row;
						cout << "Col:";
						cin >> col;

						valid = pos.isValid(row, col);
						if (valid == 0)
						{
							cout << "this position is invalid please ";
						}
					}

					if (P[row][col]) {
						char* arr;
						arr = P[row][col]->GetName();
						char arr1[] = "K2";
						if (stringCompare(arr1, arr))
						{
							gameOver = 1;
						}
					}
					P[row][col] = P[r][c];
					P[r][c] = NULL;
				}
			}
			else {
				cout << "\nNO AVAILABLE POSITIONS\n";
				return false;
			}
			return true;

		}

		if (player == 2)
		{

			Piece *temp;
			bool flag = 0;
			LL Pos;
			int i = r;
			int j = c;
			cout << "Available positions" << endl;
			while (i < 7 && j < 7) // Right DOWN
			{
				temp = P[i + 1][j + 1];
				if (temp) {
					char* arr = temp->GetName();
					if (arr[1] == '1')
					{
						flag = 1;
						//cout << "R:" << i + 1 << "C:" << j + 1;
						cout << i + 1 << " " << j + 1 << " , ";
						Pos.insert(i + 1, j + 1);
						break;

					}
				}
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '2')
					{
						break;
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << i + 1 << "C:" << j + 1;
					cout << i + 1 << " " << j + 1 << " , ";
					Pos.insert(i + 1, j + 1);
				}

				i++;
				j++;
			}

			i = r;
			j = c;

			while (i > 0 && j > 0) // UP LEFT
			{
				temp = P[i - 1][j - 1];
				if (temp) {
					char* arr = temp->GetName();
					if (arr[1] == '1')
					{
						flag = 1;
						//cout << "R:" << i - 1 << "C:" << j - 1;
						cout << i - 1 << " " << j - 1 << " , ";
						Pos.insert(i - 1, j - 1);
						break;

					}
				}
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '2')
					{
						break;
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					cout << "R:" << i - 1 << "C:" << j - 1;
					Pos.insert(i - 1, j - 1);
				}

				i--;
				j--;

			}

			i = r;
			j = c;
			while (i > 0 && j < 7) //righht up
			{
				temp = P[i - 1][j + 1];
				if (temp) {
					char* arr = temp->GetName();
					if (arr[1] == '1')
					{
						flag = 1;
						//cout << "R:" << i - 1 << "C:" << j + 1;
						cout << i - 1 << " " << j + 1 << " , ";
						Pos.insert(i - 1, j + 1);
						break;

					}
				}
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '2')
					{
						break;
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << i - 1 << "C:" << j + 1;
					cout << i - 1 << " " << j + 1 << " , ";
					Pos.insert(i - 1, j + 1);
				}

				i--;
				j++;
			}
			i = r;
			j = c;
			while (j > 0 && i < 7) //left down
			{
				temp = P[i + 1][j - 1];
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '1')
					{
						flag = 1;
						//cout << "R:" << i + 1 << "C:" << j - 1;
						cout << i + 1 << " " << j - 1 << " , ";
						Pos.insert(i + 1, j - 1);
						break;

					}
				}
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '2')
					{
						break;
					}
				}
				if (temp == NULL)
				{
					flag = 1;
					//cout << "R:" << i + 1 << "C:" << j - 1;
					cout << i + 1 << " " << j - 1 << " , ";
					Pos.insert(i + 1, j - 1);
				}

				i++;
				j--;
			}

			if (flag == 1)
			{

				char option;
				cout << "\nIf you want to change piece press Y ELSE press N" << endl;
				cin >> option;
				if (option == 'y' || option == 'Y')
				{
					cout << "\nYou have entered yes to change the piece so enter new positions" << endl;
					return false;
				}
				else if (option == 'n' || option == 'N')
				{
					cout << "Fine you do not want to change your piece...";

					int row = 0;
					int col = 0;
					bool valid = 0;

					while (!valid)
					{
						cout << "\nSELECT A POSITION FROM AVAILABLE POSITIONS:\n";
						cout << "Row:";
						cin >> row;
						cout << "Col:";
						cin >> col;

						valid = Pos.isValid(row, col);
						if (valid == 0)
						{
							cout << "this position is invalid please ";
						}
					}
					if (P[row][col]) {
						char* arr;
						arr = P[row][col]->GetName();
						char arr1[] = "K1";
						if (stringCompare(arr1, arr))
						{
							gameOver = 1;
						}
					}
					P[row][col] = P[r][c];
					P[r][c] = NULL;
				}
			}
			else
			{
				cout << "\nNO AVAILABLE POSITIONS\n";
				return false;
			}
			return true;
		}

	}
};

//-->6
class Pawn : public Piece
{
public:
	Pawn(const char N[]) :Piece(N)
	{

	}
	void Print() {
		Piece::Print();
	}
	void GetName()
	{
		Piece::GetName();
	}
	bool Movement(Piece*** P, int player, int r, int c, bool& gameOver)
	{
		LL Pos;
		Piece *temp;
		Piece *temp1;
		bool flag = 0;
		cout << "Available positions" << endl;
		if (player == 1)
		{
			if (r == 1)//first move
			{
				temp = P[r + 2][c];
				temp1 = P[r + 1][c];
				if (temp1)
				{
					char *array = temp1->GetName();
					if (array[1] == '2')
					{
						flag = 1;
						//cout << " R: " << r + 1 << " C: " << c;
						cout << r + 1 << " " << c << " , ";
						Pos.insert(r + 1, c);
					}
				}
				else if (temp == NULL && temp1 == NULL)
				{
					flag = 1;
					//cout << " R: " << r + 2 << " C: " << c;
					cout << r + 2 << " " << c << " , ";
					Pos.insert(r + 2, c);
				}
			}
			if (r == 1 && c + 1 <= 7)//first move right diagonal
			{
				temp = P[r + 2][c + 1];
				temp1 = P[r + 1][c + 1];
				if (temp1)
				{
					char *array = temp1->GetName();
					if (array[1] != '1')
					{
						flag = 1;
						//cout << " R: " << r + 2 << " C: " << c;
						cout << r + 1 << " " << c + 1 << " , ";
						Pos.insert(r + 1, c + 1);
					}
				}
				if (temp)
				{
					char *arr = temp->GetName();
					if (arr[1] == '2')
					{
						flag = 1;
						//cout << " R: " << r + 2 << " C: " << c;
						cout << r + 2 << " " << c + 1 << " , ";
						Pos.insert(r + 2, c + 1);
					}
				}
			}
			if (r == 1 && c-1 >= 0)//first move left diagonal
			{
				if (c > 0 && c < 7) {
					temp = P[r + 2][c];
					temp1 = P[r + 1][c - 1];
					char *array = temp1->GetName();
					if (temp1)
					{
						if (array[1] != '1')
						{
							flag = 1;
							//cout << " R: " << r + 2 << " C: " << c;
							cout << r + 1 << " " << c - 1 << " , ";
							Pos.insert(r + 1, c - 1);
						}
					}
					if (temp)
					{
						char* arr = temp->GetName();
						if (arr[1] == '2')
						{
							flag = 1;
							//cout << " R: " << r + 1 << " C: " << c - 1;
							cout << r + 2 << " " << c << " , ";
							Pos.insert(r + 2, c);
						}
					}
				}
			}
			if (r + 1 < 8) //lower bound
			{
				temp = P[r + 1][c];

				if (temp == NULL)
				{
						flag = 1;
						//cout << " R: " << r + 1 << " C: " << c;
						cout << r + 1 << " " << c << " , ";
						Pos.insert(r + 1, c);

				}
			}
			if (r + 1 < 8 && c + 1 <= 7) //right diagonal
			{
				temp = P[r + 1][c + 1];
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '2')
					{
						flag = 1;
						//cout << " R: " << r + 1 << " C: " << c + 1;
						cout << r + 1 << " " << c + 1 << " , ";
						Pos.insert(r + 1, c + 1);
					}
				}
			}
			if (r + 1 < 8 && c - 1 >= 0) //left diagonal
			{
				temp = P[r + 1][c - 1];
				if (temp)
				{
					char* arr = temp->GetName();
					if (arr[1] == '2')
					{
						flag = 1;
						//cout << " R: " << r + 1 << " C: " << c + 1;
						cout << r + 1 << " " << c - 1 << " , ";
						Pos.insert(r + 1, c - 1);
					}
				}
			}

			if (flag == 1)
			{
				char option;
				cout << "\nIf you want to change piece press Y  ELSE press N" << endl;
				cin >> option;
				if (option == 'y' || option == 'Y')
				{
					cout << "\nYou have entered yes to change the piece so enter new positions" << endl;
					return false;
				}
				else if (option == 'n' || option == 'N')
				{
					cout << "Fine you do not want to change your piece...";
					int row = 0;
					int col = 0;
					bool valid = 0;
					while (!valid)
					{
						cout << "\nSELECT A POSITION FROM AVAILABLE POSITIONS:\n";
						cout << "Row:";
						cin >> row;
						cout << "Col:";
						cin >> col;

						valid = Pos.isValid(row, col);
						if (valid == 0)
						{
							cout << "this position is invalid please ";
						}
					}
					if (row == 7)
					{
						int option = 0;
						cout << "Promote pawn to which piece?" << endl;
						cout << "1.Queen \n2.Knight \n3.Bishap \n4.Rook " << endl;
						cin >> option;
						if (option == 1)
						{
							static Queen q1("Q1");
							P[row][col] = &q1;
							P[r][c] = NULL;
							flag = true;
						}
						if (option == 2)
						{
							static Knight H1("H11");
							P[row][col] = &H1;
							P[r][c] = NULL;
							flag = true;
						}
						if (option == 3)
						{
							static Bishap B1("B1");
							P[row][col] = &B1;
							P[r][c] = NULL;
							flag = true;

						}
						if (option == 4)
						{
							static Rook R1("R1");
							P[row][col] = &R1;
							P[r][c] = NULL;
							flag = true;
						}
					}
					else
					{
						if (P[row][col])
						{
							char* arr;
							arr = P[row][col]->GetName();
							char arr1[] = "K2";
							if (stringCompare(arr1, arr))
							{
								gameOver = 1;
							}
						}
						P[row][col] = P[r][c];
						P[r][c] = NULL;
					}
				}
			}
			else
			{
				cout << "no available positions" << endl;
				return false;
			}
			return true;
		}
		if (player == 2)
		{
			LL Pos;
			if (r == 6)//first move
			{
				temp1 = P[r - 1][c];
				temp = P[r - 2][c];

				char* arr = temp1->GetName();
				if (temp1)
				{
					if (arr[1] != '2')
					{
						flag = 1;
						//cout << "R:" << r - 1 << "C:" << c;
						cout << r - 1 << " " << c << " , ";
						Pos.insert(r - 1, c);
					}

				}
				else if (temp == NULL  && temp1 == NULL)
				{
					flag = 1;
					//cout << "R:" << r - 2 << "C:" << c;
					cout << r - 2 << " " << c << " , ";
					Pos.insert(r - 2, c);

				}
			}
			if (r == 6)//first move right diagonal
			{
				if (c > 0 && c < 7) {
					temp1 = P[r - 1][c + 1];
					temp = P[r - 2][c + 1];

					char* arr = temp1->GetName();
					if (temp1)
					{
						if (arr[1] != '2')
						{
							flag = 1;
							//cout << "R:" << r - 2 << "C:" << c;
							cout << r - 2 << " " << c + 1 << " , ";
							Pos.insert(r - 2, c + 1);

						}

					}
					if (temp)
					{
						char *arr = temp->GetName();
						if (arr[1] == '1')
						{
							flag = 1;
							//cout << "R:" << r - 2 << "C:" << c;
							cout << r - 2 << " " << c + 1 << " , ";
							Pos.insert(r - 2, c + 1);
						}
					}
				}
			}
			if (r == 6)//first move left diagonal
			{
				if (c > 0 && c < 7) {
					temp1 = P[r - 1][c - 1];
					temp = P[r - 2][c - 1];

					char* arr = temp1->GetName();
					if (temp1)
					{
						if (arr[1] != '2')
						{
							flag = 1;
							//cout << "R:" << r - 2 << "C:" << c;
							cout << r - 2 << " " << c - 1 << " , ";
							Pos.insert(r - 2, c - 1);

						}

					}
					if (temp)
					{
						char *arr = temp->GetName();
						if (arr[1] == '1')
						{
							flag = 1;
							//cout << "R:" << r - 2 << "C:" << c;
							cout << r - 2 << " " << c - 1 << " , ";
							Pos.insert(r - 2, c - 1);
						}
					}
				}
			}
			if (r - 1 > 0) //upper bound
			{
				temp = P[r - 1][c];
				if (temp == NULL)
				{
					flag = 1;
					//cout << " R: " << r - 1 << " C: " << c;
					cout << r - 1 << " " << c << " , ";
					Pos.insert(r - 1, c);
				}
			}
			if (r - 1 >= 0 && c - 1 >= 0) //left diagonal 
			{
				temp = P[r - 1][c - 1];
				if (temp)
				{
					char *arr = temp->GetName();
					if (arr[1] == '1')
					{
						flag = 1;
						//cout << " R: " << r - 1 << " C: " << c;
						cout << r - 1 << " " << c - 1 << " , ";
						Pos.insert(r - 1, c - 1);
					}
				}
			}
			if (r - 1 >= 0 && c + 1 <= 7) //right diagonal 
			{
				temp = P[r - 1][c + 1];
				if (temp)
				{
					char *arr = temp->GetName();
					if (arr[1] == '1')
					{
						flag = 1;
						//cout << " R: " << r - 1 << " C: " << c;
						cout << r - 1 << " " << c + 1 << " , ";
						Pos.insert(r - 1, c + 1);
					}
				}
			}

			if (flag == 1)
			{
				char option;
				cout << "\nIf you want to change piece press Y ELSE press N" << endl;
				cin >> option;
				if (option == 'y' || option == 'Y')
				{
					cout << "\nYou have entered yes to change the piece so enter new positions" << endl;
					return false;
				}
				else if (option == 'n' || option == 'N')
				{
					cout << "Fine you do not want to change your piece...";
					int row = 0;
					int col = 0;

					bool valid = 0;
					while (!valid)
					{
						cout << "\nSELECT A POSITION FROM AVAILABLE POSITIONS:\n";
						cout << "Row:";
						cin >> row;
						cout << "Col:";
						cin >> col;
						valid = Pos.isValid(row, col);
						if (valid == 0)
						{
							cout << "this position is invalid please ";
						}
					}
					if (row == 0)
					{
						int option = 0;
						cout << "Promote pawn to which piece?" << endl;
						cout << "1.Queen \n2.Knight \n3.Bishap \n4.Rook " << endl;
						cin >> option;
						if (option == 1)
						{
							static Queen q2("Q2");
							P[row][col] = &q2;
							P[r][c] = NULL;
							flag = true;
						}
						if (option == 2)
						{
							static Knight H22("H22");
							P[row][col] = &H22;
							P[r][c] = NULL;
							flag = true;
						}
						if (option == 3)
						{
							Bishap B2("B2");
							P[row][col] = &B2;
							P[r][c] = NULL;
							flag = true;

						}
						if (option == 4)
						{
							Rook R2("R2");
							P[row][col] = &R2;
							P[r][c] = NULL;
							flag = true;
						}
					}
					else
					{
						if (P[row][col]) {
							char* arr;
							arr = P[row][col]->GetName();
							char arr1[] = "K1";
							if (stringCompare(arr1, arr))
							{
								gameOver = 1;
							}
						}

						P[row][col] = P[r][c];
						P[r][c] = NULL;
					}


				}
			}
			else
			{
				cout << "no available positions" << endl;
				return false;
			}
			return true;
		}
	}
};

class chess
{
private:
	Piece*** Board;

public:
	chess()
	{
		Board = new Piece**[8];

		for (int i = 0; i < 8; i++)
		{
			Board[i] = new Piece*[8];
		}
	}

	void PrintBoard()
	{

		int x1 = 410, x2 = 450, y1 = 65, y2 = 105;
		for (int i = 0; i < 8; i++) {

			for (int j = 0; j < 8; j++) {

				if (i % 2 == 0) {
					if (j % 2 == 0)
						myRect(x1, y1, x2, y2, 0, 0, 0, 255, 255, 255);
					else if (j % 2 != 0)
						myRect(x1, y1, x2, y2, 255, 255, 255, 0, 0, 0);
				}
				else {
					if (j % 2 != 0)
						myRect(x1, y1, x2, y2, 0, 0, 0, 255, 255, 255);
					else if (j % 2 == 0)
						myRect(x1, y1, x2, y2, 255, 255, 255, 0, 0, 0);
				}
				x1 = x1 + 50;
				x2 = x2 + 50;

			}
			x1 = 410;
			x2 = 450;
			y1 = y1 + 50;
			y2 = y2 + 50;
		}
	}

	void setPiece(King &k1, King &k2, Queen &q1, Queen &q2, Knight &H11, Knight &H12, Knight & H21, Knight &H22, Bishap& B11, Bishap &B12, Bishap &B21, Bishap &B22, Rook &R11, Rook &R12, Rook &R21, Rook &R22, Pawn &P11, Pawn &P12, Pawn &P13, Pawn &P14, Pawn &P15, Pawn &P16, Pawn &P17, Pawn &P18, Pawn &P21, Pawn &P22, Pawn &P23, Pawn &P24, Pawn &P25, Pawn &P26, Pawn &P27, Pawn &P28)
	{

		Board[0][0] = &R11;
		Board[0][1] = &H11;
		Board[0][2] = &B11;
		Board[0][3] = &q1;
		Board[0][4] = &k1;
		Board[0][5] = &B12;
		Board[0][6] = &H12;
		Board[0][7] = &R12;

		Board[1][0] = &P11;
		Board[1][1] = &P12;
		Board[1][2] = &P13;
		Board[1][3] = &P24;
		Board[1][4] = &P15;
		Board[1][5] = &P16;
		Board[1][6] = &P17;
		Board[1][7] = &P18;

		Board[6][0] = &P21;
		Board[6][1] = &P22;
		Board[6][2] = &P23;
		Board[6][3] = &P24;
		Board[6][4] = &P25;
		Board[6][5] = &P16;
		Board[6][6] = &P27;
		Board[6][7] = &P28;

		Board[7][0] = &R21;
		Board[7][1] = &H21;
		Board[7][2] = &B21;
		Board[7][3] = &q2;
		Board[7][4] = &k2;
		Board[7][5] = &B22;
		Board[7][6] = &H22;
		Board[7][7] = &R22;

		for (int i = 2; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				Board[i][j] = NULL;
			}
		}


	}

	void Print()
	{

		setColor(15);
		//cout << "\n\n\n";
		int counter = 1;
		char* arr;
		PrintBoard();
		int x1 = 410, x2 = 450, y1 = 65, y2 = 105;
		//cout << "         \t  \t \t\t\t 0      1      2      3    4      5      6      7" << endl << endl;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{

				if (Board[i][j] != NULL)
				{
					arr = Board[i][j]->GetName();
					char arr1[] = "K1";
					if (stringCompare(arr, arr1))
					{
						myDiamond(x1, y1, x2, y2, 255, 0, 0, 0, 0, 0);
						x1 = x1 + 50;
						x2 = x2 + 50;

					}

					char arr2[] = "Q1";
					if (stringCompare(arr, arr2))
					{
						myHexagone(x1, y1, x2, y2, 255, 0, 0, 0, 0, 0);
						x1 = x1 + 50;
						x2 = x2 + 50;

					}

					char arr3[] = "H11";
					if (stringCompare(arr, arr3))
					{
						myTriangle(x1, y1, x2, y2, 255, 0, 0, 0, 0, 0);
						x1 = x1 + 50;
						x2 = x2 + 50;

					}

					char arr4[] = "H12";
					if (stringCompare(arr, arr4))
					{
						myTriangle(x1, y1, x2, y2, 255, 0, 0, 0, 0, 0);
						x1 = x1 + 50;
						x2 = x2 + 50;

					}

					char arr5[] = "B11";
					if (stringCompare(arr, arr5))
					{
						myEllipse(x1, y1, x2, y2, 255, 0, 0, 0, 0, 0);
						x1 = x1 + 50;
						x2 = x2 + 50;

					}

					char arr6[] = "B12";
					if (stringCompare(arr, arr6))
					{
						myEllipse(x1, y1, x2, y2, 255, 0, 0, 0, 0, 0);
						x1 = x1 + 50;
						x2 = x2 + 50;

					}

					char arr7[] = "R11";
					if (stringCompare(arr, arr7))
					{
						myKite(x1, y1, x2, y2, 255, 0, 0, 0, 0, 0);
						x1 = x1 + 50;
						x2 = x2 + 50;

					}

					char arr8[] = "R12";
					if (stringCompare(arr, arr8))
					{
						myKite(x1, y1, x2, y2, 255, 0, 0, 0, 0, 0);
						x1 = x1 + 50;
						x2 = x2 + 50;

					}

					char arr9[] = "P11";
					if (stringCompare(arr, arr9))
					{
						myKite(x1, y1, x2, y2, 255, 0, 0, 0, 0, 0);
						x1 = x1 + 50;
						x2 = x2 + 50;

					}
					char arr10[] = "P12";
					if (stringCompare(arr, arr10))
					{
						myKite(x1, y1, x2, y2, 255, 0, 0, 0, 0, 0);
						x1 = x1 + 50;
						x2 = x2 + 50;

					}
					char arr11[] = "P13";
					if (stringCompare(arr, arr11))
					{
						myKite(x1, y1, x2, y2, 255, 0, 0, 0, 0, 0);
						x1 = x1 + 50;
						x2 = x2 + 50;

					}
					char arr12[] = "P14";
					if (stringCompare(arr, arr12))
					{
						myKite(x1, y1, x2, y2, 255, 0, 0, 0, 0, 0);
						x1 = x1 + 50;
						x2 = x2 + 50;

					}
					char arr13[] = "P15";
					if (stringCompare(arr, arr13))
					{
						myKite(x1, y1, x2, y2, 255, 0, 0, 0, 0, 0);
						x1 = x1 + 50;
						x2 = x2 + 50;

					}
					char arr14[] = "P16";
					if (stringCompare(arr, arr14))
					{
						myKite(x1, y1, x2, y2, 255, 0, 0, 0 , 0, 0);
						x1 = x1 + 50;
						x2 = x2 + 50;

					}
					char arr15[] = "P17";
					if (stringCompare(arr, arr15))
					{
						myKite(x1, y1, x2, y2, 255, 0, 0, 0, 0, 0);
						x1 = x1 + 50;
						x2 = x2 + 50;

					}
					char arr16[] = "P18";
					if (stringCompare(arr, arr16))
					{
						myKite(x1, y1, x2, y2, 255, 0, 0, 0, 0, 0);
						x1 = x1 + 50;
						x2 = x2 + 50;

					}

					//---------------------------------------------------------------

					arr = Board[i][j]->GetName();
					char arr17[] = "K2";
					if (stringCompare(arr, arr17))
					{
						myDiamond(x1, y1, x2, y2, 0, 0, 255, 0, 0, 0);
						x1 = x1 + 50;
						x2 = x2 + 50;

					}

					char arr18[] = "Q2";
					if (stringCompare(arr, arr18))
					{
						myHexagone(x1, y1, x2, y2, 0, 0, 255, 0, 0, 0);
						x1 = x1 + 50;
						x2 = x2 + 50;

					}

					char arr19[] = "H21";
					if (stringCompare(arr, arr19))
					{
						myTriangle(x1, y1, x2, y2, 0, 0, 255, 0, 0, 0);
						x1 = x1 + 50;
						x2 = x2 + 50;

					}

					char arr20[] = "H22";
					if (stringCompare(arr, arr20))
					{
						myTriangle(x1, y1, x2, y2, 0, 0, 255, 0, 0, 0);
						x1 = x1 + 50;
						x2 = x2 + 50;

					}

					char arr21[] = "B21";
					if (stringCompare(arr, arr21))
					{
						myEllipse(x1, y1, x2, y2, 0, 0, 255, 0, 0, 0);
						x1 = x1 + 50;
						x2 = x2 + 50;

					}

					char arr22[] = "B22";
					if (stringCompare(arr, arr22))
					{
						myEllipse(x1, y1, x2, y2, 0, 0, 255, 0, 0, 0);
						x1 = x1 + 50;
						x2 = x2 + 50;

					}

					char arr23[] = "R21";
					if (stringCompare(arr, arr23))
					{
						myKite(x1, y1, x2, y2, 0, 0, 255, 0, 0, 0);
						x1 = x1 + 50;
						x2 = x2 + 50;

					}

					char arr24[] = "R22";
					if (stringCompare(arr, arr24))
					{
						myKite(x1, y1, x2, y2, 0, 0, 255, 0, 0, 0);
						x1 = x1 + 50;
						x2 = x2 + 50;

					}

					char arr25[] = "P21";
					if (stringCompare(arr, arr25))
					{
						myKite(x1, y1, x2, y2, 0, 0, 255, 0, 0, 0);
						x1 = x1 + 50;
						x2 = x2 + 50;

					}
					char arr26[] = "P22";
					if (stringCompare(arr, arr26))
					{
						myKite(x1, y1, x2, y2, 0, 0, 255, 0, 0, 0);
						x1 = x1 + 50;
						x2 = x2 + 50;

					}
					char arr27[] = "P23";
					if (stringCompare(arr, arr27))
					{
						myKite(x1, y1, x2, y2, 0, 0, 255, 0, 0, 0);
						x1 = x1 + 50;
						x2 = x2 + 50;

					}
					char arr28[] = "P24";
					if (stringCompare(arr, arr28))
					{
						myKite(x1, y1, x2, y2, 0, 0, 255, 0, 0, 0);
						x1 = x1 + 50;
						x2 = x2 + 50;

					}
					char arr29[] = "P25";
					if (stringCompare(arr, arr29))
					{
						myKite(x1, y1, x2, y2, 0, 0, 255, 0, 0, 0);
						x1 = x1 + 50;
						x2 = x2 + 50;

					}
					char arr30[] = "P26";
					if (stringCompare(arr, arr30))
					{
						myKite(x1, y1, x2, y2, 0, 0, 255, 0, 0, 0);
						x1 = x1 + 50;
						x2 = x2 + 50;

					}
					char arr31[] = "P27";
					if (stringCompare(arr, arr31))
					{
						myKite(x1, y1, x2, y2, 0, 0, 255, 0, 0, 0);
						x1 = x1 + 50;
						x2 = x2 + 50;

					}
					char arr32[] = "P28";
					if (stringCompare(arr, arr32))
					{
						myKite(x1, y1, x2, y2, 0, 0, 255, 0, 0, 0);
						x1 = x1 + 50;
						x2 = x2 + 50;

					}
				}
				else
				{
					x1 = x1 + 50;
					x2 = x2 + 50;
				}


			}
			counter = 0;
			x1 = 410;
			x2 = 450;
			y1 = y1 + 50;
			y2 = y2 + 50;
		}


	}

	void Save()
	{
		ofstream fout;
		fout.open("SAVETXT.txt");
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{

				if (Board[i][j])
					fout << Board[i][j]->GetName() << " ";
				else
					fout << "- ";
			}
			fout << endl;
		}
		fout.close();

	}
	void Load()
	{
		//--------> new board
		Piece*** Board1 = new Piece**[8];

		for (int i = 0; i < 8; i++)
			Board1[i] = new Piece*[8];

		char buffer[100];

		ifstream fin;
		fin.open("SAVETXT.txt");

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				fin >> buffer;
				for (int k = 0; k < 8; k++)
				{
					for (int l = 0; l < 8; l++)
					{
						if (Board[k][l]) {
							if (stringCompare(Board[k][l]->GetName(), buffer)) {
								Board1[i][j] = Board[k][l];
								k = k + 10;
								break;
							}
						}
						else
							Board1[i][j] = NULL;
					}
				}

			}
		}

		Board = Board1;
		Board1 = NULL;
	}
	void MOVE()
	{
		int Player = 1;
		bool win = 0;
		char key ='\0';

		while (!win)
		{

			system("cls");
			Print();
			cout << "The red pieces are for player 1 " << endl;
			cout << "The blue pieces are for player 2" << endl;
			if (Player == 1)
			{

				int row = 0;
				int col = 0;

				bool input = 0;

				while (!input)
				{
					/*while (1)
					{
						key = GetAsyncKeyState(38);
						if (key == 1)
						{
							Save();
							system("cls");
							Print();
							break;
						}

						key = GetAsyncKeyState(37);
						if (key == 1)
						{
							Load();
							system("cls");
							Print();
							break;

						}

						key = GetAsyncKeyState(39);
						if (key == 1)
						{
							break;
						}
					}*/
					cout << "PLAYER: " << Player << endl;
					cout << "Enter Row: ";
					cin >> row;
					if (row > 7 || row < 0)
					{
						while (row > 7 || row < 0)
						{
							cout << "you have entered out of bound please enter again" << endl;
							cout << "Enter row: ";
							cin >> row;
						}
					}
					cout << "Enter col: ";
					cin >> col;
					if (col > 7 || col < 0)
					{
						while (col > 7 || col < 0)
						{
							cout << "you have entered out of bound please enter again" << endl;
							cout << "Enter col: ";
							cin >> col;
						}
					}
					if (Board[row][col] == NULL)
					{
						while (Board[row][col] == NULL)
						{
							cout << "There is no piece at this place please enter again" << endl;
							cout << " Again Enter Row: ";
							cin >> row;
							cout << "Again Enter col: ";
							cin >> col;
						}
						Piece* object = Board[row][col];
						char* arr = object->GetName();
						if (arr[1] == '1')
						{
							//----->MOVEMENT
							if (object->Movement(Board, Player, row, col, win))
								input = true;
						}
						else
						{
							cout << "WRONG PIECE SELECT AGAIN\n";
							input = false;

						}

					}
					else
					{
						Piece* object = Board[row][col];
						char* arr = object->GetName();
						if (arr[1] == '1')
						{

							//----->MOVEMENT
							if (object->Movement(Board, Player, row, col, win))
								input = true;
						}
						else
						{
							cout << "WRONG PIECE SELECT AGAIN\n";
							input = false;

						}
					}

				}
				if (win == 1)
				{
					cout << Player << " WINS";
					break;

				}
				Player = 2;
			}
			if (Player == 2)
			{
				system("cls");
				Print();

				int row = 0;
				int col = 0;

				bool input = 0;

				while (!input)
				{
					/*while (1)
					{
						key = GetAsyncKeyState(38);
						if (key == 1)
						{
							Save();
							system("cls");
							Print();
							break;
						}

						key = GetAsyncKeyState(37);
						if (key == 1)
						{
							Load();
							system("cls");
							Print();
							break;

						}

						key = GetAsyncKeyState(39);
						if (key == 1)
						{
							break;
						}
					}*/
					cout << "PLAYER: " << Player << endl;
					cout << "Enter Row: ";
					cin >> row;
					if (row > 7 || row < 0)
					{
						while (row > 7 || row < 0)
						{
							cout << "you have entered out of bound please enter again" << endl;
							cout << "Enter row: ";
							cin >> row;
						}
					}
					cout << "Enter col: ";
					cin >> col;
					if (col > 7 || col < 0)
					{
						while (col > 7 || col < 0)
						{
							cout << "you have entered out of bound please enter again" << endl;
							cout << "Enter col: ";
							cin >> col;
						}
					}
					if (Board[row][col] == NULL)
					{
						while (Board[row][col] == NULL)
						{
							cout << "There is no piece at this place please enter again" << endl;
							cout << "Enter Row: ";
							cin >> row;
							if (row > 7 || row < 0)
							{
								while (row > 7 || row < 0)
								{
									cout << "you have entered out of bound please enter again" << endl;
									cout << "Enter row: ";
									cin >> row;
								}
							}
							cout << "Enter col: ";
							cin >> col;
							if (col > 7 || col < 0)
							{
								while (col > 7 || col < 0)
								{
									cout << "you have entered out of bound please enter again" << endl;
									cout << "Enter col: ";
									cin >> col;
								}
							}
						}
						Piece* object = Board[row][col];
						char* arr = object->GetName();
						if (arr[1] == '2')
						{

							//----->MOVEMENT
							if (object->Movement(Board, Player, row, col, win))
								input = true;
						}
						else
						{
							cout << "WRONG PIECE SELECT AGAIN\n";
							input = false;

						}
					}
					else
					{
						Piece* object = Board[row][col];
						char* arr = object->GetName();
						if (arr[1] == '2')
						{
							//----->MOVEMENT
							if (object->Movement(Board, Player, row, col, win))
								input = true;

						}
						else
						{
							cout << "WRONG PIECE SELECT AGAIN\n";
							input = false;

						}
					}

				}
				if (win == 1)
			    {
				cout << Player << " WINS";
				break;
				
			    }
				Player = 1;
			}
			
		}

		
		
	}
};

int main()
{
	chess Game;
	//-->kings
	King king1("K1");
	King king2("K2");

	//-->queens
	Queen queen1("Q1");
	Queen queen2("Q2");

	//--> knights
	Knight knight11("H11");
	Knight knight12("H12");

	Knight knight21("H21");
	Knight knight22("H22");

	//--> Bishaps
	Bishap bishap11("B11");
	Bishap bishap12("B12");

	Bishap bishap21("B21");
	Bishap bishap22("B22");

	//--> Rook
	Rook rook11("R11");
	Rook rook12("R12");

	Rook rook21("R21");
	Rook rook22("R22");

	//-->Pawn
	Pawn pawn11("P11");
	Pawn pawn12("P12");
	Pawn pawn13("P13");
	Pawn pawn14("P14");
	Pawn pawn15("P15");
	Pawn pawn16("P16");
	Pawn pawn17("P17");
	Pawn pawn18("P18");

	Pawn pawn21("P21");
	Pawn pawn22("P22");
	Pawn pawn23("P23");
	Pawn pawn24("P24");
	Pawn pawn25("P25");
	Pawn pawn26("P26");
	Pawn pawn27("P27");
	Pawn pawn28("P28");

	Game.setPiece(king1, king2, queen1, queen2, knight11, knight12, knight21, knight22, bishap11, bishap12, bishap21, bishap22, rook11, rook12, rook21, rook22, pawn11, pawn12, pawn13, pawn14, pawn15, pawn16, pawn17, pawn18, pawn21, pawn22, pawn23, pawn24, pawn25, pawn26, pawn27, pawn28);

	Game.MOVE();
	_getch();
	//
}
