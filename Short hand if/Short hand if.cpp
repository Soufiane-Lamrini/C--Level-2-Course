#include <iostream>

using namespace std;

int main()
{
	string result;
	//exercice 1: Positive ou negative

	int nombre;
	/*cout << "Saisir un nombre" << endl;
	cin >> nombre;
	nombre >= 0 ? cout << "Positive" : cout << "Negative";*/
	//exercice 2: Positive ou negative ou nul

	cout << "Saisir un nombre" << endl;
	cin >> nombre;
	result=nombre > 0 ? "Positive" : nombre < 0 ?   "Negative" : "Null";
	cout << result;
}