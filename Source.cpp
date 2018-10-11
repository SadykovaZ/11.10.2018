#include<iostream>
#include<string>
#include<fstream>
#include<Windows.h>
using namespace std;
ifstream my_file;
int t;
struct Book
{
	string name;
	string author;
	string publisher;
	string genre;
	void enter()
	{
		my_file >> name >> author >> publisher >> genre;
	}
	void print()
	{
		cout << " "<<name << " " << author << " " << publisher << " " << genre << endl;
	}
	void edit()
	{
		cin >> name >> author >> publisher >> genre;
	}
};
void search(Book* b)
{
	cout << "По какому параметру хотите найти: 1-по автору, 2-по названию" << endl;
	int choice;
	cin >> choice;
	string poisk;
	switch (choice)
	{
	case 1:
		cout << "Введите имя автора: ";
		cin >> poisk;
		break;
	case 2:
		cout << "Введите название: ";
		cin >> poisk;
		break;
	}
	for (int i = 0; i < t; i++)
	{
		switch (choice) 
		{
		case 1:
		{
			if (b[i].author == poisk)
			{
				b[i].print();
				cout << "Хотите отредактировать: 1-да, 2-нет ";
				int n;
				cin >> n;
				if (n == 1)
				{
					b[i].edit();
				}
			}
		}
			break;
		case 2:
		{
			if (b[i].name == poisk)
			{
				b[i].print();
				cout << "Хотите отредактировать: 1-да, 2-нет ";
				int n;
				cin >> n;
				if (n == 1)
				{
					b[i].edit();
				}
			}
			
		}
			break;
		}

	}
}
void sort_book(Book* b)
{
	for (int pass = 0; pass < t - 1; pass++)
	{
		for (int i = 0; i < t - 1; i++)
		{
			if (b[i].name > b[i + 1].name)
				swap(b[i], b[i + 1]);
		}
	}
}
void main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	my_file.open("in.txt", ios::in);
	Book* b = new Book[10];

	my_file >> t;
	for (int i = 0; i < t; i++)
	{
		b[i].enter();
	}
	while (true)
	{
		cout << "Меню:\n1. Редактировать.\n2. Печать всех книг.\n3. Поиск книг по автору.\n4. Поиск книг по названию.\n5. Сортировка массива по названию книг." << endl;
		int n;
		cin >> n;

		switch (n)
		{
		case 1:
		{
			search(b);
		}
		break;
		case 2:
		{
			for (int i = 0; i < t; i++)
			{
				b[i].print();
			}
		}
		break;
		case 3:
		{
			search(b);
			for (int i = 0; i < t; i++)
			{
				b[i].print();
			}
		}
		break;
		case 4:
		{
			search(b);
			for (int i = 0; i < t; i++)
			{
				b[i].print();
			}
		}
		break;
		case 5:
		{
			sort_book(b);
			for (int i = 0; i < t; i++)
			{
				b[i].print();
			}
		}
		break;
		}
	}
	delete[] b;
	system("pause");
}
