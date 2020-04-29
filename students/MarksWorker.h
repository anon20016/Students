#pragma once
#include <string>
#include <vector>
#include <fstream>

#include "Mark.h"

using namespace std;

class MarksWorker
{
public:
	MarksWorker(string p);

	void Load();
	void Save();

	Mark* getMarkById(int id);

	int AddMark(Mark s);
	void DeleteMarkById(int id);
	bool existId(int id);

	int Count();

	string* getInfo();

	vector<int>* getMarksForStudentSubj(int studId, int SubjectId);
	vector<int> getMarksForStudent(int studId);


private:
	string path;
	vector<Mark> marks;
};

