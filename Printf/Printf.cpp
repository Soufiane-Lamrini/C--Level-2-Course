#include <iostream>

using namespace std;

int main()
{
    //Afficher un nombre
	printf("Page nombre est = %d\n", 2);
	//Afficher un nombre avec des zero en avant
	printf("Page nombre est = %0*d\n",4, 2);
	float PI = 3.14159265;
	//Precision specification
	printf("Precision specification of %.*f\n", 3, PI);

}

