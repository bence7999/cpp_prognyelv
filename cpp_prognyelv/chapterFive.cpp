#include "chapterFive.h"

void Variables() {
	char* ch; // karakterre hivatkoz� mutat�
	char* ch2 = "ch";
	int arr[10]; // 10 eg�szb�l �ll� t�mb
	int arr2[] = { 0,1,2,3,4,5,6,7,8,9 };
	int& int_ref = *arr; // 10 eg�szb�l �ll� t�mb referenci�ja
	std::string* str_ref[10]; // karakterl�ncokb�l �ll� t�mbre hivatkoz� mutat�
	std::string str_lst[10] = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j" };
	std::string* str_ref2 = str_lst;
	char** ppc; // karakterre hivatkoz� mutat�ra hivatkoz� mutat�
	char** ppc2 = &ch;
	const int FOUR = 4; // konstans eg�sz
	const int* const_int; // konstans eg�szre hivatkoz� mutat�
	const int* c_int = &FOUR;
	int *const const_point = new int(4); // eg�szre hivatkoz� konstans mutat�
}
