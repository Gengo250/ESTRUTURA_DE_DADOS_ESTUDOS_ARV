#include <stdio.h>
#include <stdlib.h>

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
int verifica(Arv *a);
void imprimirArv(Arv *a);
void imprimir(NoArv *aux);
void somaArv(Arv *a);
int somaNos(NoArv *raiz);
void folhasArv(Arv *a);
int folhas(NoArv *raiz);
void numerosMaiores(Arv *a, int chave);
int numeroDeNosMaiores(NoArv *raiz, int chave);
NoArv *busca(Arv *a, int chave);
NoArv *buscaRec(NoArv *raiz, int chave);
void profundidadeArv(Arv *a);
int profundidadeNos(NoArv *raiz);
void nivelDoNo(Arv *a, int chave);
int nivel_No(NoArv *raiz, int chave);
int nivel_Arv(NoArv *raiz);
void nivelArv(Arv *a);
void imprimeAteNivelArv(Arv *a, int nivelMax);
void imprimeAteNivel(NoArv *raiz, int nivelAtual, int nivelMax);
void numeros_de_nos_nivel(Arv *a, int nivelMax);
int numeros_de_nos_apos_nivel(NoArv *raiz, int nivelAtual, int nivelMax);
void NosMaiores(Arv *a, int chave);
int Nos_Maiores_que(NoArv *raiz, int chave);
void removeFolhasArv(Arv *a);
NoArv *removeFolhas(NoArv *raiz);
void numero_de_Nos_esquerda_arv(Arv *a, int chave);
int numeros_de_Nos_esq(NoArv *raiz, int chave);
int contaNosSubarvore(NoArv *raiz);
void imprimePai(Arv *a, int chave);
NoArv* buscaPai(Arv *a, int chave);
NoArv* buscaPaiNo(NoArv *raiz, int chave, NoArv *paiAtual);
void menorElementoArv(Arv *a);
int menorElemento(NoArv *raiz);
void remove_menor_elemnto_arv(Arv *a);
NoArv* removerMenorElemento(NoArv *raiz);
void alturaArvore(Arv *a);
int altura(NoArv *raiz);
int descendentes(Arv *a, int chave);
int r_descendentes(NoArv *pai, int chave);
int contaSubarvore(NoArv *raiz);
int contaAncestraisNo(NoArv *raiz, int chave);
int contaAncestrais(Arv *a, int chave);
void removerArvore(Arv *a);
void removerArvoreNo(NoArv *raiz);
void arvoreEstrBinaria(Arv *a);
int EstritamenteBinaria(NoArv *raiz);
void soma_pares_Arv(Arv *a);
int soma_pares(NoArv *raiz);






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

int verifica(Arv *a)
{
  if (a->raiz == NULL)
  {
    return 0;
  }
  else
  {
    return 1;
  }
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
void somaArv(Arv *a)
{
  int soma = somaNos(a->raiz);
  printf("Soma dos Nos: %d", soma);
}
int somaNos(NoArv *raiz)
{
  if (raiz == NULL)
  {
    return 0;
  }
  return raiz->valor + somaNos(raiz->esquerda) + somaNos(raiz->direita);
}
void folhasArv(Arv *a)
{
  int f = folhas(a->raiz);
  printf("Numero de folhas: %d", f);
}
int folhas(NoArv *raiz)
{
  if (raiz == NULL)
  {
    return 0;
  }
  if (raiz->esquerda == NULL && raiz->direita == NULL)
  {
    return 1;
  }
  return folhas(raiz->esquerda) + folhas(raiz->direita);
}

void numerosMaiores(Arv *a, int chave)
{
  int n = numeroDeNosMaiores(a->raiz, chave);
  printf("Numero de Nos maiores que %d: %d ", chave, n);
}
int numeroDeNosMaiores(NoArv *raiz, int chave)
{
  if (raiz == NULL)
  {
    return 0;
  }
  int conta = 0;
  if (chave < raiz->valor)
  {
    conta = 1;
  }

  return conta + numeroDeNosMaiores(raiz->esquerda, chave) + numeroDeNosMaiores(raiz->direita, chave);
}

NoArv *busca(Arv *a, int chave)
{
  return buscaRec(a->raiz, chave);
}

NoArv *buscaRec(NoArv *raiz, int chave)
{
  if (raiz == NULL)
  {
    return NULL;
  }

  if (chave == raiz->valor)
  {
    return raiz;
  }
  else if (chave < raiz->valor)
  {
    return buscaRec(raiz->esquerda, chave);
  }
  else
  {
    return buscaRec(raiz->direita, chave);
  }
}

void profundidadeArv(Arv *a)
{
  int prof = profundidadeNos(a->raiz);
  printf("Profundidade da arvore: %d", prof);
}
int profundidadeNos(NoArv *raiz)
{
  if (raiz == NULL)
  {
    return -1;
  }

  int esq = profundidadeNos(raiz->esquerda);
  int dir = profundidadeNos(raiz->direita);

  if (esq > dir)
  {
    return esq + 1;
  }
  else
  {
    return dir + 1;
  }
}

void nivelDoNo(Arv *a, int chave)
{
  if (a->raiz == NULL)
  {
    printf("Arvore vazia\n");
    return;
  }

  int nivel = nivel_No(a->raiz, chave);

  if (nivel == -1)
  {
    printf("Valor %d nao encontrado na arvore\n", chave);
  }
  else
  {
    printf("Nivel do no %d: %d\n", chave, nivel);
  }
}

int nivel_No(NoArv *raiz, int chave)
{

  if (raiz == NULL)
  {
    return -1;
  }
  if (chave == raiz->valor)
  {
    return 0;
  }
  int nivelSub;
  if (chave < raiz->valor)
  {
    nivelSub = nivel_No(raiz->esquerda, chave);
  }
  else
  {
    nivelSub = nivel_No(raiz->direita, chave);
  }
  if (nivelSub == -1)
  {
    return -1;
  }
  else
  {
    return nivelSub + 1;
  }
}

void nivelArv(Arv *a){
  int nivel = nivel_Arv(a->raiz);
  printf("Total de Niveis da Arvore: %d", nivel);
}
int nivel_Arv(NoArv *raiz){
    if (raiz == NULL)
  {
    return 0;
  }
 
   int esq = nivel_Arv(raiz->esquerda);
   int dir = nivel_Arv(raiz->direita);

  if(esq > dir){
    return esq + 1;
  } else {
    return dir + 1;
  }
}
void imprimeAteNivelArv(Arv *a, int nivelMax){
  if (a->raiz == NULL) {
    printf("Arvore vazia\n");
  }
  else if (nivelMax < 0) {
    printf("Nivel invalido\n");
  }
  else {
    imprimeAteNivel(a->raiz, 0, nivelMax);
    printf("\n");
  }
}

void imprimeAteNivel(NoArv *raiz, int nivelAtual, int nivelMax){
  if (raiz != NULL && nivelAtual <= nivelMax) {

    printf("%d - ", raiz->valor);

    imprimeAteNivel(raiz->esquerda, nivelAtual + 1, nivelMax);
    imprimeAteNivel(raiz->direita,  nivelAtual + 1, nivelMax);
  }
}
void numeros_de_nos_nivel(Arv *a, int nivelMax){
  if (a->raiz == NULL) {
    printf("Arvore vazia\n");
  }

  if (nivelMax < 0) {
    printf("Nivel invalido\n");
  }

  int nosTotal = numeros_de_nos_apos_nivel(a->raiz, 0, nivelMax);
  printf("Nos apos o nivel %d: %d\n", nivelMax, nosTotal);
}

int numeros_de_nos_apos_nivel(NoArv *raiz, int nivelAtual, int nivelMax){
 if(raiz == NULL){
  return 0;
 }

 int cout = 0;
 if(nivelAtual > nivelMax){
  cout = 1;
 }

  int esq = numeros_de_nos_apos_nivel(raiz->esquerda, nivelAtual + 1, nivelMax);
  int dir = numeros_de_nos_apos_nivel(raiz->direita, nivelAtual + 1, nivelMax);

  return cout + esq + dir;
}

void NosMaiores(Arv *a, int chave){
  int maiores = Nos_Maiores_que(a->raiz, chave);
  printf("Numeros de Nos maiores que %d: %d", chave, maiores);
}
int Nos_Maiores_que(NoArv *raiz, int chave){
  if(raiz == NULL){
    return 0;
  }
  int cout = 0;
  if(chave < raiz->valor){
    cout ++;
  }
  int esq = Nos_Maiores_que(raiz->esquerda, chave);
  int dir = Nos_Maiores_que(raiz->direita, chave);
  return cout + esq + dir;
}
void removeFolhasArv(Arv *a){
  if (a->raiz == NULL) {
    printf("Arvore vazia\n");
  } else {
    a->raiz = removeFolhas(a->raiz);
    printf("Folhas removidas\n");
  }
}
NoArv *removeFolhas(NoArv *raiz){
  if (raiz == NULL) {
    return NULL;
  }

  if (raiz->esquerda == NULL && raiz->direita == NULL) {
    free(raiz);
    return NULL;
  }
  raiz->esquerda = removeFolhas(raiz->esquerda);
  raiz->direita  = removeFolhas(raiz->direita);

  return raiz;
}
int contaNosSubarvore(NoArv *raiz){
  if (raiz == NULL){
    return 0;
  }
  return 1 + contaNosSubarvore(raiz->esquerda) + contaNosSubarvore(raiz->direita);
}

void numero_de_Nos_esquerda_arv(Arv *a, int chave){
  if (a->raiz == NULL){
    printf("Arvore vazia\n");
  }

  int qtd = numeros_de_Nos_esq(a->raiz, chave);

  if (qtd == -1){
    printf("No %d nao encontrado na arvore\n", chave);
  } else {
    printf("Numero de nos na sub-arvore esquerda de %d: %d\n", chave, qtd);
  }
}

int numeros_de_Nos_esq(NoArv *raiz, int chave){
  if (raiz == NULL){
    return -1;
  }

  if (chave == raiz->valor){
    return contaNosSubarvore(raiz->esquerda);
  }

  if (chave < raiz->valor){
    return numeros_de_Nos_esq(raiz->esquerda, chave);
  } else {
    return numeros_de_Nos_esq(raiz->direita, chave);
  }
}
NoArv* buscaPaiNo(NoArv *raiz, int chave, NoArv *paiAtual) {
    if (raiz == NULL) {
        return NULL; 
    }

    if (raiz->valor == chave) {
        return paiAtual;   
    }

    if (chave < raiz->valor) {
        return buscaPaiNo(raiz->esquerda, chave, raiz);
    } else {
        return buscaPaiNo(raiz->direita, chave, raiz);
    }
}

NoArv* buscaPai(Arv *a, int chave) {
    return buscaPaiNo(a->raiz, chave, NULL); 
}

void imprimePai(Arv *a, int chave) {
    NoArv *pai = buscaPai(a, chave);

    if (pai == NULL) {
        NoArv *n = busca(a, chave);
        if (n == NULL) {
            printf("Valor %d nao existe na arvore.\n", chave);
        } else {
            printf("O no %d eh a raiz e nao possui pai.\n", chave);
        }
    } else {
        printf("O pai do no %d eh %d.\n", chave, pai->valor);
    }
}

void menorElementoArv(Arv *a){
  if (a->raiz == NULL) {
    printf("Arvore vazia\n");
  } else {
    int menor = menorElemento(a->raiz);
    printf("Menor elemento da arvore: %d\n", menor);
  }
}


int menorElemento(NoArv *raiz){
  if (raiz == NULL) {
    return 0;
  }

  if (raiz->esquerda == NULL) {
    return raiz->valor;
  }

  return menorElemento(raiz->esquerda);
}

void remove_menor_elemnto_arv(Arv *a){
  if (a->raiz == NULL) {
    printf("Arvore vazia\n");
  } else {
    a->raiz = removerMenorElemento(a->raiz);
    printf("Menor elemento removido\n");
  }
}

NoArv* removerMenorElemento(NoArv *raiz){
  if (raiz == NULL) {
    return NULL;
  }
  if (raiz->esquerda == NULL) {
    NoArv *direita = raiz->direita; 
    free(raiz);
    return direita;
  }
  raiz->esquerda = removerMenorElemento(raiz->esquerda);
  return raiz;
}

void alturaArvore(Arv *a){
  int alt = altura(a->raiz);
  printf("Altura da Arvore: %d\n", alt);
}

int altura(NoArv *raiz){
  if(raiz  == NULL){
    return -1;
  } else {
    int esq = altura(raiz->esquerda);
    int dir = altura(raiz->direita);
    if(esq > dir){
      return esq + 1;
    } else {
      return dir + 1;
    }
  }
}
int contaSubarvore(NoArv *raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return 1 + contaSubarvore(raiz->esquerda) + contaSubarvore(raiz->direita);
}
int r_descendentes(NoArv *pai, int chave){
    if (pai == NULL) {
        return -1;       
    }

    if (chave == pai->valor) {
        return contaSubarvore(pai) - 1;
    }

    if (chave < pai->valor) {
        return r_descendentes(pai->esquerda, chave);
    } else {
        return r_descendentes(pai->direita, chave);
    }
}

int descendentes(Arv *a, int chave){
    return r_descendentes(a->raiz, chave);
}

int contaAncestraisNo(NoArv *raiz, int chave) {
    if (raiz == NULL) {
        return -1;
    }

    if (chave == raiz->valor) {
        return 0;
    }

    if (chave < raiz->valor) {
        int r = contaAncestraisNo(raiz->esquerda, chave);
        if (r == -1){
          return -1; 
        } 
        return r + 1;          
    } else {
        int r = contaAncestraisNo(raiz->direita, chave);
        if (r == -1) return -1; 
        return r + 1;         
    }
}

int contaAncestrais(Arv *a, int chave) {
    return contaAncestraisNo(a->raiz, chave);
}
void removerArvoreNo(NoArv *raiz){
    if (raiz != NULL) {
        removerArvoreNo(raiz->esquerda);
        removerArvoreNo(raiz->direita);
        free(raiz);
    }
}
void removerArvore(Arv *a){
    if (a == NULL) {
        printf("Ponteiro de arvore invalido\n");
    }
    else if (a->raiz == NULL) {
        printf("Arvore vazia\n");
    }
    else {
        removerArvoreNo(a->raiz);
        a->raiz = NULL; 
        printf("Arvore removida\n");
    }
}
void arvoreEstrBinaria(Arv *a){
    int result;

    if (a->raiz == NULL) {
        printf("Arvore vazia (considerada estritamente binaria)\n");
    } else {
        result = EstritamenteBinaria(a->raiz);
        if (result == 1) {
            printf("Arvore eh estritamente binaria!\n");
        } else {
            printf("Arvore nao eh estritamente binaria\n");
        }
    }
}

int EstritamenteBinaria(NoArv *raiz){

    if (raiz == NULL) {
        return 1;
    }

    if ( (raiz->esquerda == NULL && raiz->direita != NULL) ||
         (raiz->esquerda != NULL && raiz->direita == NULL) ) {
        return 0;
    }

    int esq = EstritamenteBinaria(raiz->esquerda);
    int dir = EstritamenteBinaria(raiz->direita);

    if (esq == 1 && dir == 1) {
        return 1;
    } else {
        return 0;
    }
}
void soma_pares_Arv(Arv *a){
  int somapares = soma_pares(a->raiz);
  printf("Soma dos Nos pares da Arvore: %d", somapares);
}
int soma_pares(NoArv *raiz){
  if(raiz == NULL){
    return 0;
  }
  int soma = 0;
  if(raiz->valor % 2 == 0){
    soma += raiz->valor;
  }
  int esq = soma_pares(raiz->esquerda);
  int dir = soma_pares(raiz->direita);
  return esq + dir + soma;
}



int main()
{
  int op, num, v, bs, result;
  Arv *arv = CriaArv();
  NoArv *buscar = NULL;
  do
  {
    printf("\n1 - Inserir");
    printf("\n2 - Imprimir");
    printf("\n3 - Verificar Arvore");
    printf("\n4 - Soma Dos Nos");
    printf("\n5 - Numero de Folhas");
    printf("\n6 - Numero de Nos maiores que Elemento");
    printf("\n7 - Buscar Elemento");
    printf("\n8 - Profundidade da Arvore");
    printf("\n9 - Nivel de um No");
    printf("\n10 - NIveis da Arvore");
    printf("\n11 - Imprimir ate um certo nivel");
    printf("\n12 - Numeros de Nos ate um certo nivel");
    printf("\n13 - Numeros de Nos maiores que um certo Elemento");
    printf("\n14 - Remover Folhas");
    printf("\n15 - Numero de nos da sub-arvore esquerda de um no");
    printf("\n16 - Imprime pai de certo No");
    printf("\n17 - Menor elemento da arvore");
    printf("\n18 - Altura da Arvore");
    printf("\n19 - Descendentes de um No");
    printf("\n20 - Ancestrais de um NO");
    printf("\n21 - Remover Arvore");
    printf("\n22 - Arvore estritamente binaria");
    printf("\n23 - Soma Dos Nos pares");
    printf("\n");


    scanf("%d", &op);
    switch (op)
    {
    case 0:
      printf("Saindo ...");
      break;
    case 1:
      printf("Inserir: ");
      scanf("%d", &num);
      inserir_na_arvore(arv, num);
      break;
    case 2:
      imprimirArv(arv);
      break;
    case 3:
      v = verifica(arv);
      if (v == 0)
      {
        printf("Arvore vazia\n");
      }
      else
      {
        printf("Arvore contem elementos\n");
      }
      break;
    case 4:
      somaArv(arv);
      break;
    case 5:
      folhasArv(arv);
      break;
    case 6:
      printf("Digite um valor a ser comparado: ");
      scanf("%d", &num);
      numerosMaiores(arv, num);
      break;
    case 7:
      printf("Encontre o elemento: ");
      scanf("%d", &bs);
      buscar = busca(arv, bs);
      if (buscar == NULL)
      {
        printf("Valor não encontrado\n");
      }
      else
      {
        printf("Valor %d encontrado\n", buscar->valor);
      }
      break;
    case 8:
      profundidadeArv(arv);
      break;
    case 9:
      printf("Digite o valor do no para saber o nivel: ");
      scanf("%d", &num);
      nivelDoNo(arv, num);
      break;
    case 10:
      nivelArv(arv);
    break;
    case 11:
      printf("Digite o nivel maximo a ser impresso: ");
      scanf("%d", &num);
      imprimeAteNivelArv(arv, num);
    break;
    case 12:
      printf("Digite o nivel maximo: ");
      scanf("%d", &num);
      numeros_de_nos_nivel(arv, num);
    break;
    case 13:
      printf("Digite um Valor: ");
      scanf("%d", &num);
      NosMaiores(arv, num);
    break;
    case 14:
      removeFolhasArv(arv);
    break;
    case 15:
      printf("Digite o valor do no: ");
      scanf("%d", &num);
      numero_de_Nos_esquerda_arv(arv, num);
    break;
    case 16:
      printf("Digite um No: ");
      scanf("%d", &num);
      imprimePai(arv, num);
    break;
    case 17:
       menorElementoArv(arv);
    break;
    case 18:
      alturaArvore(arv);
    break;
    case 19:
      printf("Digite um elemento que exista na arvore: ");
      scanf("%d", &num);
      result = descendentes(arv, num);
      printf("Numero de descendentes: %d", result);
    break;
    case 20:
      printf("Digite um elemento que exista na arvore: ");
      scanf("%d", &num);
      result = contaAncestrais(arv, num);
      printf("Numero de ancestrais: %d", result);
    break; 
    case 21:
      removerArvore(arv);
    break;
    case 22:
      arvoreEstrBinaria(arv);
    break;
    case 23:
      soma_pares_Arv(arv);
    break;




    }
  } while (op != 0);

  return 0;
}