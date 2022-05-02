// Дана последовательность целых чисел. Удалить все минимальные элементы.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int n; cout << "кол-во эл-ов в последовательности = ";  cin >> n;// вводим n

	vector <int> vec;				// создаём вектор
	int x;
	for (int i = 0; i < n; i++) {	// заполняем вектор
		cin >> x;
		vec.push_back(x);
	}
	int Min = *min_element(vec.begin(), vec.end());					// находим минимальный элемент
	vector<int>::iterator it = remove(vec.begin(), vec.end(), Min );
	vec.erase(it, vec.end());										// удаляем минимальные элементы вектора
	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)// выводим новый вектор
		cout << *iter << " ";
	return 0;
}