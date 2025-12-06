#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main()
{
    Pilha *p1 = CriaPilha();
    Pilha *p2 = CriaPilha();
    int op, valor, r, qual;

    do {
        printf("\n===== MENU PILHAS =====\n");
        printf("1  - Inserir na Pilha 1 (push)\n");
        printf("2  - Inserir na Pilha 2 (push)\n");
        printf("3  - Remover da Pilha 1 (pop)\n");
        printf("4  - Remover da Pilha 2 (pop)\n");
        printf("5  - Imprimir Pilha 1\n");
        printf("6  - Imprimir Pilha 2\n");
        printf("7  - Contar elementos da Pilha 1\n");
        printf("8  - Contar elementos da Pilha 2\n");
        printf("9  - Comparar Pilha 1 x Pilha 2\n");
        printf("10 - Criar pilha de dígitos (Digitos)\n");
        printf("11 - Imprimir número armazenado na pilha de dígitos\n");
        printf("0  - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
        case 1:
            printf("Valor para inserir na Pilha 1: ");
            scanf("%d", &valor);
            push(p1, valor);
            break;

        case 2:
            printf("Valor para inserir na Pilha 2: ");
            scanf("%d", &valor);
            push(p2, valor);
            break;

        case 3:
            if (vaziaPilha(p1))
                printf("Pilha 1 vazia.\n");
            else
                printf("Removido da Pilha 1: %d\n", pop(p1));
            break;

        case 4:
            if (vaziaPilha(p2))
                printf("Pilha 2 vazia.\n");
            else
                printf("Removido da Pilha 2: %d\n", pop(p2));
            break;

        case 5:
            printf("Pilha 1: ");
            if (vaziaPilha(p1)) printf("vazia\n");
            else imprime(p1);
            break;

        case 6:
            printf("Pilha 2: ");
            if (vaziaPilha(p2)) printf("vazia\n");
            else imprime(p2);
            break;

        case 7:
            printf("Pilha 1 tem %d elemento(s).\n", contaElemnetos(p1));
            break;

        case 8:
            printf("Pilha 2 tem %d elemento(s).\n", contaElemnetos(p2));
            break;

        case 9:
            r = comapara(p1, p2);
            if (r == 0)
                printf("As duas pilhas têm a MESMA quantidade de elementos.\n");
            else if (r == 1)
                printf("A Pilha 1 tem MAIS elementos.\n");
            else
                printf("A Pilha 2 tem MAIS elementos.\n");
            break;

        // 5) Ler número inteiro e guardar dígitos numa pilha
        case 10:
            printf("Usar qual pilha (1 ou 2)? ");
            scanf("%d", &qual);

            printf("Digite um numero inteiro: ");
            scanf("%d", &valor);

            if (qual == 1) {
                p1 = liberaPilha(p1);   // limpa pilha antiga
                p1 = Digitos(valor);    // cria pilha de dígitos
                printf("Pilha 1 criada com os digitos de %d.\n", valor);
            } else if (qual == 2) {
                p2 = liberaPilha(p2);
                p2 = Digitos(valor);
                printf("Pilha 2 criada com os digitos de %d.\n", valor);
            } else {
                printf("Pilha invalida.\n");
            }
            break;

        // 6) Imprimir número inteiro armazenado nos dígitos da pilha
        case 11:
            printf("Usar qual pilha (1 ou 2)? ");
            scanf("%d", &qual);

            if (qual == 1) {
                if (p1 == NULL || vaziaPilha(p1)) {
                    printf("Pilha 1 vazia.\n");
                } else {
                    printf("Numero formado pelos digitos da Pilha 1: ");
                    imprimeNumero(p1);
                    printf("\n");
                }
            } else if (qual == 2) {
                if (p2 == NULL || vaziaPilha(p2)) {
                    printf("Pilha 2 vazia.\n");
                } else {
                    printf("Numero formado pelos digitos da Pilha 2: ");
                    imprimeNumero(p2);
                    printf("\n");
                }
            } else {
                printf("Pilha invalida.\n");
            }
            break;

        case 0:
            printf("Saindo...\n");
            break;

        default:
            printf("Opcao invalida!\n");
        }

    } while (op != 0);

    p1 = liberaPilha(p1);
    p2 = liberaPilha(p2);

    return 0;
}
