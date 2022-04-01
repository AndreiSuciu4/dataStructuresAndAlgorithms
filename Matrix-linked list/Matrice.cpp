#include "Matrice.h"

#include <exception>

using namespace std;

//constructor
Nod::Nod(TElem e, int linie, int coloana, PNod ant, PNod urm) {
	this->e = e;
	this->linie = linie;
	this->coloana = coloana;
	this->ant = ant;
	this->urm = urm;
}

//returneaza elementul din nodul curent
TElem Nod::element() {
	return e;
}

//returneaza adresa urmatorului nod
PNod Nod::urmator() {
	return urm;
}

//returneaza adresa nodului anterior
PNod Nod::anterior() {
	return ant;
}

	//constructor
	//se arunca exceptie daca nrLinii<=0 sau nrColoane<=0
	//complexitate de timp : θ(1)
Matrice::Matrice(int m, int n) {
	prim = nullptr;
	if (m <= 0 || n <= 0)
		throw exception("valoare invalida ");

	this->NRlinii = m;
	this->NRcoloane = n;
}


// returnare numar linii
//complexitate de timp:θ(1)
int Matrice::nrLinii() const {
	return this->NRlinii;
}

// returnare numar coloane
//complexitate de timp:θ(1)
int Matrice::nrColoane() const {
	return this->NRcoloane;
}

    //returnare element de pe o linie si o coloana
	//se arunca exceptie daca (i,j) nu e pozitie valida in Matrice
	//indicii se considera incepand de la 0
	//complexitate de timp :- caz favorabil-cand elementul cautat se afla in capul listei - θ(1)
	//						-caz defavorabil-cand elementul cautat nu se afla in lista -θ(n),n-n-nr de elemente din matrice diferite de 0
	//                      -caz mediu:θ(n)
	//                      -total:O(n)
TElem Matrice::element(int i, int j) const
{
	if (i >= this->NRlinii)
		throw exception("linie invalida");
	if (j >= this->NRcoloane)
		throw exception("coloana invalida");
	PNod q = prim;
	while (q != nullptr)
	{
		if (q->linie == i && q->coloana == j)
			
			return q->e;

		q = q->urm;
	}
	return NULL_TELEMENT;
}


	// modificare element de pe o linie si o coloana si returnarea vechii valori
	// se arunca exceptie daca (i,j) nu e o pozitie valida in Matrice
	//complexitate de timp :- caz favorabil-cand elementul de modificat se afla in capul listei - θ(1)
	//						-caz defavorabil-cand elementul de modificat nu se afla in lista -θ(n),n-n-nr de elemente din matrice diferite de 0
	//                      -caz mediu:θ(n)
	//                      -total:O(n)
TElem Matrice::modifica(int i, int j, TElem e) {
	if (i >= this->NRlinii)
		throw exception("linie invalida");
	if (j >= this->NRcoloane)
		throw exception("coloana invalida");
	Nod* p = prim;
	while (p != nullptr)
	{
		{if (p->linie  == i && p->coloana == j)
			{
				
				TElem e1 = p->e;
				p->e = e;
				return e1;
			}
		}
		p = p->urm;
	}
	PNod q = new Nod(e, i, j, nullptr, nullptr);
	q->urm = prim;
	prim = q;
	return e;
}

/*
* preconditii:Matricea trebuie sa fie valida
* postconditii:Matrice:-transpusa matricei 
* subalgoritm transpusa(Matrice)
*	p<-[prim]
*	cat timp (p!= NIL) executa
*		aux<-[p].coloana
*		[p].coloana<-[p].linie
*		[p].linie<-aux
*	sf_catTimp
*complexitate de timp :θ(n), n-numarul de elemente din matrice diferite de 0
*/

void Matrice::transpusa()
{
	Nod* p = prim;

	while (p != nullptr)
	{
		int aux = p->coloana;
		p->coloana = p->linie;
		p->linie = aux;
		p = p->urm;
	}


}
