#include "StudentsWorker.h"

StudentsWorker::StudentsWorker(string p)
{
	path = p;
	stud.clear();
}

void StudentsWorker::Load()
{
	ifstream in(path);
	string q;
	while (getline(in, q)) {
		stud.emplace_back(Student(q));		
	}
}

void StudentsWorker::Save()
{
	ofstream out(path);
	for (auto i : stud) {
		out << i.ToString() << endl;
	}
}

Student* StudentsWorker::getStudentById(int id)
{
	for (auto i : stud) {
		if (i.getId() == id) {
			return &i;
		}
	}
	return NULL;
}

Student* StudentsWorker::getStudentByRecordBook(string record)
{
	for (auto i : stud) {
		if (i.getRecordBook() == record) {
			return &i;
		}
	}
	return NULL;
}

int StudentsWorker::AddStudent(Student s)
{
	if (s.getId() == -1) {
		int mx = 0;
		for (auto i : stud) {
			mx = std::max(mx, i.getId());
		}
		s.setId(mx + 1);
		stud.emplace_back(s);
		return mx + 1;
	}
	else {
		stud.emplace_back(s);
		return s.getId();
	}
}

void StudentsWorker::DeleteStudentById(int id)
{
	if (existId(id)) {
		for (int i = 0; i < stud.size(); i++) {
			if (stud[i].getId() == id) {
				stud.erase(stud.begin() + i);
				return;
			}
		}
	}
}

int StudentsWorker::Count()
{
	return stud.size();
}

string* StudentsWorker::studNames()
{
	string* a = new string[stud.size()];
	for (int i = 0; i < stud.size(); i++) {
		a[i] = to_string(stud[i].getId()) + " " + stud[i].getName();
	}
	return a;
}

string* StudentsWorker::getInfo()
{
	string* a = new string[stud.size()];
	for (int i = 0; i < stud.size(); i++) {
		a[i] = stud[i].ToString();
	}
	return a;
}

int* StudentsWorker::getAllId()
{
	int* r = new int[Count()];
	for (int i = 0; i < stud.size(); i++) {
		r[i] = stud[i].getId();
	}
	return r;
}

bool StudentsWorker::existId(int id) {
	for (auto i : stud) {
		if (i.getId() == id) {
			return true;
		}
	}
	return false;
}