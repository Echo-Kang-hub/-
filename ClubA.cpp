#include <iostream>
#include <cstdio>
#include "Functions.h"
#include "ClubA.h"

#include <fstream>
#define FILENAME "ClubA.txt" 
#define FILENAME1 "PrivateTrainer.txt"


ClubA::ClubA(int type,int id,string name, int cRank, string m_managerAccount, string m_managerPassword)
{
	this->m_Type = type;
	this->m_Id = id;
	this->m_ClubName = name;
	this->m_ClubRank = cRank;

	this->m_managerAccount = m_managerAccount;
	this->m_managerPassword = m_managerPassword;

	this->m_memNum = 0;

	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		//cout << "ClubA文件不存在!" << endl;

		this->m_memNum = 0;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;//文件不存在不再执行构造函数
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "ClubA文件为空!" << endl;
		this->m_memNum = 0;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}


	this->init_Mem();//用文件数据初始化堆区空间数组

	if (this->m_memNum != 0)
	{
		this->m_FileIsEmpty = false;
	}
	
	//cout << "A会员人数为：" << this->m_memNum << endl;


	ifstream ifs1;
	ifs1.open(FILENAME1, ios::in);

	if (!ifs1.is_open())
	{
		//cout << "PrivateTrainer.txt文件不存在!" << endl;

		this->m_traNum = 0;
		this->m_traFileIsEmpty = true;
		ifs1.close();
		return;//文件不存在不再执行构造函数
	}

	char ch1;
	ifs1 >> ch1;
	if (ifs1.eof())
	{
		//cout << "PrivateTrainer.txt文件为空!" << endl;
		this->m_traNum = 0;
		this->m_traFileIsEmpty = true;
		ifs1.close();
		return;
	}


	this->init_Tra();//用文件数据初始化堆区空间数组

	if (this->m_traNum != 0)
	{
		this->m_traFileIsEmpty = false;
	}

	//cout << "教练人数为：" << this->m_traNum << endl;
}

void ClubA::showInfo()
{
	
	cout<< "类型：A"<<" "
		<< "\tID号："<<this->m_Id << " "
		<< "\t俱乐部：" << this->m_ClubName << " "
		<< "\t排名："<< this->m_ClubRank << " "
		<< "\n特点：" << " A级俱乐部：高端私人健身俱乐部  ->  1.环境高端舒适 2.个性化服务极致 3.课程和设施定制化 4.隐私性强" << endl;
}

void ClubA::showMenu()
{
	system("cls");

	cout << "欢迎来到" << this->m_ClubName << "！" << endl;
	cout << "0.返回" << endl;
	cout << "1.登录账号" << endl;
	cout << "2.注册账号" << endl;
}

void ClubA::returnBack(bool& judge)
{
	cout << "正在返回......" << endl;
	judge = false;
	system("pause");
	system("cls");


}

int ClubA::IsAccountExist(string account)
{
	int index = -1;
	for (int i = 0; i < this->m_memNum; i++)
	{
		if (this->m_memArray.at(i)->m_Account == account)
		{
			index = i;

			break;
		}
	}
	return index;
}



void ClubA::init_Mem()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	string id;
	string account;
	string password;
	string name;
	int age;
	int gender;
	string phone;
	string address;


	while (ifs >>id && ifs>> account && ifs >> password && ifs >> name && ifs >> age && ifs >> gender && ifs >> phone && ifs >> address)
	{

		this->m_memArray.push_back(new Member(id, account, password, name, age, gender, phone, address));
		this->m_memNum++;
	}
	ifs.close();
}

void ClubA::init_Tra()
{
	ifstream ifs;
	ifs.open(FILENAME1, ios::in);

	string name;
	string specialties;
	

	while (ifs >> name && ifs >> specialties)
	{

		this->trainers.push_back(PrivateTrainer(name, specialties));
		this->m_traNum++;
	}
	ifs.close();
}

void ClubA::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_memNum; i++)
	{
		ofs << this->m_memArray.at(i)->m_Id << " "
			<< this->m_memArray.at(i)->m_Account << " "
			<< this->m_memArray.at(i)->m_Password << " "
			<< this->m_memArray.at(i)->m_Name << " "
			<< this->m_memArray.at(i)->m_Age << " "
			<< this->m_memArray.at(i)->m_Gender << " "
			<< this->m_memArray.at(i)->m_Phone << " "
			<< this->m_memArray.at(i)->m_Address << " "<< endl;
	}

	ofs.close();
}




bool ClubA::adminLogin(const string& account,const string& password)
{
	if (account == this->m_managerAccount && password == this->m_managerPassword)
	{
		return true;
	}
	return false;
}

bool ClubA::userLogin(const string& account, const string& password)
{
	if (this->IsAccountExist(account) != -1 && this->m_memArray.at(this->IsAccountExist(account))->m_Password == password)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ClubA::accountLogin()
{
	system("cls");

	bool judge1 = true;
	while (judge1)
	{
		cout << "0.返回" << endl;
		cout << "1.继续登录" << endl;
		cout << "请输入您的选择" << endl;
		int select;
		cin >> select;
		if (select == 0)
		{
			cout << "正在返回......" << endl;
			judge1 = false;
			system("pause");
			system("cls");
		}
		else if (select == 1)
		{
			cout << "请输入账号：";
			string account;
			cin >> account;
			cout << "请输入密码：";
			string password;
			cin >> password;
			if (this->adminLogin(account, password))
			{
				bool judge = true;
				int choice = 0;
				while (judge)
				{
					this->showMenu1();
					cout << "请输入您的选择" << endl;
					cin >> choice;
					switch (choice)
					{
					case 0:
						this->returnBack(judge);
						break;
					case 1:
						this->Show_Mem();
						break;
					case 2:
						this->Del_Mem();
						break;
					case 3:
						this->Mod_Mem();
						break;
					case 4:
						this->Find_Mem();
						break;
					case 5:
						this->Sort_Mem();
						break;
					case 6:
						this->Clean_Mem();
						break;
					default:
						break;
					}
				}
			}
			else if (this->userLogin(account, password))
			{
				
				bool judge = true;
				int choice = 0;
				while (judge)
				{
					this->showMenu2();
					cout << "请输入您的选择" << endl;
					cin >> choice;
					switch (choice)
					{
					case 0:
						this->returnBack(judge);
						break;
					case 1:
						this->createCustomTrainingPlan(this->IsAccountExist(account));

						this->displayTrainingPlan(this->IsAccountExist(account));
						break;
					case 2:
						this->displayTrainer();
						break;
					case 3:
						this->Show_Sin(this->IsAccountExist(account));
						break;
					case 4:
						this->Mod_Sin(this->IsAccountExist(account));
						break;
					case 5:
						this->Add_Card(this->IsAccountExist(account));
						break;
					case 6:
						this->renew_Sin(this->IsAccountExist(account));
						break;
					case 7:
						this->processConsumption(this->IsAccountExist(account));
						break;
					case 8:
						this->cancelCard(this->IsAccountExist(account));
						break;
					default:
						break;
					}
				}
			}
			else
			{
				cout << "账号或密码出错,请重新输入" << endl;
				system("pause");
				system("cls");
			}
		}
		else
		{
			cout << "无效输入,请重新输入" << endl;
			system("pause");
			system("cls");
		}

	}
	
}

void ClubA::accountRegister()
{
	system("cls");

	string id= generateMemberId();
	
	string account="";
	while (true)
	{
		cout << "请输入账号:" << endl;
		cin >> account;


		if (this->IsAccountExist(account) != -1)
		{
			cout << "重复，请重新输入" << endl;
			continue;
		}
		break;
	}

	cout << "请输入密码:" << endl;
	string password;
	cin >> password;
	cout << "请输入姓名:" << endl;
	string name;
	cin >> name;
	cout << "请输入年龄:" << endl;
	int age = 0;
	cin >> age;
	cout << "请输入性别:" << endl;
	cout << "1.男" << endl;
	cout << "2.女" << endl;
	int gender = 0;
	cin >> gender;
	cout << "请输入电话号码:" << endl;
	string phone;
	cin >> phone;
	cout << "请输入地址:" << endl;
	string address;
	cin >> address;

	
	this->m_memArray.push_back(new Member(id, account, password, name, age, gender, phone, address));

	cout << "请输入你想要的会员卡类型" << endl;
	cout << "日卡---1" << endl;
	cout << "周卡---2" << endl;
	cout << "月卡---3" << endl;
	cout << "季卡---4" << endl;
	cout << "年卡---5" << endl;
	cout << "暂时不办---0" << endl;

	int select;

	while (true)
	{
		cin >> select;

		if (select == 1 )
		{
			this->m_memArray.at(this->m_memArray.size()-1)->cardArray.push_back(new Card(generateMemberId(), select, getFutureDate(3), 30, getCurrentDate()));
			break;
		}
		else if(select == 2 )
		{
			this->m_memArray.at(this->m_memArray.size()-1)->cardArray.push_back(new Card(generateMemberId(), select, getFutureDate(7), 70, getCurrentDate()));
			break;
		}
		else if (select == 3 )
		{
			this->m_memArray.at(this->m_memArray.size()-1)->cardArray.push_back(new Card(generateMemberId(), select, getFutureDate(30), 150, getCurrentDate()));
			break;
		}
		else if (select == 4 )
		{
			this->m_memArray.at(this->m_memArray.size()-1)->cardArray.push_back(new Card(generateMemberId(), select, getFutureDate(90), 300, getCurrentDate()));
			break;
		}
		else if (select == 5 )
		{
			this->m_memArray.at(this->m_memArray.size()-1)->cardArray.push_back(new Card(generateMemberId(), select, getFutureDate(365), 1000, getCurrentDate()));
			break;
		}
		else if (select == 0)
		{
			return;
		}
		else
		{
			cout << "输入错误，请重新输入" << endl;
		}

	}
	
	
	this->m_memNum = this->m_memArray.size();

	this->save();

	this->m_memArray.at(this->m_memArray.size() - 1)->m_cardNum++;

	this->m_memArray.at(this->m_memArray.size() - 1)->cardsave();

	this->m_FileIsEmpty = false;

	this->m_memArray.at(this->m_memArray.size() - 1)->m_cardFileIsEmpty = false;

	cout << "成功注册!" << endl;

	system("pause");
	system("cls");
}



void ClubA::login()
{
	this->showInfo();
	bool judge = true;
	int choice = 0;
	while (judge)
	{
		this->showMenu();
		cout << "请输入您的选择" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			this->returnBack(judge);
			break;
		case 1:
			this->accountLogin();
			break;
		case 2:
			this->accountRegister();
			break;
		default:
			break;
		}
	}
}




void ClubA::showMenu1()
{
	system("cls");

	cout << this->m_ClubName << "管理员权限如下：" << endl;
	cout << "0.返回" << endl;
	cout << "1.显示会员信息" << endl;
	cout << "2.删除过期会员" << endl;
	cout << "3.修改会员信息" << endl;
	cout << "4.查找会员信息" << endl;
	cout << "5.按照编号排序" << endl;
	cout << "6.清空所有信息" << endl;
}

void ClubA::Show_Mem()
{
	if (this->m_FileIsEmpty)
	{
		cout << "ClubA文件不存在或记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_memNum; i++)
		{
			this->m_memArray.at(i)->showInfo();

			cout << "持有卡：" << endl;

			for (int j = 0; j < this->m_memArray.at(i)->cardArray.size(); j++)
			{
				this->m_memArray.at(i)->cardArray.at(j)->showCardInfo();
			}
		}
	}
	system("pause");
	system("cls");
}

int ClubA::IsExist(string id)
{
	int index = -1;
	for (int i = 0; i < this->m_memNum; i++)
	{
		if (this->m_memArray.at(i)->m_Id == id)
		{
			index = i;

			break;
		}
	}
	return index;
}

void ClubA::Del_Mem()
{
	if (this->m_FileIsEmpty)
	{
		cout << "ClubA文件不存在或记录为空" << endl;
	}
	else
	{

		cout << "请输入要删除会员的编号：" << endl;
		string id = "";
		cin >> id;

		int const index = this->IsExist(id);

		if (index != -1)
		{
			for (int i = index; i < this->m_memNum - 1; i++)
			{
				this->m_memArray[i] = this->m_memArray[i + 1];//数据前移
			}
			this->m_memNum--;

			//同步文件中
			this->save();

			cout << "删除成功" << endl;

			if (this->m_memNum == 0)
			{
				this->m_FileIsEmpty = true;
			}
		}
		else
		{
			cout << "删除失败，未找到该会员" << endl;
		}
	}
	system("pause");
	system("cls");
}

void ClubA::Mod_Mem()
{
	if (this->m_FileIsEmpty)
	{
		cout << "ClubA文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入修改会员的编号" << endl;
		string id = "";
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			string newAccount = "";
			string newPassword = "";
			string newName = "";
			int newAge = 0;
			int newGender = 0;
			string newPhone = "";
			string newAddress = "";


			cout << id << "会员" << endl;

			cout << "请输入新账号：" << endl;
			cin >> newAccount;

			cout << "请输入新密码：" << endl;
			cin >> newPassword;

			cout << "请输入新姓名：" << endl;
			cin >> newName;

			cout << "请输入新年龄：" << endl;
			cin >> newAge;

			cout << "请输入新性别：" << endl;
			cout << "1.男" << endl;
			cout << "2.女" << endl;
			cin >> newGender;

			cout << "请输入新电话号码：" << endl;
			cin >> newPhone;

			cout << "请输入新地址：" << endl;
			cin >> newAddress;

			this->m_memArray.at(ret)->m_Id = id;
			this->m_memArray.at(ret)->m_Account = newAccount;
			this->m_memArray.at(ret)->m_Password = newPassword;
			this->m_memArray.at(ret)->m_Name = newName;
			this->m_memArray.at(ret)->m_Age = newAge;
			this->m_memArray.at(ret)->m_Gender = newGender;
			this->m_memArray.at(ret)->m_Phone = newPhone;
			this->m_memArray.at(ret)->m_Address = newAddress;

			//delete this->m_memArray.at(ret);//不是删除数组，是删除数组的一个元素的内容

			//auto it = this->m_memArray.begin() + ret;

			//this->m_memArray.insert(it, new Member(id, newAccount, newPassword, newName, newAge, newGender, newPhone, newAddress));

			this->save();

			cout << "修改成功" << endl;


		}
		else
		{
			cout << "修改失败，会员不存在！" << endl;
		}
	}
	system("pause");
	system("cls");
}

void ClubA::Find_Mem()
{
	if (this->m_FileIsEmpty)
	{
		cout << "ClubA文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1.按会员编号查找" << endl;
		cout << "2.按会员姓名查找" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			string id;
			cout << "请输入查找的会员编号" << endl;
			cin >> id;

			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功！该会员信息如下：" << endl;
				this->m_memArray.at(ret)->showInfo();

				
				for (int i = 0; i < this->m_memArray.at(ret)->cardArray.size(); i++)
				{
					this->m_memArray.at(ret)->cardArray.at(i)->showCardInfo();
				}

				
			}
			else
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "请输入查找的姓名" << endl;
			cin >> name;

			bool flag = false;

			for (int i = 0; i < this->m_memNum; i++)
			{
				if (this->m_memArray.at(i)->m_Name == name)
				{
					cout << "查找成功，会员编号为：" << this->m_memArray.at(i)->m_Id
						<< "号会员信息如下：" << endl;

					flag = true;

					this->m_memArray.at(i)->showInfo();

					
					for (int j = 0; j < this->m_memArray.at(i)->cardArray.size(); j++)
					{
						this->m_memArray.at(i)->cardArray.at(j)->showCardInfo();
					}
				}
			}

			if (flag == false)
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else
		{
			cout << "输入有误" << endl;
		}
	}
	system("pause");
	system("cls");
}

void ClubA::Sort_Mem()
{
	if (this->m_FileIsEmpty)
	{
		cout << "ClubA文件不存在或记录为空" << endl;

		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式：" << endl;
		cout << "1.按编号进行升序" << endl;
		cout << "2.按编号进行降序" << endl;

		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_memNum; i++)
		{
			int minOrMax = i;

			for (int j = i + 1; j < this->m_memNum; j++)
			{
				if (select == 1)
				{
					if (this->m_memArray.at(minOrMax)->m_Id > this->m_memArray.at(j)->m_Id)
					{
						minOrMax = j;
					}
				}
				else
				{
					if (this->m_memArray.at(minOrMax)->m_Id < this->m_memArray.at(j)->m_Id)
					{
						minOrMax = j;
					}
				}
			}

			if (i != minOrMax)
			{
				Member* temp = this->m_memArray.at(i);
				this->m_memArray.at(i) = this->m_memArray.at(minOrMax);
				this->m_memArray.at(minOrMax) = temp;
			}
		}

		cout << "排序成功！排序后的结果为：" << endl;

		this->save();

		this->Show_Mem();
	}
}

void ClubA::Clean_Mem()
{
	cout << "确定清空？" << endl;
	cout << "1、清空" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_memArray.empty() == false)
		{
			for (int i = 0; i < this->m_memArray.size(); i++)
			{
				int const result = remove(this->m_memArray.at(i)->filename.c_str());

				if (result == 0) 
				{
					cout << "文件 " << this->m_memArray.at(i)->filename << " 已成功删除。" << endl;
				}
				else 
				{
					cerr << "无法删除文件 " << this->m_memArray.at(i)->filename << "。错误代码: " << result << endl;
				}

				delete this->m_memArray.at(i);

				this->m_memArray.at(i) = nullptr;
			}

			this->m_memArray.clear();

			this->m_memNum = 0;

			this->m_FileIsEmpty = true;


		}

		cout << "清空成功！" << endl;
	}

	system("pause");
	system("cls");
}








void ClubA::showMenu2()
{
	system("cls");

	cout << this->m_ClubName << "会员权限如下：" << endl;
	cout << "0.返回" << endl;
	cout << "1.制定训练方案" << endl;
	cout << "2.教练团队" << endl;
	cout << "3.显示个人信息" << endl;
	cout << "4.修改个人信息" << endl;
	cout << "5.会员办卡" << endl;
	cout << "6.会员续费" << endl;
	cout << "7.会员消费结算" << endl;
	cout << "8.会员退卡" << endl;
	
}

void ClubA::Show_Sin(int index)
{
	this->m_memArray.at(index)->showInfo();
	for (int i = 0; i < this->m_memArray.at(index)->m_cardNum; i++)
	{
		if (this->m_memArray.at(index)->m_cardFileIsEmpty == false)
		{
			this->m_memArray.at(index)->cardArray.at(i)->showCardInfo();
		}
		else
		{
			cout << "无持有卡" << endl;
		}
		cout << endl;
		
	}
	

	system("pause");
	system("cls");
}

void ClubA::Mod_Sin(int index)
{
	string newAccount = "";
	string newPassword = "";
	string newName = "";
	int newAge = 0;
	int newGender = 0;
	string newPhone = "";
	string newAddress = "";

	cout << this->m_memArray.at(index)->m_Id << "会员" << endl;

	cout << "请输入新账号：" << endl;
	cin >> newAccount;

	cout << "请输入新密码：" << endl;
	cin >> newPassword;

	cout << "请输入新姓名：" << endl;
	cin >> newName;

	cout << "请输入新年龄：" << endl;
	cin >> newAge;

	cout << "请输入新性别：" << endl;
	cout << "1.男" << endl;
	cout << "2.女" << endl;
	cin >> newGender;

	cout << "请输入新电话号码：" << endl;
	cin >> newPhone;

	cout << "请输入新地址：" << endl;
	cin >> newAddress;

	this->m_memArray.at(index)->m_Account = newAccount;
	this->m_memArray.at(index)->m_Password = newPassword;
	this->m_memArray.at(index)->m_Name = newName;
	this->m_memArray.at(index)->m_Age = newAge;
	this->m_memArray.at(index)->m_Gender = newGender;
	this->m_memArray.at(index)->m_Phone = newPhone;
	this->m_memArray.at(index)->m_Address = newAddress;

	this->save();

	cout << "修改成功" << endl;

	system("pause");
	system("cls");
}

void ClubA::Add_Card(int index)
{
	cout << "请输入你想要的会员卡类型" << endl;
	cout << "日卡---1" << endl;
	cout << "周卡---2" << endl;
	cout << "月卡---3" << endl;
	cout << "季卡---4" << endl;
	cout << "年卡---5" << endl;

	int type;

	while (true)
	{
		cin >> type;

		if (type == 1)
		{
			this->m_memArray.at(index)->cardArray.push_back(new Card(generateMemberId(), type, getFutureDate(3), 30, getCurrentDate()));
			break;
		}
		else if (type == 2)
		{
			this->m_memArray.at(index)->cardArray.push_back(new Card(generateMemberId(), type, getFutureDate(7), 70, getCurrentDate()));
			break;
		}
		else if (type == 3)
		{
			this->m_memArray.at(index)->cardArray.push_back(new Card(generateMemberId(), type, getFutureDate(30), 150, getCurrentDate()));
			break;
		}
		else if (type == 4)
		{
			this->m_memArray.at(index)->cardArray.push_back(new Card(generateMemberId(), type, getFutureDate(90), 300, getCurrentDate()));
			break;
		}
		else if (type == 5)
		{
			this->m_memArray.at(index)->cardArray.push_back(new Card(generateMemberId(), type, getFutureDate(365), 1000, getCurrentDate()));
			break;
		}
		else
		{
			cout << "输入错误，请重新输入" << endl;
		}

	}

	this->m_memArray.at(index)->m_cardNum++;

	this->m_memArray.at(index)->cardsave();

	this->m_memArray.at(this->m_memArray.size() - 1)->m_cardFileIsEmpty = false;

	cout << "成功办卡!" << endl;

	system("pause");
	system("cls");
}


void ClubA::renew_Sin(int index)
{
	if (this->m_memArray.at(index)->m_cardFileIsEmpty)
	{
		cout << this->m_memArray.at(index)->filename << "文件不存在或记录为空" << endl;
	}
	else
	{
		string targetCardId;
		cout << "请输入要续费的卡ID：" << endl;
		cin >> targetCardId;

		int const ret = this->m_memArray.at(index)->IsCardExist(targetCardId);
		if (ret != -1)
		{
			cout << "查找成功！该会员卡信息如下：" << endl;
			this->m_memArray.at(index)->cardArray.at(ret)->showCardInfo();


			cout << "找到会员信息，请输入续费金额：" << endl;
			//根据用户输入的续费金额，更新会员卡的有效期（根据卡类型和续费金额计算延长的时长）以及余额信息，并将更新后的信息保存到数据文件中，同时提示续费成功及更新后的信息。
			double renewalAmount;
			cin >> renewalAmount;

			// 根据卡类型和续费金额计算延长的时长
			short newDuration = 0;
			switch (this->m_memArray.at(index)->cardArray.at(ret)->Ctype) {
			case 1:
				newDuration = static_cast<short>(renewalAmount / 10 * 3);
				break;
			case 2:
				newDuration = static_cast<short>(renewalAmount / 70 * 7);
				break;
			case 3:
				newDuration = static_cast<short>(renewalAmount / 150 * 30);
				break;
			case 4:
				newDuration = static_cast<short>(renewalAmount / 300 * 90);
				break;
			case 5:
				newDuration = static_cast<short>(renewalAmount / 1000 * 365);
				break;
			default:
				break;
			}

			// 更新有效期和余额信息
			this->m_memArray.at(index)->cardArray.at(ret)->Cbalance += renewalAmount;
			this->m_memArray.at(index)->cardArray.at(ret)->CexpirationDate = getFutureDate(newDuration);


			this->m_memArray.at(index)->cardsave();

			cout << "成功续费" << endl;
		}
		else
		{
			cout << "查找失败，查无此卡" << endl;
		}
		
	}
	system("pause");
	system("cls");

}

void  ClubA::processConsumption(int index)
{

	if (this->m_memArray.at(index)->m_cardFileIsEmpty)
	{
		cout << this->m_memArray.at(index)->filename << "文件不存在或记录为空" << endl;
	}
	else
	{
		string targetCardId;
		cout << "请输入消费的卡ID：" << endl;
		cin >> targetCardId;


		int const ret = this->m_memArray.at(index)->IsCardExist(targetCardId);
		
		cout << "找到会员信息，请输入本次消费金额：" << endl;
		double consumptionAmount;
		cin >> consumptionAmount;

		

		if (ret != -1)
		{
			// 折扣优惠
			double discountRate = 1.0;
			if (this->m_memArray.at(index)->cardArray.at(ret)->Ctype == 1)
			{
				discountRate = 0.9;
			}
			else if (this->m_memArray.at(index)->cardArray.at(ret)->Ctype == 2)
			{
				discountRate = 0.8;
			}
			else if (this->m_memArray.at(index)->cardArray.at(ret)->Ctype == 3)
			{
				discountRate = 0.7;
			}
			else if (this->m_memArray.at(index)->cardArray.at(ret)->Ctype == 4)
			{
				discountRate = 0.6;
			}
			else if (this->m_memArray.at(index)->cardArray.at(ret)->Ctype == 5)
			{
				discountRate = 0.5;
			}

			double const actualConsumptionAmount = consumptionAmount * discountRate;

			// 从会员卡余额中扣除该金额
			this->m_memArray.at(index)->cardArray.at(ret)->Cbalance -= actualConsumptionAmount;

			// 更新成员信息
			this->m_memArray.at(index)->cardsave();

			cout << "成功扣除" << endl;
		}

	}
	system("pause");
	system("cls");
	

}

void  ClubA::cancelCard(int index)
{
	if (this->m_memArray.at(index)->m_cardFileIsEmpty)
	{
		cout << this->m_memArray.at(index)->filename << "文件不存在或记录为空" << endl;
	}
	else
	{
		string targetCardId;
		cout << "请输入要退的卡ID：" << endl;
		cin >> targetCardId;


		int const ret = this->m_memArray.at(index)->IsCardExist(targetCardId);

		if (ret != -1)
		{
			for (int i = ret; i < this->m_memArray.at(index)->m_cardNum - 1; i++)
			{
				this->m_memArray.at(index)->cardArray.at(i) = this->m_memArray.at(index)->cardArray.at(i+1);//数据前移

				if (i == this->m_memArray.at(index)->m_cardNum - 2)
				{
					delete this->m_memArray.at(i + 1);

					this->m_memArray.at(i + 1) = nullptr;
				}
			}
			this->m_memArray.at(index)->m_cardNum--;

			//同步文件中
			this->m_memArray.at(index)->cardsave();

			cout << "退卡成功" << endl;

			if (this->m_memArray.at(index)->m_cardNum == 0)
			{
				this->m_memArray.at(index)->m_cardFileIsEmpty = true;
			}
		}
		else
		{
			cout << "删除失败，未找到该卡" << endl;
		}
	}
	system("pause");
	system("cls");
}

void ClubA::displayTrainer()
{
	cout << "优秀教练如下：" << endl;

	cout << endl;

	for (const auto& trainer : this->trainers)
	{
		trainer.showInfo();
	}

	system("pause");
	system("cls");
}

void ClubA::createCustomTrainingPlan(int index)
{
	cout << "请输入你的健身计划：(增肌/减脂/提高心肺功能)" << endl;
	string fitnessGoal;
	cin >> fitnessGoal;
	this->m_memArray.at(index)->fitnessGoal = fitnessGoal;


	if (this->m_memArray.at(index)->fitnessGoal == "增肌") {
		this->m_memArray.at(index)->trainingPlan.push_back("杠铃卧推，3组，每组8 - 10次");
		this->m_memArray.at(index)->trainingPlan.push_back("哑铃肩推，3组，每组8 - 10次");
		this->m_memArray.at(index)->trainingPlan.push_back("深蹲，3组，每组8 - 10次");
	}
	else if (this->m_memArray.at(index)->fitnessGoal == "减脂") {
		this->m_memArray.at(index)->trainingPlan.push_back("慢跑，30分钟");
		this->m_memArray.at(index)->trainingPlan.push_back("跳绳，15分钟");
		this->m_memArray.at(index)->trainingPlan.push_back("高强度间歇训练（HIIT），20分钟");
	}
	else if (this->m_memArray.at(index)->fitnessGoal == "提高心肺功能") {
		this->m_memArray.at(index)->trainingPlan.push_back("动感单车课程，45分钟");
		this->m_memArray.at(index)->trainingPlan.push_back("游泳，30分钟");
		this->m_memArray.at(index)->trainingPlan.push_back("有氧操，30分钟");
	}
}

void ClubA::displayTrainingPlan(int index)
{
	cout << this->m_memArray.at(index)->m_Name << " 的训练计划如下：" << endl;

	for (const auto& plan : this->m_memArray.at(index)->trainingPlan)
	{
		cout << "- " << plan << endl;
	}

	system("pause");
	system("cls");
}

ClubA::~ClubA()
{
	for (size_t i = 0; i < m_memArray.size(); i++)
	{
		if (m_memArray.at(i) != nullptr)
		{
			delete m_memArray.at(i);
			this->m_memArray.at(i) = nullptr;
		}
	}
	this->m_memArray.clear();
		
}