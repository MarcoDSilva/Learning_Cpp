#include <stdio.h>
#include <stdlib.h>

int main(){

	//declarar apontador para inteiro
	//declarar o apontador para o começo da lista, visto que vamos manipular o endereço
	int *lista_valores = NULL; 
	int *inicio_lista  = NULL;
	int num_pos = 13;

     //reservar espaço na mem
    lista_valores = malloc(sizeof(int) * num_pos);
    inicio_lista = lista_valores; //endereço inicial passa para inicio_lista

     //preenche pos e aumenta o endereço para dar outro endereço
    *lista_valores = 20;
    lista_valores++;
    *lista_valores = 12;
    lista_valores++;
    *lista_valores = 37;
    lista_valores++;

    for(int i = 0; i < 10; i++) {
    	lista_valores = i;
    	lista_valores++;
	}

	int i = 0;
	//array plox
		while(i < 13)
		{
			printf("\nPos %d %d: ", i, inicio_lista[i]);
			i++;
		}

	printf("\n");
	return 0;

} 
