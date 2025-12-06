#include<stdio.h>
#include<stdlib.h>

typedef struct no
{
  int valor;
  struct no *esquerda, *direita;
} NoArv;

typedef struct Arv
{
  NoArv *raiz;
} Arv;

Arv *CriaArv();
void inserir_na_arvore(Arv *a, int chave);
NoArv *NovoNo(int chave);
NoArv *incerir_no(NoArv *raiz, int chave);
void imprimirArv(Arv *a);
void imprimir(NoArv *aux);
void copiarNos(NoArv *raiz, Arv *dest);
Arv *uniaoArvores(Arv *a1, Arv *a2);
int  existeValor(NoArv *raiz, int valor);
void copiarIntersec(NoArv *raiz1, Arv *dest, Arv *a2);
Arv *intersecArvores(Arv *a1, Arv *a2);
int nosSaoSimetricos(NoArv *r1, NoArv *r2);
int arvoresSaoSimetricas(Arv *a1, Arv *a2);
void compararSimetria(Arv *a1, Arv *a2);




Arv *CriaArv()
{
  Arv *a = (Arv *)malloc(sizeof(Arv));
  if (a == NULL)
  {
    return a;
  }
  a->raiz = NULL;
  return a;
}
void inserir_na_arvore(Arv *a, int chave)
{
  a->raiz = incerir_no(a->raiz, chave);
}

NoArv *NovoNo(int chave)
{
  NoArv *aux = (NoArv *)malloc(sizeof(NoArv));
  if (aux == NULL)
  {
    return NULL;
  }
  aux->valor = chave;
  aux->esquerda = NULL;
  aux->direita = NULL;
  return aux;
}
NoArv *incerir_no(NoArv *raiz, int chave)
{
  if (raiz == NULL)
  {
    return NovoNo(chave);
  }
  if (chave < raiz->valor && chave != raiz->valor)
  {
    raiz->esquerda = incerir_no(raiz->esquerda, chave);
  }
  else
  {
    if (chave > raiz->valor && chave != raiz->valor)
    {
      raiz->direita = incerir_no(raiz->direita, chave);
    }
  }
  return raiz;
}
void imprimirArv(Arv *a)
{
  imprimir(a->raiz);
}
void imprimir(NoArv *aux)
{
  if (aux != NULL)
  {
    printf("%d - ", aux->valor);
    imprimir(aux->esquerda);
    imprimir(aux->direita);
  }
}
void copiarNos(NoArv *raiz, Arv *dest) {
    if (raiz != NULL) {

        inserir_na_arvore(dest, raiz->valor);

        copiarNos(raiz->esquerda, dest);
        copiarNos(raiz->direita,  dest);
    }
}



Arv *uniaoArvores(Arv *a1, Arv *a2) {
    Arv *a3 = CriaArv();
    if (a3 == NULL) return NULL;

    if (a1 != NULL && a1->raiz != NULL)
        copiarNos(a1->raiz, a3);

    if (a2 != NULL && a2->raiz != NULL)
        copiarNos(a2->raiz, a3);

    return a3;
}

int existeValor(NoArv *raiz, int valor) {
    if (raiz == NULL) {
        return 0;
    }
    if (valor == raiz->valor) {
        return 1;
    }
    if (valor < raiz->valor) {
        return existeValor(raiz->esquerda, valor);
    } else {
        return existeValor(raiz->direita, valor);
    }
}


void copiarIntersec(NoArv *raiz1, Arv *dest, Arv *a2) {
    if (raiz1 == NULL) return;

    if (existeValor(a2->raiz, raiz1->valor)) {
        inserir_na_arvore(dest, raiz1->valor);
    }

    copiarIntersec(raiz1->esquerda, dest, a2);
    copiarIntersec(raiz1->direita,  dest, a2);
}


Arv *intersecArvores(Arv *a1, Arv *a2) {
    Arv *a3 = CriaArv();
    if (a3 == NULL) return NULL;

    if (a1 != NULL && a1->raiz != NULL && a2 != NULL && a2->raiz != NULL) {
        copiarIntersec(a1->raiz, a3, a2);
    }
    return a3;
}
int nosSaoSimetricos(NoArv *r1, NoArv *r2) {

    if (r1 == NULL && r2 == NULL) {
        return 1;
    }

    if (r1 == NULL || r2 == NULL) {
        return 0;
    }

    if (r1->valor != r2->valor) {
        return 0;
    }

    int simEsqDir = nosSaoSimetricos(r1->esquerda, r2->direita);
    int simDirEsq = nosSaoSimetricos(r1->direita,  r2->esquerda);

    return simEsqDir && simDirEsq;
}

int arvoresSaoSimetricas(Arv *a1, Arv *a2) {
    return nosSaoSimetricos(a1->raiz, a2->raiz);
}
void compararSimetria(Arv *a1, Arv *a2) {
    int r = arvoresSaoSimetricas(a1, a2);
    if (r == 1) {
        printf("As arvores sao simetricas\n");
    } else {
        printf("As arvores NAO sao simetricas\n");
    }
}


int main(){
  Arv *a1 = CriaArv();
  Arv *a2 = CriaArv();
  Arv *a3 = NULL;

  int op, num, num2;

  do{ 
    printf("\n0 - Sair");
    printf("\n1- Inserir");
    printf("\n2 - Imprimir");
    printf("\n3 - Criar A3 = uniao(A1, A2) e imprimir");
    printf("\n4 - A3 = intersec(A1, A2) e imprimir");
    printf("\n5 - Verificar se A1 e A2 sao simetricas");
    printf("\n");
    scanf("%d", &op);

    switch(op){
      case 0:
        printf("Saindo ...");
      break;
      case 1:
        printf("Insira um elemento na Arvore 1: ");
        scanf("%d", &num);
        inserir_na_arvore(a1, num);
        printf("Insira umelemnto na Arvore 2: ");
        scanf("%d", &num2);
        inserir_na_arvore(a2, num2);
      break;
      case 2:
            printf("Arvore 1: ");
            imprimirArv(a1);
            printf("\nArvore 2: ");
            imprimirArv(a2);
            printf("\n");
            break;
      break;
       case 3:
            a3 = uniaoArvores(a1, a2);
            printf("Arvore uniao (A3): ");
            imprimirArv(a3);
            printf("\n");
       break;
       case 4:
            a3 = intersecArvores(a1, a2);
            printf("Intersecao (A3): ");
            imprimirArv(a3);
            printf("\n");
        break;
         case 5:
             compararSimetria(a1, a2);
         break;
    }
  }while(op != 0);
}