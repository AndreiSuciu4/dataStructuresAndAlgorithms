#include "IteratorMDO.h"
#include "MDO.h"

IteratorMDO::IteratorMDO(const MDO& d) : dict(d) {
	curent = dict.prim;
	curentLista = dict.elems->valori.prim;
}

void IteratorMDO::prim() {
	curent = dict.prim;
	curentLista = dict.elems[curent].valori.prim;
}

void IteratorMDO::urmator() {
	if (dict.elems[curent].valori.urm[curentLista] != NULL_TELEMENT)
		curentLista = dict.elems[curent].valori.urm[curentLista];
	else
	{
		curent = dict.urm[curent];
		curentLista = dict.elems[curent].valori.prim;
	}
}

bool IteratorMDO::valid() const {
	if (curent == NULL_TELEMENT)
		return false;
	else
		return true;
}

TElem IteratorMDO::element() const {
	if (curent == NULL_TELEMENT)
		throw std::exception("iterator invalid");
	return pair <TCheie, TValoare>(dict.elems[curent].key, dict.elems[curent].valori.lista[curentLista]);
}

