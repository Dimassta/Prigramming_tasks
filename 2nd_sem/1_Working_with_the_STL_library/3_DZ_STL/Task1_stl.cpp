#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
#include <string>
#include <numeric>

using namespace std;

void print_v(vector <int> vec) {											// функция вывода вектора
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
void print_l(list <int> l) {												// функция вывода списка
	for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void fun_1(vector<int> task) {												// ф-ия для 1-го задания
	cout << "Задание 1 " << endl;
	cout << "Начальный вектор : "; print_v(task);
	nth_element(task.begin(), task.begin() + task.size() / 2, task.end());	// переопределяем вектор так
	cout << "Изменённый вектор: "; print_v(task);//тобы сначала были все элементы, меньшие 5-го элемента, потом большие
	cout << endl;
}
void fun_2(list <int> task) {												// ф-ия для 2-го задания
	cout << "Задание 2 " << endl;
	cout << "Начальный список : " ; print_l(task);
	rotate(task.begin(), max_element(task.begin(), task.end()), task.end());// циклический сдвиг списка
	cout << "Изменённый список: "; print_l(task);

	cout << endl;
}
void fun_3(vector<int> task) {												// ф-ия для 3-го задания
	cout << "Задание 3 " << endl;
	cout << "Начальный вектор : " ; print_v(task);
	make_heap(task.begin(), task.end());									// создаём из списка кучу
	cout << "Изменённый вектор: "; print_v(task);
	cout << endl;
}
void fun_4(list<int> l_1, list<int> l_2) {									// ф-ия для 4-го задания
	cout << "Задание 4 " << endl;
	cout << "1-й список: "; print_l(l_1);
	cout << "2-й список: "; print_l(l_2);
	cout << "Скалярное произведение списков: ";
	cout << inner_product(l_1.begin(), l_1.end(), l_2.begin(), 10);         // вычисляем скалярное произведение
	cout << endl;
	cout << endl;
}
void fun_5(string str) {													// ф-ия для 5-го задания
	cout << "Задание 5 " << endl;
	cout << "Начальная строка: " << str;
	set <int> s;															// создаём множество в которое
	for (int i = 0; i < str.length(); i++) {								// по циклу добавляем все эл-ты строки
		s.insert(str[i]);
	}
	cout << endl;
	cout << "Количество различных букв в строке: "; cout << s.size();		// размер множества и есть кол-во различных букв в строке
}



int main() {
	setlocale(LC_ALL, "rus");
	vector <int> task_1{31, 11, 23, 4, 17, 6, 10, 35, 2, 8};
	fun_1(task_1);

	list <int> task_2{ 7, 4, 8, 10, 5, 3, 10, 1, 2, 5 };
	fun_2(task_2);

	vector <int> task_3{ 7, 13, 4, 5, 1, 8, 10, 2, 6, 9 };
	fun_3(task_3);

	list <int> task_4_1{ 4, 6, 1, 21, 8, 2, 1, 34, 2, 4 };
	list <int> task_4_2{ 5, 6, 9, 10, 9, 4, 1, 84, 9, 7 };
	fun_4(task_4_1, task_4_2);

	string s = "adfadfdgfgfhjgjkgjhk";
	fun_5(s);
	cout << endl;
	return 0;
}