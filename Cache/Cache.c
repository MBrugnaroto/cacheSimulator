#include "Cache.h"
#include "ConversorBinario.h"
#include "Random.h"

void Imprimir (Cache *Bloco, int NConjuntos) {

	for (int i = 0; i < NConjuntos; i++) {
		printf("[%d] - Tag: %s || Indicie: %lu\n", i, Bloco[i].Dado, Bloco[i].indice);
		}

	}

void Inicializar (Cache *Bloco, int NConjuntos) {

	for (int i = 0; i < NConjuntos; i++) {
		strcpy(Bloco[i].Dado, "-1");
		Bloco[i].indice = -1;
		Bloco[i].first = -1;
		}

	}

void Criar (Cache *Bloco, int NConjuntos){

		if ((Bloco = malloc (NConjuntos*sizeof(Cache))) == NULL){
			printf("ERRO: Erro na alocação dos Blocos");
			exit(1);
	}
}
void Inserir (Cache *Bloco, char tag[], int posicao, float *MCompulsorio, float *MConflito, float *MCapacidade, float *Hit, unsigned QpalavrasB, unsigned long indice, int Associatividade, int NConjuntos, char substituicao){

		int flag = 0;
		int flag2 = QpalavrasB;
		int flag4 = 0;

		unsigned longflag3 = 0;

		//printf("Processado: Tag: %s || Indicie: %lu\n", tag, indice);
		//printf("Na cache:   Tag: %s || Indicie: %lu\n", Bloco[posicao].Dado, Bloco[posicao].indice);

		if (Associatividade == 1){
			if (flag2 > 1) {
				if (strcmp(Bloco[posicao].Dado, "-1")){
					if ((((indice-Bloco[posicao].indice) < QpalavrasB && (indice-Bloco[posicao].indice) > longflag3)) || (((indice-Bloco[posicao].indice) > -QpalavrasB && indice-Bloco[posicao].indice < longflag3))){
						*Hit = *Hit+1;
					}
					else {
						if((indice-Bloco[posicao].indice) == longflag3 && !(strcmp(Bloco[posicao].Dado, tag))){
							*Hit = *Hit+1;
							}
						else {
							for (int i = 0; i < NConjuntos; i++){
								if (!(strcmp(Bloco[i].Dado, "-1"))){
										flag = 1;
										break;
									}
								}
								if (flag == 1) {
									flag = 0;
									*MConflito = *MConflito+1;}
									//printf("CONFLITO\n");
								else {
									flag = 0;
									*MCapacidade = *MCapacidade+1;
									}
							}
						}
				}
				else
					{ *MCompulsorio = *MCompulsorio+1; }
			}
			else
				if (!(strcmp(Bloco[posicao].Dado, "-1")) && flag2 <= 1){
					*MCompulsorio = *MCompulsorio+1;
					//printf("COMPULSORIO\n");
					}
					else {
							if (!(strcmp(Bloco[posicao].Dado, tag)) && (indice == Bloco[posicao].indice)){
								*Hit = *Hit+1;
								//printf("HIT\n");
							}
							else {
									for (int i = 0; i < NConjuntos; i++){
										if (!(strcmp(Bloco[i].Dado, "-1"))){
											flag = 1;
											break;
										}
									}
									if ((strcmp(Bloco[posicao].Dado, "-1"))){
										if (flag == 1 && (indice == Bloco[posicao].indice)) {
											*MConflito = *MConflito+1;}
											//printf("CONFLITO\n");
										else
											*MCapacidade = *MCapacidade+1;
											//printf("CAPACIDADE\n");
								}
							}
						}

			strcpy(Bloco[posicao].Dado, tag);
			Bloco[posicao].indice = indice;
		}
		else {
			int inicio;
			int fim = 0;
			int cont = 0;

			for (int l = 0; l < NConjuntos; l++) {
				if (cont == 0){
					inicio = l;
				}
				cont++;
				if (cont == Associatividade) {
					fim = l;
					cont = 0;
				}
				if (fim != 0 && (posicao >= inicio && posicao <= fim)) {
					for (int k = inicio; k <= fim; k++){
						if (strcmp(Bloco[k].Dado, "-1")){
							if ((((indice-Bloco[k].indice) < QpalavrasB && (indice-Bloco[k].indice) > longflag3)) || (((indice-Bloco[k].indice) > -QpalavrasB && indice-Bloco[k].indice < longflag3))){
								*Hit = *Hit+1;
								flag4 = 1;
								break;
							}
							else {
								if((indice-Bloco[k].indice) == longflag3 && !(strcmp(Bloco[k].Dado, tag))){
									*Hit = *Hit+1;
									flag4 = 1;
									break;
								}
							}
						}
					}
					if (flag4 == 0) {
						for (int i = 0; i < NConjuntos; i++){
							if (!(strcmp(Bloco[i].Dado, "-1"))){
								flag = 1;
								break;
							}
						}
						if (flag == 1) {
							flag = 0;
							int flag5 = 0;
							int ocupado = 0;

							for (int z = inicio; z <= fim; z++) {
								if (Bloco[z].first == 1){
									ocupado = 1;
								}
							}
							for (int z = inicio; z <= fim; z++) {
								if (!(strcmp(Bloco[z].Dado, "-1"))){
									strcpy(Bloco[z].Dado, tag);
									Bloco[z].indice = indice;

									if (ocupado != 1) {
										Bloco[z].first = 1;
									}

									*MCompulsorio = *MCompulsorio+1;
									ocupado = 0;
									flag5 = 1;
									flag4 = 1;
									break;
								}
							}

							if (flag5 == 0){
								//SUBISTUTUIÇÃO NO BLOCO CHEIO
								if (substituicao == 'R'){
									int rad = Randomico(inicio, Associatividade);
									strcpy(Bloco[rad].Dado, tag);
									Bloco[rad].indice = indice;
									*MConflito = *MConflito+1;
									flag4 = 1;
									break;
									}

								else if (substituicao == 'F'){
									for (int m = inicio; m < fim; m++){
										if (Bloco[m].first == 1){
											strcpy(Bloco[m].Dado, tag);
											Bloco[m].indice = indice;
											break;
											}
										}
									*MConflito = *MConflito+1;
									flag4 = 1;
									break;
									}

							}
						}
						else if (flag == 0) {
								//SUBISTUTUIÇÃO SE A CACHE ESTIVER CHEIA
								int rad = Randomico(inicio, Associatividade);
									strcpy(Bloco[rad].Dado, tag);
									Bloco[rad].indice = indice;
									*MCapacidade = *MCapacidade+1;
									flag4 = 1;
									break;
							}
					}

				inicio = 0;
				fim = 0;
				}

				else
					if (fim != 0) {
						fim = 0;
						inicio = 0;
						}
				}
		}
	}
