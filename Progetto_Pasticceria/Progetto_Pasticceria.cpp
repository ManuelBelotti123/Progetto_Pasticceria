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
		if (m[0] == ';')
		{
			break;
		}
		cout << m << endl;
	}
	cout << endl;
	fin.close();
}

void Aggiungi(string dolagg, string ingred, int quantita) 
{
	string m;
	ofstream fout("menu.txt", ios::app);
	ofstream fout1("ricette.txt", ios::app);
	fout << dolagg << endl;
	fout1 << ingred << ';' << quantita << ';' << dolagg << endl;
	fout.close();

}

void Replace(string file1, string file2)
{
	string m;
	ifstream fin(file1);
	ofstream fout(file2);
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
	Replace("appoggio.txt", "menu.txt");
}

void Modifica(string dolR, string dolagg, int quantmod, string ingredmod) 
{
	string m;
	ifstream fin("menu.txt");
	ofstream fout("appoggio.txt");
	ifstream fin1("ricette.txt");
	ofstream fout1("appoggioR.txt");
	while (fin >> m)
	{
		if (m != dolR)
		{
			fout << m << endl;
		}
		else 
		{
			fout << dolagg << endl;
		}
	}
	Replace("appoggio.txt", "menu.txt");
	while (fin1 >> m)
	{
		if (m != dolR)
		{
			fout1 << m << endl;
		}
		else
		{
			fout1 << ingredmod << ';' << quantmod << ';' << dolagg << endl;
		}
	}
	Replace("appoggioR.txt", "ricette.txt");
	fout.close();
	fin.close();
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
	ofstream fout("listaspesa.txt", ios::app);
	ofstream fout1("dispensaagg.txt");
	for (int i = 0; i < l; i++)
	{
		if (ing[i].dolce == dol)
		{
			for (int j = 0; j < l; j++) 
			{
				if (ing1[j].nome == ing[i].nome) 
				{
					if (ing1[j].quantita >= ing[i].quantita * numd)
					{
						ing1[j].quantita = ing1[j].quantita - ing[i].quantita * numd;
					}
					else
					{
						diff = ing[i].quantita * numd - ing1[j].quantita;
						fout << ing1[j].nome << ';' << diff << endl;
					}
				}
			}
		}
	}
	for (int i = 0; i < l; i++) 
	{
		fout1 << ing1[i].nome << ';' << ing1[i].quantita << endl;
	}
	fout.close();
}

void CancContFile(string nomefile) 
{
	ofstream fout(nomefile);
	fout.close();
}

int main()
{
	int scelta, numd, quantita, b, v;
	string dolagg, ingred, dol, dolR;
	do {
		system("CLS");
		//opzioni
		cout << "Pasticceria" << endl;
		cout << "1. Aggiungi un dolce sulla lista" << endl;
		cout << "2. Cancella un dolce sulla lista" << endl;
		cout << "3. Modifica un dolce sulla lista" << endl;
		cout << "3. Ordina un dolce" << endl;
		cout << "4. Visualizza la dispensa" << endl;
		cout << "5. Visualizza la lista della spesa" << endl;
		cout << "6. Cancella la lista della spesa" << endl;
		cout << "0. Esci dal programma" << endl;
		cin >> scelta;
		//scelta
		switch (scelta)
		{
		case 1:
			cout << "Inserisci il nome del dolce che vuoi aggiungere: " << endl;
			cin >> dolagg;
			do {
				cout << "Inserisci un ingrediente: " << endl;
				cin >> ingred;
				cout << "Inserisci la sua quantita: " << endl;
				cin >> quantita;
				cout << "Vuoi inserire un altro ingrediente? (immettere '0' per uscire): ";
				cin >> v;
				Aggiungi(dolagg, ingred, quantita);
			} while (v != 0);
			cout << "Digitare '0' per continuare..." << endl;
			cin >> b;
			if (b == 0) 
			{
				break;
			}
		case 2:
			cout << "Inserisci il nome del dolce che vuoi cancellare:" << endl;
			cin >> dolagg;
			Cancella(dolagg);
			cout << "Digitare '0' per continuare..." << endl;
			cin >> b;
			if (b == 0)
			{
				break;
			}
		case 7:
			cout << "Inserisci il nome del dolce che vuoi modificare:" << endl;
			cin >> dolR;
			cout << "Inserisci il nuovo nome del dolce da modificare:" << endl;
			cin >> dolagg;

			cout << "Inserisci il nuovo nome dell'ingrediente del da modificare:" << endl;
			cin >> dolagg;
			cout << "Digitare '0' per continuare..." << endl;
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
			do {
				cout << "Inserisci il dolce che vuoi ordinare: ";
				cin >> dol;
				cout << "Inserisci il numero di " << dol << " che vuoi ordinare: ";
				cin >> numd;
				cout << "Vuoi ordinare altro? (immettere '0' per uscire): ";
				cin >> v;
				OrdSpesa(dol, numd);
			} while (v != 0);

			cout << "Dispensa aggiornata" << endl;
			StampaFile("dispensaagg.txt");
			cout << "Lista della Spesa" << endl;
			StampaFile("listaspesa.txt");
			cout << "Digitare '0' per continuare..." << endl;
			cin >> b;
			if (b == 0)
			{
				break;
			}
		case 4:
			cout << "Dispensa" << endl;
			StampaFile("dispensaagg.txt");
			cout << "Digitare '0' per continuare..." << endl;
			cin >> b;
			if (b == 0)
			{
				break;
			}
		case 5:
			cout << "Lista della Spesa" << endl;
			StampaFile("listaspesa.txt");
			cout << "Digitare '0' per continuare..." << endl;
			cin >> b;
			if (b == 0)
			{
				break;
			}
		case 6:
			CancContFile("listaspesa.txt");
			StampaFile("listaspesa.txt");
			cout << "Cancellazione completata" << endl;
			cout << "Digitare '0' per continuare..." << endl;
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
