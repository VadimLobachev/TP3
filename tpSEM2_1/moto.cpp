#include "moto.h"
#include <iostream>

using namespace std;

void motos::data()
{
	cout << "марка мотоцикла " << markamoto << endl;
	cout << "модель мотоцикла: " << modelmoto << endl;
	cout << "двинатель мотоцикла: " << dvigmoto << endl;
	cout << "мощность мотоцикла: " << mowdvigmoto << endl;
	cout << "месность мотоцикла: " << mestnmoto << endl;

}

void motos::set()
{
	while (1)
	{
		system("cls");
		cout << "марка мотоцикла: ";
		cin >> markamoto;
		if (exception(markamoto) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "модель мотоцикла: ";
		cin >> modelmoto;
		if (exception(modelmoto) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "двигатель мотоцикла: ";
		cin >> dvigmoto;
		if (exception(dvigmoto) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "мощность двигаетеля: ";
		cin >> mowdvigmoto;
		if (exception(mowdvigmoto) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "местность мотоцикла: ";
		cin >> mestnmoto;
		if (exception(mestnmoto) == -2)
			continue;
		break;
	}
}

void motos::recover(ifstream& fin)
{
	string line;
	for (int i = 0; i < 5; i++)
	{
		getline(fin, line);
		switch (i)
		{
		case 0:
		{
			markamoto = line;
			break;
		}
		case 1:
		{
			modelmoto = line;
			break;
		}

		case 2:
		{
			dvigmoto = line;
			break;
		}
		case 3:
		{
			mowdvigmoto = line;
			break;
		}
		case 4:
		{
			mestnmoto = line;
			break;
		}
		default:
		{
			break;
		}
		}
	}
}

void motos::save(ofstream& out)
{
	out << 2 << endl;
	out << markamoto << endl;
	out << modelmoto << endl;
	out << dvigmoto << endl;
	out << mowdvigmoto << endl;
	out << mestnmoto << endl;
}

motos::motos() /*конструктоор поумолчанию*/
{
	markamoto = "ямаха";
	modelmoto = "k-3";
	dvigmoto = "мощный";
	mowdvigmoto = "700";
	mestnmoto = "трековый";
}

motos::motos(string marka, string model, string dvig, string mowdvig, string mestn) /*конструктор с парметром*/
{
	this->markamoto = marka;
	this->modelmoto = model;
	this->dvigmoto = dvig;
	this->mowdvigmoto = mowdvig;
	this->mestnmoto = mestn;
}

motos::motos(const motos& Motos) : /*конуструктор копирования*/
	markamoto(Motos.markamoto), modelmoto(Motos.modelmoto), dvigmoto(Motos.dvigmoto), mowdvigmoto(Motos.mowdvigmoto), mestnmoto(Motos.mestnmoto) {}

motos::~motos() {} /*диструктор*/

int motos::exception(string line) /*првоерка заполенености линий*/
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
			cout << "неверный ввод запроса" << endl;
			system("pause");
			return -2;
		}
		default:
		{
			cout << "ошибка" << endl;
			system("pause");
			break;
		}
		}
	}
	return 0;
}