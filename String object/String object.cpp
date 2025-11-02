#include <iostream>
#include <string>

using namespace std;

int main()
{
	string MyName = "Soufiane Lamrini";
	//Affiche la longueur de la chaîne
	cout << "longeur est: " << MyName.length() << endl;

	//Affiche le caractère à la position 5.
	cout << "le caractère à la position 5 est: " << MyName.at(5) << endl;
	//Insère le mot "Dev" après ton prénom.
	cout << MyName.insert(8," Dev") << endl;

	//Ajoute la chaîne " - Apprenant C++" à la fin.
	cout << MyName.append(" - Apprenant C++") << endl;

	//Affiche les 10 caractères à partir de la position 8.

	cout << MyName.substr(8, 10) << endl;
	//Ajoute le caractère '*' à la fin de la chaîne.
	MyName.push_back('*');
	cout << MyName << endl;
	//Supprime le dernier caractère.
	MyName.pop_back();
	cout << MyName << endl;

}

