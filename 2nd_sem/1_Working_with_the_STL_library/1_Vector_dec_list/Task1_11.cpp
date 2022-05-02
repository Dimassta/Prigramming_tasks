// ���� ��� ������������������ ����� �����.
// � ������ ������������������ ������� ��� ������ ��������, �� ������ - ��� ��������.
// ������������� ������ ������������������.���������� �� � ���� ��������������� ������������������.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool even(int x) {						// �������� �� ��������
	return x % 2 == 0;
}

bool odd(int x) {						// �������� �� ����������
	return x % 2 != 0;
}

vector <int> pushback(int n) {			// ������� ���������� ��������
	vector <int> vec;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		vec.push_back(x);
	}
	return vec;
}
void print(vector<int> vec) {			// ������� ��� ������ �������
	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
		cout << *iter << ' ';
	cout << endl;
}

int main() {
	setlocale(LC_ALL, "rus");
	int n, m;
	cout << "����� 1-� ������������������: "; cin >> n;	// ������ ����� �������������������
	cout << "����� 2-� ������������������: "; cin >> m;

	vector <int> vec_1;
	cout << "������������������ 1 : ";					// ������ ������������������
	vec_1 = pushback(n); cout << endl;

	vector <int> vec_2;
	cout << "������������������ 2 : ";
	vec_2 = pushback(m); cout << endl;

	// ������� ������ �������� �� 1-� ������������������
	vector<int>::iterator it = remove_if(vec_1.begin(), vec_1.end(), even);
	vec_1.erase(it, vec_1.end());
	sort(vec_1.begin(), vec_1.end()); // ���������� ������������������

	// ������� �������� �������� �� 2-� ������������������
	vector<int>::iterator ite = remove_if(vec_2.begin(), vec_2.end(), odd);
	vec_2.erase(ite, vec_2.end());
	sort(vec_2.begin(), vec_2.end()); // ���������� ������������������

	cout << "����� 1-� ����-��: "; print(vec_1);
	cout << "����� 2-� ����-��: "; print(vec_2);
	// ����������� ������ ���� ������������������� � ���� ���������������
	vector<int> vec_3;
	for (vector<int>::iterator it = vec_1.begin(); it != vec_1.end(); it++)
		vec_3.push_back(*it);
	for (vector<int>::iterator it = vec_2.begin(); it != vec_2.end(); it++)
		vec_3.push_back(*it);
	sort(vec_3.begin(), vec_3.end());
	cout << endl;
	cout << "����������� ���� �������������������: "; print(vec_3);
	return 0;
}