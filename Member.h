#pragma once
#include "Card.h"
#include <vector>

using namespace std;

class Member
{
public:
	string m_Id;

	string m_Account;

	string m_Password;

	string m_Name;

	int m_Age;

	int m_Gender;

	string m_Phone;

	string m_Address;

	vector<Card*>cardArray;

	int m_cardNum ;

	bool m_cardFileIsEmpty;

	string filename;


	string fitnessGoal; // 健身目标，比如 "增肌"、"减脂"、"提高心肺功能" 等

	vector<string> trainingPlan;  // 训练计划

	Member();

	Member(string m_Id,string account, string password, string name, int age, int gender, string phone, string address);

	void showInfo();

	void init_Card();

	int IsCardExist(string id);

	void cardsave();

	~Member();
};
