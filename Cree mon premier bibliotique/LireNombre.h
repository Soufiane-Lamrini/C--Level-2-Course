#pragma once

#include <iostream>

using namespace std;

namespace LireNombre
{
	int LireNombre(string message)
	{
		int Nombre;
		cout << message << endl;
		cin >> Nombre;
		return Nombre;
	}

	int LirePositiveNombre(string message)
	{
		int Nombre;
		do
		{
			cout << message << endl;
			cin >> Nombre;
		} while (Nombre < 0);
		return Nombre;
	}
	int LireNombreDansRange(string message, int from, int to)
	{
		int Nombre;
		do
		{
			cout << message << endl;
			cin >> Nombre;
		} while (Nombre < from || Nombre>to);
		return Nombre;
	}

}