#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

char* task1(char* arr, int position);

char* task2(char* str, char s);

char* task3(char* str, int p, char c);

char* task4(char* str);

int task5(char* str, int c);

void task6(char* str);

char* task7(char* str);

int task8(char* str);

void task9(char* str);

int main()
{
	cout << "Task1" << endl;
	char* new_str = new char[100];
	int i;
	gets_s(new_str, 100);
	cin >> i;
	new_str = task1(new_str, i);
	cout << new_str << endl;
	cout << endl;

	cout << "Task 2" << endl;
	char* new_str2 = new char[100] { "Hello wordl!" };
	char h;
	cin >> h;
	cout << task2(new_str2, h) << endl;
	cout << endl;

	cout << "Task 3" << endl;
	char* new_str3 = new char[100] {"Hello world!"};
	int j;
	char c;
	cin >> j;
	cin >> c;
	cout << task3(new_str3, j, c) << endl;
	cout << endl;

	cout << "Task 4" << endl; 
	char* new_str4 = new char[100];
	gets_s(new_str4, 100);
	cout << task4(new_str4) << endl;
	cout << endl;

	cout << "Task 5" << endl;
	char* new_str5 = new char[100];
	char q;
	gets_s(new_str5, 100);
	cin >> q;
	cout << task5(new_str5, q) << endl;
	cout << endl;

	cout << "Task 6" << endl;
	char* new_str6 = new char[100];
	gets_s(new_str6, 100);
	task6(new_str6);
	cout << endl;

	cout << "Task 7" << endl;
	char* new_str7 = new char[100];
	gets_s(new_str7, 100);
	cout << task7(new_str7) << endl;
	cout << endl;

	cout << "Task 8" << endl;
	char* new_str9 = new char[100];
	gets_s(new_str9, 100);
	cout << task8(new_str9) << endl;
	cout << endl;

	cout << "Task 9";
	setlocale(LC_ALL, "");
	char* new_str10_1 = new char[200] { "довод" };
	char* new_str10_2 = new char[200] { "Молебен о коне белом" };
	char* new_str10_3 = new char[200] { "не палиндром" };
	task9(new_str10_1);
	cout << endl;
	task9(new_str10_2);
	cout << endl;
	task9(new_str10_3);
	cout << endl;
}

char* task1(char* arr, int position) {
	char* new_arr = new char[strlen(arr) - 1];
	strncpy_s(new_arr, strlen(arr), arr, position - 1);
	strcat_s(new_arr, strlen(arr), arr + position);
	delete[]arr;
	return new_arr;

}

char* task2(char* str, char s) {
	char* new_str = new char[100]{" "};
	char* temp_str;
	while (temp_str = strchr(str, s)) {
		strncat_s(new_str, 100, str,
			strlen(str) - strlen(temp_str));
		str = ++temp_str;
	}
	strcat_s(new_str, 100, str);

	return new_str;
}

char* task3(char* str, int p, char c) {
	char* new_str = new char[strlen(str) + 1];
	strncpy_s(new_str, p + 2, str, p + 1);
	*(new_str + p) = c;
	strcat_s(new_str, strlen(str) + 2, str + p);
	return new_str;
}

char* task4(char* str) {
	char* temp;
	while (temp = strchr(str, '.')) {
		*temp = '!';
		strcpy_s(str + (strlen(str) - strlen(temp)),
			strlen(str),
			temp);
	}
	return str;
}

int task5(char* str5, int c) {
	char* temp;
	int count = 0;
	while (temp = strchr(str5, c)) {
		count++;
		str5 = ++temp;
	}
	return count;
}

void task6(char* str) {
	int num = 0, chr = 0, other = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] >= 48 && str[i] <= 57)
			num++;
		else if (str[i] >= 65 && str[i] <= 90 || str[i] >= 97 && str[i] <= 122)
			chr++;
		else
			other++;
	}
	cout << "Numbers: " << num << " chars:  " << chr << " other simbols: " << other << endl;
}

char* task7(char* str) {
	char* temp;
	while (temp = strchr(str, ' ')) {
		*temp = '\t';
		strcpy_s(str + (strlen(str) - strlen(temp)),strlen(str), temp);
	}
	return str;
}

int task8(char* str) {
	char* temp;
	int count = 1;
	while (temp = strchr(str, ' ')) {
		count++;
		str = ++temp;
	}
	return count;
}

void task9(char* str) {
	char* str9 = new char[256];
	for (int i = 0, j = 0; i < strlen(str) + 1; i++) {
		if (str[i] != ' ') {
			str9[j] = str[i];
			j++;
		}
	}
	delete[]str;
	if (_stricmp(str9, _strrev(str9)) == 0) 
		std::cout << "палиндром";
	else 
		std::cout << "Не палиндром";
}