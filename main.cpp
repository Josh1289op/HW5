#include "WinnerT.h"

int main(){

	int players[4] = { 1, 2, 3, 4 };

	WinnerT<int>* lol = new WinnerT<int>(players, (size_t)4, 'X');






	return 0; 
}