#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include "Coada.h"
#include "TestExtins.h"
#include "TestScurt.h"
using namespace std;
//TAD Coadă -reprezentare secvențială circulară folosind un vector dinamic de elemente

int main() {
	testAll();
	testAllExtins();
	_CrtDumpMemoryLeaks();
}
