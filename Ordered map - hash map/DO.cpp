#include "Iterator.h"
#include "DO.h"
#include <iostream>
#include <math.h>

#include <exception>
using namespace std;

//calculeaza modului unei chei
//date de intrare:-c TCheie
//date de iesire:-modulul cheii
//complexitate de timp : theta(1)
int DO::hashCode(TCheie c) const
{
	return abs(c);
}

/*functia de dispersie
* date de intrare:-c-TCheie
*                 -i-int
* date de iesire-rezultatul functiei
* complexitate de timp:theta(1)
*/
int DO::d(TCheie c, int i) const
{
	return (d1(c) + i * d2(c)) % m;
}
 
/*functie de dispersie
* date de intrare:-c-TCheie
* date de iesire-rezultatul functiei
* complexitate de timp:theta(1)
*/
int DO::d1(TCheie c) const
{
	return hashCode(c) % m;
}

/*functie de dispersie
* date de intrare:-c-TCheie
* date de iesire-rezultatul functiei
* complexitate de timp:theta(1)
*/
int DO::d2(TCheie c) const
{
	return 1 + hashCode(c) % (m - 2);
}

/*functie de cautare
* date de intrare:-c-TCheie
* date de iesire:-pozitia cheii-int
* complexitate de timp:
* caz favorabil:cheia cautata se afla pe prima pozitie:theta(1)
* caz defavorabil:nu exista cheia in vector:theta(m)
* caz mediu:theta(m)
* overall complexity:O(m)
*/
int DO::pozitie(TCheie c) const
{
	int i = 0;
	while (e[d(c, i)].first != NULL_TVALOARE && e[d(c, i)].first != c) {
		i++;
		if (i == m)
			return -1;
	}
	return i;
}

/*constructor
* date de intrare:r-relatie 
* date de iesire:-
* complexitate de timp:theta(m)
*/
DO::DO(Relatie r) {
	m = MAX; //initializam m cu o valoare predefinita
	rel = r;
	e = new TElem[m];
	for (int i = 0; i < m; i++) {
		e[i].first = NULL_TVALOARE;
		e[i].second = NULL_TVALOARE;
	}
}

/*redimensionare
* date de intrare:-
* date de iesire:-
* complexitate de timp : theta(m)
*/
void DO::redimensionare() {
	TElem* aux = new TElem[m];
	for (int i = 0; i < m; i++)
		aux[i] = e[i];

	//alocam un spatiu de capacitate dubla
  	TElem* eNou = new TElem[2 * m];

	for (int i = 0; i < 2 * m; i++) {
		eNou[i].first = NULL_TVALOARE;
		eNou[i].second = NULL_TVALOARE;
	}

	//dublam capacitatea
	m = 2 * m;

	//eliberam vechea zona
	delete[] e;

	//vectorul indica spre noua zona
	e = eNou;

	for (int i = 0; i < m/2; i++)
		adauga(aux[i].first,aux[i].second);
	delete[] aux;
}

//adauga o pereche (cheie, valoare) in dictionar
//date de intrare:c-TCheie
//                v-TValoare
//daca exista deja cheia in dictionar, inlocuieste valoarea asociata cheii si returneaza vechea valoare
//daca nu exista cheia, adauga perechea si returneaza null
//complexitate de timp:
//  caz favorabil:adaugam pe prima pozitie:theta(1) amortizata
// caz defavorabil : adaugam pe ultim pozitie : theta(m) amortizata
// caz mediu : theta(m) amortizata
// overall complexity : O(m) amortizata

TValoare DO::adauga(TCheie c, TValoare v) {
	//locatia de dispersie a cheii
	int i = 0; //numarul de verificare
	TElem el;
	el.first = c;
	el.second = v;
	bool gasit = false;
	do {
		int j = d(c, i);
		if (e[j].first == NULL_TVALOARE || e[j].first == STERS) {
			e[j] = el;
			gasit = true;
			return NULL_TVALOARE;
		}
		if (e[j].first == c)
		{
			TValoare v1 = e[j].second;
			e[j] = el;
			return v1;
		}
		i++;
	} while (i < m && !gasit);
	if (i == m) {
		redimensionare();
		adauga(c, v);
	}
}

/*
* date de intrare:-c-TCheie
cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null
* complexitate de timp:
* caz favorabil:cheia cautata se afla pe prima pozitie:theta(1)
* caz defavorabil:nu exista cheia in vector:theta(m)
* caz mediu:theta(m)
* overall complexity:O(m)
*/
TValoare DO::cauta(TCheie c) const {
	int i = 0;
	while (e[d(c, i)].first != NULL_TVALOARE && e[d(c, i)].first != c) {
		if (i == m)
			return NULL_TVALOARE;
		i++;
	}
	return e[d(c,i)].second;
}

/*date de intrare:-c-TCheie
sterge o cheie si returneaza valoarea asociata (daca exista) sau null
complexitate de timp:
* caz favorabil:cheia cautata se afla pe prima pozitie:theta(1)
* caz defavorabil:nu exista cheia in vector:theta(m)
* caz mediu:theta(m)
* overall complexity:O(m)
*/
TValoare DO::sterge(TCheie c) {
	int i = pozitie(c);
	if (i != -1)
	{
		e[d(c, i)].first = STERS;
		return e[d(c,i)].second;
	}
	return NULL_TVALOARE;
}
/*
* date de intrare:-
returneaza numarul de perechi (cheie, valoare) din dictionar
complexitate de timp:theta(m)
*/
int DO::dim() const {
	int contor = 0;
	for (int i = 0; i < m; i++)
	{
		if (e[i].first != NULL_TVALOARE)
			if (e[i].first != STERS)
			contor++;
	}
	return contor;
}

/*
verifica daca dictionarul e vid
date de intrare:-
date de iesire:-true daca e vid
			   -false - in caz contrar
complexitate de timp:theta(m)
*/
bool DO::vid() const {
	if(dim() == 0 )
		return true;
	return false;
}

/*returneaza un iterator pe acest dictionar
* date de intrare:-
* date de iesire:-
* complexitate de timp:theta(1)
*/
Iterator DO::iterator() const {
	return  Iterator(*this);
}

/* inlocuieste valoarea asociată fiecărei chei cu rezultatul dat de o funcție invocată pe pereche. 
date de intrare:t-Transformator
date de iesire:-
Subalgoritm inlocuiesteToate(DO,t)
	Pre:DO-un dictionar ordonat
	    t-un Transformator
	Post:DO'-dictionarul ordonat in care s-a aplicat t-ul

	Pentru i<-0,m executa
		daca e[i].first != NULL executa
			e[i].second<-t(e[i].first,e[i].second)
		SfDaca
	SfPentru
SfSubalgoritm

Complexitate de timp:theta(m)
*/
void DO::înlocuieșteToate(Transformator t)
{
	for (int i = 0; i < m; i++)
		if (e[i].first != NULL_TVALOARE)
			e[i].second = t(e[i].first, e[i].second);

}

/*destructor
* date de intrare:-
* date de iesire:-
* complexitate de timp:theta(1)
*/
DO::~DO() {
	delete[] e;
}