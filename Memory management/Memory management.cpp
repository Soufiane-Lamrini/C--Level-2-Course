#include <iostream>

using namespace std;


int main()
{
	int* ptra;
	float* ptrb;
	char* ptrc;
	ptra = new int;
	ptrb = new float;
	ptrc = new char;
	*ptra = 10;
	*ptrb = 12.4;
	*ptrc = 'c';
	cout << "Valeur de a: " << *ptra << endl;
	cout << "L'adresse de a: " << ptra << endl;
	cout << "Valeur de b: " << *ptrb << endl;
	cout << "L'adresse de b: " << ptrb << endl;
	cout << "Valeur de c: " << *ptrc << endl;
	cout << "L'adresse de c: " << static_cast<void*>(ptrc) << endl;
	delete ptra;
	delete ptrb;
	delete ptrc;

}
