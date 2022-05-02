#include <iostream>
#include <vector>
using namespace std;
int RUN;				
int GetMinrun(int n)// вычисление minrun
{
	int r = 0;
	while (n >= 64) {
		r |= n & 1;
		n >>= 1;
	}
	return n + r;
}
// сортировка вставками для RUN-ов
void Insertion(int a[], int L, int R) 
{
	for (int i = L + 1; i <= R; i++)
	{
		int temp = a[i];
		int j = i - 1;
		while (j >= L && a[j] > temp)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
}
// сортировка слиянием, для отстортированных подмассивов
void Merge(int a[], int l, int m, int r) {
	int len1 = m - l + 1, len2 = r - m;
	vector <int> left(len1);
	vector <int> right(len2);
	for (int i = 0; i < len1; i++) 
		left[i] = a[l + i];
	for (int i = 0; i < len2; i++)
		right[i] = a[m + 1 + i];

	int i = 0, j = 0, k = l;
	while (i < len1 && j < len2) {
		if (left[i] <= right[j]) {
			a[k] = left[i];
			i++;
		}
		else {
			a[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < len1) {
		a[k] = left[i];
		i++;
		k++;
	}
	while (j < len2) {
		a[k] = right[j];
		j++;
		k++;
	}
}

// функция сортировки Тимсорт
void Timsort(int a[], int n) {		
	for (int i = 0; i < n; i += RUN)
		Insertion(a, i, min((i + RUN - 1), (n - 1)));
	for (int size = RUN; size < n; size = 2 * size) {
		for (int L = 0; L < n; L += 2 * size) {
			int mid = L + size - 1;
			int R = min((L + 2 * size), (n - 1));
			if (mid < R)
				Merge(a, L, mid, R);
		}
	}
}
int main() {
	setlocale(LC_ALL, "rus");
	int mas[] = { 60, 69, 42, 40, 76, 50, 3, 7, 54, 22, 3, 10, 70, 76, 28, 53 };
	int size = sizeof(mas) / sizeof(mas[0]);		// размер массива
	cout << "Первоначальный массив:" << endl;		// вывод изначального массива
	for (int i = 0; i < size; i++) {
		cout << mas[i] << ' ';
	}
	RUN = GetMinrun(size);							// подсчёт рана
	Timsort(mas, size);								// вызов сортировки Тимсорт
	cout << endl << "Отсортированный массив:" << endl;
	for (int i = 0; i < size; i++) {				// вывод отсортированного массива
		cout << mas[i] << ' ';
	}
	return 0;
}