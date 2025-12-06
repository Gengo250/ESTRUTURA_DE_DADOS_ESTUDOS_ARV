#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

/* FUNÇÕES DE MANIPULAÇÃO DE PILHA
   Pilha* CriaPilha (void)          -> cria a pilha
   No*    ins_ini (No* t, int a)    -> auxiliar da inserção
   void   push (Pilha* p, int v)    -> inserção (empilha)
   No*    ret_ini (No* l)           -> auxiliar da remoção
   int    pop (Pilha* p)            -> remove retornando o valor removido
   Pilha* liberaPilha (Pilha* p)    -> libera a pilha
   void   imprime (Pilha* p)        -> imprime a pilha
   int    vaziaPilha(Pilha *p)      -> verifica se a pilha está vazia, retorna 1
*/

typedef struct no {
    int info;
    struct no *prox;
} No;

typedef struct pilha {
    No *Topo;
} Pilha;

/* Protótipos */
Pilha* CriaPilha(void);
No*    ins_ini(No* t, int a);
void   push(Pilha* p, int v);
No*    ret_ini(No* aux);
int    pop(Pilha *p);
Pilha* liberaPilha(Pilha* p);
void   imprime(Pilha* p);
int    vaziaPilha(Pilha *p);
int contaElemnetos(Pilha *p);
void inverte(Pilha *p);
void removeElemento(Pilha *p, int elem);
int comapara(Pilha *p1, Pilha *p2);
Pilha* Digitos(int num);
void imprimeNumero(Pilha *p);




/* Implementações exatamente como você enviou */

Pilha* CriaPilha(void)
{
    Pilha *p;
    p = (Pilha*) malloc(sizeof(Pilha));
    p->Topo = NULL;
    return p;
}

No* ins_ini(No* t, int a)
{
    No* aux = (No*) malloc(sizeof(No));
    aux->info = a;
    aux->prox = t;
    return aux;
}

void push(Pilha* p, int v)
{
    p->Topo = ins_ini(p->Topo, v);
}

No* ret_ini(No* aux)
{
    No* p = aux->prox;
    free(aux);
    return p;
}

int pop(Pilha *p)
{
    int v;

    if (vaziaPilha(p))
    {
        printf("\n\n\t==> Pilha VAZIA, IMPOSSÍVEL CONTINUAR.\b\n");
        exit(1); /* aborta programa */
    }

    v = p->Topo->info;
    p->Topo = ret_ini(p->Topo);
    return v;
}

int vaziaPilha(Pilha *p) {
    return (p->Topo == NULL);
}

void imprime(Pilha *p) {
    No *aux = p->Topo;

    printf("Topo -> ");
    while (aux != NULL) {
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}

// se quiser liberar tudo ao sair:
Pilha* liberaPilha(Pilha* p) {
    No *aux = p->Topo;
    while (aux != NULL) {
        No *tmp = aux->prox;
        free(aux);
        aux = tmp;
    }
    free(p);
    return NULL;
}

int contaElemnetos(Pilha *p){
    if(p == NULL){
        return 0;
    }
    int cont = 0;
    No *aux = p->Topo;

    while(aux != NULL){
        cont++;
        aux = aux->prox;
    }

    return cont;
}

void inverte(Pilha *p) {
    if (p == NULL || p->Topo == NULL){
        printf("Pilha vazia");
    }

    Pilha *aux = CriaPilha();

    while (!vaziaPilha(p)) {
        int v = pop(p);
        push(aux, v);
    }

    while (!vaziaPilha(aux)) {
        int v = pop(aux);
        push(p, v);
    }

    liberaPilha(aux);
}
void removeElemento(Pilha *p, int elem) {
    if (p != NULL && !vaziaPilha(p)) {
        Pilha *aux = CriaPilha();
        int x;
        int encontrado = 0;

        // tira da pilha original
        while (!vaziaPilha(p)) {
            x = pop(p);
            if (!encontrado && x == elem) {
                encontrado = 1;   // achou: descarta esse
            } else {
                push(aux, x);     // guarda os outros
            }
        }

        // devolve pra pilha original
        while (!vaziaPilha(aux)) {
            x = pop(aux);
            push(p, x);
        }

        free(aux); // pilha auxiliar já está vazia
    }
}

int comapara(Pilha *p1, Pilha *p2) {
    int qtd1 = contaElemnetos(p1);
    int qtd2 = contaElemnetos(p2);

    if (qtd1 == qtd2)
        return 0;   // mesma quantidade
    else if (qtd1 > qtd2)
        return 1;   // pilha 1 tem mais
    else
        return 2;   // pilha 2 tem mais
}
Pilha* Digitos(int num) {
    Pilha *p = CriaPilha();

    if (num < 0) {
        num = -num;   
    }

    if (num == 0) {
        push(p, 0);
    } else {
        while (num > 0) {
            int dig = num % 10;   /* último dígito */
            push(p, dig);         /* empilha o dígito */
            num = num / 10;       /* “anda” para o próximo dígito */
        }
    }

    return p;
}

void imprimeNumeroRec(No *n) {
    if (n != NULL) {
        imprimeNumeroRec(n->prox);  /* vai até o final */
        printf("%d", n->info);      /* imprime na volta */
    }
}

void imprimeNumero(Pilha *p) {
    if (p != NULL && p->Topo != NULL) {
        imprimeNumeroRec(p->Topo);
    } else {
        printf("(pilha vazia)");
    }
}



#endif /* PILHA_H_INCLUDED */
