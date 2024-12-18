#include "Functions.h"

string generateMemberId()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	string memberId = "M";
	for (int i = 0; i < 6; ++i)
	{
		memberId += static_cast<char>(rand() % 10 + '0');
	}
	return memberId;
}

// 获取当前日期（格式为YYYY-MM-DD）
string getCurrentDate()
{
	time_t now = time(nullptr);

	struct tm tmNow;

	errno_t err = localtime_s(&tmNow, &now);
	if (err != 0)
	{
		cerr << "获取当前时间失败！" << endl;
		return string("");
	}

	char buffer[11];
	strftime(buffer, sizeof(buffer), "%Y-%m-%d", &tmNow);

	return string(buffer);
}


// 获取未来指定天数后的日期（格式为YYYY-MM-DD）
string getFutureDate(short validDays)
{
	time_t now = time(nullptr);

	struct tm tmNow;
	errno_t err = localtime_s(&tmNow, &now);
	if (err != 0)
	{
		// 如果获取当前时间失败，这里可以根据具体需求进行错误处理，比如抛出异常或返回一个默认值等
		cerr << "获取当前时间失败！" << endl;
		return string("");
	}

	// 备份原始的日期信息
	struct tm originalTm = tmNow;

	tmNow.tm_mday += validDays;

	// 处理月份和年份的溢出
	while (tmNow.tm_mday > ((tmNow.tm_mon == 1 && (tmNow.tm_year % 4 == 0 && (tmNow.tm_year % 100 != 0 || tmNow.tm_year % 400 == 0))) ? 29 : (tmNow.tm_mon % 7 % 2 == 0 && tmNow.tm_mon != 1) ? 30 : 31))
	{
		tmNow.tm_mday -= ((tmNow.tm_mon == 1 && (tmNow.tm_year % 4 == 0 && (tmNow.tm_year % 100 != 0 || tmNow.tm_year % 400 == 0))) ? 29 : (tmNow.tm_mon % 7 % 2 == 0 && tmNow.tm_mon != 1) ? 30 : 31);

		tmNow.tm_mon++;
		if (tmNow.tm_mon > 11)
		{
			tmNow.tm_mon = 0;
			tmNow.tm_year++;
		}
	}

	time_t expTime = mktime(&tmNow);

	if (expTime == -1)
	{
		// 如果时间转换失败，恢复到原始日期并返回
		tmNow = originalTm;
		expTime = mktime(&tmNow);
	}

	struct tm expTm;

	err = localtime_s(&expTm, &expTime);

	if (err != 0)
	{
		// 如果获取转换后的时间失败，这里可以根据具体需求进行错误处理，比如抛出异常或返回一个默认值等
		cerr << "获取转换后的时间失败！" << endl;
		return std::string("");
	}

	char buffer[11];

	strftime(buffer, sizeof(buffer), "%Y-%m-%d", &expTm);

	return string(buffer);
}