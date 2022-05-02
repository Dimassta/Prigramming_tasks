// Даны две последовательности целых чисел.
// В первой последовательности удалить все четные элементы, во второй - все нечетные.
// Отсортировать данные последовательности.Объединить их в одну отсортированную последовательность.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool even(int x) {						// проверка на чётность
	return x % 2 == 0;
}

bool odd(int x) {						// проверка на нечётность
	return x % 2 != 0;
}

vector <int> pushback(int n) {			// функция заполнения векторов
	vector <int> vec;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		vec.push_back(x);
	}
	return vec;
}
void print(vector<int> vec) {			// функция для вывода вектора
	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
		cout << *iter << ' ';
	cout << endl;
}

int main() {
	setlocale(LC_ALL, "rus");
	int n, m;
	cout << "длина 1-й последовательности: "; cin >> n;	// вводим длины последовательностей
	cout << "длина 2-й последовательности: "; cin >> m;

	vector <int> vec_1;
	cout << "последовательность 1 : ";					// вводим последовательности
	vec_1 = pushback(n); cout << endl;

	vector <int> vec_2;
	cout << "последовательность 2 : ";
	vec_2 = pushback(m); cout << endl;

	// удаляем чётные элементы из 1-й последовательности
	vector<int>::iterator it = remove_if(vec_1.begin(), vec_1.end(), even);
	vec_1.erase(it, vec_1.end());
	sort(vec_1.begin(), vec_1.end()); // сортировка последовательности

	// удаляем нечётные элементы из 2-й последовательности
	vector<int>::iterator ite = remove_if(vec_2.begin(), vec_2.end(), odd);
	vec_2.erase(ite, vec_2.end());
	sort(vec_2.begin(), vec_2.end()); // сортировка последовательности

	cout << "Новая 1-я посл-ть: "; print(vec_1);
	cout << "Новая 2-я посл-ть: "; print(vec_2);
	// объединение первых двух последовательностей в одну отсортированную
	vector<int> vec_3;
	for (vector<int>::iterator it = vec_1.begin(); it != vec_1.end(); it++)
		vec_3.push_back(*it);
	for (vector<int>::iterator it = vec_2.begin(); it != vec_2.end(); it++)
		vec_3.push_back(*it);
	sort(vec_3.begin(), vec_3.end());
	cout << endl;
	cout << "Объединение двух последовательностей: "; print(vec_3);
	return 0;
}