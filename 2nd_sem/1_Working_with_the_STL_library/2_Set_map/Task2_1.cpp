//���� ������������������ ����� �����.
//����� ��� ����� �����, ������� ����������� ������ � ���������� ������.
// 999 12 1 23 78 7 655 56 33 11 90
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;



int main() {
	setlocale(LC_ALL, "rus");
	vector <int> vec;										// ������ ������
	int n; cout << "������ ������������������ "; cin >> n;	// ����� ������������������
	cout << "������� ������������������: ";					// ��������� ������
	// �����:����� ��������� �������� ��������� ����� ������� ������ ������������� �����
	// ��� ���� ����� �������� � � �������������� ������� ����� ����� �������� ��������� ������� � if
	int x; 
	for (int i = 0; i < n; i++) {
		cin >> x;
		vec.push_back(x);
	}

	set <int> in_other;										// �������������� ��������� ��� ���� �������� �� ����������
	set <int> in_dub;										// � ��� ���� ����������� �����


	
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		if (*it > 9 && *it < 100) {							// ���� ����� ����������, �� ��������� ��-��
			in_dub.insert(*it % 10);						// ��� �������
			in_dub.insert(*it / 10);
		}
		else {												// �����, �������� ������ ��-��, � ������� ����������
			int x = *it;									// ����� �� ����� �������� �� ����������
			while ( x > 0) {
				in_other.insert(x % 10);
				x /= 10;
			}
		}

	}
	cout << "�����, ������� ����������� ������ � ���������� ������: ";
	set <int> v3;											// ������ 3-� ���������, ������� ����� ���������
															// �������� ����� ����� �����������
	// ������� ���������� �������� ����� �����������:
	set_difference(in_dub.begin(), in_dub.end(), in_other.begin(), in_other.end(), inserter(v3, v3.end()));
	for (set <int>::iterator i = v3.begin(); i != v3.end(); i++) {
		cout << *i << ' ';
	}
	cout << endl;
	return 0;
}