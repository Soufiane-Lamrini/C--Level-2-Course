#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void LoadDataFromFileToVector(string NomFichier, vector <string>&	vFileContent)
{
	fstream Produits;
	Produits.open("Produits.txt", ios::in);//read Mode
	if (Produits.is_open())
	{
		string Line;
		while (getline(Produits, Line))
		{
			vFileContent.push_back(Line);
		}
		Produits.close();
	}
}
void SaveVectorToFile(string NomFichier, vector <string> vFileContent)
{
	fstream Produits;
	Produits.open("Produits.txt", ios::out);
	if (Produits.is_open())
	{
		for (string Line : vFileContent)
		{
			if (Line != "")
			{
				Produits << Line << endl;
			}
		}
		Produits.close();
	}
}
void DeleteRecordFromFile(string NomFichier, string Record)
{
	vector <string> vFileContent;
	LoadDataFromFileToVector(NomFichier, vFileContent);
	for (string& Line : vFileContent)
	{
		if (Line == Record)
		{
			Line = "";
		}
	}
	SaveVectorToFile(NomFichier, vFileContent);
}
void PrintFileContent(string NomFichier)
{
	fstream Produits;
	Produits.open(NomFichier, ios::in);//read Mode
	if (Produits.is_open())
	{
		string Line;
		while (getline(Produits, Line))
		{
			cout << Line << endl;
		}
		Produits.close();
	}
}
int main()
{
	cout << "Fichier Content Avant Suprimer.\n";
	PrintFileContent("Produits.txt");
	DeleteRecordFromFile("MyFile.txt", "Pomme");
	cout << "\n\nFile Content Apres Delete.\n";
	PrintFileContent("Produits.txt");
	return 0;
}