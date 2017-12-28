#include <iostream>
#include <string>
#include <climits>
#include "chapterOne.h"

int main(){

	helloword();

	std::string exit;
	std::cout << "Do you want exit: (y/n)";
	getline(std::cin, exit);
	return 0;
}