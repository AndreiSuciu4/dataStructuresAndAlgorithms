#pragma once

typedef int TElem;

#define NULL_TELEMENT 0

class Nod;

//se defineste tipul PNod ca fiind adresa unui Nod

typedef Nod* PNod;

class Nod

{

public:

	friend class Matrice;

	//constructor

	Nod(TElem e,int linie, int coloana, PNod ant, PNod urm);

	//returneaza elementul din nodul curent
	TElem element();

	//returneaza adresa urmatorului nod
	PNod urmator();

	//returneaza adresa nodului anterior
	PNod anterior();

private:

	TElem e;
	int linie;
	int coloana;
	PNod ant;
	PNod urm;

};

class Matrice {

private:
	/* aici e reprezentarea */
	PNod prim;
	int NRlinii;
	int NRcoloane;

public:

	//constructor
	//se arunca exceptie daca nrLinii<=0 sau nrColoane<=0
	//complexitate de timp : θ(1)
	Matrice(int nrLinii, int nrColoane);


	//destructor
	//complexitate de timp : θ(n),n-nr de elemente din matrice diferite de 0
	~Matrice() {
		while (prim != nullptr) {
			PNod p = prim;
			prim = prim->urm;
			delete p;
		}
	};

	//returnare element de pe o linie si o coloana
	//se arunca exceptie daca (i,j) nu e pozitie valida in Matrice
	//indicii se considera incepand de la 0
	//complexitate de timp :- caz favorabil-cand elementul cautat se afla in capul listei - θ(1)
	//						-caz defavorabil-cand elementul cautat nu se afla in lista -θ(n),n-n-nr de elemente din matrice diferite de 0
	//                      -caz mediu:θ(n)
	//                      -total:O(n)
	TElem element(int i, int j) const;


	// returnare numar linii
	//complexitate de timp:θ(1)
	int nrLinii() const;

	// returnare numar coloane
	//complexitate de timp:θ(1)
	int nrColoane() const;


	// modificare element de pe o linie si o coloana si returnarea vechii valori
	// se arunca exceptie daca (i,j) nu e o pozitie valida in Matrice
	//complexitate de timp :- caz favorabil-cand elementul de modificat se afla in capul listei - θ(1)
	//						-caz defavorabil-cand elementul de modificat nu se afla in lista -θ(n),n-n-nr de elemente din matrice diferite de 0
	//                      -caz mediu:θ(n)
	//                      -total:O(n)
	TElem modifica(int i, int j, TElem);

	void transpusa();
};