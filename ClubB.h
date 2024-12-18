#pragma once
#include "Manager.h"
class ClubB :public Manager
{
public:
	ClubB(int typeint, int id,string name, int rank, string m_managerAccount, string m_managerPassword);

	virtual void showInfo()override;

	virtual void showMenu()override;

	virtual void returnBack(bool&)override;

	virtual int IsAccountExist(string)override;

	virtual void init_Mem()override;

	virtual void save()override;



	virtual bool adminLogin(const string& account, const string& password)override;

	virtual bool userLogin(const string& account, const string& password)override;

	virtual void accountLogin()override;

	virtual void accountRegister()override;

	virtual void login()override;






	virtual void showMenu1();

	virtual void Show_Mem();

	virtual void Del_Mem();

	virtual int IsExist(string id);

	virtual void Mod_Mem();

	virtual void Find_Mem();

	virtual void Sort_Mem();

	virtual void Clean_Mem();




	virtual void showMenu2();

	virtual void Show_Sin(int index);

	virtual void Mod_Sin(int index);

	virtual void Add_Card(int index);

	virtual void renew_Sin(int index);

	virtual void processConsumption(int index);

	virtual void cancelCard(int index);

	~ClubB();

};
