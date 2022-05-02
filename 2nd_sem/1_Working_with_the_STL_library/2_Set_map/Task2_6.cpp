//��� �����, ��������� �� �����������, ����������� ������� ���������� ��
//������ �.?!�.����������� � ���� ������� ������� �� ����, ���������� ���� ��
//����� ���������. ����� �����(��� ����� ��������) � �� ����������, �������
//����������� ������ � ����������������� ������������.
/*
Aaad dss ggf wp Tgd. gF ffa ggf! daa? adad ggf hkf! dss wp wp wp.
*/
#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <iterator>
#include <map>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	cout << "������� ������:" << endl;
	string str;					// ������ ������
	getline(cin, str);
	set<string> pov;			// ��������� ���� � ����������������� ������������
	set<string> ost;			// ��������� ���� � ��������� ������������
	multiset<string> tm;		// ��������� ���������������
	string word = "";			// ������ �����
	map <string, int> mp;		// ������ map

	transform(str.begin(), str.end(), str.begin(), tolower); // ������ ������� ���� ���� �� ������, �� ��� �� ���������
	// ���������� �� ������� �������� ������
	for (int i = 0; i < str.length(); i++) {
		// ���� ������ �� ����� " .?!", �� � ���������� word ��������� ������
		if (str[i] != ' ' && str[i] != '.' && str[i] != '?' && str[i] != '!') {
			word += str[i];
		}
		// ����� ���� ������ ����������� ' .?!', ��, ���� ����� �� ������, ���������� ��� �� ��������� ��������� 
		else {
			if (word != "") {
				tm.insert(word);
			}
			if (mp.count(word) == 0) {// ���� � ���� ��� �����, �� ��������� ���
				mp[word] = 0;
			}
			mp[word]++;				// ������� ���-�� ����
			word = "";
		}
		// ���� ���������� �����, �� ��������� ��-�� pov ���������� ���������� ��������� 
		if (str[i] == '.') {
			for (multiset<string>::iterator it = tm.begin(); it != tm.end(); it++) {
				pov.insert(*it);
			}
			tm.clear();
		}
		// ���� ��-� = ? ��� !, �� ��������� ������ ���������
		else if (str[i] == '?' || str[i] == '!') {
			for (multiset<string>::iterator it = tm.begin(); it != tm.end(); it++) {
				ost.insert(*it);
			}
			tm.clear();
		}
	}
	// ������ ����� ��������� � ������� ����� ����������� �������� ���� ������
	set<string> def;
	// ���� ��������
	set_difference(pov.begin(), pov.end(), ost.begin(), ost.end(), inserter(def, def.end()));
	// ����� ������ ��-��
	cout << "�����: " << endl;
	int s = 0; // ���-�� ����
	for (set<string>::iterator ite = def.begin(); ite != def.end(); ite++) {
		cout << *ite << ", ";
		s += mp[*ite];
	}
	
	cout << endl << "���-�� ���� � ������������: " << s;
	return 0;
}