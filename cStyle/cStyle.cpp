#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "stdio.h"

using namespace std;

char** wordsList(char* str); //Преобразование строки в набор уникальных слов без повторений
char** sameWords(char** first, char** second); //Нахождение в двух массивах слов совпадений
void printArray(char** sentence); //Вывод массива слов на экран
bool equal(char* first, char* second); //Проверка на равенство двух слов


int main()
{
	setlocale(LC_ALL, "ru");
	char str1[1024], str2[1024];
	cout << "Enter the first:" << endl;
	gets_s(str1); //Ввод первого предложения
	cout << "Enter the second:" << endl;
	gets_s(str2); //Ввод второго предложения
	char** first = wordsList(str1); //Получение всех слов первого
	char** second = wordsList(str2); //Получение всех слов второго
	char** same = sameWords(first, second); // Нахождение одинаковых слов
	cout << "=====" << endl;
	cout << "Same words: " << endl;
	printArray(same);
	return 0;
}

char** wordsList(char* str)
{
	char** sentence = new char* [100]; //Создание двумерного массива 100х100
	for (size_t i = 0; i < 100; ++i) 
	{
		sentence[i] = new char[100];
	} 
	int i = 0, word = 0, j;
	while (str[i] != '\0') //Чтение до конца строки
	{
		while (str[i] != '\0' && (str[i] == ' ' || str[i] == ',' || str[i] == '.' || str[i] == '?'))  //Пропуск разделителей
		{
			i++;
		}
		j = 0;
		while (str[i] != '\0' && str[i] != ' ' && str[i] != ',' && str[i] != '.' && str[i] != '?') //Чтение до разделителя
		{
			sentence[word][j] = str[i]; //Копируем бо букве
			i++;
			j++;
		}
		sentence[word][j] = '\0'; //Встретили разделитель -> слово кончилось -> ставим nullptr
		word++; //Идём к след. 
	}
	int end = word; //Запоминаем значение конца
	sentence[end][0] = '\0'; //Ставим в конце nullptr
	for (size_t m = 0; m < end; m++) //Проход по всем словам
	{
		for (size_t i = m + 1; i < end; i++) //По всем словам, идущим далее
		{
			if (equal(sentence[m], sentence[i])) //Если нашлись одинаковые
			{
				for (size_t k = i; k < end - 1; k++)
				{
					int j = 0;
					while (sentence[k + 1][j] != '\0') //Сдвиг элементов влево на 1
					{
						sentence[k][j] = sentence[k + 1][j];
						j++;
					}
				}
				end--; //Длина уменьшается на 1
				sentence[end][0] = '\0'; //Ставим новую отетку конца
			}
		}
	}
	return sentence;
}

char** sameWords(char** first, char** second)
{
	char** sameWords = new char* [100]; //Создание нового массива
	for (size_t i = 0; i < 100; ++i)
	{
		sameWords[i] = new char[100];
	}
	int same = 0;
	int word1 = 0, word2 = 0;
	while (first[word1][0] != '\0') //Проход по всем словам первого предложения
	{
		word2 = 0;
		while (second[word2][0] != '\0') //Проход по всем словам второго предложения
		{
			if (equal(first[word1], second[word2])) //Если одинаковы
			{
				sameWords[same] = first[word1]; //Копируем в новый массив
				same++;
			}
			word2++;
		}
		word1++;
	}
	sameWords[same][0] = '\0'; //Ставим nullptr, чтобы показать конец массива
	return sameWords;
}

void printArray(char** sentence) {
	int letter = 0, word = 0;
	while (sentence[word][0] != '\0') //Проход по всем словам массива
	{
		while (sentence[word][letter] != '\0')
		{
			cout << sentence[word][letter]; //Посимвольный вывод
			letter++;
		}
		cout << endl;
		letter = 0;
		word++;
	}
	if (word == 0)
	{
		cout << "The same words were not found";
	}

}

bool equal(char* first, char* second)
{
	int i = 0;
	while (first[i] != '\0' || second[i] != '\0') //Чтобы цикл остановился, нужно чтобы оба слова закончились или функция вернула значение
	{
		if (first[i] != second[i])
		{
			return false; //Если хоть один символ не совпал, возвращаем false
		}
		i++;
	}
	return true; //Если совпали все символы - возвращаем true
}
