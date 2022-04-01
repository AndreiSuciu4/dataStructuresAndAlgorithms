#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


#include <iostream>
#include "Matrice.h"
#include "TestExtins.h"
#include "TestScurt.h"
#include "TestNou.h"

using namespace std;


int main() {

		testAll();
		testAllExtins();
		testPropriu();
		_CrtDumpMemoryLeaks();
	cout << "End";
}
