#pragma once
#include "IteratorMatrice.h"

typedef int TElem;


#define NULL_TELEMENT 0

//nod
typedef struct {
	int linie;
	int coloana;
	TElem valoare;
} nod;

class IteratorMatrice;

class Matrice {
	friend class IteratorMatrice;
private:
	//capacitate initiala
	int cap = 10;
	//vector dinamic pentru valori
	nod* elem;
	//vectorul dinamic pentru subarborele stang
	int* stanga;
	//vectorul dinamic pentru subarborele drept
	int* dreapta;
	//referinta catre primul radacina arborelui
	int rad;
	//int curent;
	//referinta catre primul element din lista spatiului liber
	
	//numarul de linii
	int nrLin;

	//numarul de coloane
	int nrCol;

	//redimensionare vector dinamic
	//date de intrare:_
	//date de iesire:-
	//complexitate de timp:theta(n),n-capacitatea
	void redimensionare();

public:

	//constructor
	//se arunca exceptie daca nrLinii<=0 sau nrColoane<=0
	//date de intrare:-nrLinii-int
	//				  -nrColoane-int
	//date de iesire:-
	//complexitate de timp :caz favorabil = caz defavorabil = caz mediu = theta(n), n-capacitatea vectorilor
	Matrice(int nrLinii, int nrColoane);


	//destructor
	//date de intarare:-
	//date de iesire:-
	//complexitae de timp:caz favorabil = caz defavorabil = caz mediu = theta(1);
	~Matrice() {
		delete[] elem;
		delete[] stanga;
		delete[] dreapta;
	};


	//returnare element de pe o linie si o coloana
	//se arunca exceptie daca (i,j) nu e pozitie valida in Matrice
	//indicii se considera incepand de la 0
	//date de intare:-i-int
	//				 -j-int
	//date de iesire:-e-elementul de pe pozitia cautata , daca pozitia exista in arbore
	//				 -NULL_TELEMENT in caz contrar
	//Complexitate de timp:-caz favorabil-pozitia (i,j) se afla in radacina arborelui :theta(1)
	//					   -caz defavorabil-pozitia cautata(i, j) nu se afla in arbore:theta(h),h-inaltimea arborelui(log2n)
	//					   -caz mediu:theta(h),h-inaltimea arborelui(log2n)
	//overall complexity :O(h),h-inaltimea arborelui(log2n)
	TElem element(int i, int j) const;


	// returnare numar linii
	//date de intare:-
	//date de iesire:nrLin-int
	//Complexitate de timp:caz favorabil = caz defavorabil = caz mediu = theta(1)
	int nrLinii() const;

	// returnare numar coloane
	//date de intare:-
	//date de iesire:nrCol-int
	//Complexitate de timp:caz favorabil = caz defavorabil = caz mediu = theta(1)
	int nrColoane() const;


	// modificare element de pe o linie si o coloana si returnarea vechii valori
	// se arunca exceptie daca (i,j) nu e o pozitie valida in Matrice
	//date de intare:-i-int
	//				 -j-int
	//				 -e-TElem
	//date de iesire:-e-elementul de pe pozitia unde se face modificarea , daca pozitia exista in arbore
	//				 -NULL_TELEMENT in caz contrar
	//Complexitate de timp:-caz favorabil-pozitia (i,j) se afla in radacina arborelui :theta(1)
	//					   -caz defavorabil-pozitia cautata(i, j) nu se afla in arbore:theta(h),h-inaltimea arborelui(log2n)
	//					   -caz mediu:theta(h),h-inaltimea arborelui(log2n)
	//overall complexity :O(h) amortizata,h-inaltimea arborelui(log2n)
	TElem modifica(int i, int j, TElem);

	/*returneaza un iterator pe matrice
	* date de intrare:-coloana-int
	* date de iesire-iteratorul
	* Subalgoritm iterator(m,coloana,it)
	* pre{m-matrice
	*	  coloana-tip intreg}
	* post{it-IteratorMatrice}
	* @programul arunca exceptie daca coloana nu e valida
	*	iterator<-IteratorMatrice(m,coloana)
	* SfSubalgoritm
	*/
	IteratorMatrice iterator(int coloana);
};

