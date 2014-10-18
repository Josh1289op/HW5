#include "WinnerT.h"
#include "KQueue.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(){
	int const size = 6;
	int players[size] = { 1, 2, 10000, 4, 5, 6 };
	WinnerT<int>* lol = new WinnerT<int>(players, (size_t)size, 'X');


	return 0; 
}