#pragma once

#include <vector>
#include "IteratorMDO.h"

typedef int TCheie;
typedef int TValoare;
#define NULL_TELEMENT -1
#include <utility>
#include "IteratorMDO.h"
typedef std::pair<TCheie, TValoare> TElem;

using namespace std;

class IteratorMDO;

typedef bool(*Relatie)(TCheie, TCheie);


class valori {
private:
	//capacitate initiala
	int cap = 10;
	//vector dinamic pentru valori
	TValoare* lista;
	//vectorul dinamic pentru legaturi
	int* urm;
	//referinta catre primul element al listei
	int prim;
	//referinta catre primul element din lista spatiului liber
	int primLiber;
public:
	//functii pentru alocarea/dealocarea unui spatiu liber
	//se returneaza pozitia unui spatiu liber in lista
	//date de intrare:-
	//date de iesire:-i-tip int
	//complexitate de timp:theta(1)
	int aloca();

	//dealoca spatiul de indice i
	//date de intrare:i-int
	//date de iesire:-
	//complexitate de timp:theta(1)
	void dealoca(int i);

	//functie privata care creeaza un nod in lista inlantuita
	//date de intrare:-e-tip TValoare
	//date de iesire:-i-tip int
	//complexitate de tipm:theta(1)
	int creeazaNod(TValoare e);

	//redimensionare vector dinamic
	//date de intrare:_
	//date de iesire:-
	//complexitate de timp:theta(n),n-capacitatea
	void redimensionare();

	//constructorul clasei
	//date de intrare:
	//date de iesire:-
	valori();

	//adauga valoare
	//date de intrare:e-TValoare
	//date de iesire:-
	//complexitate de timp:theta(1)-amortizata
	void adauga(TValoare e);

	//pozitia unei valori
	//date de intrare:-
	//date de iesire:-poz-tip int
	//complezitate de timp:-caz favorabil:-theta(1)-e e pe prima pozitie
	//					   -caz defavorabil:-theta(n)-e nu e in vector
	//					   -caz mediu:-theta(n)
	//					   -overall complexity:O(n)
	int pozitie(TValoare e);

	//stergerea unei valori din vector
	//date de intrare:poz-tip int
	//date de iesire:-
	//complezitate de timp:-caz favorabil:-theta(1)-stergem el de pe prima poz
	//					   -caz defavorabil:-theta(n)-stergem elementul de oe ultima pozitie
	//					   -caz mediu:-theta(n)
	//					   -overall complexity:O(n)
	void sterge(int poz);

	//vectorul e vid
	//date de ingtrare:-
	//date de iesire:-true-daca vectorul e vid
	//               -false-daca vectorul nu e vid
	//complexitate de timp:theta(1)
	bool vida();

	//dimensiunea vectorului
	//date de intrare:-
	//date de iesire:-contor-tip int
	//complexitate de timp:theta(n)
	int dim() const;
	friend class MDO;
	friend class IteratorMDO;
};

struct nod {
	TCheie key;
	valori valori;
};

class MDO {
	friend class IteratorMDO;
private:
	//relatie
	Relatie relatie;
	//capacitate initiala
	int cap = 10;
	//vector de noduri
	nod* elems;
	//vectorul dinamic pentru legaturi
	int* urm;
	//referinta catre primul element al listei
	int prim;
	//referinta catre primul element din lista spatiului liber
	int primLiber;

	//functii pentru alocarea/dealocarea unui spatiu liber
	//se returneaza pozitia unui spatiu liber in lista
	//date de intrare:-
	//date de iesire:-i-tip int
	//complexitate de timp:theta(1)
	int aloca();

	//dealoca spatiul de indice i
	//date de intrare:i-int
	//date de iesire:-
	//complexitate de timp:theta(1)
	void dealoca(int i);

	//functie privata care creeaza un nod in lista inlantuita
	//date de intrare:-e-tip TValoare
	//date de iesire:-i-tip int
	//complexitate de tipm:theta(1)-amortizata
	int creeazaNod();

	//redimensionare vector dinamic
	//date de intrare:_
	//date de iesire:-
	//complexitate de timp:theta(n),n-capacitatea
	void redimensionare();

	//cauta nod
	//date de intrare:-cheie-referinta la TCheie
	//               :-nodc-referinta la int
	//				 :-prec-referinta la int
	//date de iesire:-
	////complezitate de timp:-caz favorabil:-theta(1)-stergem el de pe prima poz
	//					   -caz defavorabil:-theta(n)-stergem elementul de oe ultima pozitie
	//					   -caz mediu:-theta(n)
	//					   -overall complexity:O(n)
	void cautaNod(const TCheie& cheie, int& nodc, int& prec) const;

	//adauga chie noua
	//date de intrare:-cheie-TCheie
	//               :-v-TValoare
	//				 :-prec-int
	//complexitate de timp:theta(1)
	void adaugaCheieNoua(TCheie c, TValoare v, int prec);

	//sterge cheie
	//date de intrare:-prec-int
	//date de iesire:-
	//complexitate de timp:-theta(1)
	void stergeCheie(int prec);

public:

	// constructorul implicit al MultiDictionarului Ordonat
	//date de intrare:-r-Relatie
	//date de iesire:-
	//complexitate de timp:theta(1)
	MDO(Relatie r);

	// adauga o pereche (cheie, valoare) in MDO
	//date de intrare:c-TCheie
	//               :v-TValoare
	//date de iesire:-
	//complexitate de timp:O(n)
	void adauga(TCheie c, TValoare v);

	//cauta o cheie si returneaza vectorul de valori asociate
	//date de intrare:c-TCheie
	//date de iesire:-val-vector
	//complexitate de timp:O(n*m),m-lungimea listei de valori
	vector<TValoare> cauta(TCheie c) const;

	//sterge o cheie si o valoare 
	//returneaza adevarat daca s-a gasit cheia si valoarea de sters
	//date de intrare:c-TCheie
	//               :v-TValoare
	//date de iesire:-true-daca stergerea s-a realizat cu succes
	//				:-false-in caz contrar
	//complexitate de timp:O(n)
	bool sterge(TCheie c, TValoare v);

	//returneaza numarul de perechi (cheie, valoare) din MDO 
	//const trebuie sa fie constante
	//date de intrare:-
	//date de iesire:-cont-int
	//complexitate de timp:O(n*m),m-multimea de valori
	int dim() const;

	//verifica daca MultiDictionarul Ordonat e vid 
	//date de intrare:-
	//date de iesire:-true-daca MDO-ul e vid
	//				:-false-in caz constar
	//complexitate de timp:O(n)
	bool vid() const;

	// se returneaza iterator pe MDO
	// iteratorul va returna perechile in ordine in raport cu relatia de ordine
	//date de intrare:-
	//date de iesire:-iterator
	//complexitate de timp:O(n)
	IteratorMDO iterator() const;

	// destructorul
	//date de intrare:-
	//date de iesire:-
	//complexitate de timp:theta(1)
	~MDO();

	// elimină o cheie împreună cu toate valorile sale 
	// returneaza un vector cu valorile care au fost anterior asociate acestei chei (și au fost eliminate)
	//date de intrare:cheie-tip TCheie
	//date de iesire:valori-tip vector
	//subalgoritm stergeValoriPentruCheie(MDO,cheie,valori)
	//		valori<-cauta(cheie)
	//		for val in valori executa
	//            sterge(cheie,val)
	//		sfPentru
	//sfSubalgoritm
	//complexitate de timp:O(n*m),m-lungimea listei de valori
	vector<TValoare> stergeValoriPentruCheie(TCheie cheie);
};
