#include "Calculo.h"

int CalculoEndereco (int NConjuntos, int indice, int Associatividade){
	
	int Endereco;
		
	Endereco = (indice % (NConjuntos-1/Associatividade))*Associatividade; 
	
 	return Endereco;

}
