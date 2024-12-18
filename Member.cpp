#include <iostream>
#include <string>
#include <fstream>
#include "Member.h"


Member::Member()
{

}

Member::Member(string id,string account, string password, string name, int age, int gender, string phone, string address)
{
	this->m_Id = id;

	this->m_Account=account;

	this->m_Password=password;

	this->m_Name=name;

	this->m_Age=age;

	this->m_Gender=gender;

	this->m_Phone=phone;

	this->m_Address=address;

	this->m_cardNum = 0;

	this->filename = this->m_Id + "_" + this->m_Account + "_" + "user_card_data" + ".txt";

	ifstream ifs;
	ifs.open(this->filename, ios::in);

	if (!ifs.is_open())
	{
		//cout << this->filename << "文件不存在!" << endl;

		this->m_cardNum = 0;

		this->m_cardFileIsEmpty = true;
		ifs.close();
		return;//文件不存在不再执行构造函数
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << this->filename << "文件为空!" << endl;
		this->m_cardNum = 0;

		this->m_cardFileIsEmpty = true;
		ifs.close();
		return;
	}

	this->init_Card();//用文件数据初始化堆区空间数组

	//cout << "卡个数为：" << this->m_cardNum << endl;



}

void Member::showInfo()
{
	cout<<"会员编号:"<<this->m_Id<<" "
		<< "\t账号:" << this->m_Account << " "
		<< "\t姓名:" << this->m_Name << " "
		<< "\t年龄:" << this->m_Age << " "
		<< "\t性别:" << (this->m_Gender==1?"男":"女") << " "
		<< "\t电话号码:" << this->m_Phone << " "
		<< "\t地址:" << this->m_Address<< endl;
}

void Member::init_Card()
{
	ifstream ifs;
	ifs.open(this->filename, ios::in);

	string id;
	short type = 0;
	string expirationDate;
	double balance = 0;
	string consumptionTime;


	while (ifs >> id && ifs >> type && ifs >> expirationDate && ifs >> balance && ifs >> consumptionTime)
	{

		this->cardArray.push_back(new Card(id,type,expirationDate, balance, consumptionTime));

		this->m_cardNum++;
	}
	ifs.close();
}

int Member::IsCardExist(string id)
{
	int index = -1;
	for (int i = 0; i < this->cardArray.size(); i++)
	{
		if (this->cardArray.at(i)->Cid==id)
		{
			index = i;

			break;
		}
	}
	return index;
}

void Member::cardsave()
{
	ofstream ofs;
	ofs.open(this->filename, ios::out);

	for (int i = 0; i < this->m_cardNum; i++)
	{
		ofs << this->cardArray.at(i) ->Cid << " "
			<< this->cardArray.at(i) ->Ctype << " "
			<< this->cardArray.at(i) ->CexpirationDate << " "
			<< this->cardArray.at(i) ->Cbalance <<" "
			<< this->cardArray.at(i) ->consumptionTime <<" "<< endl;
	}

	ofs.close();
}

Member::~Member()noexcept
{
	for (size_t i = 0; i < this->cardArray.size(); i++)
	{
		if (this->cardArray.at(i) != nullptr)
		{
			delete this->cardArray.at(i);
			this->cardArray.at(i) = nullptr;
		}
	}
	this->cardArray.clear();
}
