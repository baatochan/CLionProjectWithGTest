#include <iostream>
#include "src/Printer.hpp"

int main() {
	Printer printer;
	std::cout << printer.printHelloWorld() << std::endl;
	std::cout << printer.print420() << std::endl;
	return 0;
}
