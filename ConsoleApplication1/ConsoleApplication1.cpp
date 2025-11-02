#include <iostream>
#include <iomanip> // pour setw
using namespace std;

int main()
{
    cout << "---------|--------------------------------|---------|" << endl;
    cout << setw(9) << "Code" << " |" << endl;
    cout << setw(36) << "Name" << " |" << endl;
        cout << setw(9) << "Mark" << " |" << endl;
    cout << "---------|--------------------------------|---------|" << endl;

    cout << setw(9) << "C101" << " |" << endl;
    cout << setw(36) << "Introduction to Programming 1" << " |" << endl;
    cout << setw(9) << "95" << " |" << endl;

    cout << setw(9) << "C102" << " |" << endl;
        cout << setw(32) << "Computer Hardware" << " |" << endl;
        cout << setw(9) << "88" << " |" << endl;
    
    cout << setw(9) << "C10352" << " |" << endl;
    cout << setw(36) << "Network" << " |" << endl;
    cout << setw(9) << "75" << " |" << endl;

    cout << "---------|--------------------------------|---------|" << endl;

    return 0;
}
