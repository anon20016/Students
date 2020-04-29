class Date;

#include "Student.h"
#include "Date.h"


Student::Student()
{
	Name = string();
	SecName = string();
	Patronymic = string();
	DayOfBirth = Date();
	YearStart = Date();
	Faculty = string();
	Group = string();
	RecordBook = string();
}

Student::Student(int id, string name, string secname, string patro, Date dayofbirth,
	Date yearstart, string faculttm, string group, string recbook)
{
	setStudent(id, name, secname, patro, dayofbirth, yearstart, faculttm, group, recbook);
}

Student::Student(const Student& s)
{
	setStudent(s.Id, s.Name, s.SecName, s.Patronymic, s.DayOfBirth, s.YearStart, s.Faculty, s.Group, s.RecordBook);
}

Student::Student(string s)
{
	if (s[s.size() - 1] != ' ') {
		s += " ";
	}
	int last = 0;
	int c = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			string p = s.substr(last, i - last);
			last = i + 1;
			switch (c)
			{
			case 0:
				setId(stoi(p));				
				break;
			case 1:
				setName(p);
				break;
			case 2:
				setSecName(p);
				break;
			case 3:
				setPatronymic(p);
				break;
			case 4:
				setDayOfBirth(Date(p));
				break;
			case 5:
				setYearStart(Date(p));
				break;
			case 6:
				setFaculty(p);
				break;
			case 7:
				setGroup(p);
				break;
			case 8:
				setRecordBook(p);
				break;
			default:
				break;
			}
			c++;
		}
	}
}



int Student::getId() {
	return Id;
}
string Student::getName() {
	return Name;
}
string Student::getSecName() {
	return SecName;
}
string Student::getPatronymic() {
	return Patronymic;
}

Date Student::getDayOfBirth()
{
	return DayOfBirth;
}

Date Student::getYearStart()
{
	return YearStart;
}

string Student::getRecordBook()
{
	return RecordBook;
}

string Student::getFaculty()
{
	return Faculty;
}

string Student::getGroup()
{
	return Group;
}

void Student::setId(int id)
{
	Id = id;
}

void Student::setName(string name)
{
	Name = name;
}

void Student::setSecName(string secname)
{
	SecName = secname;
}

void Student::setPatronymic(string patro)
{
	Patronymic = patro;
}

void Student::setDayOfBirth(Date date)
{
	DayOfBirth = date;
}

void Student::setYearStart(Date date)
{
	YearStart = date;
}

void Student::setRecordBook(string r)
{
	RecordBook = r;
}

void Student::setFaculty(string f)
{
	Faculty = f;
}

void Student::setGroup(string g)
{
	Group = g;
}

void Student::setStudent(int id, string name, string secname, string patro, Date dayofbirth,
	Date yearstart, string faculttm, string group, string recbook)
{
	setId(id);
	setName(name);
	setSecName(secname);
	setPatronymic(patro);
	getDayOfBirth();
	getYearStart();
	setDayOfBirth(dayofbirth);
	setYearStart(yearstart);
	setRecordBook(recbook);
	setFaculty(faculttm);
	setGroup(group);
}

void Student::print() const
{
	cout << Name + " " + SecName + " " + Patronymic + " " << Group << ' ' << Faculty;
}

string Student::ToString()
{
	return to_string(Id) + " " + Name +
		" " + SecName + " " + Patronymic +
		" " + DayOfBirth.ToString() + " " +
		YearStart.ToString() + " " + Faculty +
		" " + Group + " " + RecordBook;
}
