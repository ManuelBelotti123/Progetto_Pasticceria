#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void StampaMenu()
{
	string m = "ciao";
	ifstream fin("menu.txt");
	while (fin >> m) 
	{
		if (m[m.size() - 1] == ';') 
		{
			cout << endl;
		}
		else 
		{
			cout << m;
		}
	}
	fin.close();
}

int main()
{
	int scelta, dolce, quantita;
	//opzioni
	cout << "1. Visualizza il menu" << endl;
	cout << "2. Ordina un dolce" << endl;
	cout << "3. Visualizza la dispensa" << endl;
	cout << "4. Visualizza la lista della spesa" << endl;
	cin >> scelta;
	//scelta
	switch (scelta)
	{
		case 1:
			cout << "Menu Pasticceria" << endl;
			StampaMenu();
			break;
		case 2:
			cout << "Inserisci il dolce che vuoi ordinare: ";
			cin >> dolce;
			cout << "Inserisci la quantita di dolci che vuoi ordinare: ";
			cin >> quantita;
			//Ricerca();
			break;
		case 3:
			cout << "Dispensa";
			//fout...
			break;
		case 4:
			cout << "Lista della Spesa";
			//ListaSpesa
			break;
	}

}
