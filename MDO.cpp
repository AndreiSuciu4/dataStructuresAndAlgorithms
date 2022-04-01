#include "IteratorMDO.h"
#include "MDO.h"
#include <iostream>
#include <vector>

#include <exception>
using namespace std;

valori::valori() {
	//lista e vida
	lista = new TValoare[cap];
	urm = new int[cap];
	prim = NULL_TELEMENT;
	//se initializeaza lista spatiului liber - toate pozitiile din vecto sunt marcate ca fiind libere
	for (int i = 0; i < cap - 1; i++)
		urm[i] = i + 1;
	urm[cap - 1] = NULL_TELEMENT;
	//referinta spre prima pozitie libera din lista
	primLiber = 0;

}

int valori::aloca() {
	//se sterge primul element din lista spatiului liber
	int i = primLiber;
	if (i != NULL_TELEMENT)
		primLiber = urm[primLiber];
	return i;
}

void valori::dealoca(int i) {
	//se trece pozitia i in lista spatiului liber
	urm[i] = primLiber;
	primLiber = i;
}

void valori::redimensionare() {

	//alocam un spatiu de capacitate dubla
	TValoare* eNou = new int[2 * cap];
	int* urmNou = new int[2 * cap];

	//copiem vechile valori in noua zona
	for (int i = 0; i < cap; i++)
	{
		eNou[i] = lista[i];
		urmNou[i] = urm[i];
	}

	//dublam capacitatea
	primLiber = cap;
	int cp = cap;
	cap = 2 * cap;
	delete[] lista;
	delete[] urm;
	lista = eNou;
	urm = urmNou;

	for (int i = cp; i < cap - 1; i++)
		urm[i] = i + 1;
	urm[cap - 1] = NULL_TELEMENT;


}

//creeaza un nod in lista inlantuita unde se memoreaza informatia utila e
int valori::creeazaNod(TValoare e) {

	int i = aloca();
	if (i == NULL_TELEMENT) {
		redimensionare();
		i = aloca();
	}
	this->lista[i] = e;
	urm[i] = NULL_TELEMENT;
	return i;
}

void valori::adauga(TValoare e) {
	int i = creeazaNod(e);
	if (i != NULL_TELEMENT) {
		urm[i] = prim;
		prim = i;
	}
}

int valori::pozitie(TValoare e)
{
	int poz = prim;
	while (poz != -1 && this->lista[poz] != e) {
		poz = urm[poz];
	}
	if (this->lista[poz] == e)
		return poz;
	else
		return NULL_TELEMENT;
}

void valori::sterge(int poz)
{
	if (poz == prim) {
		int aux = prim;
		prim = urm[prim];
		dealoca(aux);
		return;
	}
	int aux = prim;
	while (aux != NULL_TELEMENT) {
		int prim1 = aux;
		aux = urm[aux];
		if (aux == poz)
		{
			urm[prim1] = urm[aux];
			dealoca(aux);
			return;
		}
	}

}

bool valori::vida()
{
	if (prim == NULL_TELEMENT)
		return true;
	else
		return false;
}

int valori::dim()const {
	int contor = 0;
	int parcurg = prim;
	while (parcurg != NULL_TELEMENT) {
		parcurg = urm[parcurg];
		contor++;
	}
	return contor;
}


int MDO::aloca() {
	//se sterge primul element din lista spatiului liber
	int i = primLiber;
	primLiber = urm[primLiber];
	return i;
}

void MDO::dealoca(int i) {
	//se trece pozitia i in lista spatiului liber
	urm[i] = primLiber;
	primLiber = i;

}

//creeaza un nod in lista inlantuita unde se memoreaza informatia utila e
int MDO::creeazaNod() {
	int i = aloca();
	if (i == NULL_TELEMENT) {
		redimensionare();
		i = aloca();
	}
	urm[i] = -1;
	
	return i;
}

void MDO::redimensionare()
{
	//alocam un spatiu de capacitate dubla
	nod* eNou = new nod[2 * cap];
	int* urmNou = new int[2 * cap];

	//copiem vechile valori in noua zona
	for (int i = 0; i < cap; i++)
	{
		eNou[i] = elems[i];
		urmNou[i] = urm[i];
	}

	//dublam capacitatea
	primLiber = cap;
	int cp = cap;
	cap = 2 * cap;
	delete[] elems;
	delete[] urm;
	elems = eNou;
	urm = urmNou;

	for (int i = cp; i < cap - 1; i++)
		urm[i] = i + 1;
	urm[cap - 1] = NULL_TELEMENT;
}

void MDO::cautaNod(const TCheie& cheie, int &nodc, int &prec)const {
	int aux = prim;
	int precedent  = -1;
	bool gasit=false;
	while (gasit == false && aux != -1 && relatie(elems[aux].key, cheie))
	{
		if (elems[aux].key == cheie)
			gasit = true;
		else
		{
			precedent = aux;
			aux = urm[aux];
		}
	}
	if (gasit)
	{
		nodc = aux;
		prec = precedent;
	}
	else
	{
		nodc = -1;
		prec = precedent;
	}
}

MDO::MDO(Relatie r) {
	elems = new nod[cap];
	urm = new int[cap];
	relatie = r;
	prim = -1;
	//se initializeaza lista spatiului liber - toate pozitiile din vecto sunt marcate ca fiind libere
	for (int i = 0; i < cap - 1; i++)
		urm[i] = i + 1;
	urm[cap - 1] = -1;
	//referinta spre prima pozitie libera din lista
	primLiber = 0;
}

void MDO::adaugaCheieNoua(TCheie c, TValoare v, int prec)
{
	int nou = creeazaNod();
	if (prec == -1)
	{
		urm[nou] = prim;
		prim = nou;
	}
	else
	{
		urm[nou] = urm[prec];
		urm[prec] = nou;
	}
	elems[nou].valori.adauga(v);
	elems[nou].key = c;
}

void MDO::stergeCheie(int prec)
{
	if (prec == -1)
	{
		int sters = prim;
		prim = urm[prim];
		//distruge lsi
		dealoca(sters);

	}
	else
	{
		int sters = urm[prec];
		urm[prec] = urm[urm[prec]];
		//distruge lsi
		dealoca(sters);
	}
		
}

void MDO::adauga(TCheie c, TValoare v) {
	int nod, prec;

	cautaNod(c, nod, prec);
	if (nod == -1)
	{
		adaugaCheieNoua(c, v, prec);
	}
	else
		elems[nod].valori.adauga(v);

}
 
//trebuie const
vector<TValoare> MDO::cauta(TCheie c) const {
	vector<TValoare>val;
	int nod, prec;
	cautaNod(c, nod, prec);
	int i = elems[nod].valori.prim;
	if (nod != -1)
	{
		while (i != -1)
		{
			val.push_back(elems[nod].valori.lista[i]);
			i = elems[nod].valori.urm[i];
		}
	}
	return val;
}

bool MDO::sterge(TCheie c, TValoare v) {
	int nod, prec,poz;
	cautaNod(c, nod, prec);
	bool rez = false;
	if (nod != -1)
	{
		poz = elems[nod].valori.pozitie(v);
		if (poz != -1)
		{
			elems[nod].valori.sterge(poz);
			rez = true;
		}
	}
	if (elems[nod].valori.prim == -1)
	{
		stergeCheie(prec);
		rez = true;
	}


	return rez;
}

int MDO::dim() const {
	int cont = 0;
	int parcurg = prim;
	while (parcurg != -1) {
		cont = cont + elems[parcurg].valori.dim();
		parcurg = urm[parcurg];
	}
	return cont;
}

bool MDO::vid() const {
	if (prim == -1)
		return true;
	else
		return false;
}

IteratorMDO MDO::iterator() const {
	return IteratorMDO(*this);
}

MDO::~MDO() {
	delete[] elems;
	delete[] urm;
}

vector<TValoare> MDO::stergeValoriPentruCheie(TCheie cheie)
{
	vector <TValoare> valori = cauta(cheie);
	if (valori.size() != 0) {
		for (const auto& val : valori)
		{
			sterge(cheie, val);
		}
	}
	return valori;
}
