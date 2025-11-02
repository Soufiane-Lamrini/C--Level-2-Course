#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void PrintFileContent(string FileName)
{
	fstream MatieresFile;
	MatieresFile.open("MatieresFile.txt", ios::in);
	if (MatieresFile.is_open())
	{
		string line;
		while (getline(MatieresFile, line))
		{

			cout << line << endl;

		}
		MatieresFile.close();
	}
}

int main()
{
	PrintFileContent("MatieresFile.txt");

}

/*
int main()
{
	fstream PlatsFile;
	PlatsFile.open("MatieresFile.txt", ios::out);
	if (PlatsFile.is_open())
	{
		PlatsFile << "1. Couscous\n";
		PlatsFile << "2. Tajine\n";
		PlatsFile << "3. Pizza\n";
		PlatsFile << "4. Spaghetti\n";

		PlatsFile.close();
	}
}
*/