// ���� ������������������ ����� �����. ������� ��� ����������� ��������.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int n; cout << "���-�� ��-�� � ������������������ = ";  cin >> n;// ������ n

	vector <int> vec;				// ������ ������
	int x;
	for (int i = 0; i < n; i++) {	// ��������� ������
		cin >> x;
		vec.push_back(x);
	}
	int Min = *min_element(vec.begin(), vec.end());					// ������� ����������� �������
	vector<int>::iterator it = remove(vec.begin(), vec.end(), Min );
	vec.erase(it, vec.end());										// ������� ����������� �������� �������
	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)// ������� ����� ������
		cout << *iter << " ";
	return 0;
}