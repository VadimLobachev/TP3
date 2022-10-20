#pragma once
#include "bus.h"
#include "garage.h"
#include "car.h"
#include "moto.h"
#include "keeper.h"
#include <iostream>
using std::cout;
using std::cin;

short num;

bool check_input()
{
	if (!cin.good())
	{
		cout << "выбран не существующий пнукт меню " << endl;
		system("pause");
		cin.clear();
		while (cin.get() != '\n');
		return false;
	}
	return true;
}

void menu()
{
	while (1)
	{
		system("cls");
		cout <<	"	ГЛАВНОЕ МЕНЮ" << endl << endl;
		cout << "1. ввод транспорта" << endl;
		cout << "2. удаление первого транспорта" << endl;
		cout << "3. сохранение в файл" << endl;
		cout << "4. загрузка из файла" << endl;
		cout << "5. вывод транспорта" << endl;
		cout << "0. выход из программы" << endl;
		cout << "\n";
		cout << "выбереите пункт меню: ";
		cin >> num;
		if (!check_input())
			continue;
		break;
	}
}

void dop_menu(Keeper* keeper)
{
	short num2;
	while (1)
	{
		system("cls");
		cout << "	МЕНЮ ТРАНСПОРТА" << endl;
		cout << "1. машины" << endl;
		cout << "2. мотоциклы" << endl;
		cout << "3. автобусы" << endl;
		cout << "4. вернуться" << endl;
		cout << "Выбирите пункт меню : ";
		cin >> num2;
		if (!check_input())
			continue;
		switch (num2)
		{
		case 1:
		{
			garage* obj = new cars;
			obj->set();
			keeper->push(obj);
			continue;
		}
		case 2:
		{
			garage* obj = new motos;
			obj->set();
			keeper->push(obj);
			continue;
		}
		case 3:
		{
			garage* obj = new buses;
			obj->set();
			keeper->push(obj);
			continue;
		}
		case 4:
		{
			break;
		}
		default:
		{
			cout << "ошбка что ле" << endl;
			system("cls");
			continue;
		}
		}
		break;
	}
}

void LoadData()
{
	Keeper* keeper = new Keeper;
	while (1)
	{
		menu();
		switch (num)
		{
		case 1:
		{
			dop_menu(keeper);
			continue;
		}
		case 2:
		{
			if (!(keeper->pop()))
			{
				cout << "нет такого" << endl;
				system("pause");
			}
			continue;
		}
		case 3:
		{
			system("cls");
			int ans;
			if (keeper->get_size() == 0)
			{
				cout << "в файл нечего сохранять" << endl;
				system("pause");
				continue;
			}
			cout << "(2)?" << endl;
			cin >> ans;
			if (!check_input())
			{
				cout << "систем цлс" << endl;
				system("pause");
				continue;
			}

			switch (ans)
			{
			case 1:
			{
				if (keeper->save_all())
				{
					cout << "ошибка" << endl;
					system("pause");
				}
				break;
			}
			case 2:
			{
				if (remove("garage.txt") != 0)
					cout << "файл чист что ле";
				else
				{
					if (keeper->save_all())
						cout << "сохраненно" << endl;
				}
				system("pause");
				break;
			}
			default:
			{
				cout << "ошибька :)" << endl;
				system("pause");
				break;
			}
			}
			continue;
		}
		case 4:
		{
			if ((keeper->recover_all()) != -1)
				cout << "файл успешно загружен" << endl;
			else
				cout << "файл не загружен" << endl;
			system("pause");
			continue;
		}
		case 5:
		{
			system("cls");
			keeper->show();
			system("pause");
			continue;
		}
		case 0:
		{
			break;
		}
		default:
		{
			cout << "введ не существующий пункт меню" << endl;
			system("pause");
			continue;
		}
		}
		break;
	}
}