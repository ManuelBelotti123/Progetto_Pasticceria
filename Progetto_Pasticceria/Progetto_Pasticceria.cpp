#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

struct ingredienti {
	string nome;
	int quantita;
	string dolce;
	string u;
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

void AggMenuhtml(string dolagg)
{
	string m;
	const int lun = 100;
	string a[lun];
	string d = "";
	ifstream fin("menu.txt");
	int j = 0;
	while (fin >> m) 
	{
		a[j] = m;
		j++;
	}
	ofstream fout("SitoPasticceria.html");
	for (int i = 0; i < j; i++) 
	{
		d = d + "<div><h2>" + a[i] + "</h2></div>";
	}
	string html = "<html><head><title>Pasticceria Elegante</title><style>body h1{padding: 10px;font-family: Verdana, Geneva, Tahoma, sans-serif;text-align: center;}body div{width: 50%;margin: auto;}body div h2{text-align: center;padding: 20px 50px 20px 50px;color: black;}</style></head><body><h1>Menu della Pasticceria</h1><div>" + d + "</div></body></html>";
	fout << html;
	fin.close();
	fout.close();
}

void AggRicettehtml(string ingred, int quantita, string dolagg)
{
	ingredienti r[l];
	string m;
	const int lun = 100;
	string d = "";
	ifstream fin("ricette.txt");
	int j = 0;
	while (fin >> m)
	{
		int pos = 0;
		int pos1 = 0;
		int posun = 0;
		for (int i = 0; i < m.length(); i++)
		{
			if (m[i] == ';')
			{
				pos = i;
				break;
			}
		}
		r[j].nome = m.substr(0, pos);
		for (int i = pos + 1; i < m.length(); i++)
		{
			if (m[i] == ';')
			{
				pos1 = i;
				break;
			}
		}
		for (int i = 0; i < m.length(); i++)
		{
			if (m[i] == ';')
			{
				posun = i;
			}
		}
		r[j].quantita = stoi(m.substr(pos + 1, pos1));
		r[j].dolce = m.substr(pos1 + 1, posun - pos1 - 1);
		r[j].u = m.substr(posun + 1, m.length());
		j++;
	}
	for (int i = 0; i < j; i++)
	{
		d = d + "<div class = \"riga\"><div class=\"colonna\">" + r[i].nome + "</div><div class = \"colonna\">" + to_string(r[i].quantita) + "</div><div class=\"colonna\">" + r[i].u + "</div><div class=\"colonna\">" + r[i].dolce + "</div></div>";
	}
	ofstream fout("ricette.html");
	string html = "<html><head><title>Pasticceria Elegante</title><style>.tabella{display: table;width: 80%;margin: auto;padding: 0px 50px 50px 50px;}.riga{ display: table-row;}.colonna{display: table-cell;border: 1px solid grey;padding: 0.5em 0 0.5em 0.5em;}body h1{padding: 20px;font-size: 50;text-align: center;}</style></head><body><h1>Ingredienti e Ricette</h1><div class=\"tabella\"><div class=\"riga\"><div class=\"colonna\">Nome</div><div class=\"colonna\">Quantità</div><div class=\"colonna\">Unità di misura</div><div class=\"colonna\">Dolce</div></div>" + d + "</div></body></html>";
	//string html = "<html><head><title>Pasticceria Elegante</title><style>.tabella{display: table;width: 80%;margin: auto;padding: 0px 50px 50px 50px;}.riga{ display: table-row;}.colonna{display: table-cell;border: 1px solid grey;padding: 0.5em 0 0.5em 0.5em;}body h1{padding: 20px;font-size: 50;text-align: center;}</style></head><body><h1>Ingredienti e Ricette</h1><div class=\"tabella\"><div class=\"riga\"><div class=\"colonna\">Nome</div><div class=\"colonna\">Quantità</div><div class=\"colonna\">Unità di misura</div><div class=\"colonna\">Dolce</div></div><div class=\"riga\"><div class=\"colonna\">savoiardi</div><div class=\"colonna\">10</div><div class=\"colonna\">u</div><div class=\"colonna\">Tiramisu</div></div><div class=\"riga\"><div class=\"colonna\">mascarpone</div><div class=\"colonna\">500</div><div class=\"colonna\">g</div><div class=\"colonna\">Tiramisu</div></div><div class=\"riga\"><div class=\"colonna\">uova</div><div class=\"colonna\">4</div><div class=\"colonna\">u</div><div class=\"colonna\">Tiramisu</div></div><div class=\"riga\"><div class=\"colonna\">zucchero</div><div class=\"colonna\">100</div><div class=\"colonna\">g</div><div class=\"colonna\">Tiramisu</div></div><div class=\"riga\"><div class=\"colonna\">tazza_caffe</div><div class=\"colonna\">1</div><div class=\"colonna\">u</div><div class=\"colonna\">Tiramisu</div></div><div class=\"riga\"><div class=\"colonna\">panna</div><div class=\"colonna\">500</div><div class=\"colonna\">g</div><div class=\"colonna\">Panna_Cotta</div></div><div class=\"riga\"><div class=\"colonna\">baccello_vaniglia</div><div class=\"colonna\">1</div><div class=\"colonna\">u</div><div class=\"colonna\">Panna_Cotta</div></div><div class=\"riga\"><div class=\"colonna\">zucchero</div><div class=\"colonna\">80</div><div class=\"colonna\">g</div><div class=\"colonna\">Panna_Cotta</div></div><div class=\"riga\"><div class=\"colonna\">gelatina_fogli</div><div class=\"colonna\">8</div><div class=\"colonna\">u</div><div class=\"colonna\">Panna_Cotta</div></div><div class=\"riga\"><div class=\"colonna\">uova</div><div class=\"colonna\">2</div><div class=\"colonna\">u</div><div class=\"colonna\">Zuppa_Inglese</div></div><div class=\"riga\"><div class=\"colonna\">farina</div><div class=\"colonna\">30</div><div class=\"colonna\">g</div><div class=\"colonna\">Zuppa_Inglese</div></div><div class=\"riga\"><div class=\"colonna\">fecola</div><div class=\"colonna\">30</div><div class=\"colonna\">g</div><div class=\"colonna\">Zuppa_Inglese</div></div><div class=\"riga\"><div class=\"colonna\">zucchero</div><div class=\"colonna\">60</div><div class=\"colonna\">g</div><div class=\"colonna\">Zuppa_Inglese</div></div><div class=\"riga\"><div class=\"colonna\">baccello_vaniglia</div><div class=\"colonna\">1</div><div class=\"colonna\">u</div><div class=\"colonna\">Zuppa_Inglese</div></div><div class=\"riga\"><div class=\"colonna\">cioccolato</div><div class=\"colonna\">200</div><div class=\"colonna\">g</div><div class=\"colonna\">Gianduiotti</div></div><div class=\"riga\"><div class=\"colonna\">pasta_nocciole</div><div class=\"colonna\">100</div><div class=\"colonna\">g</div><div class=\"colonna\">Gianduiotti</div></div><div class=\"riga\"><div class=\"colonna\">cioccolato</div><div class=\"colonna\">260</div><div class=\"colonna\">g</div><div class=\"colonna\">Brownies</div></div><div class=\"riga\"><div class=\"colonna\">nocciole</div><div class=\"colonna\">170</div><div class=\"colonna\">g</div><div class=\"colonna\">Brownies</div></div><div class=\"riga\"><div class=\"colonna\">zucchero</div><div class=\"colonna\">160</div><div class=\"colonna\">g</div><div class=\"colonna\">Brownies</div></div><div class=\"riga\"><div class=\"colonna\">burro</div><div class=\"colonna\">150</div><div class=\"colonna\">g</div><div class=\"colonna\">Brownies</div></div><div class=\"riga\"><div class=\"colonna\">uova</div><div class=\"colonna\">2</div><div class=\"colonna\">u</div><div class=\"colonna\">Brownies</div></div><div class=\"riga\"><div class=\"colonna\">farina</div><div class=\"colonna\">90</div><div class=\"colonna\">g</div><div class=\"colonna\">Brownies</div></div><div class=\"riga\"><div class=\"colonna\">cacao</div><div class=\"colonna\">20</div><div class=\"colonna\">g</div><div class=\"colonna\">Brownies</div></div><div class=\"riga\"><div class=\"colonna\">cioccolato</div><div class=\"colonna\">150</div><div class=\"colonna\">g</div><div class=\"colonna\">Torta_Cioccolato</div></div><div class=\"riga\"><div class=\"colonna\">burro</div><div class=\"colonna\">200</div><div class=\"colonna\">g</div><div class=\"colonna\">Torta_Cioccolato</div></div><div class=\"riga\"><div class=\"colonna\">zucchero</div><div class=\"colonna\">150</div><div class=\"colonna\">g</div><div class=\"colonna\">Torta_Cioccolato</div></div><div class=\"riga\"><div class=\"colonna\">Nome</div><div class=\"colonna\">Cognome</div><div class=\"colonna\">Unità di misura</div><div class=\"colonna\">Dolce</div></div><div class=\"riga\"><div class=\"colonna\">farina</div><div class=\"colonna\">150</div><div class=\"colonna\">g</div><div class=\"colonna\">Torta_Cioccolato</div></div><div class=\"riga\"><div class=\"colonna\">cacao</div><div class=\"colonna\">30</div><div class=\"colonna\">g</div><div class=\"colonna\">Torta_Cioccolato</div></div><div class=\"riga\"><div class=\"colonna\">uova</div><div class=\"colonna\">4</div><div class=\"colonna\">u</div><div class=\"colonna\">Torta_Cioccolato</div></div><div class=\"riga\"><div class=\"colonna\">lievito</div><div class=\"colonna\">8</div><div class=\"colonna\">g</div><div class=\"colonna\">Torta_Cioccolato</div></div><div class=\"riga\"><div class=\"colonna\">farina</div><div class=\"colonna\">125</div><div class=\"colonna\">g</div><div class=\"colonna\">Pancake</div></div><div class=\"riga\"><div class=\"colonna\">latte</div><div class=\"colonna\">200</div><div class=\"colonna\">ml</div><div class=\"colonna\">Pancake</div></div><div class=\"riga\"><div class=\"colonna\">burro</div><div class=\"colonna\">25</div><div class=\"colonna\">g</div><div class=\"colonna\">Pancake</div></div><div class=\"riga\"><div class=\"colonna\">zucchero</div><div class=\"colonna\">15</div><div class=\"colonna\">g</div><div class=\"colonna\">Pancake</div></div><div class=\"riga\"><div class=\"colonna\">uova</div><div class=\"colonna\">2</div><div class=\"colonna\">u</div><div class=\"colonna\">Pancake</div></div><div class=\"riga\"><div class=\"colonna\">lievito</div><div class=\"colonna\">6</div><div class=\"colonna\">g</div><div class=\"colonna\">Pancake</div></div><div class=\"riga\"><div class=\"colonna\">mandorle</div><div class=\"colonna\">200</div><div class=\"colonna\">g</div><div class=\"colonna\">Amaretti</div></div><div class=\"riga\"><div class=\"colonna\">zucchero</div><div class=\"colonna\">140</div><div class=\"colonna\">g</div><div class=\"colonna\">Amaretti</div></div><div class=\"riga\"><div class=\"colonna\">zucchero_velo</div><div class=\"colonna\">125</div><div class=\"colonna\">g</div><div class=\"colonna\">Amaretti</div></div><div class=\"riga\"><div class=\"colonna\">albumi</div><div class=\"colonna\">50</div><div class=\"colonna\">g</div><div class=\"colonna\">Amaretti</div></div><div class=\"riga\"><div class=\"colonna\">farina</div><div class=\"colonna\">300</div><div class=\"colonna\">g</div><div class=\"colonna\">Crostata</div></div><div class=\"riga\"><div class=\"colonna\">zucchero</div><div class=\"colonna\">150</div><div class=\"colonna\">g</div><div class=\"colonna\">Crostata</div></div><div class=\"riga\"><div class=\"colonna\">burro</div><div class=\"colonna\">100</div><div class=\"colonna\">g</div><div class=\"colonna\">Crostata</div></div><div class=\"riga\"><div class=\"colonna\">uova</div><div class=\"colonna\">1</div><div class=\"colonna\">u</div><div class=\"colonna\">Crostata</div></div><div class=\"riga\"><div class=\"colonna\">tuorli</div><div class=\"colonna\">1</div><div class=\"colonna\">u</div><div class=\"colonna\">Crostata</div></div><div class=\"riga\"><div class=\"colonna\">lievito</div><div class=\"colonna\">5</div><div class=\"colonna\">g</div><div class=\"colonna\">Crostata</div></div><div class=\"riga\"><div class=\"colonna\">marmellata_albicocca</div><div class=\"colonna\">1</div><div class=\"colonna\">u</div><div class=\"colonna\">Crostata</div></div><div class=\"riga\"><div class=\"colonna\">riso</div><div class=\"colonna\">100</div><div class=\"colonna\">g</div><div class=\"colonna\">Kheer</div></div><div class=\"riga\"><div class=\"colonna\">latte</div><div class=\"colonna\">600</div><div class=\"colonna\">ml</div><div class=\"colonna\">Kheer</div></div><div class=\"riga\"><div class=\"colonna\">cardamomo</div><div class=\"colonna\">10</div><div class=\"colonna\">u</div><div class=\"colonna\">Kheer</div></div><div class=\"riga\"><div class=\"colonna\">zucchero</div><div class=\"colonna\">70</div><div class=\"colonna\">g</div><div class=\"colonna\">Kheer</div></div><div class=\"riga\"><div class=\"colonna\">pistacchi</div><div class=\"colonna\">30</div><div class=\"colonna\">g</div><div class=\"colonna\">Kheer</div></div></div></body></html>";
	fout << html;
	fin.close();
	fout.close();
}

void AggDisphtml()
{
	ingredienti r[l];
	string m;
	const int lun = 100;
	string d = "";
	ifstream fin("dispensa.txt");
	int j = 0;
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
		r[j].nome = m.substr(0, pos);
		for (int i = pos + 1; i < m.length(); i++)
		{
			if (m[i] == ';')
			{
				pos1 = i;
				break;
			}
		}
		r[j].quantita = stoi(m.substr(pos + 1, pos1));
		r[j].u = m.substr(pos1 + 1, m.length());
		j++;
	}
	for (int i = 0; i < j; i++)
	{
		d = d + "<div class = \"riga\"><div class=\"colonna\">" + r[i].nome + "</div><div class=\"colonna\">" + r[i].u + "</div><div class=\"colonna\">" + r[i].dolce + "</div></div>";
	}
	ofstream fout("dispensa.html");
	string html = "<html><head><title>Pasticceria \"Elegante\"</title><link rel=\"stylesheet\" href=\"dispensastile.css\" type=\"text/css\"><style>.tabella{display: table;width: 80%;margin: auto;padding: 0px 50px 50px 50px;}.riga{ display: table-row; }.colonna{display: table-cell;border: 1px solid grey;padding: 0.5em 0 0.5em 0.5em;}body h1{padding: 20px;font-size: 50;text-align: center;}</style></head><body><h1>Dispensa</h1><div class=\"tabella\"><div class=\"riga\"><div class=\"colonna\">Nome</div><div class=\"colonna\">Quantità</div><div class=\"colonna\">Unità di misura</div>" + d + "</div></div></body></html>";
	fout << html;
	fin.close();
	fout.close();
}

void Aggiungi(string dolagg, string ingred, int quantita) 
{
	string m;
	ofstream fout("menu.txt", ios::app);
	ofstream fout1("ricette.txt", ios::app);
	fout << dolagg << endl;
	fout1 << ingred << ';' << quantita << ';' << dolagg << endl;
	fout.close();
	fout1.close();
	AggMenuhtml(dolagg);
	AggRicettehtml(ingred, quantita, dolagg);
}

void Cancella(string dolagg)
{
	string m;
	ifstream fin("menu.txt");
	ofstream fout("appoggio.txt");
	ifstream fin1("ricette.txt");
	ofstream fout1("appoggioR.txt");
	while (fin >> m) 
	{
		if (m != dolagg) 
		{
			fout << m << endl;
		}
	}
	Replace("appoggio.txt", "menu.txt");
	int j = 0;
	string dol[l];
	while (fin1 >> m)
	{
		int pos = 0;
		for (int i = 0; i < m.length(); i++)
		{
			if (m[i] == ';')
			{
				pos = i;
			}
		}
		dol[j] = m.substr(pos + 1, m.length());
		cout << dol[j];
		if (dol[j] != dolagg)
		{
			fout1 << m << endl;
		}
		j++;
	}
	Replace("appoggioR.txt", "ricette.txt");
	fout.close();
	fin.close();
}

void Modifica(string dolR, string dolagg) 
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
	fout.close();
	fin.close();
}

void Dispensa(string filetesto, string filehtml)
{
	string m;
	string d = "";
	ofstream fout(filetesto);
	ofstream fout1(filehtml);
	int j = 0;
	while (fout << m)
	{
		for (int i = 0; i < l; i++) 
		{
			if (ing1[i].nome == "")
			{
				break;
			}
			fout << ing1[i].nome << ';' << ing1[i].quantita << ';' << ing1[i].u << endl;
			d = d + "<div class = \"riga\"><div class=\"colonna\">" + ing1[i].nome + "</div><div class=\"colonna\">" + to_string(ing1[i].quantita) + "</div><div class=\"colonna\">" + ing1[i].u + "</div></div>";
		}
		break;
	}
	string html = "<html><head><title>Pasticceria \"Elegante\"</title><link rel=\"stylesheet\" href=\"dispensastile.css\" type=\"text/css\"><style>.tabella{display: table;width: 80%;margin: auto;padding: 0px 50px 50px 50px;}.riga{ display: table-row; }.colonna{display: table-cell;border: 1px solid grey;padding: 0.5em 0 0.5em 0.5em;}body h1{padding: 20px;font-size: 50;text-align: center;}</style></head><body><h1>Dispensa</h1><div class=\"tabella\"><div class=\"riga\"><div class=\"colonna\">Nome</div><div class=\"colonna\">Quantità</div><div class=\"colonna\">Unità di misura</div></div>" + d + "</div></body></html>";
	fout1 << html;
	fout.close();
	fout1.close();
}

void Aggiusta()
{
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
					ing1[k].u = ing[i].u;
					break;
				}
			}
		}
	}
	cout << endl;
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
		int posun = 0;
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
		for (int i = 0; i < m.length(); i++)
		{
			if (m[i] == ';')
			{
				posun = i;
			}
		}
		ing[j].quantita = stoi(m.substr(pos + 1, pos1));
		ing[j].dolce = m.substr(pos1 + 1, posun - pos1 - 1);
		ing[j].u = m.substr(posun + 1, m.length());
		cout << ing[j].u;
		j++;
	}
	Aggiusta();
	fin.close();
}

void OrdSpesa(string dol, int numd)
{
	int diff;
	string d = "";
	ofstream fout("listaspesa.txt", ios::app);
	ofstream fout1("dispensaagg.txt");
	ofstream fout2("listadellaspesa.html");
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
						d = d + "<div class = \"riga\"><div class=\"colonna\">" + ing1[j].nome + "</div><div class=\"colonna\">" + to_string(diff) + "</div><div class=\"colonna\">" + "u" + "</div></div>";
					}
				}
			}
		}
	}
	for (int i = 0; i < l; i++) 
	{
		fout1 << ing1[i].nome << ';' << ing1[i].quantita << endl;
	}
	string html = "<html><head><title>Pasticceria \"Elegante\"</title><style>.tabella{display: table;width: 80%;margin: auto;padding: 0px 50px 50px 50px;}.riga{ display: table-row; }.colonna{display: table-cell;border: 1px solid grey;padding: 0.5em 0 0.5em 0.5em;}body h1{padding: 20px;font-size: 50;text-align: center;}</style></head><body><h1>Lista della Spesa</h1><div class=\"tabella\"><div class=\"riga\"><div class=\"colonna\">Nome</div><div class=\"colonna\">Quantità</div><div class=\"colonna\">Unità di misura</div></div>" + d + "</div></body></html>";
	fout2 << html;
	fout.close();
	fout1.close();
	fout2.close();
	Dispensa("dispensaagg.txt", "dispensa.html");
}

void CancContFile(string nomefile) 
{
	ofstream fout(nomefile);
	fout.close();
}

void Ordinazionehtml(string dol, int numd)
{
	string d;
	ofstream fout("ordinazione.html");
	d = d + "<div class = \"riga\"><div class=\"colonna\">" + dol + "</div><div class=\"colonna\">" + to_string(numd) + "</div></div>";
	string html = "<html><head><title>Pasticceria \"Elegante\"</title><style>.tabella{display: table;width: 80%;margin: auto;padding: 0px 50px 50px 50px;}.riga{ display: table-row; }.colonna{display: table-cell;border: 1px solid grey;padding: 0.5em 0 0.5em 0.5em;}body h1{padding: 20px;font-size: 50;text-align: center;}</style></head><body><h1>Ordinazione</h1><div class=\"tabella\"><div class=\"riga\"><div class=\"colonna\">Nome</div><div class=\"colonna\">Quantità</div></div>" + d + "</div></body></html>";
	fout << html;
	fout.close();
}

int main()
{
	int scelta, numd, quantita, b, v;
	string dolagg, ingred, dol, dolR;
	ofstream fout("ordinazione.html");
	fout.close();
	do {
		system("CLS");
		//opzioni
		cout << "Pasticceria" << endl;
		cout << "1. Aggiungi un dolce sulla lista" << endl;
		cout << "2. Cancella un dolce sulla lista" << endl;
		cout << "3. Modifica un dolce sulla lista" << endl;
		cout << "4. Ordina un dolce" << endl;
		cout << "5. Visualizza la dispensa" << endl;
		cout << "6. Visualizza la lista della spesa" << endl;
		cout << "7. Cancella la lista della spesa" << endl;
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
		case 3:
			cout << "Inserisci il nome del dolce che vuoi modificare:" << endl;
			cin >> dolR;
			cout << "Inserisci il nuovo nome del dolce da modificare:" << endl;
			cin >> dolagg;
			do {
				cout << "Inserisci un ingrediente: " << endl;
				cin >> ingred;
				cout << "Inserisci la sua quantita: " << endl;
				cin >> quantita;
				cout << "Vuoi inserire un altro ingrediente? (immettere '0' per uscire): ";
				cin >> v;
				Modifica(dolR, dolagg);
			} while (v != 0);
			cout << "Digitare '0' per continuare..." << endl;
			cin >> b;
			if (b == 0)
			{
				break;
			}
		case 4:
			cout << "Menu Pasticceria:" << endl;
			StampaFile("menu.txt");
			Caricamento();
			Dispensa("dispensa.txt", "dispensa.html");
			//...
			do {
				cout << "Inserisci il dolce che vuoi ordinare: ";
				cin >> dol;
				cout << "Inserisci il numero di " << dol << " che vuoi ordinare: ";
				cin >> numd;
				cout << "Vuoi ordinare altro? (immettere '0' per uscire): ";
				cin >> v;
				Ordinazionehtml(dol, numd);
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
		case 5:
			cout << "Dispensa" << endl;
			StampaFile("dispensaagg.txt");
			cout << "Digitare '0' per continuare..." << endl;
			cin >> b;
			if (b == 0)
			{
				break;
			}
		case 6:
			cout << "Lista della Spesa" << endl;
			StampaFile("listaspesa.txt");
			cout << "Digitare '0' per continuare..." << endl;
			cin >> b;
			if (b == 0)
			{
				break;
			}
		case 7:
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
