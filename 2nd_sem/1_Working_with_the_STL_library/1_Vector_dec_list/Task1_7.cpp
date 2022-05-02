// Дана последовательность целых чисел. Удалить все четные элементы. 
// Заменить все максимальные элементы на минимальный. Найти количество элементов, кратных Х.
// пример данных:
/*
15
4 6 1 -1 7 3 3 9 19 20 20 4 19 7 2
3
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool even(int x) {						// проверка на чётность
	return x % 2 == 0;
}

int main() {
	setlocale(LC_ALL, "rus");
	int n;
	cout << "длина последовательности "; cin >> n;	// вводим длину последовательности
	vector <int> vec;
	cout << "последовательность: ";					// вводим последовательность 
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		vec.push_back(x);
	}
	int X;
	cout << "X = "; cin >> X;						// вводим значение Х
	cout << "Удаление чётных элементов: ";
	vector <int>::iterator it = remove_if(vec.begin(), vec.end(), even);//удаление чётных элементов
	vec.erase(it, vec.end());

	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)// вывод новой последовательности
		cout << *iter << ' ';
	cout << endl;
	cout << "Замена максимальных элементов на минимальные: ";
	int Min = *min_element(vec.begin(), vec.end());	// нахождение минимального элемента последовательности 
	int Max = *max_element(vec.begin(), vec.end());	// нахождение максимального элемента последовательности
	replace(vec.begin(), vec.end(), Max, Min);		// замена

	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)// вывод новой последовательности
		cout << *iter << ' ';
	cout << endl;

	cout << "Кол-во эл-ов кратных Х: ";
	int count = 0;
	for (vector <int>::iterator i = vec.begin(); i != vec.end(); i++)// считаем количесво э-ов кратных Х
		if (*i % X == 0)
			count++;
	cout << count;
	return 0;
}