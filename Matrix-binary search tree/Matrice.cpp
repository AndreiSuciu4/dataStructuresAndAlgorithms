#include "Matrice.h"

#include <exception>
#include <iostream>

using namespace std;

void Matrice::redimensionare()
{
	nod* eNou = new nod[2 * cap];
	int* stangaNou = new int[2 * cap];
	int* dreaptaNou = new int[2 * cap];

	for (int i = 0; i < cap ; i++)
	{
		eNou[i] = elem[i];
	}

	for (int i = 0; i < cap - 1; i++)
	{
		stangaNou[i] = stanga[i];
		dreaptaNou[i] = dreapta[i];
	}

	int cp = cap;
	cap = 2 * cap;
	delete[] elem;
	delete[] stanga;
	delete[] dreapta;
	elem = eNou;
	stanga = stangaNou;
	dreapta = dreaptaNou;

	for (int i = cp - 1; i < cap - 1; i++) {
		stanga[i] = i + 1;
		dreapta[i] = i + 1;
	}

	for (int i = cp ; i < cap; i++) {
		elem[i].valoare = -1;
		elem[i].linie = -1;
		elem[i].coloana = -1;
	}
}

Matrice::Matrice(int m, int n) {
	if (m <= 0 || n <= 0)
		throw ("eroare!");
	elem = new nod[cap];
	stanga = new int[cap];
	dreapta = new int[cap];
	rad = 0;
	for (int i = 0; i < cap - 1; i++)
	{
		stanga[i] = i + 1;
		dreapta[i] = i + 1;
	}

	for (int i = 0; i < cap; i++) {
		elem[i].valoare = -1;
		elem[i].linie = -1; 
		elem[i].coloana = -1;
	}
	
	rad = 0;
	nrLin = m;
	nrCol = n;
}



int Matrice::nrLinii() const {
	return nrLin;
}


int Matrice::nrColoane() const {
	return nrCol;
}


TElem Matrice::element(int i, int j) const {
	if (i >= nrLin)
		throw exception("linie invalida");
	if (j >= nrCol)
		throw exception("coloana invalida");

	int p = rad;
	while (elem[p].valoare != -1 && (elem[p].linie != i || elem[p].coloana != j)) {
		if (i < elem[p].linie)
			p = stanga[p];
		else
		{
			if (i == elem[p].linie && j < elem[p].coloana)
				p = stanga[p];
			else
				p = dreapta[p];
		}
	}

	if (elem[p].valoare != -1 && elem[p].valoare != -2)
		return elem[p].valoare;
	else
		return NULL_TELEMENT;

}



TElem Matrice::modifica(int i, int j, TElem e) {
	if (i >= nrLin || i < 0)
		throw exception("linie invalida");
	if (j >= nrCol || j < 0)
		throw exception("coloana invalida");
	
	int p = rad;
	nod n{ i, j, e };
	while(elem[p].valoare != -1 && (elem[p].linie != i || elem[p].coloana != j)) {
		if (i < elem[p].linie) {
			p = stanga[p];
		}

		else

		{
			if (i == elem[p].linie && j <= elem[p].coloana) {
				p = stanga[p];
			}

			else 
				if (i == elem[p].linie && j > elem[p].coloana) {
					p = dreapta[p];
				}
			     else
			if (i > elem[p].linie) {
				p = dreapta[p];
			}
		}
		if (p == cap - 1) 
			redimensionare();
	}

	if (elem[p].valoare != -1)
	{
		if (e != 0) {
			TElem aux = elem[p].valoare;
			elem[p].valoare = e;
			return aux;
		}
		else
		{
			TElem aux = elem[p].valoare;
			elem[p].valoare = -1;
			elem[p].linie = -1;
			elem[p].coloana = -1;
			return aux;
		}
	}
	else {
		elem[p] = n;
	}
	return NULL_TELEMENT;
}

IteratorMatrice Matrice::iterator(int coloana)
{
	return IteratorMatrice(*this, coloana );

}
 