#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cache {
	char Dado[32];
	unsigned long indice;
	int first;
	
}Cache;

void Imprimir (Cache *Bloco, int NConjuntos);

void Inicializar (Cache *Bloco, int NConjuntos) ;

void Criar (Cache *Bloco, int NConjuntos);

void Inserir (Cache *Bloco, char tag[], int posicao, float *MCompulsorio, float *MConflito, float *MCapacidade, float *Hit, unsigned QpalavrasB, unsigned long indice, int Associatividade, int NConjuntos, char substituicao);
