//�� ������� ����� ����� ����� ���� � ����� �����, ����������� ���������.
//����� ��� �����, ������������� ������� �� ���, ������� ������ �����.


#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <fstream>
#include <map>
#include <iterator>

using namespace std;

bool is_digit(const std::string& s)	// ������� ������� �������� �������� �� ������ ������
{
	return !s.empty() && (s.find_first_not_of("0123456789") == s.npos);
}

int main() {
	setlocale(LC_ALL, "rus");
	ifstream input;
	input.open("task_11.txt");			// �������� ����� ��� ������
	if (!input.is_open()) {
		cout << "������ �������� �����";
	}
	map <string, int> words;			// map ��������� ���� ���� 
	map <string, int> num;
	string T;							// ������ ������� �������� ������ �����
	while (!input.eof()) {				// ���� �� ����� �����
		string s;
		getline(input, s);				// ���������� ��������� ������
		string word;
		bool f = true;					// ���� ��� ����������� ������� �����
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != ' ') {			// �������� ����� �� ��������� ���� �� ����� �� �������
				word += s[i];
			}
			else {
				if (is_digit(word)) {	// ���� ������ - ����� , ��
					if (num.count(word) == 0 && f) { // �������� ���� � ���� �� ���� ������� � ����
						num[word] = 1;				// ���� �� ����� ������� ��� 1 ���������
						f = false;					// ���� ����������� false, ����� �� ��������� ����� ����� � ���
						T = word;					// ���������� ����� 
					}
					else
						num[word]++;
					word = "";

				}
				else {
					if (words.count(word) == 0) {	// ���� ������ - �� �����, �� � ��� ������ �� �����������
						words[word] = 1;			// �� ��������� �
					}
					else
						words[word]++;				
					word = "";
				}
			}
		}
	}
	map <string, int> ::iterator it = words.begin();
	cout << "�����, ������� ����������� ������� �� ��� ������� � �����: " << T << endl;
	for (int i = 0; it != words.end(); it++, i++) {  // � ������� ��������� ���������� �� ���� �� ������� � ����������
		if (it->second == num[T]) {					 // ������ �������� ����� �����������
			cout << it->first << ' ';
		}
	}
	input.close();
	return 0;
}