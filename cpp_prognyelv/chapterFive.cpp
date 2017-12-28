#include "chapterFive.h"

void Variables() {
	char* ch; // karakterre hivatkozó mutató
	char* ch2 = "ch";
	int arr[10]; // 10 egészbõl álló tömb
	int arr2[] = { 0,1,2,3,4,5,6,7,8,9 };
	int& int_ref = *arr; // 10 egészbõl álló tömb referenciája
	std::string* str_ref[10]; // karakterláncokból álló tömbre hivatkozó mutató
	std::string str_lst[10] = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j" };
	std::string* str_ref2 = str_lst;
	char** ppc; // karakterre hivatkozó mutatóra hivatkozó mutató
	char** ppc2 = &ch;
	const int FOUR = 4; // konstans egész
	const int* const_int; // konstans egészre hivatkozó mutató
	const int* c_int = &FOUR;
	int *const const_point = new int(4); // egészre hivatkozó konstans mutató
}
