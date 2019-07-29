#include <stdio.h>
#include <stdlib.h>

void mostra_idades(int tamanho, int maxima_idade, int *lista_idades){
	int pos = 0;
	// auxiliar criado para ser utilizado o apontador nas arrays
	int *auxiliar = lista_idades;
	printf("\n\n Lista de Idades: \n");
	
	while(pos < tamanho){
		if(*auxiliar < maxima_idade && *auxiliar > 0) 
		{
			printf("num: %d \n", *auxiliar);
		}
		pos++;
		auxiliar++;
	}
	printf("\n\n");
}

int main(){
	int nova_idade = 0;
	int qtd_introduzidos = 0;
	int *idades = NULL;

	do {
		printf ("Introduza a idade da pessoa (0 para finalizar): ");
		scanf ("%d", &nova_idade);
		getchar();
		
		qtd_introduzidos++;
    //alocar memoria para array
		idades = (int*) realloc (idades, qtd_introduzidos * sizeof(int));

		if (idades == NULL) {
			printf("\n\nErro, não foi possivel (re)alocar memória\n\n");
			return -1;
		}
		if(nova_idade > 0){
			idades[qtd_introduzidos-1] = nova_idade;
		}
	} while (nova_idade!=0);
		
	mostra_idades(qtd_introduzidos, 65, idades);	
	printf ("\n\n\n\n");
	
	free (idades);
    
    return 0;
}
