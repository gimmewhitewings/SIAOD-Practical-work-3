#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "stdio.h"

using namespace std;

char** wordsList(char* str); //�������������� ������ � ����� ���������� ���� ��� ����������
char** sameWords(char** first, char** second); //���������� � ���� �������� ���� ����������
void printArray(char** sentence); //����� ������� ���� �� �����
bool equal(char* first, char* second); //�������� �� ��������� ���� ����


int main()
{
	setlocale(LC_ALL, "ru");
	char str1[1024], str2[1024];
	cout << "Enter the first:" << endl;
	gets_s(str1); //���� ������� �����������
	cout << "Enter the second:" << endl;
	gets_s(str2); //���� ������� �����������
	char** first = wordsList(str1); //��������� ���� ���� �������
	char** second = wordsList(str2); //��������� ���� ���� �������
	char** same = sameWords(first, second); // ���������� ���������� ����
	cout << "=====" << endl;
	cout << "Same words: " << endl;
	printArray(same);
	return 0;
}

char** wordsList(char* str)
{
	char** sentence = new char* [100]; //�������� ���������� ������� 100�100
	for (size_t i = 0; i < 100; ++i) 
	{
		sentence[i] = new char[100];
	} 
	int i = 0, word = 0, j;
	while (str[i] != '\0') //������ �� ����� ������
	{
		while (str[i] != '\0' && (str[i] == ' ' || str[i] == ',' || str[i] == '.' || str[i] == '?'))  //������� ������������
		{
			i++;
		}
		j = 0;
		while (str[i] != '\0' && str[i] != ' ' && str[i] != ',' && str[i] != '.' && str[i] != '?') //������ �� �����������
		{
			sentence[word][j] = str[i]; //�������� �� �����
			i++;
			j++;
		}
		sentence[word][j] = '\0'; //��������� ����������� -> ����� ��������� -> ������ nullptr
		word++; //��� � ����. 
	}
	int end = word; //���������� �������� �����
	sentence[end][0] = '\0'; //������ � ����� nullptr
	for (size_t m = 0; m < end; m++) //������ �� ���� ������
	{
		for (size_t i = m + 1; i < end; i++) //�� ���� ������, ������ �����
		{
			if (equal(sentence[m], sentence[i])) //���� ������� ����������
			{
				for (size_t k = i; k < end - 1; k++)
				{
					int j = 0;
					while (sentence[k + 1][j] != '\0') //����� ��������� ����� �� 1
					{
						sentence[k][j] = sentence[k + 1][j];
						j++;
					}
				}
				end--; //����� ����������� �� 1
				sentence[end][0] = '\0'; //������ ����� ������ �����
			}
		}
	}
	return sentence;
}

char** sameWords(char** first, char** second)
{
	char** sameWords = new char* [100]; //�������� ������ �������
	for (size_t i = 0; i < 100; ++i)
	{
		sameWords[i] = new char[100];
	}
	int same = 0;
	int word1 = 0, word2 = 0;
	while (first[word1][0] != '\0') //������ �� ���� ������ ������� �����������
	{
		word2 = 0;
		while (second[word2][0] != '\0') //������ �� ���� ������ ������� �����������
		{
			if (equal(first[word1], second[word2])) //���� ���������
			{
				sameWords[same] = first[word1]; //�������� � ����� ������
				same++;
			}
			word2++;
		}
		word1++;
	}
	sameWords[same][0] = '\0'; //������ nullptr, ����� �������� ����� �������
	return sameWords;
}

void printArray(char** sentence) {
	int letter = 0, word = 0;
	while (sentence[word][0] != '\0') //������ �� ���� ������ �������
	{
		while (sentence[word][letter] != '\0')
		{
			cout << sentence[word][letter]; //������������ �����
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
	while (first[i] != '\0' || second[i] != '\0') //����� ���� �����������, ����� ����� ��� ����� ����������� ��� ������� ������� ��������
	{
		if (first[i] != second[i])
		{
			return false; //���� ���� ���� ������ �� ������, ���������� false
		}
		i++;
	}
	return true; //���� ������� ��� ������� - ���������� true
}
