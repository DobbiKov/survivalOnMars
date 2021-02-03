#include "Game.h"
#include <conio.h>
void Game::Buildings::EnterStorage() {
	bool Entering = true;
	if (rand() % 8 == 0) {
		int DenyType = 1 + rand() % 3;
		DenyToGoIn(H, T, DenyType, "�� ������", Entering);
	}
}
void Game::Buildings::EnterLaboratory() {
	bool Entering = true;
	if (rand() % 8 == 0) {
		int DenyType = 1 + rand() % 3;
		DenyToGoIn(H, T, DenyType, "�� �����������", Entering);
	}
}
void Game::Buildings::EnterBedrooms() {
	bool Entering = true;
	if (rand() % 8 == 0) {
		int DenyType = 1 + rand() % 3;
		DenyToGoIn(H, T, DenyType, "�� ������", Entering);
	}
}
void Game::Buildings::EnterCantin(Inventory& I) {
	bool Entering = true;
	if (rand() % 8 == 0) {
		int DenyType = 1 + rand() % 3;
		DenyToGoIn(H, T, DenyType, "�� ��������", Entering);
	}
	I.DarkChocolateBar.SetNew();
}
void Game::Buildings::EnterHospital() {
	bool Entering = true;
	if (rand() % 8 == 0) {
		int DenyType = 1 + rand() % 3;
		DenyToGoIn(H, T, DenyType, "�� ���������", Entering);
	}
}
void Game::Buildings::DenyToGoIn(Human& H, Text& T, int Type, string RoomType, bool& Entering) {
	// ������ �� ���� ������ ���������
	system("cls");
	SetConsoleTextAttribute(h, 13);
	switch (Type) {
	case 1: {
		cout << "����� " << RoomType << " �������������. � ���� ����� ����� ��� ����� ����� ������ ������" << endl;
		Entering = false;
		break;
	}
	case 2: {
		cout << "������ ����� " << RoomType << ", �� ������ ���� �����: �� ���� �������� ������� ��������� ������" << endl;
		if (rand() % 5 == 0) {
			cout << "��� ����� �� �������� �� ������ ���-�� ������������ �����... ���� ����� ����� �� ����� � �� �������� ������� �����" << endl;
			H.Set(hi_PHP, '-', 40);
		}
		else cout << "������ ���� ����� ���� ������, � �� ������ �����" << endl;
		Entering = false;
		break;
	}
	case 3: {
		int CountOfTry = 3 + rand() % 8;
		bool UsedDoor = CountOfTry < 10;
		int Thousands = 1 + rand() % 9;
		int Type = 1 + rand() % 4;
		int Chance = rand() % 5;
		int Hundreds = rand() % 10;
		int Decs = rand() % 10;
		int Ones = rand() % 10;
		int Code = (1 + rand() % 9) * 1000 + rand() % 10 * 100 + rand() % 10 * 10 + rand() % 10;
		while (CountOfTry != 0) {
			SetConsoleTextAttribute(h, 13);
			system("cls");
			if (UsedDoor && Chance == 0) {
				switch (Type) {
				case 1: {
					T.PRC(1, "�� ������� � ����� " + RoomType + ". �� ��� ��������� ����� �������� ����� ������-�� ��������... ������, ������-�� ���������� �������� ���������...\n");
					break;
				}
				case 2: {
					T.PRC(1, "� ����� �� ������ ������ ���� ��������� �������. ��� ���������� ������ ����, ���� �� �������� ������ � ��������� ����. ���� �� ���������� ������� � ������ ���������� ������ ����� ��������, ��� ���-�� ���������� ������� �������������� ��� �����.\n");
					break;
				}
				case 3: {
					T.PRC(1, "� �������� ����� ���� ������������ ��������. �� ����� �������������. �� �������, � �������� �������� ������� ������ ���. ������, ��� �������� ��������� ������: ���������� ���� �������� �����-�� ����� ������\n���������, ��-�� ���� ��������� ������ �� ��������. � ���, ������, ���-�� ������� ������ ��� �� ����\n");
					break;
				}
				case 4: {
					T.PRC(1, "�������� �����, ���������� ���� " + RoomType + ", ��� � ���������. � ������ ����� ����� ��������� �������, ������� �������, ��� �� �������� ����������, ����� 20 �����������\n�� ����������� ������ ����� �������� ����� � ���������� ����������� �������������. �� ��������, �����������\n�� ����� ���� ����� �����, ������, ��� ��������� ������� ���������: \"������� ���\"\n");
					break;
				}
				}
			}
			cout << "����� ����� ������, ����� ������ ���-��� - ������������� �����" << endl;
			T.V(4, 50);
			SetConsoleTextAttribute(h, 13);
			cout << "�������� �������: ";
			SetConsoleTextAttribute(h, 15);
			cout << CountOfTry << endl;
			T.V(4, 25);
			if (CountOfTry != 10) {
				cout << "� ������� ��������!" << endl;
				SetConsoleTextAttribute(h, 13);
				cout << "���-���: ";
				if (Code / 1000 % 10 == Thousands) SetConsoleTextAttribute(h, 10);
				else SetConsoleTextAttribute(h, 4);
				cout << "*";
				if (Code / 100 % 10 == Hundreds) SetConsoleTextAttribute(h, 10);
				else SetConsoleTextAttribute(h, 4);
				cout << "*";
				if (Code / 10 % 10 == Decs) SetConsoleTextAttribute(h, 10);
				else SetConsoleTextAttribute(h, 4);
				cout << "*";
				if (Code % 10 == Ones) SetConsoleTextAttribute(h, 10);
				else SetConsoleTextAttribute(h, 4);
				cout << "*" << endl;
				T.V(4, 40);
			}
			SetConsoleTextAttribute(h, 13);
			cout << "������� ���: ";
			SetConsoleTextAttribute(h, 15);
			cin >> Code;
			if (Code < 1000 || Code > 9999) Code = 0;
			if (Code == Thousands * 1000 + Hundreds * 100 + Decs * 10 + Ones) {
				Entering = true;
				system("cls");
				SetConsoleTextAttribute(h, 13);
				cout << "���� ������� ��������� ���-��� � �����" << endl;
				break;
			}
			CountOfTry--;
			if (CountOfTry == 0) {
				system("cls");
				int DenyingType = 1 + rand() % 4;
				switch (DenyingType) {
				case 1: {
					T.PRC(1, "");
					break;
				}
				case 2: {
					break;
				}
				case 3: {
					break;
				}
				case 4: {
					break;
				}
				}
				break;
			}
		}
		break;
	}
	}
	T.V(4, 40);
	SetConsoleTextAttribute(h, 15);
	system("pause");
}


void Game::Buildings::LocationGeneration() {
	// "����������" ���������
	int CountOfRooms = 2 + rand() % 4;


	system("cls");
	
	
	SetConsoleTextAttribute(h, 3);
	cout << "�� ����� � ������" << endl;
	SetConsoleTextAttribute(h, 4);
	cout << "________________________________________" << endl;
	SetConsoleTextAttribute(h, 15);


	system("pause");


	while (CountOfRooms != 0) {
		SetConsoleTextAttribute(h, 3);
		system("cls");
		cout << "�� ���������� � ���������" << endl;
		cout << "�������� ������������� �������: ";
		SetConsoleTextAttribute(h, 15);
		cout << CountOfRooms << endl;
		SetConsoleTextAttribute(h, 4);
		cout << "________________________________________" << endl;
		SetConsoleTextAttribute(h, 13);
		cout << "(1) ";
		SetConsoleTextAttribute(h, 15);
		int RoomType = 1;
		if (rand() % 2 == 0) RoomType++;
		if (rand() % 3 == 0) RoomType++;
		if (rand() % 4 == 0) RoomType++;
		if (rand() % 5 == 0) RoomType++;
		switch (RoomType) {
		case 1: cout << "����� � �������" << endl; break;
		case 2: cout << "����� � ��������" << endl; break;
		case 3: cout << "����� �� �����" << endl; break;
		case 4: cout << "����� � ��������" << endl; break;
		case 5: cout << "����� � �����������" << endl; break;
		}


		while (true) {
			int Click = _getch();
			if (Click == 49) {
				switch (RoomType) {
				case 1: EnterBedrooms(); break;
				case 2: EnterCantin(I); break;
				case 3: EnterStorage(); break;
				case 4: EnterHospital(); break;
				case 5: EnterLaboratory(); break;
				}
				break;
			}
		}
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		CountOfRooms--;
	}
}