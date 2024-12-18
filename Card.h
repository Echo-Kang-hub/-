#pragma once
#include <string>
using namespace std;

class Card
{
public:
	string Cid;
	short Ctype = 0;
	string CexpirationDate;
	double Cbalance = 0;
	string consumptionTime;

	

	Card(string Cid, short type, string expirationDate, double balance,string consumptionTime);

	void showCardInfo();

	~Card();

};
