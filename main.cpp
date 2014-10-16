#include "WinnerT.h"

int main(){

	int players[4] = { 1, 2, 3, 4 };

	WinnerT<int>* lol = new WinnerT<int>(players, (size_t)4, 'X');



	lol->pretty_print(std::cout);
	std::cout << std::endl << std::endl << std::endl;
	lol->update_player(2, 1);
	lol->eliminate_player(2);
	std::cout << std::endl << std::endl << std::endl;
	lol->pretty_print(std::cout);
	return 0; 
}