#pragma once

#include "DO.h"

class Iterator {
	friend class DO;
private:
	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container
	/*contructor
* date de intrare:-d-DO
* date de iesire:-
* complexitate de timp:
*/
	Iterator(const DO& dictionar);

	//contine o referinta catre containerul pe care il itereaza
	const DO& dict;

	/* aici e reprezentarea specifica a iteratorului */

	//locatia curenta din tabela
	int curent;

	//deplasare iterator pe o pozitie care e ocupata (nu are memorat NIL_
/*functie de deplasare a curentului
* date de intrare:-
* date de iesire:-
* complexitate de timp:
* caz favorabil:-vectorul e plin:theta(1)
* caz defavorabil:-vectorul e gol:theta(m)
* caz mediu:theta(m)
* overall complexity:O(m)
*/
	void deplasare();

public:

	/*pozitioneaza curent pe prima pozitie
	* date de intrare:-
	* date de iesire:-
	* complexitate de timp:
	* caz favorabil:vectorul e plin si cheile sunt ordonate comform relatiei:theta(1)
	* caz defavorabil:vectorul e gol si/sau cheile sun ordonate invers relatiei:theta(m)
	* caz mediu:theta(m)
	* overall complexity:O(m)
	*/	void prim();

	/*pozitioneaza curent pe pozitia urmatoare
	* date de intrare:-
	* date de iesire:-
	* complexitate de timp:
	* caz favorabil:cheile sunt ordonate comform relatiei:theta(1)
	* caz defavorabil:cheile sun ordonate invers relatiei:theta(m)
	* caz mediu:theta(m)
	* overall complexity:O(m)
	*/
	void urmator();

	/*verificam daca iteratorul e valid
	* date de intrare:-
	* date de iesire:-true-daca e valid
	*				 -false:in caz contrare
	*/	bool valid() const;

	/*returneaza perechea de pe pozitia curenta
	* date de intrare:-
	* date de iesire:-perechea de pe pozitia curenta
	*/
	TElem element() const;
};

