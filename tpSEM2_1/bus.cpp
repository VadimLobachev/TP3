#include "bus.h"
#include <iostream>
#include <cstring>

using namespace std;

void buses::data()
{
	cout << "марка автобуса: " << markabus << endl;
	cout << "модель автобуса: " << modelbus << endl;
	cout << "колличество сидячих мест автобуса: " << kolvosid << endl;
	cout << "общее число мест автобуса: " << kolvomest << endl;
	cout << "конечный пункт автобуса: " << konpunkt << endl;
}

void buses::set()
{
	while (1)
	{
		system("cls");
		cout << "введите марку автобуса: ";
		cin >> markabus;
		if (exception(markabus) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "введите модель автобуса: ";
		cin >> modelbus;
		if (exception(modelbus) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "введите число сидячих мест автобуса: ";
		cin >> kolvosid;
		if (exception(kolvosid) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "введите общеее число мест автобуса: ";
		cin >> kolvomest;
		if (exception(kolvomest) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "введите контрольный пункт автобуса: ";
		cin >> konpunkt;
		if (exception(konpunkt) == -2)
			continue;
		break;
	}
}

void buses::recover(ifstream& fin)
{
	string line;
	for (int i = 0; i < 5; i++)
	{
		getline(fin, line);
		switch (i)
		{
		case 0:
		{
			markabus = line;
			break;
		}
		case 1:
		{
			modelbus = line;
			break;
		}
		case 2:
		{
			kolvosid = line;
			break;
		}
		case 3:
		{
			kolvomest = line;
			break;
		}
		case 4:
		{
			konpunkt = line;
			break;
		}
		default:
		{
			break;
		}
		}
	}
}

void buses::save(ofstream& out)
{
	out << 3 << endl;
	out << markabus << endl;
	out << modelbus << endl;
	out << kolvosid << endl;
	out << kolvomest << endl;
	out << konpunkt << endl;
}

buses::buses()
{
	markabus = "man";
	modelbus = "114-a";
	kolvosid = "111";
	kolvomest = "135";
	konpunkt = "москва";
}

buses::buses(string mb, string mob, string kos, string kom, string kop)
{
	this->markabus = mb;
	this->modelbus = mob;
	this->kolvosid = kos;
	this->kolvomest = kom;
	this->konpunkt = kop;

}

buses::buses(const buses& Buses) : markabus(Buses.markabus), modelbus(Buses.modelbus), kolvosid(Buses.kolvosid), kolvomest(Buses.kolvomest), konpunkt(Buses.konpunkt) {}

int buses::exception(string line)
{
	try
	{
		if (line.empty())
			throw - 2;
	}
	catch (int a)
	{
		switch (a)
		{
		case -2:
		{
			cout << "ошибка получается" << endl;
			system("pause");
			return -2;
		}
		default:
		{
			cout << "error 404" << endl;
			system("pause");
			break;
		}
		}
	}
	return 0;
}

buses::~buses() {}