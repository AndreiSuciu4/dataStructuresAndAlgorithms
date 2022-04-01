#include "Iterator.h"
#include "DO.h"
#include <iostream>

using namespace std;

/*contructor
* date de intrare:-d-DO
* date de iesire:-
* complexitate de timp:
*/
Iterator::Iterator(const DO& d) : dict(d) {
	curent = 0;
	deplasare();
}

/*functie de deplasare a curentului
* date de intrare:-
* date de iesire:-
* complexitate de timp:
* caz favorabil:-vectorul e plin:theta(1)
* caz defavorabil:-vectorul e gol:theta(m)
* caz mediu:theta(m)
* overall complexity:O(m)
*/
void Iterator::deplasare()
{

	while ((curent < dict.m) && dict.e[curent].first == NULL_TVALOARE)
		curent++;
}

/*pozitioneaza curent pe prima pozitie 
* date de intrare:-
* date de iesire:-
* complexitate de timp:
* caz favorabil:vectorul e plin si cheile sunt ordonate comform relatiei:theta(1)
* caz defavorabil:vectorul e gol si/sau cheile sun ordonate invers relatiei:theta(m)
* caz mediu:theta(m)
* overall complexity:O(m)
*/
void Iterator::prim() {
	int i, j=0;
	TElem aux = dict.e[0];
	for (i = 0; i < dict.m; i++)
		if (dict.e[i].first != NULL_TVALOARE)
		{
			aux = dict.e[i];
			break;
		}
	for (i = 0; i < dict.m; i++)
		if (dict.rel(dict.e[i].first, aux.first) && dict.e[i].first!=NULL_TVALOARE)
		{
			aux = dict.e[i];
				j = i;
		}
	curent = j;
	deplasare();
}

/*pozitioneaza curent pe pozitia urmatoare
* date de intrare:-
* date de iesire:-
* complexitate de timp:
* caz favorabil:cheile sunt ordonate comform relatiei:theta(1)
* caz defavorabil:cheile sun ordonate invers relatiei:theta(m)
* caz mediu:theta(m)
* overall complexity:O(m)
*/
void Iterator::urmator() {
	int i, j;
	TElem aux = dict.e[curent];
	for (i = 0; i < dict.m; i++)
		if (dict.rel(dict.e[i].first, aux.first))
		{
			aux = dict.e[i];
			j = i;
		}
	curent = i;
	deplasare();
}

/*verificam daca iteratorul e valid
* date de intrare:-
* date de iesire:-true-daca e valid
*				 -false:in caz contrare
*/
bool Iterator::valid() const {
	if (curent < dict.m)
		return true;
	return false;
}

/*returneaza perechea de pe pozitia curenta
* date de intrare:-
* date de iesire:-perechea de pe pozitia curenta
*/
TElem Iterator::element() const {
	if(this->valid())
		return pair <TCheie, TValoare>(dict.e[curent].first, dict.e[curent].second);
}
