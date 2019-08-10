#include "IOManager.h"
#include <iostream>

int main( int argc, char** argv ) {
	IOManager a("origen.pas");
	char b = a.getNext();
	while (b != NULL) {
		std::cout << b;
		b = a.getNext();
	}
	std::cin >> b;
	return 0;
}