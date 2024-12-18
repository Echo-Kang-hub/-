#include <iostream>
#include <string>
#include <fstream>
#include "Card.h"

Card::Card(string id, short type, string expirationDate, double balance, string consumptionTime)
{
	this->Cid = id;
	this->Ctype = type;
	this->CexpirationDate = expirationDate;
	this->Cbalance = balance;
	this->consumptionTime = consumptionTime;

}

void Card::showCardInfo()
{
	cout << "卡ID：" << this->Cid << " ";
	switch (this->Ctype)
	{
	case 1:
		cout << "卡型：次卡  ";
		break;
	case 2:
		cout << "卡型：周卡  ";
		break;
	case 3:
		cout << "卡型：月卡  ";
		break;
	case 4:
		cout << "卡型：季卡  ";
		break;
	case 5:
		cout << "卡型：年卡  ";
		break;
	default:
		break;
	}
	
	cout<< "卡到期时间：" << this->CexpirationDate << " "
		<< "卡所剩余额：" << this->Cbalance <<" "
		<<"消费初始日期："<<this->consumptionTime << endl;
}

Card::~Card()
{
	
}