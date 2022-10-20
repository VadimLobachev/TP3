#include "car.h"
#include <iostream>
#include <cstring>
using namespace std;

void cars::data()
{
	cout << "марка машины: " << markacar << endl;
	cout << "модель машины: " << modelcar << endl;
	cout << "двигатель машины˙: " << dvigcar << endl;
	cout << "цвет машины: " << cvetcar << endl;
	cout << "кпп машины: " << kppcar << endl;
}

void cars::set()
{
	while (1)
	{
		system("cls");
		cout << "какая марка машины: ";
		cin >> markacar;
		if (exception(markacar) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "какая модель машины˙: ";
		cin >> modelcar;
		if (exception(modelcar) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "объем двигателя машины: ";
		cin >> dvigcar;
		if (exception(dvigcar) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << " цвет машины : ";
		cin >> cvetcar;
		if (exception(cvetcar) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "КПП машины : ";
		cin >> kppcar;
		if (exception(kppcar) == -2)
			continue;
		break;
	}
}

void cars::recover(ifstream& fin)
{
	string line;
	for (int i = 0; i < 5; i++)
	{
		getline(fin, line);
		switch (i)
		{
		case 0:
		{
			markacar = line;
			break;
		}
		case 1:
		{
			modelcar = line;
			break;
		}
		case 2:
		{
			dvigcar = line;
			break;
		}
		case 3:
		{
			cvetcar = line;
			break;
		}
		case 4:
		{
			kppcar = line;
			break;
		}
		default:
		{
			break;
		}
		}
	}
}

void cars::save(ofstream& out)
{
	out << 1 << endl;
	out << markacar << endl;
	out << modelcar << endl;
	out << dvigcar << endl;
	out << cvetcar << endl;
	out << kppcar << endl;
}

cars::cars()
{
	markacar = "поагни";
	modelcar = "зонда";
	dvigcar = "v8";
	cvetcar = "блэк";
	kppcar = "автомат";
}

cars::cars(string mc, string moc, string dvc, string cvc, string kc)
{
	this->markacar = mc;
	this->modelcar = moc;
	this->dvigcar = dvc;
	this->cvetcar = cvc;
	this->kppcar = kc;
}

cars::cars(const cars& Cars) :
	markacar(Cars.markacar), modelcar(Cars.modelcar), dvigcar(Cars.dvigcar), cvetcar(Cars.cvetcar), kppcar(Cars.kppcar) {}

cars::~cars() {}

int cars::exception(string line)
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