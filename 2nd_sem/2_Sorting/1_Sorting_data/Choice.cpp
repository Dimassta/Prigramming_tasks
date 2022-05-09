#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

ifstream in("Work.txt");
ofstream out("output.txt");

struct date {				//структура даты
	int dd, mm, yy;
};

struct people {
	string Surname;			//Фамилия
	string Post;			//Должность
	date DateOfBirth;		//Дата рождения
	int Exp;				//Стаж работы
	int Salary;				//Зарплата
};

date Str_to_Date(string str) {	// перевод из строки в формат даты
	date x;
	string temp = str.substr(0, 2);	// день 
	x.dd = atoi(temp.c_str());

	temp = str.substr(3, 2);		// месяц
	x.mm = atoi(temp.c_str());

	temp = str.substr(6, 4);		// год
	x.yy = atoi(temp.c_str());
	return x;
}

vector<people> inFile() {			// ввод из файла
	vector <people> x;
	people temp;

	while (in.peek() != EOF) {
		in >> temp.Surname;
		in >> temp.Post;

		string tmp;
		in >> tmp;
		temp.DateOfBirth = Str_to_Date(tmp);

		in >> temp.Exp;
		in >> temp.Salary;
		x.push_back(temp);
	}

	return x;
}

void print(people x) {						// вывод в файл
	out << setw(15) << left << x.Surname;	// по левому краю 15 позиций от фамилии 
	out << setw(27) << left << x.Post;		// 27 позиций от должности
	if (x.DateOfBirth.dd < 10)				// отдельный вывод нуля перед датой, если она меньше 10
		out << '0' << x.DateOfBirth.dd << '.';
	else out << left << x.DateOfBirth.dd << '.';
	if (x.DateOfBirth.mm < 10)
		out << '0' << x.DateOfBirth.mm << '.';
	else out << x.DateOfBirth.mm << '.';
	out << left << setw(6) << x.DateOfBirth.yy;	// так же отступает определённое кол-во позиций от соот-ных
	out << left << setw(5) << x.Exp;
	out << left << setw(9) << x.Salary << endl;
}

bool operator < (people a, people b) {//переопределяем оператор < в соотвествии с условием
	if (a.Salary < b.Salary) return true;// сначала сортируем по зарплате 
	if (a.Salary == b.Salary && a.DateOfBirth.yy < b.DateOfBirth.yy) return true; // если зарплата одинаковая, то сортируем по году рождения
	if (a.Salary == b.Salary && a.DateOfBirth.yy == b.DateOfBirth.yy && a.Exp < b.Exp) return true;// иначе сортируем по стажу
	
	return false;
}

void choice_sort(vector <people> &x) { // сортировка выбором
	int min;
	for (int i = 0; i < x.size(); i++) {
		min = i;
		for (int j = i + 1; j < x.size(); j++) {
			if (x[j] < x[min]) 
				min = j;
		}
		swap(x[i], x[min]);
	}
	
}

int main() {
	vector <people> x; // переменная которая будет содержать вектор структур people
	x = inFile();
	int L = 0;
	int R = x.size() - 1;
	choice_sort(x);		// вызов ф-ии
	for (int i = 0; i < x.size(); i++) // печать в файл
		print(x[i]);
	out.close();
	system("output.txt");
	return 0;
}