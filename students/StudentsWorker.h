#include <iostream>
#include "Student.h"
#include <vector>
#include <fstream>

#pragma once
class StudentsWorker
{
public:
	StudentsWorker(string p);

	void Load();
	void Save();

	Student* getStudentById(int id);
	Student* getStudentByRecordBook(string rec);

	int AddStudent(Student s);
	void DeleteStudentById(int id);
	bool existId(int id);

	int Count();
	string* studNames();
	string* getInfo();
	int* getAllId();
private:
	string path;
	vector<Student> stud;
};
