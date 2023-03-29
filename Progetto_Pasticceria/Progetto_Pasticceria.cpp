#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct ingredienti {
	string nome;
	int quantita;
};

ingredienti ing[100];

void StampaMenu()
{
	string m;
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

void Aggiungi(string dolagg) 
{
	string m;
	ofstream fout("menu.txt", ios::app);
	fout << dolagg << " ;" << endl;
	fout.close();
}

void Replace()
{
	string m;
	ifstream fin("appoggio.txt");
	ofstream fout("menu.txt");
	while (fin >> m)
	{
		fout << m << endl;
	}
	fout.close();
	fin.close();
}

void Cancella(string dolagg) 
{
	string m;
	ifstream fin("menu.txt");
	ofstream fout("appoggio.txt");
	while (fin >> m) 
	{
		if (m != dolagg) 
		{
			fout << m << endl;
		}
	}
	fout.close();
	fin.close();
	Replace();
}

void Dispensa()
{
	string m;
	ofstream fout("dispensa.txt");
	ifstream fin("ricette.txt");
	while (fin >> m)
	{

	}
	fout.close();
}

void Caricamento()
{
	string m;
	ifstream fin("ricette.txt");
	while (fin >> m)
	{
		int j = 0;
		int pos = 0;
		for (int i = 0; i < m.length(); i++)
		{
			if (m[i] == ';')
			{
				pos = i;
			}
		}
		ing[j].nome = m.substr(0, pos);
		ing[j].quantita = stoi(m.substr(pos));
		j++;
		cout << ing[j].nome << " " << ing[j].quantita << endl;
	}
	fin.close();
}

void Ordinazione(string dolce)
{

}

int main()
{
	int scelta, dolce, quantita;
	string dolagg, dol;
	do {
		//opzioni
		cout << "1. Aggiungi un dolce" << endl;
		cout << "2. Cancella un dolce" << endl;
		cout << "3. Visualizza il menu" << endl;
		cout << "4. Ordina un dolce" << endl;
		cout << "5. Visualizza la dispensa" << endl;
		cout << "6. Visualizza la lista della spesa" << endl;
		cin >> scelta;
		//scelta
		switch (scelta)
		{
		case 1:
			cout << "Inserisci il nome del dolce che vuoi aggiungere:" << endl;
			cin >> dolagg;
			Aggiungi(dolagg);
			break;
		case 2:
			cout << "Inserisci il nome del dolce che vuoi aggiungere:" << endl;
			cin >> dolagg;
			Cancella(dolagg);
			break;
		case 3:
			cout << "Menu Pasticceria" << endl;
			StampaMenu();
			Caricamento();
			break;
		case 4:
			cout << "Inserisci il dolce che vuoi ordinare: ";
			cin >> dolce;
			switch (dolce)
			{
			case 1:
				string m = "ciao";
				ifstream fin("tiramisu.txt");
				while (fin >> m)
				{
					cout << m;
				}
				fin.close();
			}
			cout << "Inserisci la quantita di dolci che vuoi ordinare: ";
			cin >> quantita;
			//Ricerca();
			break;
		case 5:
			cout << "Dispensa";
			//fout...
			break;
		case 6:
			cout << "Lista della Spesa";
			//ListaSpesa
			break;
		case 0:
			int a;
			cin >> a;
			break;
		}
	} while (scelta != 0);

}
