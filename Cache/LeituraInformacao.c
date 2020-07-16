#include "LeituraInformacao.h"

void parametros(int *NConjuntos, int *TBloco, int *Associatividade, char *Substituicao)
{
		char dados[50];
		int numero = 0;
		char dados2[50] = "default";
		
		scanf(" %[^\n]", dados);
		
		int t = strlen(dados);
		
		if (!(strcmp(dados,dados2))){
				*NConjuntos = 32;
				*TBloco = 32;
				*Associatividade = 1;
				}
		else {
		for (int i = 0; i < t; i++){
			if (numero == 1 && (dados[i] > 47 && dados[i] < 58)){
				if (*NConjuntos == 0){
					*NConjuntos = dados[i] - 48;}
				else
					*NConjuntos = *NConjuntos*10 + (dados[i] - 48);
				}
			
			if (numero == 3 && (dados[i] > 47 && dados[i] < 58)){
				if (*TBloco == 0){
					*TBloco = dados[i] - 48;}
				else
					*TBloco = *TBloco*10 + (dados[i] - 48);
				}
			
			if (numero == 5 && (dados[i] > 47 && dados[i] < 58)){
				if (*Associatividade == 0){
					*Associatividade = dados[i] - 48;}
				else
					*Associatividade = *Associatividade*10 + (dados[i] - 48);
				}
			
			if (dados[i] == 'R' || dados[i] == 'F'){
					*Substituicao = dados[i];
				}
			
			if ('<' == dados[i]){
				if (numero == 0){
					numero = 1;}
				
				else if (numero == 2){
					numero = 3;}
				
				else if (numero == 4){
					numero = 5;}
				}
			
			if ('>' == dados[i]){
				if (numero == 1){
					numero = 2;}
				
				else if (numero == 3){
					numero = 4;
					}
					
				else if (numero == 5){
					numero = 6;
					}
				}
			}
		}
}
