#include <iostream>


using namespace std;

int main()
{
	int arr[5] = { 10,20,30,40,50 };
	int* p;
	p = arr;
	for (int i = 0; i < 5; i++)
	{
		cout << "L'adresse de cellule numero[ " << i + 1 << " ] : " << p + i << endl;
	}
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "La valeur de cellule numero[ " << i + 1 << " ] : " << *(p + i) << endl;
	}
	return 0;
}