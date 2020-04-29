// students.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "StudentsWorker.h"
#include "SubjectWorker.h"
#include "MarksWorker.h"

using namespace std;

void menu() {
	cout << "Введите команду:\n1, если хотите добавить студента\n";
	cout << "2, если хотите удалить студента\n";
	cout << "3, если хотите добавить предмет\n";
	cout << "4, если хотите удалить предмет\n";

	cout << "5, если хотите добавить оценку\n";
	cout << "6, если хотите вывести всех студентов\n";
	cout << "7, если хотите вывести все предметы\n";

	cout << "0, если хотите выйти из программы\n";
}
void menuPrintStud() {
	cout << "Введите 1, если хотите вывести только имена студентов с их id\n";
	cout << "Введите 2, если хотите вывести всю информацию о студентах\n";
	cout << "Введите 3, если хотите вывести всю информацию о студентах с оценками\n";
}
void menuPrintSubj() {
	cout << "Введите 1, если хотите вывести только названия предметов с их id\n";
	cout << "Введите 2, если хотите вывести всю информацию о предметах\n";
}

void SetMark(StudentsWorker* sw, SubjectWorker* sbw, MarksWorker * mw) {
	int stdid, sbjid, val, id;
	cout << "Введите id студента ";
	cin >> stdid;
	if (!sw->existId(stdid)) {
		cout << "Нет такого студента" << endl;
	}
	cout << "Введите id предмета ";
	cin >> sbjid;
	if (!sbw->existId(sbjid)) {
		cout << "Нет такого предмета" << endl;
	}
	cout << "Введите оценку ";
	cin >> val;
	id = mw->AddMark(Mark(-1, val, stdid, sbjid));
	cout << "Выставлена оценка с id = " << id << endl;
}

void PrintSubj(StudentsWorker * sw, SubjectWorker * sbw, MarksWorker* mw) {
	int comand;
	string* list;
	menuPrintSubj();
	cin >> comand;
	switch (comand)
	{
	case 1:
		list = sbw->subjectNames();
		for (int i = 0; i < sbw->Count(); i++) {
			cout << list[i] << endl;
		}
		break;

	case 2:
		list = sbw->getInfo();
		for (int i = 0; i < sbw->Count(); i++) {
			cout << list[i] << endl;
		}
		break;
	default:
		break;
	}
}
void AddStud(StudentsWorker * sw) {
	string name, scname, patro, dob, dor, fac, group, rb, id;

	cout << "Введите имя ";
	cin >> name;
	cout << "Введите фамилию ";
	cin >> scname;
	cout << "Введите отчество ";
	cin >> patro;
	cout << "Введите дату рождения в формате ДД.ММ.ГГГГ ";
	cin >> dob;


	dor = "01.01.1999";
	cout << "Введите факультет ";
	cin >> fac;
	cout << "Введите группу ";
	cin >> group;
	cout << "Введите номер зачетки ";
	cin >> rb;

	id = sw->AddStudent(Student(-1, name, scname, patro, Date(dob), dor, fac, group, rb));

	cout << "Студент добавлен под id = " << id << endl;
}
void DeleteStud(StudentsWorker * sw) {
	int id;
	cout << "Введите id студента для удаления ";
	cin >> id;
	if (sw->existId(id)) {
		sw->DeleteStudentById(id);
	}
	else {
		cout << "Нет студента с таким id";
	}
}
void PrintStud(StudentsWorker * sw, SubjectWorker * sbw, MarksWorker* mw) {
	string* list;
	int* ids;
	vector<int> m;
	int comand;
	menuPrintStud();
	cin >> comand;
	switch (comand)
	{
	case 1:
		list = sw->studNames();
		for (int i = 0; i < sw->Count(); i++) {
			cout << list[i] << endl;
		}
		break;

	case 2:
		list = sw->getInfo();
		for (int i = 0; i < sw->Count(); i++) {
			cout << list[i] << endl;
		}
		break;
	case 3:
		ids = sw->getAllId();
		list = sw->getInfo();
		for (int i = 0; i < sw->Count(); i++) {
			cout << list[i] << " Marks: ";

			m = mw->getMarksForStudent(ids[i]);
			for (auto j : m) {
				cout << j << ' ';
			}
			cout << endl;
		}
		break;
	default:
		break;
	}
}

void AddSubj(SubjectWorker * sbw) {
	string name, info;

	cout << "Введите название ";
	cin >> name;
	cout << "Введите информацию ";
	cin >> info;	

	int id = sbw->AddSubject(Subject(-1, name, info));

	cout << "Предмет добавлен под id = " << id << endl;
}
void DeleteSubj(SubjectWorker * sbw) {
	int id;
	cout << "Введите id предмета для удаления ";
	cin >> id;
	if (sbw->existId(id)) {
		sbw->DeleteSubjectById(id);
	}
	else {
		cout << "Нет предмета с таким id";
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	menu();
	StudentsWorker sw("Students.txt");
	SubjectWorker sbw("Subjects.txt");
	MarksWorker mw("Marks.txt");

	sw.Load();
	sbw.Load();
	mw.Load();
	int id, comand;

	int c;
	cin >> c;
	while (1) {
		switch (c)
		{
		case 1:
			AddStud(&sw);
			break;
		case 2:
			DeleteStud(&sw);
			break;
		case 3:
			AddSubj(&sbw);
			break;
		case 4:
			DeleteSubj(&sbw);
		case 5:
			SetMark(&sw, &sbw, &mw);
			break;
		case 6:
			PrintStud(&sw, &sbw, &mw);
			break;
		case 7:
			PrintSubj(&sw, &sbw, &mw);
			break;
		case 0:
			sw.Save();
			sbw.Save();
			mw.Save();
			return 0;
			break;
		default:
			cout << "Неправильная команда, повторите ввод.";
			break;
		}
		menu();
		cin >> c;
	}
	


}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
