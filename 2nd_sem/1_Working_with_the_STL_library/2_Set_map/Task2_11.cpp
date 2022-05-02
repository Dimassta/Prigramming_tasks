//Во входном файле задан набор слов и целых чисел, разделенных пробелами.
//Найти все слова, встречающиеся столько же раз, сколько первое число.


#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <fstream>
#include <map>
#include <iterator>

using namespace std;

bool is_digit(const std::string& s)	// функция которая проверят является ли строка числом
{
	return !s.empty() && (s.find_first_not_of("0123456789") == s.npos);
}

int main() {
	setlocale(LC_ALL, "rus");
	ifstream input;
	input.open("task_11.txt");			// открытие файла для чтения
	if (!input.is_open()) {
		cout << "Ошибка открытия файла";
	}
	map <string, int> words;			// map количеств всех слов 
	map <string, int> num;
	string T;							// строка которая запомнит первое число
	while (!input.eof()) {				// пока не конец файла
		string s;
		getline(input, s);				// считывание очередной строки
		string word;
		bool f = true;					// флаг для запоминания первого числа
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != ' ') {			// собираем слова по элементно пока не дойдём до пробела
				word += s[i];
			}
			else {
				if (is_digit(word)) {	// если строка - число , то
					if (num.count(word) == 0 && f) { // проверям флаг и есть ли этот элемент в мапе
						num[word] = 1;				// если всё верно считаем как 1 появление
						f = false;					// флаг присваиваем false, чтобы не добавлять новые числа в мап
						T = word;					// запоминаем число 
					}
					else
						num[word]++;
					word = "";

				}
				else {
					if (words.count(word) == 0) {	// если строка - не число, то и она раньше не встречалась
						words[word] = 1;			// то добавляем её
					}
					else
						words[word]++;				
					word = "";
				}
			}
		}
	}
	map <string, int> ::iterator it = words.begin();
	cout << "Слова, которые встречаются столько же раз сколько и число: " << T << endl;
	for (int i = 0; it != words.end(); it++, i++) {  // с помощью итератора проходимся по мапу со словами и сравниваем
		if (it->second == num[T]) {					 // вторые значения обеих отображений
			cout << it->first << ' ';
		}
	}
	input.close();
	return 0;
}