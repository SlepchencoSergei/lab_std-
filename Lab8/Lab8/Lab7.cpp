﻿#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
using namespace std;

struct Person
{
	char surname[30], name[30], middlename[30];
	char address[100];
	char phone[20];
	int age;
};

void form_file();
void read_file();
void work_file();
void delete_from_file(int startAge, int endAge);
Person create();

int main()
{
	setlocale(LC_ALL, "rus");

	int oper;

	do
	{
		cout << "1.Сформировать файл" << endl;
		cout << "2.Работа с файлом" << endl;
		cout << "3.Выход" << endl;

		cin >> oper;

		switch (oper)
		{
		case 1:
			form_file();
			break;
		case 2:
			work_file();
			break;
		default:
			break;
		}

	} while (oper != 3);
}

Person create()
{
	cout << "Фамилия: ";
	char surname[30];
	cin >> surname;

	cout << "Имя: ";
	char name[30];
	cin >> name;

	cout << "Отчество: ";
	char middlename[30];
	cin >> middlename;

	cout << "Возраст: ";
	int age;
	cin >> age;

	cout << "Адрес: ";
	char address[100];
	cin.ignore();
	gets_s(address);

	cout << "Телефон: ";
	char phone[20];
	cin >> phone;

	Person p;
	strcpy(p.address, address);
	strcpy(p.middlename, middlename);
	strcpy(p.name, name);
	strcpy(p.phone, phone);
	strcpy(p.surname, surname);
	p.age = age;

	return p;
}

void form_file()
{
	cout << "Кол-во людей = ";
	int count;
	cin >> count;

	FILE* file = fopen("file.dat", "wb");
	if (file == NULL)
		exit(1);

	for (int i = 0; i < count; i++)
	{
		Person p = create();

		fwrite(&p, sizeof(Person), 1, file);

		if (ferror(file))
			exit(2);
	}

	fclose(file);
}

void read_file()
{
	FILE* file = fopen("file.dat", "rb");
	Person p;
	cout << setw(25) << "ФИО" << setw(10) << "Возраст" << setw(11) << "Телефон" << setw(20) << "Адрес" << endl;

	while (fread(&p, sizeof(Person), 1, file))
	{
		char fio[30] = "";
		strcat(fio, p.surname);
		strcat(fio, " ");
		strcat(fio, p.name);
		strcat(fio, " ");
		strcat(fio, p.middlename);

		cout << setw(25) << fio << setw(10) << p.age << setw(11) << p.phone << setw(20) << p.address << endl;
	}

	fclose(file);
}

void delete_from_file(int startAge, int endAge)
{
	FILE* file = fopen("file.dat", "rb");
	FILE* tempfile = fopen("temp.dat", "wb");
	Person p;

	while (fread(&p, sizeof(Person), 1, file))
	{
		if (p.age < startAge || p.age > endAge)
		{
			fwrite(&p, sizeof(Person), 1, tempfile);
		}
	}

	fclose(file);
	fclose(tempfile);

	remove("file.dat");
	rename("temp.dat", "file.dat");
}

void add_person(Person t, int pos)
{
	if (pos < 1)
		cout << "Некорректный номер" << endl;
	else
	{
		FILE* file = fopen("file.dat", "rb");
		FILE* tempfile = fopen("temp.dat", "wb");
		Person p;
		int index = 0;

		while (fread(&p, sizeof(Person), 1, file))
		{
			fwrite(&p, sizeof(Person), 1, tempfile);
			index++;

			if (index == pos)
				fwrite(&t, sizeof(Person), 1, tempfile);
		}

		fclose(file);
		fclose(tempfile);

		remove("file.dat");
		rename("temp.dat", "file.dat");

		if (index < pos)
			cout << "Некорректный номер" << endl;
	}
}

void work_file()
{
	int oper;
	do
	{
		cout << "1.Чтение файла" << endl;
		cout << "2.Удаление из файла" << endl;
		cout << "3.Добавление в файл" << endl;
		cout << "0.Назад" << endl;

		cin >> oper;

		switch (oper)
		{
		case 1:
			read_file();
			break;
		case 2:
		{
			int start, end;
			cout << "Введете начальный возраст: ";
			cin >> start;
			cout << "Введете конечный возраст: ";
			cin >> end;

			delete_from_file(start, end);
			break;
		}
		case 3:
		{
			int pos;
			cout << "После какого элемента добавить? ";
			cin >> pos;

			Person p = create();
			add_person(p, pos);
			break;
		}
		}
	} while (oper != 0);
}
