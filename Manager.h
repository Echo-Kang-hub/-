#pragma once
#include <string>
#include "Member.h"
using namespace std;

class Manager
{
public:

	virtual void showInfo() = 0;

	int m_Type = 0;

	int m_Id = 0;

	string m_ClubName;

	int m_ClubRank = 0;


	string m_managerAccount;

	string m_managerPassword;



	int m_memNum;

	vector<Member*> m_memArray;

	bool m_FileIsEmpty=true;

	virtual void showMenu() = 0;

	virtual void returnBack(bool&) = 0;

	virtual int IsAccountExist(string) = 0;

	virtual void init_Mem() = 0;

	virtual void save()=0;

	//管理者登录判断
	virtual bool adminLogin(const string& account, const string& password)=0;

	//用户登录判断
	virtual bool userLogin(const string& account, const string& password)=0;

	virtual void accountLogin() = 0;

	virtual void accountRegister() = 0;

	virtual void login() = 0;





	virtual void showMenu1() = 0;

	virtual void Show_Mem() = 0;


	virtual void Del_Mem() = 0;

	virtual int IsExist(string id) = 0;

	virtual void Mod_Mem() = 0;

	virtual void Find_Mem() = 0;

	virtual void Sort_Mem() = 0;

	virtual void Clean_Mem() = 0;





	virtual void showMenu2() = 0;

	virtual void Show_Sin(int index) = 0;

	virtual void Mod_Sin(int index) = 0;

	virtual void Add_Card(int index) = 0;

	virtual void renew_Sin(int index) = 0;

	virtual void processConsumption(int index) = 0;

	virtual void cancelCard(int index) = 0;

};