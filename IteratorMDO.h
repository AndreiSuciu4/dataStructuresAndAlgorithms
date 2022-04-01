#pragma once

#include "MDO.h"
#include "IteratorMDO.h"

typedef int TCheie;
typedef int TValoare;
typedef std::pair<TCheie, TValoare> TElem;

class IteratorMDO {
	friend class MDO;
private:

	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container
	//date de intrare:-dictionar:-referinta la MDO
	//date de iesire:-
	//complexitate de timp:theta(1)
	IteratorMDO(const MDO& dictionar);

	//contine o referinta catre containerul pe care il itereaza
	const MDO& dict;
	/* aici e reprezentarea  specifica a iteratorului */
	int curent;
	int curentLista;

public:

	//reseteaza pozitia iteratorului la inceputul containerului
	//date de intrare:-dictionar:-referinta la MDO
	//date de iesire:-
	//complexitate de timp:theta(1)
	void prim();

	//muta iteratorul in container
	// arunca exceptie daca iteratorul nu e valid
	//date de intrare:-dictionar:-referinta la MDO
	//date de iesire:-
	//complexitate de timp:theta(1)
	void urmator();

	//verifica daca iteratorul e valid (indica un element al containerului)
	//date de intrare:-dictionar:-referinta la MDO
	//date de iesire:-true-daca e valid
	// 	            :-false-daca nu e valid
	//complexitate de timp:theta(1)
	bool valid() const;

	//returneaza valoarea elementului din container referit de iterator
	//arunca exceptie daca iteratorul nu e valid
	//date de intrare:-
	//date de iesire:TElem
	//complexitate de timp:O(1)
	TElem element() const;
};

