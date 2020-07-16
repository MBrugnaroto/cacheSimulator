#include <stdio.h>
#include "LeituraInformacao.h"
#include "LeituraArquivo.h"
#include "Cache.h"
#include "ConversorBinario.h"
#include "CalculoBits.h"
#include "Indice.h"
#include "Tag.h"
#include "Calculo.h"
#include "TabelaDeDados.h"
#include "PalavrasBloco.h"

int main(	)
{
	//VARIAVEIS PARA INFORMAÇẼOS DE MISS E HIT//
	float MCompulsorio = 0;
	float MConflito = 0;
	float MCapacidade = 0;
	float Hit = 0;
	
	//INFORMAÇÕES INICIAIS DA CACHE RECEBIDOS PELO USUARIO//
	int NConjuntos = 0;
	int TBloco = 0;
	int Associatividade = 0;
	char Substituicao;

	parametros(&NConjuntos, &TBloco, &Associatividade, &Substituicao);

	//printf("%d %d %d %c\n", NConjuntos, TBloco, Associatividade, Substituicao);

	//CALCULO DOS BITS PARA OFFSET, INDICE E TAG//
	int tag = 0;
	int offset = 0;
	int indice = 0;
	unsigned QpalavrasB = NPalavrasBloco(TBloco); 
	indice = Bits (NConjuntos);
	offset = Bits (TBloco);

	tag = 32 - indice - offset;
	
	//printf("Indice: %d\n", indice);
	//printf("Tag: %d\n", tag);
	//printf("Offset: %d\n", offset);
	
	//CRIAÇÃO DA CACHE//
	Cache *Bloco;
	Bloco = malloc (sizeof(Cache));
	Criar(Bloco, NConjuntos);
	Inicializar(Bloco, NConjuntos);
	//Imprimir(Bloco, NConjuntos);

	//DADOS PARA INCERIR NA CACHE//
	char palavra[50];
	int Tarquivo;
	char BIndice[32];
	char BTag[32];
		unsigned long IndiceConvertido = 0;
		
	
	Tarquivo = TamArq("Teste.txt");
	
	for (int i = 0; i < Tarquivo-1; i++) {
		Dados("Teste.txt", i, palavra);
		//printf("\nDado[%d]: %s", i, palavra);
		IndiceConvertido = 0;
		
		//BITS DO INDICE PARA O DADO//
		BitsIndice(palavra, indice, tag, BIndice);
		//printf("%s\n", BIndice);

		//CONVERSAO PARA INTEIRO//
		Conversor(BIndice, &IndiceConvertido);
		//printf("%lu\n", IndiceConvertido);/
		
		//CALCULO DO ENDERAÇO DO DADO//
		int endereco = 0;
		endereco = CalculoEndereco(NConjuntos, IndiceConvertido, Associatividade);
		//printf("Endereco[%d]: %d\n", i, endereco);
		
		//BITS DA TAG PARA O DADO//
		BitsTag(palavra, tag, BTag);
		//printf("Tag[%d]: %s\n", i, BTag);
		
		//printf("Tag: %s || Indicie: %s\n", BTag, BIndice);
		
		//INSERIR DADO NA CACHE//
		Inserir(Bloco, BTag, endereco, &MCompulsorio, &MConflito, &MCapacidade, &Hit, QpalavrasB, IndiceConvertido, Associatividade, NConjuntos, Substituicao);
	}
	
	ImprimirDados(Tarquivo-1, MConflito, MCapacidade, MCompulsorio, Hit);
	//Imprimir(Bloco, NConjuntos);
	return 0;
}
