#include <assert.h>
#include <iostream>
#include "DO.h"
#include "Iterator.h"

#include <exception>
using namespace std;

bool relatie1(TCheie cheie1, TCheie cheie2) {
    if (cheie1 <= cheie2) {
        return true;
    }
    else {
        return false;
    }
}

TValoare Transformator1(TCheie cheie, TValoare valoare) {
    return 2 * valoare;
}

TValoare Transformator2(TCheie cheie, TValoare valoare) {
    return cheie * valoare;
}

void testAll() {
    DO dictOrd = DO(relatie1);
    assert(dictOrd.dim() == 0);
    assert(dictOrd.vid());
    dictOrd.adauga(1, 2);
    assert(dictOrd.dim() == 1);
    assert(!dictOrd.vid());
    assert(dictOrd.cauta(1) != NULL_TVALOARE);
    TValoare v = dictOrd.adauga(1, 3);
    assert(v == 2);
    assert(dictOrd.cauta(1) == 3);
    Iterator it = dictOrd.iterator();
    it.prim();
    while (it.valid()) {
        TElem e = it.element();
        assert(e.second != NULL_TVALOARE);
        it.urmator();
    }
    assert(dictOrd.sterge(1) == 3);
    assert(dictOrd.vid());

    //teste iteratia noua 

    for (int i = 10; i < 20; i++)
        dictOrd.adauga(i, 5*i);
    dictOrd.înlocuieșteToate(Transformator1);
    for (int i = 10; i < 20; i++)
        assert(dictOrd.cauta(i) == 10 * i);

    dictOrd.înlocuieșteToate(Transformator2);
    for (int i = 10; i < 20; i++)
        assert(dictOrd.cauta(i) == 10 * i * i);
}