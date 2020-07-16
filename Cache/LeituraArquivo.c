#include "LeituraArquivo.h"

int TamArq (char NomeArquivo[]) {
	
	FILE *arq;
	int cont = 0;
	char dado[50];
	
	if((arq = fopen(NomeArquivo, "r")) == NULL){
		printf("ERROR: Falha ao abrir o arquivo\n");
		exit(1);
		return 0;
	}
	
	while (!feof(arq)){
		fgets(dado, 50, arq);
		cont++;
		}
		
	fclose(arq);
	return cont;
	
	}
	
void Dados (char NomeArquivo[], int posicao, char dado []){
	
	FILE *arq;
	int cont = 0;

	if((arq = fopen(NomeArquivo, "r")) == NULL){
		printf("ERROR: Falha ao abrir o arquivo\n");
		exit(1);
	}
	
	while (!feof(arq)){
		fgets(dado, 50, arq);
		if (cont == posicao){
			break;
			}
		cont++;
		}
}

