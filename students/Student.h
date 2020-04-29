#pragma once
#include <string>
#include <regex>
#include "Date.h"

using namespace std;

class Student
{
private:
	int Id;
	string Name;
	string SecName;
	string Patronymic;
	Date DayOfBirth;
	Date YearStart;
	string Faculty;
	string Group;
	string RecordBook;
public:
	Student();
	Student(int id, string name, string secname, string patro, Date dayofbirth, Date yearstart,
		string faculttm, string group, string recbook);
	Student(const Student& s);
	Student(string s);

	int getId();
	string getName();
	string getSecName();
	string getPatronymic();
	Date getDayOfBirth();
	Date getYearStart();
	string getRecordBook();
	string getFaculty();
	string getGroup();

	void setId(int id);
	void setName(string name);
	void setSecName(string secname);
	void setPatronymic(string patro);
	void setDayOfBirth(Date date);
	void setYearStart(Date date);
	void setRecordBook(string r);
	void setFaculty(string f);
	void setGroup(string g);


	void setStudent(int id, string name, string secname, string patro, Date dayofbirth, Date yearstart,
		string faculttm, string group, string recbook);
	void print() const;

	string ToString();
};

