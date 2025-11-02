#include <iostream>
#include <string>
using namespace std;

struct stinfo {
   string nom;
   int age = 0; 
};

int main()
{
   stinfo p1, * ptr;
   cout << "Saisir votre nom et prenom?" << endl;
   getline(cin, p1.nom);
   cout << "Saisir votre age?" << endl;
   cin >> p1.age;
   ptr = &p1;
   cout << "Votre nom est: " << ptr->nom << endl;
   cout << "Votre age est: " << ptr->age << endl;
}