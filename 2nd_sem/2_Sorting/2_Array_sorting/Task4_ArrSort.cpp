#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

ifstream in("Inarr.txt");
ofstream outarr("Outarr.txt");

void quick_sort(vector<vector<int>> &a, int L, int R, int k) { // Функция быстрой сортировки
	int i = L;
	int j = R;
	int op = a[(L+R)/2][k];
	do {
		while (a[i][k] < op) {
			i++;
		}
		while (op < a[j][k]) {
			j--;
		}
		if (i <= j) {
			swap(a[i][k], a[j][k]);
			j--;
			i++;
		}
	} while (i <= j);
	if (j > L) {
		quick_sort(a, L, j,k);
	}
	if (i < R) {
		quick_sort(a, i, R, k);
	}
}

void Merge(vector<int> &V, int l, int r, int m) {	// сортировка слиянием
	int len1 = m - l + 1, len2 = r - m;
	vector <int> left(len1);
	vector <int> right(len2);
	for (int i = 0; i < len1; i++)
		left[i] = V[l + i];
	for (int i = 0; i < len2; i++)
		right[i] = V[m + 1 + i];

	int i = 0, j = 0, k = l;
	while (i < len1 && j < len2) {
		if (left[i] <= right[j]) {
			V[k] = left[i];
			i++;
		}
		else {
			V[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < len1) {
		V[k] = left[i];
		i++;
		k++;
	}
	while (j < len2) {
		V[k] = right[j];
		j++;
		k++;
	}
}

void split_merge(vector < int> &V, int L, int R) {	// рекурсивная функция для деления массива на подмассивы 
													// и последующего слияния этих подмассивов
	if (L >= R)
		return;
	int m = (L + R) / 2;
	split_merge(V, L, m);
	split_merge(V, m + 1, R);
	Merge(V, L, R, m);	
}

void Insertion(vector<int> &vec, int s) // сортировка вставками
{
	for (int i = 1; i < s; i++)
	{
		int j = i;
		while (j > 0 && vec[j] < vec[j-1])
		{
			swap(vec[j], vec[j - 1]);
			j--;
		}
	}
}

void print(vector < vector < int>> &a, int n) { // функция вывода двумерного массива в файл
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			outarr << a[i][j] << ' ';
		outarr << endl;
	}
}

void choice(int Z, vector < vector < int>> a, int L, int R, int n) { // функция выбора задания
	if (Z == 1) {										// если выбрали 1, то запускается сортировка столбцов с помощью
		for (int k = 0; k < n; k++)						// быстрой сортировки
			quick_sort(a, L, R, k);
		print(a, n);									// вывод полученного массива
	}

	else if (Z == 2) {
		vector <int> V;						// временный вектор
		for (int i = 0; i < n; i++) {
			if ((i + 1) % 3 > 0)			// сортируем построчно, передавая в функцию указатель на одномерный вектор
				split_merge(a[i], L, R);		
			else if ((i + 1) % 3 == 0) {	// указываем временному вектору на строку матрицы, сортируем её
				V = a[i];
				split_merge(V, L, R);
				for (int j = 0; j < n; j++)	// и присваиваем в обртном порядке эл-ты временного вектора в строку матрицы
					a[i][n - 1 - j] = V[j];
			}
		}
		print(a, n);						// выводим массив
	}

	else if (Z == 3) {									// если выбрали 3, то сортируются диагонали параллельные побочной
														// по возрастанию с помощью сортировки вставками
		for (int k = 1; k < 2 * n - 2; k++) {			// алгоритм выбора элементов с диагоналей (из лекции)
			vector<int> vec;							
			for (int i = 0; i < n; i++)
				if (k - i < n && k - i >= 0)
					vec.push_back(a[i][k - i]);
			int s = vec.size();
			Insertion(vec, s);							// сортировка полученного вектора
			int P = 0;
			for (int i = 0; i < n; i++) 
				if (k - i < n && k - i >= 0) {
					a[i][k - i] = vec[P];
					P++;
				}
			vec.clear();
		}
		print(a, n);									// вывод массива
	}

	else
		cout << "Неверная цифра";
}

int main() {
	setlocale(LC_ALL, "rus");
	int n; in >> n;						// считывание размерности массива
	vector < vector < int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			in >> a[i][j];

	cout << "Выбирите номер сотрировки:" << endl;
	cout << "1 - быстрая сортировка (столбцы по возрастанию)" << endl;
	cout << "2 - слиянием (каждую третью строку по убыванию, остальные по возрастанию)" << endl;
	cout << "3 - вставками (диагонали, параллельные побочной по возрастанию)";
	int Z;
	cout << endl << "Выбор: "; cin >> Z;
	int L = 0, R = n - 1;
	choice(Z, a, L, R, n);
	outarr.close();
	system("Outarr.txt");
	return 0;
}