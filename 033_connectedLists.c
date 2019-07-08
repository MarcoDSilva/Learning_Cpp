//listas ligadas, exercicios
//by ms
//08-07-2019

#include <stdio.h>
#include <stdlib.h>

//struct node
//contem um inteiro e um apontador para o proximo nodo
typedef struct node_st {
    int dados;
    struct node_st *proximo;
} *node;

//func para criar um node novo
//aloca espaco para um novo modo
//se o novo modo tiver alocado espaco, cria um inteiro e passa o valor
//passa o endereco do apontador para null

node cria_node(int valor) {
    node novo = (node) malloc(sizeof(node));

     if(novo != NULL){
         novo->dados = valor;
         novo->proximo = NULL;
     }
     return novo;
}

int main (){

    node head = NULL;
    node tail = NULL;

    // if null
    if(head == NULL)
    {
        head = cria_node(10);
        tail = head;
    } 
/*    else 
    {
        //--------------HEAD INSERTION
        if()
        {
            //head insertion
        } 
        else 
        {
            //-----------TAIL INSERTION
            if(){
                //tail insertion
            }
            //-----------BODY INSERTION
            else
            {
                //body insertion   
            }

        }
*/
   
return 0;
}
