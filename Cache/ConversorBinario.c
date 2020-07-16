#include "ConversorBinario.h"

void Conversor (char c[], unsigned long *dec)
{
    char bin[100];
    strcpy(bin, c);
   
    int i = 0;
    int s;
   
    s = strlen( bin );
    
    while( s-- ) {
        if( bin[s] == '0' || bin[s] == '1' ) {
            *dec = *dec + pow(2, i++) * (bin[s] - '0');
        }
    };
}
