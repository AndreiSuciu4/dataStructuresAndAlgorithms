#include "TestScurt.h"
#include <assert.h>
#include "Matrice.h"
#include "IteratorMatrice.h"
#include <exception>

using namespace std;

void testAll() { //apelam fiecare functie sa vedem daca exista
	Matrice m(4, 4);
	assert(m.nrLinii() == 4);
	assert(m.nrColoane() == 4);
	//adaug niste elemente
	m.modifica(1, 1, 5);
	assert(m.element(1, 1) == 5);
	m.modifica(1, 1, 6);
	assert(m.element(1, 2) == NULL_TELEMENT);

	for (int i = 0; i <= 10; i++)
		if (i % 2 == 0)
			m.modifica(i, 2,i+1);
	IteratorMatrice it = m.iterator(2);
	it.prim();
	for (int i = 0; i <= 10; i++)
		if (i % 2 == 0)
		{
			assert(it.elem() == i + 1);
			it.urmator();
		}
		else
		{
			assert(it.elem() == NULL_TELEMENT);
			it.urmator();
		}

	try {
		IteratorMatrice it1 = m.iterator(5);
		
	}
	catch (exception&) {
		assert(true); //ar trebui sa arunce exceptie
	}


}

