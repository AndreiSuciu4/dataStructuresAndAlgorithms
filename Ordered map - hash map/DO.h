#pragma once

typedef int TCheie;
typedef int TValoare;

#define NULL_TVALOARE -50000
#define STERS -50001

#define MAX 30 //numarul maxim de locatii din tabela

#include <utility>
typedef std::pair<TCheie, TValoare> TElem;

class Iterator;

typedef bool(*Relatie)(TCheie, TCheie);
typedef TValoare(*Transformator) (TCheie, TValoare);

class DO {
	friend class Iterator;
private:
	//reprezentare folosind o TD - rezolvare coliziuni prin adresare deschisa si verificare liniara
	int m; //numarul de locatii din tabela de dispersie
	TElem* e; //vectorul elementelor
	Relatie rel;
	// functia de dispersie extinsa

//calculeaza modului unei chei
//date de intrare:-c TCheie
//date de iesire:-modulul cheii
//complexitate de timp : theta(1)
	int hashCode(TCheie c) const;

	/*functia de dispersie
	* date de intrare:-c-TCheie
	*                 -i-int
	* date de iesire-rezultatul functiei
	* complexitate de timp:theta(1)
	*/
	int d(TCheie c, int i) const;

	/*functie de dispersie
	* date de intrare:-c-TCheie
	* date de iesire-rezultatul functiei
	* complexitate de timp:theta(1)
	*/
	int d1(TCheie c) const;

	/*functie de dispersie
	* date de intrare:-c-TCheie
	* date de iesire-rezultatul functiei
	* complexitate de timp:theta(1)
	*/
	int d2(TCheie c) const;

	/*functie de cautare
	* date de intrare:-c-TCheie
	* date de iesire:-pozitia cheii-int
	* complexitate de timp:
	* caz favorabil:cheia cautata se afla pe prima pozitie:theta(1)
	* caz defavorabil:nu exista cheia in vector:theta(m)
	* caz mediu:theta(m)
	* overall complexity:O(m)
	*/
	int pozitie(TCheie c) const;

	/*redimensionare
	* date de intrare:-
	* date de iesire:-
	* complexitate de timp : theta(m)
	*/
	void redimensionare();
public:

/*constructor
* date de intrare:r-relatie
* date de iesire:-
* complexitate de timp:theta(m)
*/
	DO(Relatie r);


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
	TValoare adauga(TCheie c, TValoare v);

	/*
* date de intrare:-c-TCheie
cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null
* complexitate de timp:
* caz favorabil:cheia cautata se afla pe prima pozitie:theta(1)
* caz defavorabil:nu exista cheia in vector:theta(m)
* caz mediu:theta(m)
* overall complexity:O(m)
*/
	TValoare cauta(TCheie c) const;


	/*date de intrare:-c-TCheie
sterge o cheie si returneaza valoarea asociata (daca exista) sau null
complexitate de timp:
* caz favorabil:cheia cautata se afla pe prima pozitie:theta(1)
* caz defavorabil:nu exista cheia in vector:theta(m)
* caz mediu:theta(m)
* overall complexity:O(m)
*/
	TValoare sterge(TCheie c);

	/*
* date de intrare:-
returneaza numarul de perechi (cheie, valoare) din dictionar
complexitate de timp:theta(m)
*/
	int dim() const;

	/*
	verifica daca dictionarul e vid
	date de intrare:-
	date de iesire:-true daca e vid
				   -false - in caz contrar
	complexitate de timp:theta(m)
	*/	bool vid() const;

	/*returneaza un iterator pe acest dictionar
* date de intrare:-
* date de iesire:-
* complexitate de timp:theta(1)
*/
	Iterator iterator() const;

	/* inlocuieste valoarea asociată fiecărei chei cu rezultatul dat de o funcție invocată pe pereche.
	date de intrare:t-Transformator
	date de iesire:-
	Subalgoritm inlocuiesteToate(DO,t)
		Pre:DO-un dictionar ordonat
			t-un Transformator
		Post:-

		Pentru i<-0,m executa
			daca e[i].first != NULL executa
				e[i].second<-t(e[i].first,e[i].second)
			SfDaca
		SfPentru
	SfSubalgoritm

	Complexitate de timp:theta(m)
	*/
	void înlocuieșteToate(Transformator t);

	/*destructor
	* date de intrare:-
	* date de iesire:-
	* complexitate de timp:theta(1)
	*/	~DO();

};
