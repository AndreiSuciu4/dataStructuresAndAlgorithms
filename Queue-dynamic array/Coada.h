#pragma once
#include <vector>
using namespace std;

typedef int TElem;

class Coada
{
private:

	//fata
	int fata;

	//spate

	int spate;

	//capacitate
	int cp ;

	//elemente
	TElem* e;

	//functia de redimensionare
	//complexitate θ(n),n-nr de elemente
	void redim();
public:
	//constructorul implicit
	//complexitatea de timp:θ(1)
	Coada();

	//adauga un element in coada
	//complexitatea de timp:O(1) amortizata
	void adauga(TElem e);

	//acceseaza elementul cel mai devreme introdus in coada 
	//arunca exceptie daca coada e vida
	//complexitatea de timp :θ(1)
	TElem element() const;

	//sterge elementul cel mai devreme introdus in coada si returneaza elementul sters (principiul FIFO)
	//arunca exceptie daca coada e vida
	//complexitatea de timp :θ(1)
	TElem sterge();

	//verifica daca coada e vida;
	//complexitatea de timp :θ(1)
	bool vida() const;


	// destructorul cozii
	//complexitatea de timp :θ(1)
	~Coada();
};

