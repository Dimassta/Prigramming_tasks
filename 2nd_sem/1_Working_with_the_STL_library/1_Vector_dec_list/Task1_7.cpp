// ���� ������������������ ����� �����. ������� ��� ������ ��������. // �������� ��� ������������ �������� �� �����������. ����� ���������� ���������, ������� �.// ������ ������:
/*
15
4 6 1 -1 7 3 3 9 19 20 20 4 19 7 2
3
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool even(int x) {						// �������� �� ��������
	return x % 2 == 0;
}

int main() {
	setlocale(LC_ALL, "rus");
	int n;
	cout << "����� ������������������ "; cin >> n;	// ������ ����� ������������������
	vector <int> vec;
	cout << "������������������: ";					// ������ ������������������ 
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		vec.push_back(x);
	}
	int X;
	cout << "X = "; cin >> X;						// ������ �������� �
	cout << "�������� ������ ���������: ";
	vector <int>::iterator it = remove_if(vec.begin(), vec.end(), even);//�������� ������ ���������
	vec.erase(it, vec.end());

	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)// ����� ����� ������������������
		cout << *iter << ' ';
	cout << endl;
	cout << "������ ������������ ��������� �� �����������: ";
	int Min = *min_element(vec.begin(), vec.end());	// ���������� ������������ �������� ������������������ 
	int Max = *max_element(vec.begin(), vec.end());	// ���������� ������������� �������� ������������������
	replace(vec.begin(), vec.end(), Max, Min);		// ������

	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)// ����� ����� ������������������
		cout << *iter << ' ';
	cout << endl;

	cout << "���-�� ��-�� ������� �: ";
	int count = 0;
	for (vector <int>::iterator i = vec.begin(); i != vec.end(); i++)// ������� ��������� �-�� ������� �
		if (*i % X == 0)
			count++;
	cout << count;
	return 0;
}