#include <iostream>
#include <vector>

using namespace std;

struct InfoPerson
{
	string FirstNomEmployee;
	string LastNameEmployee;
	float Salaire = 0;
};
void remplirVector(vector <InfoPerson> &vInfoEmp)
{
	InfoPerson stInfo;
	char remplirAutreFois = 'o';
	do
	{
		cout << "Saisir first name de l'employee?" << endl;
		cin >> stInfo.FirstNomEmployee;
		cout << "Saisir last name de l'employee?" << endl;
		cin >> stInfo.LastNameEmployee;
		cout << "Saisir salaire de l'employee?" << endl;
		cin >> stInfo.Salaire;
		vInfoEmp.push_back(stInfo);
		cout << "Tu veux continue de travaille" << endl;
		cin >> remplirAutreFois;
	} while (remplirAutreFois == 'o' || remplirAutreFois == 'O');
}
void printVector(vector <InfoPerson> &vInfoEmp)
{
	cout << "Les informations de les employees qui tu saisis sont: " << endl;
	cout << "_____________________________" << endl;
	for (InfoPerson &Info : vInfoEmp)
	{
		cout << "First Name  : " << Info.FirstNomEmployee << endl;
		cout << "Last Name   : " << Info.LastNameEmployee << endl;
		cout << "Salaire     : " << Info.Salaire << endl;
		cout << "_______________________________" << endl;
	}
	cout << endl;
}
int main()
{
	vector <InfoPerson> vInfoEmp;
	remplirVector(vInfoEmp);
	printVector(vInfoEmp);
}