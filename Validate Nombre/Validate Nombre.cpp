#include <iostream>
using namespace std;

int readNumber()
{
    int number;
    cout << "Saisir un nombre" << endl;
    cin >> number;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalide nombre, Saisir un nombre valide" << endl;
        cin >> number;

    }
    return number;
}
int main()
{
    cout << "Votre nombre est: " << readNumber();
}
