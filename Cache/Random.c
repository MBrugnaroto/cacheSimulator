#include "Random.h"

int Randomico (int inicio, int Associatividade) {
	
	srand(time(NULL));
	int result = inicio + rand()%Associatividade;
	
	return result;
	}


