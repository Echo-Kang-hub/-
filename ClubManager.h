#pragma once
#include "Manager.h"
#include <vector>
using namespace std;
class ClubManager
{
public:

	int m_ClubNum;

	vector<Manager*> m_ClubArray;
	//span<Club*> m_ClubArray;

	bool m_FileIsEmpty;

	ClubManager();

	//显示俱乐部选择菜单
	void showMenu();

	//退出系统
	void ExitSystem();

	//读取文件初始化俱乐部
	void init_Club();
	//void init_Club(vector<Club>& clubs);

	////展示俱乐部
	//void displayClub(Manager*);

	////进入俱乐部下的系统
	//void useSystem(Manager*);

	int IsExist(int id);

	void save();

	bool authenticate()const;

	void addClub();

	void ShowClub();

	void DelClub();

	void ModClub();

	void FindClub();

	void SortClub();

	void CleanClub();

	void selectClub();

	~ClubManager()noexcept;

};