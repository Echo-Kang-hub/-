#include <iostream>
#include "ClubManager.h"


int main()
{
	ClubManager cm;

	int choice = 0;
	while (true)
	{
		cm.showMenu();
		cout << "ÇëÊäÈëÄúµÄÑ¡Ôñ" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			cm.ExitSystem();
			break;
		case 1:
			cm.selectClub();
			break;
		case 2:
			cm.ShowClub();
			break;
		case 3:
			cm.addClub();
			break;
		case 4:
			cm.DelClub();
			break;
		case 5:
			cm.ModClub();
			break;
		case 6:
			cm.FindClub();
			break;
		case 7:
			cm.SortClub();
			break;
		case 8:
			cm.CleanClub();
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}