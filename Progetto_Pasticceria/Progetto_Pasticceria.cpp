#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

struct ingredienti {
	string nome;
	int quantita;
	string dolce;
};

struct dolce {
	string nome;
	string ingredienti;
};

const int l = 100;
ingredienti ing[l];
ingredienti ing1[l];
dolce dol[l];

void StampaFile(string nomefile)
{
	string m;
	ifstream fin(nomefile);
	while (fin >> m) 
	{ 

		cout << m << endl;

	}
	fin.close();
}

void Aggiungi(string dolagg, string ingred) 
{
	string m;
	ofstream fout("menu.txt", ios::app);
	fout << dolagg << endl;
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
	while (fout << m)
	{
		for (int i = 0; i < l; i++) 
		{
			if (ing1[i].nome == "")
			{
				break;
			}
			fout << ing1[i].nome << ';' << ing1[i].quantita << endl;
		}
		break;
	}
	fout.close();
}

void Aggiusta()
{
	ofstream fout("dispensa.txt");
	//stampa
	cout << endl;
	for (int i = 0; i < l; i++)
	{
		int somma = ing[i].quantita;
		if (ing[i].nome == "")
		{
			break;
		}
		else 
		{
			for (int k = i + 1; k < l; k++) 
			{
				if (ing[i].nome == ing[k].nome) 
				{
					somma = somma + ing[k].quantita;
				}
			}
			for (int k = 0; k < l; k++) 
			{
				if (ing1[k].nome == ing[i].nome) 
				{
					break;
				}
				else if (ing1[k].nome == "")
				{
					ing1[k].nome = ing[i].nome;
					ing1[k].quantita = somma;
					break;
				}
			}
		}
	}
	for (int i = 0; i < l; i++)
	{
		cout << ing[i].nome << ';' << ing[i].quantita << ';' << ing[i].dolce << endl;
	}
	//stampaprova
	for (int i = 0; i < l; i++)
	{
		cout << ing1[i].nome << ';' << ing1[i].quantita << endl;
	}
	cout << endl;
	fout.close();
}

void Caricamento()
{
	string m;
	ifstream fin("ricette.txt");
	int j = 0;
	ingredienti ing1[l];
	while (fin >> m)
	{
		int pos = 0;
		int pos1 = 0;
		for (int i = 0; i < m.length(); i++)
		{
			if (m[i] == ';')
			{
				pos = i;
				break;
			}
		}
		ing[j].nome = m.substr(0, pos);
		for (int i = pos + 1; i < m.length(); i++)
		{
			if (m[i] == ';')
			{
				pos1 = i;
				break;
			}
		}
		ing[j].quantita = stoi(m.substr(pos + 1, pos1));
		ing[j].dolce = m.substr(pos1 + 1, m.length());
		j++;
	}
	Aggiusta();
	fin.close();
}

void OrdSpesa(string dol, int numd)
{
	int diff;
	ofstream fout("listaspesa.txt");
	ofstream fout1("dispensa.txt");
	for (int i = 0; i < l; i++)
	{
		if (ing[i].dolce == dol)
		{
			if (ing1[i].quantita >= ing[i].quantita * numd)
			{
				ing1[i].quantita = ing1[i].quantita - ing[i].quantita * numd;
			}
			else
			{
				diff = ing[i].quantita * numd - ing1[i].quantita;
				fout << ing1[i].nome << ';' << diff << endl;
			}
		}
	}
	for (int i = 0; i < l; i++) 
	{
		cout << ing1[i].nome << ';' << ing1[i].quantita << ';' << ing1[i].dolce;
	}
	fout.close();
}

int main()
{
	int scelta, numd, quantita, b;
	string dolagg, ingred, dol;
	do {
		system("CLS");
		//opzioni
		cout << "Pasticceria" << endl;
		cout << "1. Aggiungi un dolce" << endl;
		cout << "2. Cancella un dolce" << endl;
		cout << "3. Ordina un dolce" << endl;
		cout << "4. Visualizza la dispensa" << endl;
		cout << "5. Visualizza la lista della spesa" << endl;
		cout << "0. Esci dal programma" << endl;
		cin >> scelta;
		//scelta
		switch (scelta)
		{
		case 1:
			cout << "Inserisci il nome del dolce che vuoi aggiungere:" << endl;
			cin >> dolagg;
			cout << "Inserisci gli ingredienti necessari alla preparazione" << endl;
			cin >> ingred;
			Aggiungi(dolagg, ingred);
			cin >> b;
			if (b == 0) 
			{
				break;
			}
		case 2:
			cout << "Inserisci il nome del dolce che vuoi cancellare:" << endl;
			cin >> dolagg;
			Cancella(dolagg);
			cin >> b;
			if (b == 0)
			{
				break;
			}
		case 3:
			cout << "Menu Pasticceria:" << endl;
			StampaFile("menu.txt");
			Caricamento();
			Dispensa();
			//...
			cout << "Inserisci il dolce che vuoi ordinare: ";
			cin >> dol;
			cout << "Inserisci il numero di " << dol << " che vuoi ordinare : ";
			cin >> numd;
			OrdSpesa(dol, numd);
			cin >> b;
			if (b == 0)
			{
				break;
			}
		case 4:
			cout << "Dispensa" << endl;
			StampaFile("dispensa.txt");
			cin >> b;
			if (b == 0)
			{
				break;
			}
		case 5:
			cout << "Lista della Spesa" << endl;
			StampaFile("listaspesa.txt");
			cin >> b;
			if (b == 0)
			{
				break;
			}
		case 0:
			break;
		}
	} while (scelta != 0);

}
