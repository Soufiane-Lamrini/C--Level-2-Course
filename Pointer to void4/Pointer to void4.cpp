#include <iostream>

using namespace std;

int main()
{
	int a = 18;
	float b = 22.55;
	char c = 'D';
	void* ptr;
	ptr = &a;
	cout << "L' adresse de a: " << ptr << endl;
	cout << "La valeur de a: " << *(static_cast<int*>(ptr)) << endl;

	ptr = &b;
	cout << "L' adresse de b: " << ptr << endl;
	cout << "La valeur de b: " << *(static_cast<float*>(ptr)) << endl;

	ptr = &c;
	cout << "L' adresse de c: " << ptr << endl;
	cout << "La valeur de c: " << *(static_cast<char*>(ptr)) << endl;
}