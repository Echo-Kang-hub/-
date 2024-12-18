#include <iostream>
#include "ClubManager.h"
#include "ClubA.h"
#include "ClubB.h"
#include "ClubC.h"


#include <fstream>
#define FILENAME "Club.txt"

ClubManager::ClubManager()
{
	this->m_ClubNum = 0;

	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		//cout << "Club文件不存在!" << endl;

		this->m_ClubNum = 0;
		
		this->m_FileIsEmpty = true;
		ifs.close();
		return;//文件不存在不再执行构造函数
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "Club文件为空!" << endl;
		this->m_ClubNum = 0;
		
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	this->init_Club();//用文件数据初始化堆区空间数组

	if (this->m_ClubNum != 0)
	{
		this->m_FileIsEmpty = false;
	}

	//cout << "俱乐部个数为：" << this->m_ClubNum << endl;

	 

}

void ClubManager::showMenu()
{
	cout << "********************************" << endl;
	cout << "******欢迎使用健身房会员系统！******" << endl;
	cout << "*********0.退出系统*********" << endl;
	cout << "*********1.选择俱乐部*********" << endl;
	cout << "*********2.显示俱乐部*********" << endl;
	cout << "********************************" << endl;
	cout << "*********管理员选项如下：*********" << endl;
	cout << "*********3.添加俱乐部*********" << endl;
	cout << "*********4.删除俱乐部*********" << endl;
	cout << "*********5.修改俱乐部*********" << endl;
	cout << "*********6.查找俱乐部*********" << endl;
	cout << "*********7.按照编号排序*********" << endl;
	cout << "*********8.清空俱乐部*********" << endl;
	cout << "********************************" << endl;
}

void ClubManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;

	system("pause");
	exit(0);
}



void ClubManager::init_Club()//读取文件数据存入程序中
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int ctype;
	int cId;
	string name;
	int rank;
	string account;
	string password;


	while ( ifs>>ctype && ifs >> cId && ifs >> name && ifs>>rank && ifs >> account && ifs >> password)
	{
		

		if (ctype == 1)
		{
			this->m_ClubArray.push_back(new ClubA(ctype,cId, name, rank, account,password));
		}
		else if (ctype == 2)
		{
			this->m_ClubArray.push_back(new ClubB(ctype, cId, name, rank, account, password));
		}
		else if (ctype == 3)
		{
			this->m_ClubArray.push_back(new ClubC(ctype, cId, name, rank, account, password));
		}
		this->m_ClubNum++;
	}
	ifs.close();
}


void ClubManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	if (!ofs.is_open()) 
	{
		cerr << "无法打开文件: " << FILENAME << endl;
		// 可以在这里进一步添加错误处理逻辑，比如抛出异常或者尝试其他操作等
		return;
	}
	for (int i = 0; i < this->m_ClubNum; i++)
	{
		ofs << this->m_ClubArray.at(i)->m_Type<<" "
			<< this->m_ClubArray.at(i)->m_Id << " "
			<< this->m_ClubArray.at(i)->m_ClubName << " "
			<< this->m_ClubArray.at(i)->m_ClubRank << " "
			<< this->m_ClubArray.at(i)->m_managerAccount << " "
			<< this->m_ClubArray.at(i)->m_managerPassword << endl;
	}

	ofs.close();
}


int ClubManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_ClubNum; i++)
	{
		if (this->m_ClubArray.at(i)->m_Id == id)
		{
			index = i;

			break;
		}
	}
	return index;
}

bool ClubManager::authenticate() const 
{
	string inputPassword;
	cout << "请输入管理员密码: ";
	cin >> inputPassword;
	return inputPassword == "1234567890";
}

void ClubManager::addClub()
{
	if (this->authenticate())
	{
		cout << "请输入添加俱乐部数量:" << endl;
		int addNum = 0;
		cin >> addNum;

		if (addNum > 0)
		{
			int const newSize = this->m_ClubNum + addNum;


			for (int i = 0; i < addNum; i++)
			{
				int id;
				string name;
				int rank;
				string account;
				string password;

				int dSelect;

				cout << "请输入第" << i + 1 << "个新俱乐部编号:" << endl;
				cin >> id;


				if (this->IsExist(id) != -1)
				{
					cout << "重复，请重新输入" << endl;
					i = -1;
					continue;
				}


				cout << "请输入第" << i + 1 << "个新俱乐部名称:" << endl;
				cin >> name;

				cout << "请输入第" << i + 1 << "个新俱乐部排名:" << endl;
				cin >> rank;

				cout << "请输入第" << i + 1 << "个新俱乐部管理员账号:" << endl;
				cin >> account;

				cout << "请输入第" << i + 1 << "个新俱乐部管理员密码:" << endl;
				cin >> password;

				cout << "请选择俱乐部类型:" << endl;
				cout << "1.A" << endl;
				cout << "2.B" << endl;
				cout << "3.C" << endl;
				cin >> dSelect;

				switch (dSelect)
				{
				case 1:
					this->m_ClubArray.push_back(new ClubA(dSelect,id, name, rank, account, password));
					break;
				case 2:
					this->m_ClubArray.push_back(new ClubB(dSelect, id, name, rank, account, password));
					break;
				case 3:
					this->m_ClubArray.push_back(new ClubC(dSelect, id, name, rank, account, password));
					break;
				default:
					break;
				}
			}

			this->m_ClubNum = newSize;

			this->m_FileIsEmpty = false;


			this->save();


			cout << "成功添加" << addNum << "个新俱乐部!" << endl;

		}
		else
		{
			cout << "输入数据错误" << endl;
		}
		system("pause");
		system("cls");
	}
	else
	{
		cout << "您无权限，请退出" << endl;
		system("pause");
		system("cls");
		exit(0);
		
	}
	
}


void ClubManager::ShowClub()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "A类型俱乐部如下：" << endl;

		for (int i = 0; i < m_ClubNum; i++)
		{

			if (this->m_ClubArray.at(i)->m_Type == 1)
			{
				this->m_ClubArray.at(i)->showInfo();

				cout << endl;
			}
		}

		cout << "B类型俱乐部如下：" << endl;

		for (int i = 0; i < m_ClubNum; i++)
		{

			if (this->m_ClubArray.at(i)->m_Type == 2)
			{
				this->m_ClubArray.at(i)->showInfo();

				cout << endl;
			}
		}

		cout << "C类型俱乐部如下：" << endl;

		for (int i = 0; i < m_ClubNum; i++)
		{
			
			if (this->m_ClubArray.at(i)->m_Type == 3)
			{
				this->m_ClubArray.at(i)->showInfo();

				cout << endl;
			}
		}
	}

	system("pause");

	system("cls");
}

void ClubManager::DelClub()
{
	if (this->authenticate())
	{
		if (this->m_FileIsEmpty)
		{
			cout << "文件不存在或记录为空" << endl;
		}
		else
		{

			cout << "请输入要删除俱乐部的ID：" << endl;
			int id = 0;
			cin >> id;

			int const index = this->IsExist(id);

			if (index != -1)
			{
				delete this->m_ClubArray.at(index);
				for (int i = index; i < this->m_ClubNum - 1; i++)
				{
					this->m_ClubArray.at(i) = this->m_ClubArray.at(i+1);//数据前移

					if (i == this->m_ClubNum - 2)
					{
						delete this->m_ClubArray.at(i+1);

						this->m_ClubArray.at(i + 1) = nullptr;
					}
				}

				this->m_ClubNum--;

				//同步文件中
				this->save();

				cout << "删除成功" << endl;

				if (this->m_ClubNum == 0)
				{
					this->m_FileIsEmpty = true;
				}
			}
			else
			{
				cout << "删除失败，未找到该俱乐部" << endl;
			}
		}
		system("pause");
		system("cls");
	}
	else
	{
		cout << "您无权限，请退出" << endl;
		system("pause");
		system("cls");
		exit(0);
	}
	

}


void ClubManager::ModClub()
{
	if (this->authenticate())
	{
		if (this->m_FileIsEmpty)
		{
			cout << "文件不存在或记录为空" << endl;
		}
		else
		{
			cout << "请输入修改俱乐部的编号" << endl;
			int id = 0;
			cin >> id;

			int const ret = this->IsExist(id);
			if (ret != -1)
			{
				int newId = 0;
				string newName = "";
				int newRank = 0;
				string newaccount = "";
				string newpassword = "";
				int newType = 0;

				cout << "查到：" << id << "号俱乐部，请输入新ID号：" << endl;
				cin >> newId;

				cout << "请输入新名称：" << endl;
				cin >> newName;

				cout << "请输入新排名：" << endl;
				cin >> newRank;

				cout << "请输入新账号：" << endl;
				cin >> newaccount;

				cout << "请输入新密码：" << endl;
				cin >> newpassword;

				cout << "请输入俱乐部类型：" << endl;
				cout << "1.A" << endl;
				cout << "1.B" << endl;
				cout << "1.C" << endl;

				cin >> newType;

				delete this->m_ClubArray.at(ret);//不是删除数组，是删除数组的一个元素的内容

				this->m_ClubArray.at(ret) = nullptr;

				switch (newType)
				{
				case 1:
					this->m_ClubArray.at(ret) = new ClubA(newType, newId, newName, newRank, newaccount, newpassword);
					break;
				case 2:
					this->m_ClubArray.at(ret) = new ClubB(newType, newId, newName, newRank, newaccount, newpassword);
					break;
				case 3:
					this->m_ClubArray.at(ret) = new ClubC(newType, newId, newName, newRank, newaccount, newpassword);
					break;
				default:
					break;
				}

				this->save();

				cout << "修改成功" << endl;
			}
			else
			{
				cout << "修改失败，俱乐部不存在！" << endl;
			}
		}
		system("pause");
		system("cls");
	}
	else
	{
		cout << "您无权限，请退出" << endl;
		system("pause");
		system("cls");
		exit(0);
	}
	
}

void ClubManager::FindClub()
{
	if (this->authenticate())
	{
		if (this->m_FileIsEmpty)
		{
			cout << "文件不存在或记录为空" << endl;
		}
		else
		{
			cout << "请输入查找的方式：" << endl;
			cout << "1.按俱乐部编号查找" << endl;
			cout << "2.按俱乐部名称查找" << endl;

			int select = 0;
			cin >> select;

			if (select == 1)
			{
				int id;
				cout << "请输入查找的俱乐部ID" << endl;
				cin >> id;

				int const ret = IsExist(id);
				if (ret != -1)
				{
					cout << "查找成功！该俱乐部信息如下：" << endl;
					this->m_ClubArray.at(ret)->showInfo();
				}
				else
				{
					cout << "查找失败" << endl;
				}
			}
			else if (select == 2)
			{
				string name;
				cout << "请输入查找的名称" << endl;
				cin >> name;

				bool flag = false;

				for (int i = 0; i < m_ClubNum; i++)
				{
					if (this->m_ClubArray.at(i)->m_ClubName == name)
					{
						cout << "查找成功，俱乐部ID为：" << this->m_ClubArray.at(i)->m_Id
							<< "号俱乐部信息如下：" << endl;

						flag = true;

						this->m_ClubArray.at(i)->showInfo();
					}
				}

				if (flag == false)
				{
					cout << "查找失败" << endl;
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
	else
	{
		cout << "您无权限，请退出" << endl;
		system("pause");
		system("cls");
		exit(0);
	}
	
}

void ClubManager::SortClub()
{
	if (this->authenticate())
	{
		if (this->m_FileIsEmpty)
		{
			cout << "文件不存在或记录为空" << endl;

			system("pause");
			system("cls");
		}
		else
		{
			cout << "请选择排序方式：" << endl;
			cout << "1.按ID号进行升序" << endl;
			cout << "2.按ID号进行降序" << endl;
			cout << "3.按排名进行升序" << endl;
			cout << "4.按排名进行降序" << endl;

			int select = 0;
			cin >> select;
			if (select == 1 || select == 2)
			{
				for (int i = 0; i < this->m_ClubNum; i++)
				{
					int minOrMax = i;

					for (int j = i + 1; j < this->m_ClubNum; j++)
					{
						if (select == 1)
						{
							if (this->m_ClubArray.at(minOrMax)->m_Id > this->m_ClubArray.at(j)->m_Id)
							{
								minOrMax = j;
							}
						}
						else
						{
							if (this->m_ClubArray.at(minOrMax)->m_Id < this->m_ClubArray.at(j)->m_Id)
							{
								minOrMax = j;
							}
						}
					}

					if (i != minOrMax)
					{
						Manager* temp = this->m_ClubArray.at(i);
						this->m_ClubArray.at(i) = this->m_ClubArray.at(minOrMax);
						this->m_ClubArray.at(minOrMax) = temp;
					}
				}
			}
			else if (select == 3 || select == 4)
			{
				for (int i = 0; i < this->m_ClubNum; i++)
				{
					int minOrMax = i;

					for (int j = i + 1; j < this->m_ClubNum; j++)
					{
						if (select == 3)
						{
							if (this->m_ClubArray.at(minOrMax)->m_ClubRank > this->m_ClubArray.at(j)->m_ClubRank)
							{
								minOrMax = j;
							}
						}
						else
						{
							if (this->m_ClubArray.at(minOrMax)->m_ClubRank < this->m_ClubArray.at(j)->m_ClubRank)
							{
								minOrMax = j;
							}
						}
					}

					if (i != minOrMax)
					{
						Manager* temp = this->m_ClubArray.at(i);
						this->m_ClubArray.at(i) = this->m_ClubArray.at(minOrMax);
						this->m_ClubArray.at(minOrMax) = temp;
					}
				}
			}


			cout << "排序成功！排序后的结果为：" << endl;

			this->save();

			this->ShowClub();
		}
	}
	else
	{
		cout << "您无权限，请退出" << endl;
		system("pause");
		system("cls");
		exit(0);
	}
	
}

void ClubManager::CleanClub()
{
	if (this->authenticate())
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

			if (!this->m_ClubArray.empty())
			{
				for (int i = 0; i < this->m_ClubArray.size(); i++)
				{
					delete this->m_ClubArray.at(i);
					this->m_ClubArray.at(i) = nullptr;
				}

				//clear不能释放内存,只能清空容器内元素
				this->m_ClubArray.clear();//先把开辟的堆区内存释放，然后清空容器内所有元素，会将vector的大小（通过size()函数获取）设置为 0

				this->m_ClubNum = 0;
				this->m_FileIsEmpty = true;
			}

			cout << "清空成功！" << endl;
		}

		system("pause");
		system("cls");
	}
	else
	{
		cout << "您无权限，请退出" << endl;
		system("pause");
		system("cls");
		exit(0);
	}
	

}

void ClubManager::selectClub() 
{
	system("cls");

	int index;
	cout << "选择俱乐部:\n";
	for (int i = 0; i < this->m_ClubArray.size(); ++i) 
	{
		if (this->m_ClubArray.at(i) != nullptr)
		{
			if (this->m_ClubArray.at(i)->m_Type == 1)
			{
				cout << i + 1 << ". A型：" << this->m_ClubArray.at(i)->m_ClubName << "--------- A级俱乐部：高端私人健身俱乐部  ->  1.环境高端舒适 2.个性化服务极致 3.课程和设施定制化 4.隐私性强" << endl;
			}

			else if (this->m_ClubArray.at(i)->m_Type == 2)
			{
				cout << i + 1 << ". B型：" << this->m_ClubArray.at(i)->m_ClubName << "--------- B级俱乐部：商业综合型健身房俱乐部  ->  1.设施齐全 2.课程丰富" << endl;
			}

			else if (this->m_ClubArray.at(i)->m_Type == 3)
			{
				cout << i + 1 << ". C型：" << this->m_ClubArray.at(i)->m_ClubName << "--------- C级俱乐部：社区小型健身房俱乐部  ->  1.位置便利 2.氛围亲切友好 3.价格亲民 4.活动丰富" << endl;
			}
			
		}
		
	}

	cout << "请输入选择: ";
	cin >> index;
	if (index > 0 && index <= this->m_ClubArray.size())
	{
		this->m_ClubArray.at(index-1)->login();  // 使用多态调用对应俱乐部的登录函数
	}
	else 
	{
		cout << "无效选择！\n";
	}
}

ClubManager::~ClubManager()noexcept
{
	for (size_t i = 0; i < m_ClubArray.size(); i++) 
	{
		if (m_ClubArray.at(i) != nullptr) 
		{
			delete m_ClubArray.at(i);
			this->m_ClubArray.at(i) = nullptr;
		}
	}
	m_ClubArray.clear();
}


