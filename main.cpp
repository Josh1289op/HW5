#include "WinnerT.h"
#include "LoserT.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(){
	int const size = 8;
	int players[size] = { 1, 2, 3, 4, 5, 6, 7, 8};
	WinnerT<int>* wt = new WinnerT<int>(players, (size_t)size, 'X');
	LoserT<int>* lt = new LoserT<int>(players, (size_t)size, 'X');


	std::cout << std::endl << std::endl;
	std::cout << std::endl << std::endl;
	wt->pretty_print(std::cout);
	std::cout << std::endl << std::endl;
	//lt->pretty_print(std::cout);

	int const size2 = 4;
	int players2[size2] = { 1, 2, 3, 4};
	WinnerT<int>* wt2 = new WinnerT<int>(players2, (size_t)size2, 'X');

	std::cout << std::endl << std::endl;
	std::cout << std::endl << std::endl;
	wt2->pretty_print(std::cout);
	std::cout << std::endl << std::endl;
	return 0; 
}