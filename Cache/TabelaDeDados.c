#include "TabelaDeDados.h"

void ImprimirDados (float Quantidade, float MissConflito, float MissCapacidade, float MissCompulsorio, float HitTotal)
{
	float MissTotal = MissConflito + MissCapacidade + MissCompulsorio;
	float MissRate = MissTotal/Quantidade;
	
	printf(" --Dados processados-- \n");
	printf("\nQuantidade:   %.0lf\n", Quantidade);
	printf("\n --------Hits--------- \n");
	printf("\nTotal:        %.0lf\n", HitTotal);
	printf("\n -------Misses--------\n");
	printf("\nTotal:        %.0lf\n", MissTotal);
	printf("Compulsório:  %.0lf\n", MissCompulsorio);
	printf("Conflito:     %.0lf\n", MissConflito);
	printf("Capacidade:   %.0lf\n", MissCapacidade);
	printf("MissRate:     %0.4lf\n", MissRate);
	
	
}
