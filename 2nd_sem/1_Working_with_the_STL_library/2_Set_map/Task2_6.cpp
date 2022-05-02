//Дан текст, состоящий из предложений, разделенных знаками препинания из
//набора «.?!».Предложения в свою очередь состоят из слов, отделенных друг от
//друга пробелами. Найти слова(без учета регистра) и их количество, которые
//встречаются только в повествовательных предложениях.
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
	cout << "Введите строку:" << endl;
	string str;					// вводим строку
	getline(cin, str);
	set<string> pov;			// множество слов в повествовательных предложениях
	set<string> ost;			// множество слов в остальных предложениях
	multiset<string> tm;		// временное мультимножество
	string word = "";			// пустое слово
	map <string, int> mp;		// создаём map

	transform(str.begin(), str.end(), str.begin(), tolower); // меняем регистр всех букв на нижний, тк его не учитываем
	// проходимся по каждому элементу строки
	for (int i = 0; i < str.length(); i++) {
		// если символ не равен " .?!", то к переменной word добавляем символ
		if (str[i] != ' ' && str[i] != '.' && str[i] != '?' && str[i] != '!') {
			word += str[i];
		}
		// иначе если символ принадлежит ' .?!', то, если слово не пустое, записываем его во временное множество 
		else {
			if (word != "") {
				tm.insert(word);
			}
			if (mp.count(word) == 0) {// если в мапе нет слова, то добавляем его
				mp[word] = 0;
			}
			mp[word]++;				// считаем кол-во слов
			word = "";
		}
		// если встреченна точка, то заполняем мн-во pov содержимим временного множества 
		if (str[i] == '.') {
			for (multiset<string>::iterator it = tm.begin(); it != tm.end(); it++) {
				pov.insert(*it);
			}
			tm.clear();
		}
		// если эл-т = ? или !, то заполняем второе множество
		else if (str[i] == '?' || str[i] == '!') {
			for (multiset<string>::iterator it = tm.begin(); it != tm.end(); it++) {
				ost.insert(*it);
			}
			tm.clear();
		}
	}
	// создаём новое множество в котором будет содержаться разность двух других
	set<string> def;
	// сама разность
	set_difference(pov.begin(), pov.end(), ost.begin(), ost.end(), inserter(def, def.end()));
	// вывод нового мн-ва
	cout << "Ответ: " << endl;
	int s = 0; // кол-во слов
	for (set<string>::iterator ite = def.begin(); ite != def.end(); ite++) {
		cout << *ite << ", ";
		s += mp[*ite];
	}
	
	cout << endl << "Кол-во слов с повторениями: " << s;
	return 0;
}