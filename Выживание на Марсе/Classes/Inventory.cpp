#include "Game.h"
Game::Inventory::Inventory() {
	// ������� (�������) ���������� ����� 1-2 ����. ������ ����� 3 ����
	Hammer.Constructor("�������", 1.5);
	Jigsaw.Constructor("����", 2.0);
	Axe.Constructor("�����", 4.5);

	Palont.Constructor("���� \"������\"", 0.1, hi_DP, -2.0, hi_HP, 20);
	Aspirin.Constructor("������� ��������", 0.025, hi_DP, -0.5, hi_HP, 15);
	Trivoclisine.Constructor("������ � �������������", 0.01, hi_DP, -15.0, hi_EP, -70);
	Gericline.Constructor("���� ���������", 0.1, hi_DP, 2.0, hi_EP, 75);
	Phenothan.Constructor("�������� ��������", 0.05, hi_DP, -1.0, hi_HP, 30);

	CannedBeef.Constructor("���������������� ��������", 0.25, hi_FP, 30, hi_EP, 25);
	Hardtack.Constructor("����� �����", 0.15, hi_FP, 20);
	EnergyBar.Constructor("�������������� ��������", 0.05, hi_FP, 10, hi_EP, 30);
	MushroomSoup.Constructor("������� ��� � �������", 0.3, hi_FP, 40, hi_EP, 20);
	CannedApple.Constructor("������������������ ������", 0.2, hi_FP, 20, hi_EP, 20);
	RicePurge.Constructor("�������� � �����", 0.3, hi_FP, 30, hi_EP, 20);
	MeatBriquette.Constructor("������ ������", 0.3, hi_FP, 25, hi_EP, 50);
	MeltedCheese.Constructor("�������� ����������� ����", 0.15, hi_FP, 20);

	FishSoup.Constructor("������� �� ������", 0.4, hi_DP, -5.0, hi_FP, 40, hi_EP, 55);
	DarkChocolateBar.Constructor("������ �������� ��������", 0.1, hi_FP, 25, hi_EP, 40, hi_PHP, 30);
	BartonsDrug.Constructor("��������� ���������� �������", 0.4, hi_DP, -10.0, hi_HP, 40, hi_EP, 20);
}