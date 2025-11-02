#include <iostream>

using namespace std;
int main()
{
	int nombreNotes;
	cout << "Saisir combien des notes tu veux saisir? \n";
	cin >> nombreNotes;
	int* ptr;
	ptr = new int[nombreNotes];
	cout << "Saisir la :" << endl;
	for (int i = 0; i < nombreNotes; i++)
	{
		cout << "\nNote numero [" << i + 1 << "] ";
		cin >> *(ptr + i);
	}

	cout << "Les resultats:" << endl;
	for (int i = 0; i < nombreNotes; i++)
	{
		cout << "\nValeur de la note[" << i + 1 << "] : " << *(ptr + i) << endl;
		cout << "\nAdresse de la note [" << i + 1 << "] : " << (ptr + i) << endl;

	}
	delete[] ptr;
}