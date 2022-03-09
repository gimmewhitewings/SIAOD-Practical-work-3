#include <iostream>
#include <string>

using namespace std;

string* wordsList(string str); //Преобразование строки в набор уникальных слов без повторений
string* sameWords(string* first, string* second); //Нахождение в двух массивах слов совпадений
void printArray(string* sentence); //Вывод массива слов на экран


void main() 
{
	string first, second;
	cout << "Enter the first:" << endl;
	getline(cin, first); //Ввод первого предложения
	cout << "Enter the second:" << endl;
	getline(cin, second); //Ввод второго предложения
	string* firstArray = wordsList(first);
	string* secondArray = wordsList(second);
	string* same = sameWords(firstArray, secondArray);
	cout << "=====" << endl;
	cout << "Same words: " << endl;
	printArray(same);
}

string* wordsList(string str)
{
	string *sentence = new string[100]; //Создаем новый массив строк
	int i = 0, word = 0;
	while (str[i] != '\0') //Чтение до конца строки
	{
		while (str[i] != '\0' && (str[i] == ' ' || str[i] == ',' || str[i] == '.' || str[i] == '?'))  //Пропуск разделителей
		{
			i++;
		}
		while (str[i] != '\0' && str[i] != ' ' && str[i] != ',' && str[i] != '.' && str[i] != '?') //Чтение до разделителя
		{
			sentence[word] += str[i]; //Добавляем бо букве
			i++;
		}
		word++; //Идём к след. 
	}
	int end = word; //Запоминаем значение конца
	for (size_t m = 0; m < end; m++) //Проход по всем словам
	{
		for (size_t i = m + 1; i < end; i++) //По всем словам, идущим далее
		{
			if (sentence[m] == sentence[i]) //Если нашлись одинаковые
			{
				for (size_t k = i; k < end - 1; k++) //Сдвиг слов влево на 1
				{
						sentence[k] = sentence[k + 1];
				}
				end--; //Длина уменьшается на 1
				sentence[end] = ""; //Удаляем последнее слово
			}
		}
	}
	return sentence;
}

string* sameWords(string* first, string* second)
{
	string *sameWords = new string[100]; //Создание нового массива
	int same = 0;
	int word1 = 0, word2 = 0;
	while (!first[word1].empty()) //Проход по всем словам первого предложения
	{
		word2 = 0;
		while (!second[word2].empty()) //Проход по всем словам второго предложения
		{
			if (first[word1] == second[word2]) //Если одинаковы
			{
				sameWords[same] = first[word1]; //Копируем в новый массив
				same++;
			}
			word2++;
		}
		word1++;
	}
	return sameWords;
}

void printArray(string* sentence)
{
	int word = 0;
	while (!sentence[word].empty()) //Пока не встретилась пустая строка
	{
		cout << sentence[word] << endl; //Вывод слова на экран
		word++;
	}
	if (word == 0)
	{
		cout << "The same words were not found";
	}
}
