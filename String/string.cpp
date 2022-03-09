#include <iostream>
#include <string>

using namespace std;

string* wordsList(string str); //�������������� ������ � ����� ���������� ���� ��� ����������
string* sameWords(string* first, string* second); //���������� � ���� �������� ���� ����������
void printArray(string* sentence); //����� ������� ���� �� �����


void main() 
{
	string first, second;
	cout << "Enter the first:" << endl;
	getline(cin, first); //���� ������� �����������
	cout << "Enter the second:" << endl;
	getline(cin, second); //���� ������� �����������
	string* firstArray = wordsList(first);
	string* secondArray = wordsList(second);
	string* same = sameWords(firstArray, secondArray);
	cout << "=====" << endl;
	cout << "Same words: " << endl;
	printArray(same);
}

string* wordsList(string str)
{
	string *sentence = new string[100]; //������� ����� ������ �����
	int i = 0, word = 0;
	while (str[i] != '\0') //������ �� ����� ������
	{
		while (str[i] != '\0' && (str[i] == ' ' || str[i] == ',' || str[i] == '.' || str[i] == '?'))  //������� ������������
		{
			i++;
		}
		while (str[i] != '\0' && str[i] != ' ' && str[i] != ',' && str[i] != '.' && str[i] != '?') //������ �� �����������
		{
			sentence[word] += str[i]; //��������� �� �����
			i++;
		}
		word++; //��� � ����. 
	}
	int end = word; //���������� �������� �����
	for (size_t m = 0; m < end; m++) //������ �� ���� ������
	{
		for (size_t i = m + 1; i < end; i++) //�� ���� ������, ������ �����
		{
			if (sentence[m] == sentence[i]) //���� ������� ����������
			{
				for (size_t k = i; k < end - 1; k++) //����� ���� ����� �� 1
				{
						sentence[k] = sentence[k + 1];
				}
				end--; //����� ����������� �� 1
				sentence[end] = ""; //������� ��������� �����
			}
		}
	}
	return sentence;
}

string* sameWords(string* first, string* second)
{
	string *sameWords = new string[100]; //�������� ������ �������
	int same = 0;
	int word1 = 0, word2 = 0;
	while (!first[word1].empty()) //������ �� ���� ������ ������� �����������
	{
		word2 = 0;
		while (!second[word2].empty()) //������ �� ���� ������ ������� �����������
		{
			if (first[word1] == second[word2]) //���� ���������
			{
				sameWords[same] = first[word1]; //�������� � ����� ������
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
	while (!sentence[word].empty()) //���� �� ����������� ������ ������
	{
		cout << sentence[word] << endl; //����� ����� �� �����
		word++;
	}
	if (word == 0)
	{
		cout << "The same words were not found";
	}
}
