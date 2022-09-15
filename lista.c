// Programa de merge de listas ligadas. Questao 4.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

//#define DEBUG
//#define EMPTY_DATA

typedef struct ListNode {
int value;
struct ListNode *next;
} ListNode;


// Array para carga de dados:
typedef int ArrayNode[10][10];

// Array usado em versao preliminar:
int vet_lista_out[100];

// funcao de comparaca, usada em versao preliminar com qsort.
int comp_func (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

// Funcao de inclusao na lista ligada.
ListNode *addNode(ListNode *r, int value) {
ListNode *new_elem;
ListNode *cur_elem;

new_elem = (ListNode *) malloc(sizeof(ListNode));
new_elem->value = value;
new_elem->next = NULL;

if (r == (ListNode *) NULL) {
  r = new_elem;
} 
else {
  cur_elem = r;
  while ((cur_elem->next != NULL) && (cur_elem->next->value < value)) {
    cur_elem = cur_elem->next;
  }
  if (cur_elem->next == NULL) {
    cur_elem->next = new_elem;
  }
  else {
    new_elem->next =  cur_elem->next; 
    cur_elem->next = new_elem;
  }
}

return (r);
}

// Print de debug, com mais informacoes.
void printNodesDebug(ListNode *r) {
ListNode *cur_elem;
int cont=0;

  cur_elem = r;
  while (cur_elem != NULL) {
    printf("ELEM index [%d] value [%d] next [%08X]\n", cont, cur_elem->value, (unsigned int) cur_elem->next);
    cur_elem = cur_elem->next;
    cont++;
  } 
}


// Funcao de print da lista ligada.
void printNodes(ListNode *r) {
ListNode *cur_elem;

  cur_elem = r;

  if(cur_elem == NULL)
     printf("[ ");
  else
    printf("[");

  while (cur_elem != NULL) {
    if (cur_elem->next == NULL)
      printf("%d", cur_elem->value);
    else
      printf("%d,", cur_elem->value);
    cur_elem = cur_elem->next;
  } 

  printf("]\n");
}


// Funcao que responde a questao 4, proposta no teste da IGS.

ListNode *mergeKListas(ListNode **listas, int listasSize) {
ListNode *rootNode=NULL;
ListNode *cur_elem;
int i;

rootNode = (ListNode *) listas[0];

for (i = 1; i < listasSize; i++) {
  cur_elem = listas[i];
  while (cur_elem != NULL) {
    rootNode = addNode(rootNode, cur_elem->value);
    cur_elem = cur_elem->next;
  }
}

return (rootNode);
}

// Funcao de release (free) dos elementos da lista ligada.
void releaseNodes(ListNode *head_elem) {
ListNode *cur_elem;

  while (head_elem != NULL) {
    cur_elem = head_elem;
    head_elem = head_elem->next;
    free(cur_elem);
  } 
}


// Funcao main()
int main()
{
int i, j;
int total_elem = 0;
int listasSize = 3;
ListNode *rootNode=NULL;
ListNode *arrayOfLists[3];

  for (i = 0; i < 3; i++) {
    arrayOfLists[i] = NULL;
  }

#ifndef EMPTY_DATA
  // associa os dados de entrada a um array, para facilitar a insercao de dados nas listas ligadas.
  ArrayNode vet_listas = {{1,3,8},{1,3,6},{8,9}};

  for (i = 0; i < listasSize; i++) {
    for (j = 0; j < 10; j++) {
#ifdef DEBUG_2
      printf("elemento %d total_elem %d\n", vet_listas[i][j], total_elem);
#endif
      if (vet_listas[i][j] > 0) {
        vet_lista_out[total_elem++] = vet_listas[i][j];
        arrayOfLists[i] = addNode(arrayOfLists[i], vet_listas[i][j]); 
      }
      else
        break;
    }
  }
#endif

#ifdef DEBUG
  printf("total_elem %d\n", total_elem);
#endif

  for (i = 0; i < 3; i++) {
//    printNodesDebug(arrayOfLists[i]);
    printNodes(arrayOfLists[i]);
  }

  rootNode = mergeKListas(arrayOfLists, 3);

//  Versao preliminar faz sort em array:
//  qsort(lista_out, total_elem, sizeof(int), comp_func);

#ifdef DEBUG
  if (listasSize == 0)
    printf("[ ");
  else
    printf("[");

  for (i = 0; i < total_elem; i++) {
    if (i == (total_elem - 1))
      printf("%d", vet_lista_out[i]);
    else
      printf("%d,", vet_lista_out[i]);
  }
#endif

//  printNodesDebug(rootNode);
  printNodes(rootNode);

 
  // Libera espaco alocado das listas parciais.
  for (i = 0; i < 3; i++) {
    releaseNodes(arrayOfLists[i]);
  }


  // libera espaco da lista gerada por merge.
  releaseNodes(rootNode);

  return 0;
}
