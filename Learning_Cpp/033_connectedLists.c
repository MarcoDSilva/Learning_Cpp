//listas ligadas, exercicios
//by ms
//08-07-2019 - 10-07-2019

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
    node aux = NULL;

    node novoNode = cria_node(10);
    
    // if null, cria um node
    if(head == NULL)
    {
        head = novoNode;
        tail = head;
    } 
    else 
    {
        //--------------HEAD INSERTION
        if(novoNode->dados <= head->dados)
        {
            //head insertion
            novoNode->proximo = head;
            head = novoNode;
        } 
        else 
        {
            //-----------TAIL INSERTION
            if(novoNode->dados > tail->dados){
                //tail insertion
                tail->proximo = novoNode;
                tail = novoNode;
            }
            //-----------BODY INSERTION
            else
            {
                //insert in the body
                for(aux = head; aux->proximo->dados < novoNode->dados; aux = aux->proximo){}
                novoNode->proximo = aux->proximo;
                aux->proximo = novoNode;
                }
        }
   
return 0;
    }
}
