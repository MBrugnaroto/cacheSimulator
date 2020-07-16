#include "Indice.h"

void BitsIndice (char dados[], int indice, int tag, char copy[])
{

	int t = 0;
	int k = indice + tag;
	int i;
	
	for (i = 0; i < indice; i++){
		copy[i] = '\0';
		}
	
	for (i = tag-1; i < k-2; i++){
		copy[t] = dados[i];
		t++;
		}
	}

