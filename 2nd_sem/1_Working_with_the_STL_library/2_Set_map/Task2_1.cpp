//Дана последовательность целых чисел.
//Найти все такие цифры, которые встречаются только в двузначных числах.
// 999 12 1 23 78 7 655 56 33 11 90
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;



int main() {
	setlocale(LC_ALL, "rus");
	vector <int> vec;										// создаём вектор
	int n; cout << "Длинна последовательности "; cin >> n;	// длина последовательности
	cout << "Введите последовательность: ";					// заполняем вектор
	// Важно:чтобы программа работала корректно нужно вводить только положительные числа
	// Для того чтобы работала и с отрицательными числами нужно будет дописать несколько условий в if
	int x; 
	for (int i = 0; i < n; i++) {
		cin >> x;
		vec.push_back(x);
	}

	set <int> in_other;										// инициализируем множество для цифр отличных от двузначных
	set <int> in_dub;										// и для цифр двухзначных чисел


	
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		if (*it > 9 && *it < 100) {							// если число двузначное, то заполняем мн-во
			in_dub.insert(*it % 10);						// его цифрами
			in_dub.insert(*it / 10);
		}
		else {												// иначе, заплняем другое мн-во, в котором содержатся
			int x = *it;									// цифры из чисел отличных от двузначных
			while ( x > 0) {
				in_other.insert(x % 10);
				x /= 10;
			}
		}

	}
	cout << "цифры, которые встречаются только в двузначных числах: ";
	set <int> v3;											// создаём 3-е множество, которое будет содержать
															// разность между двумя множествами
	// функция вычисления разности между множествами:
	set_difference(in_dub.begin(), in_dub.end(), in_other.begin(), in_other.end(), inserter(v3, v3.end()));
	for (set <int>::iterator i = v3.begin(); i != v3.end(); i++) {
		cout << *i << ' ';
	}
	cout << endl;
	return 0;
}