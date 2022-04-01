
#include "Coada.h"
#include <exception>
#include <iostream>

using namespace std;

void Coada::redim() {

	//alocam un spatiu de capacitate dubla
	TElem* eNou = new int[2 * cp];

	//copiem vechile valori in noua zona
	for (int i = 0; i < spate; i++)
		eNou[i] = e[i];

	//dublam capacitatea
	cp = 2 * cp;

	//eliberam vechea zona
	delete[] e;

	//vectorul indica spre noua zona
	e = eNou;
}


//constructorul implicit
//complexitatea de timp:θ(1)
Coada::Coada() {
	//setam capacitatea
	cp = 1;

	//setam fata
	fata = 0;

	//setam spatele
	e = new TElem[cp];

	//setam spatele
	spate = 0;
}

//adauga un element in coada
//complexitatea de timp:O(1) amortizata
void Coada::adauga(TElem elem) {
	
	if (spate == cp)
		redim();
	e[spate++] = elem;
}

//acceseaza elementul cel mai devreme introdus in coada 
//arunca exceptie daca coada e vida
//complexitatea de timp :θ(1)
TElem Coada::element() const {
	if (fata == spate)

		throw exception("coada vida");

	return e[fata];
}

//sterge elementul cel mai devreme introdus in coada si returneaza elementul sters (principiul FIFO)
//arunca exceptie daca coada e vida
//complexitatea de timp :θ(1)
TElem Coada::sterge() {
	if (fata == spate)
		throw exception("coada vida");

	TElem el = e[fata];
	fata = fata + 1;
	return el;

}

//verifica daca coada e vida;
//complexitatea de timp :θ(1)
bool Coada::vida() const {
	if (fata == spate)
		return true;
	else
		return false;
}

// destructorul cozii
//complexitatea de timp :θ(n)
Coada::~Coada() {
	delete[] e;
}
