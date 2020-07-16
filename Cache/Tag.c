#include "Tag.h"

void BitsTag (char dados[], int tag, char copy[])
{
	int i;
	for (i = 0; i < tag; i++){
		copy[i] = '\0';
		}
	for (i = 0; i < tag-1; i++){
		copy[i] = dados[i];
		}
	copy[i+1] = '\0';
	}


