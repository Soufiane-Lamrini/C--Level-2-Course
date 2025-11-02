#include <iostream>
#include <vector>

using namespace std;

void remplirVector(vector <int> & Vector)
{
	char remplirAutreFois = 'o';
	int number;
	do
	{
		cout << "Saisir la valeur que tu veux ajouter?" << endl;
		cin >> number;
		Vector.push_back(number);
		cout << "Tu veux continuer? " << endl;
		cin >> remplirAutreFois;
	} while (remplirAutreFois == 'o' || remplirAutreFois == 'O');
}
void printVector(vector <int> &Vector)
{
	cout << "Les nombres que tu saisis sont: " << endl;
	for (int number : Vector)
	{
		cout << number << endl;
	}
	cout << endl;
}
int main()
{
	vector <int> Vector;
	remplirVector(Vector);
	printVector(Vector);
}